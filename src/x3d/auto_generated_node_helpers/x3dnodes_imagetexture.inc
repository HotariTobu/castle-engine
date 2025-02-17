{ -*- buffer-read-only: t -*-

  Copyright 2015-2021 Michalis Kamburelis.

  This file is part of "Castle Game Engine".

  "Castle Game Engine" is free software; see the file COPYING.txt,
  included in this distribution, for details about the copyright.

  "Castle Game Engine" is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

  ----------------------------------------------------------------------------
}

{ Automatically generated node properties.

  Do not edit this file manually!
  To add new properties:
  - add them to the text files in tools/internal/x3d-nodes-to-pascal/nodes-specification/ ,
  - and regenerate include files by running x3d-nodes-to-pascal .

  The documentation for properties should go to x3dnodes_documentation.txt . }

{$ifdef read_interface}

  strict private
    function GetFlipVertically: Boolean;
    procedure SetFlipVertically(const Value: Boolean);
  public
    { Set X3D field "url". } { }
    procedure SetUrl(const Value: array of string); overload;
    { Set X3D field "url". } { }
    procedure SetUrl(const Value: TCastleStringList); overload;
    { X3D field "flipVertically". } { }
    property FlipVertically: Boolean read GetFlipVertically write SetFlipVertically;

{$endif read_interface}

{$ifdef read_implementation}

{ TImageTextureNode ----------------------------------------------- }

procedure TImageTextureNode.SetUrl(const Value: array of string);
begin
  FdUrl.Send(Value);
end;

procedure TImageTextureNode.SetUrl(const Value: TCastleStringList);
begin
  FdUrl.Send(Value);
end;

function TImageTextureNode.GetFlipVertically: Boolean;
begin
  Result := FdFlipVertically.Value;
end;

procedure TImageTextureNode.SetFlipVertically(const Value: Boolean);
begin
  FdFlipVertically.Send(Value);
end;

{$endif read_implementation}
