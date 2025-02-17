{
  Copyright 2001-2018 Michalis Kamburelis.

  This file is part of "Castle Game Engine".

  "Castle Game Engine" is free software; see the file COPYING.txt,
  included in this distribution, for details about the copyright.

  "Castle Game Engine" is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

  ----------------------------------------------------------------------------
}

type
  TBitmapFileHeader = packed record
    bfType: array[0..1]of AnsiChar;
    bfSize: UInt32;
    bfReserved1: Word;
    bfReserved2: Word;
    bfOffBits: UInt32;
  end;

  TBitmapInfoHeader = packed record
    biSize: UInt32;
    biWidth: Int32;
    biHeight: Int32;
    biPlanes: Word;
    biBitCount: Word;
    biCompression: UInt32;
    biSizeImage: UInt32;
    biXPelsPerMeter: Int32;
    biYPelsPerMeter: Int32;
    biClrUsed: UInt32;
    biClrImportant: UInt32;
  end;

  TRGBQuad = packed record blue, green, red, reserved : byte end;
  //PRGBQuad = ^TRGBQuad;
  TRGBQuadArray = packed array[0..MaxInt div SizeOf(TRGBQuad)-1]of TRGBQuad;
  PRGBQuadArray = ^TRGBQuadArray;

  TRGB_BMP24 = packed record b, g, r: byte end; { trojka RGB w zapisie danych 24 bitowej bitmapy }
  PRGB_BMP24 = ^TRGB_BMP24;
  TRGB_BMP24Array = array[0..MaxInt div SizeOf(TRGB_BMP24)-1] of TRGB_BMP24;
  PRGB_BMP24Array = ^TRGB_BMP24Array;

const
  BI_RGB = 0;
  //BI_RLE8 = 1;
  //BI_RLE4 = 2;
  //BI_BITFIELDS = 3;

function LoadBMP(const Stream: TStream;
  const AllowedImageClasses: array of TEncodedImageClass): TEncodedImage;
var fhead: TBitmapFileHeader;
    ihead: TBitmapInfoHeader;
    paletteSize: integer;    { rozmiar palety (0 jesli brak) }
    palette: PRGBQuadArray; { odczytana paleta (nil jesli paletteSize = 0) }
    rowLength: integer;      { dlugosc wiersza (bez 32bit padding !) }
    rownum: integer;

  procedure PutPaletteColor(paletteIndex: integer; var rgb3: TVector3Byte);
  { ustaw rgb3 na kolor numer paletteIndex wziety z palety }
  begin
   rgb3.Data[0] := palette^[paletteIndex].red;
   rgb3.Data[1] := palette^[paletteIndex].green;
   rgb3.Data[2] := palette^[paletteIndex].blue;
  end;

  procedure WriteRow(Row: Pointer; bmprow: PByteArray);
  { przepisz wiersz bitmapy bmprow na wiersz strukturek TVector3Byte. }

    function FiveBitsToByte(fivebits: Word): byte;
    begin
     {liczbe z zkaresu 0..31 (1111 binarnie) (ale podana jako typ Word -
      ponizej bezdiemy chcieli ja mnozyc przez 255 !) mapuje na zakres 0..255}
     result := fivebits*255 div 31;
    end;

  var
    bmpi, rgbi: integer;  { bmpi iteruje po bmprow, rgbi iteruje po rgbrow }
    rgbrow: PVector3ByteArray absolute Row;
    rgbarow: PVector4ByteArray absolute Row;
  begin
   bmpi := 0;
   rgbi := 0;
   case ihead.biBitCount of
    1: for rgbi := 0 to ihead.biWidth-1 do
       begin
        PutPaletteColor((bmprow^[bmpi] shr (7-(rgbi mod 8)) ) and 1, rgbrow^[rgbi]);
        if (rgbi+1) mod 8 = 0 then Inc(bmpi);
       end;
    4: begin
        for bmpi := 0 to rowLength-2 do
        begin
         PutPaletteColor(bmprow^[bmpi] and $F0 shr 4, rgbrow^[bmpi*2]);
         PutPaletteColor(bmprow^[bmpi] and $F, rgbrow^[bmpi*2+1]);
        end;
        { gdy bmpi = rowLength - 1 musimy uwazac : kolumna bmpi*2 na pewno
          jest w bitmapie, ale kolumna bmp*2+1 moze byc juz poza bitmapa }
        bmpi := rowLength-1;
        PutPaletteColor(bmprow^[bmpi] and $F0 shr 4, rgbrow^[bmpi*2]);
        if bmpi*2+1 < ihead.biWidth then
         PutPaletteColor(bmprow^[bmpi] and $F, rgbrow^[bmpi*2+1]);
       end;
    8: for bmpi := 0 to rowLength-1 do
        PutPaletteColor(bmprow^[bmpi], rgbrow^[bmpi]);
    16:for rgbi := 0 to ihead.biWidth-1 do
       begin
        {$ifndef FPC}{$POINTERMATH ON}{$endif}
        rgbrow^[rgbi].Data[0] := FiveBitsToByte((PWord(bmprow)[rgbi] and $7C00) shr 10);
        rgbrow^[rgbi].Data[1] := FiveBitsToByte((PWord(bmprow)[rgbi] and $03E0) shr 5);
        rgbrow^[rgbi].Data[2] := FiveBitsToByte(PWord(bmprow)[rgbi] and $001F);
        {$ifndef FPC}{$POINTERMATH OFF}{$endif}
       end;
    24:{ bmprow in 24 bit bitmap have almost the same format as rgbrow  -
         we only have to swap bgr to rgb }
       for rgbi := 0 to ihead.biWidth-1 do
       begin
        rgbrow^[rgbi].Data[0] := PRGB_BMP24Array(bmprow)^[rgbi].r;
        rgbrow^[rgbi].Data[1] := PRGB_BMP24Array(bmprow)^[rgbi].g;
        rgbrow^[rgbi].Data[2] := PRGB_BMP24Array(bmprow)^[rgbi].b;
       end;
    32:for rgbi := 0 to ihead.biWidth-1 do
       begin
         { We know that for 32, we have TRGBAlphaImage, so we use rgbarow }
         Assert(Result is TRGBAlphaImage);

         rgbarow^[rgbi].Data[0] := PRGBQuadArray(bmprow)^[rgbi].red;
         rgbarow^[rgbi].Data[1] := PRGBQuadArray(bmprow)^[rgbi].green;
         rgbarow^[rgbi].Data[2] := PRGBQuadArray(bmprow)^[rgbi].blue;
         { At least GIMP treats the 4th component as alpha value. }
         rgbarow^[rgbi].Data[3] := PRGBQuadArray(bmprow)^[rgbi].reserved;
       end;
   end;
  end;

  { ClassAllowed is only shortcut to global utility. }
  function ClassAllowed(ImageClass: TEncodedImageClass): boolean;
  begin
    Result := CastleImages.ClassAllowed(ImageClass, AllowedImageClasses);
  end;

var
  i: integer;
  rowsGoingUp: boolean;
  rowdata: PByteArray;
begin
 try
  { read and check headers }
  Stream.ReadBuffer(fhead, SizeOf(fhead));
  Stream.ReadBuffer(ihead, SizeOf(ihead));
  with fhead do
   Check( (bfType[0]='B') and (bfType[1]='M'), 'not a bitmap file (first two bytes <> BM)');
  with ihead do
  begin
   { check removed - ImageMagick can write such wrong bitmaps (but they are
     really wrong !
     - TotalCommander's internal view
     - and Windows2k code to show bmps on desktop
     - and GIMP
     all fail trying to open them.) }
   if biSize <> SizeOf(TBitmapInfoHeader) then
      WritelnWarning('BMP', 'Invalid BMP: Wrong size of a bitmap header --- should be %d, is %d',
        [SizeOf(TBitmapInfoHeader), biSize]);

   { height can be negative - it means rows are written from up to down }
   rowsGoingUp := biHeight > 0;
   biHeight := Abs(biHeight);

   PaletteSize := 0;
   case biBitCount of
    1: begin PaletteSize := 2; rowLength := DivRoundUp(biWidth, 8) end;
    4: begin PaletteSize := 16; rowLength := DivRoundUp(biWidth, 2) end;
    8: begin PaletteSize := 256; rowLength := biWidth end;
    16: begin rowLength := biWidth * 2 end;
    24: begin rowLength := biWidth * 3 end;
    32: begin rowLength := biWidth * 4 end;
    else raise EInvalidBMP.Create('Wrong bitmap : biBitCount doesn''t match any allowed value');
   end;

   if (paletteSize <> 0 {paletted format}) and (biClrUsed <> 0) then
    paletteSize := biClrUsed;

   if biCompression <> BI_RGB then
    raise EInvalidBMP.Create('TODO: RLE compressed and bitfields bitmaps not implemented yet');

   palette := nil;
   rowdata := nil;
   Result := nil;
   try
    try
     { optionally read palette }
     if paletteSize <> 0 then
     begin
      palette := GetMem(paletteSize * SizeOf(TRGBQuad));
      Stream.ReadBuffer(palette[0], paletteSize * SizeOf(TRGBQuad));
     end;

     { read data }
     { we have to use here Stream.Position, we can't be sure we're standing
       in the right place - because sometimes when the palette is not fully
       used image can be written earlier in the file - it's simple, for example
       we are writing 8 bit bitmap with only 200 colors. We're writing 200 colors
       and than we're immediately start writing pixel-data (even though
       documentation states we have to provide 256 colors).
       And we're setting bfOffBits 56*4 bytes earlier than SizeOf(fileheader) +
       SizeOf(infoheader) + SizeOf(palette with 256 entries). This way we
       don't waste place. This is what bitmap writers like Corel do. And it's ok.

       Besides we (the bitmap Reader) want to use that feature bacause we're
       using biClrUsed so we don't waste time for readind usused colors.
       Ans no one said that bitmap writer HAS to use that trick with setting
       bfOffBits earlier - it can just fill unused palette space with shit,
       and write always 256 color palette event when he doesn't use so many colors.
       So we have to use bfOffBits. }

     Stream.Position := fhead.bfOffBits;
     rowdata := GetMem(rowLength);

     { We always allocate Result most matching to file format
       (biBitCount = 32 is RGBA, else RGB).
       We let LoadEncodedImage to later fix the output type
       to satisfy AllowedImageClasses. }
     if biBitCount = 32 then
       Result := TRGBAlphaImage.Create(biWidth, biHeight)
     else
       Result := TRGBImage.Create(biWidth, biHeight);

     for i := 0 to biHeight - 1 do
     begin
      Stream.ReadBuffer(rowdata[0], rowLength);
      { skip row 32bit padding }
      with Stream do Position := Position + DivRoundUp(rowLength, 4)*4 - rowLength;
      if rowsGoingUp then rownum := i else rownum := biHeight-i-1;
      WriteRow(TCastleImage(Result).RowPtr(rownum), rowData);
     end;

    finally
     FreeMemNiling(pointer(rowdata));
     FreeMemNiling(pointer(palette));
    end;
   except Result.Free; raise end;
  end;

 except
  { EReadError is thrown by Stream.ReadBuffer when it can't read
    specified number of bytes }
  on E: EReadError do raise EInvalidBMP.Create('Read error: ' + E.Message);
  on E: ECheckFailed do raise EInvalidBMP.Create('Wrong bitmap: ' + E.Message);
 end;
end;

procedure SaveBMP(const Img: TEncodedImage; const Stream: TStream);
var fhead: TBitmapFileHeader;
    ihead: TBitmapInfoHeader;
    i, j, rowPaddedLength, PadSize: cardinal;
    p :PVector3Byte;
    row, rowdata :PRGB_BMP24;
begin
  if not (Img is TRGBImage) then
    raise EImageSaveError.CreateFmt('Saving to BMP image class %s not possible', [Img.ClassName]);

 rowPaddedLength := img.Width*SizeOf(TRGB_BMP24);
 if rowPaddedLength mod 4 <> 0 then
  padsize := 4-rowPaddedLength mod 4 else
  padsize := 0;
 rowPaddedLength := rowPaddedLength + padsize;

 fhead.bfType[0] := 'B';
 fhead.bfType[1] := 'M';
 fhead.bfSize := SizeOf(TBitmapFileHeader) + SizeOf(TBitmapInfoHeader) + rowPaddedLength*img.Height;
 fhead.bfReserved1 := 0;
 fhead.bfReserved2 := 0;
 fhead.bfOffBits := SizeOf(TBitmapFileHeader) + SizeOf(TBitmapInfoHeader);

 ihead.biSize := SizeOf(TBitmapInfoHeader);
 ihead.biWidth := img.Width;
 ihead.biHeight := img.Height;
 ihead.biPlanes := 1;
 ihead.biBitCount := 24;
 ihead.biCompression := BI_RGB;
 ihead.biSizeImage := 0;
 ihead.biXPelsPerMeter := 3779;
 ihead.biYPelsPerMeter := 3779;
 ihead.biClrUsed := 0;
 ihead.biClrImportant := 0;

 Stream.WriteBuffer(fhead, SizeOf(fhead));
 Stream.WriteBuffer(ihead, SizeOf(ihead));

 rowdata := GetMem(rowPaddedLength);
 try
  for j := 0 to img.Height-1 do
  begin
   p := PVector3Byte(TCastleImage(Img).PixelPtr(0, j));
   row := rowdata;
   for i := 0 to img.Width - 1 do
   begin
    row^.r := p^.Data[0];
    row^.g := p^.Data[1];
    row^.b := p^.Data[2];
    Inc(p);
    Inc(row);
   end;
   FillChar(row^, padsize, 0);
   Stream.WriteBuffer(rowdata^, rowPaddedLength);
  end;
 finally FreeMem(rowdata) end;
end;
