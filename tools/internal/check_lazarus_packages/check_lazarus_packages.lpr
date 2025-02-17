// -*- compile-command: "castle-engine compile --mode=release && castle-engine run -- ../../../" -*-
{
  Copyright 2021-2021 Michalis Kamburelis.

  This file is part of "Castle Game Engine".

  "Castle Game Engine" is free software; see the file COPYING.txt,
  included in this distribution, for details about the copyright.

  "Castle Game Engine" is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

  ----------------------------------------------------------------------------
}

{ Check CGE Lazarus packages correctness. }

uses SysUtils, DOM,
  CastleXMLUtils, CastleUtils, CastleFindFiles, CastleStringUtils, CastleParameters,
  CastleLog, CastleApplicationProperties;

var
  CgePath: String;
  CgePathExpanded: String;
  HasWarnings: Boolean = false;

type
  EInvalidPackage = class(Exception);

{ Report warning.
  Continue the work, but the test will exit with non-zero status signalling invalid package.
  This way we report many problems in one go. }
procedure PackageWarning(const S: String; const Args: array of const);
begin
  WriteLnWarning(Format(S, Args));
  HasWarnings := true;
end;

{ TLazarusPackage ------------------------------------------------------------}

type
  TLazarusPackage = class
  strict private
    RequiredFilesList: TCastleStringList;
    FLpkFileName: String;
    procedure GatherRequiredFiles(const FileInfo: TFileInfo; var StopSearch: Boolean);
    procedure ExcludeFromRequiredFiles(const FileInfo: TFileInfo; var StopSearch: Boolean);
  public
    Files: TCastleStringList;
    constructor Create(const ALpkFileName: String);
    destructor Destroy; override;
    { Check that package
      - contains all files from RequiredFiles (except ExcludedFromRequiredFiles)
      - doesn't contain any files not in RequiredFiles (except ExcludedFromRequiredFiles) + OptionalFiles
    }
    procedure CheckFiles(const RequiredFiles, ExcludedFromRequiredFiles, OptionalFiles: array of String);
  end;

constructor TLazarusPackage.Create(const ALpkFileName: String);
var
  Doc: TXMLDocument;
  FilesElement, FileElement: TDOMElement;
  I, FilesCount: Cardinal;
  FileName: String;
begin
  inherited Create;
  Files := TCastleStringList.Create;
  Files.CaseSensitive := FileNameCaseSensitive;

  FLpkFileName := ALpkFileName;
  Doc := URLReadXML(FLpkFileName);
  try
    FilesElement := Doc.DocumentElement.Child('Package').Child('Files');
    FilesCount := FilesElement.AttributeCardinal('Count');
    for I := 1 to FilesCount do
    begin
      FileElement := FilesElement.Child('Item' + IntToStr(I));
      FileName := FileElement.Child('Filename').AttributeString('Value');
      if not IsPrefix('../src/', FileName, not FileNameCaseSensitive) then
        PackageWarning('All filenames in lpk must be in CGE src, invalid: %s', [FileName]);
      FileName := PrefixRemove('../src/', FileName, not FileNameCaseSensitive);
      Files.Append(FileName);
    end;
  finally FreeAndNil(Doc) end;

  Writeln(Format('LPK %s: %d files', [FLpkFileName, Files.Count]));
end;

destructor TLazarusPackage.Destroy;
begin
  FreeAndNil(Files);
  inherited;
end;

procedure TLazarusPackage.GatherRequiredFiles(const FileInfo: TFileInfo; var StopSearch: Boolean);
var
  FileName, CgePrefix: String;
begin
  FileName := FileInfo.AbsoluteName;
  FileName := SReplaceChars(FileName, PathDelim, '/'); // replace backslashes with slashes on Windows

  CgePrefix := CgePathExpanded + 'src/';
  if not IsPrefix(CgePrefix, FileName, not FileNameCaseSensitive) then
    PackageWarning('All found files must be in CGE src, invalid: %s', [FileName]);
  FileName := PrefixRemove(CgePrefix, FileName, not FileNameCaseSensitive);

  RequiredFilesList.Append(FileName);
end;

procedure TLazarusPackage.ExcludeFromRequiredFiles(const FileInfo: TFileInfo; var StopSearch: Boolean);
var
  FileName, CgePrefix: String;
  I: Integer;
begin
  FileName := FileInfo.AbsoluteName;
  FileName := SReplaceChars(FileName, PathDelim, '/'); // replace backslashes with slashes on Windows

  CgePrefix := CgePathExpanded + 'src/';
  if not IsPrefix(CgePrefix, FileName, not FileNameCaseSensitive) then
    PackageWarning('All found files must be in CGE src, invalid: %s', [FileName]);
  FileName := PrefixRemove(CgePrefix, FileName, not FileNameCaseSensitive);

  I := RequiredFilesList.IndexOf(FileName);
  if I = -1 then
    raise EInternalError.Create('File found in ExcludeFromRequiredFiles, but not in RequiredFiles: ' + FileName);
  RequiredFilesList.Delete(I);
end;

procedure TLazarusPackage.CheckFiles(const RequiredFiles, ExcludedFromRequiredFiles, OptionalFiles: array of String);

  function InsideOptionalFiles(const FileName: String): Boolean;
  var
    I: Integer;
  begin
    for I := 0 to High(OptionalFiles) do
      if IsPrefix(OptionalFiles[I] + PathDelim, FileName, not FileNameCaseSensitive) or
         IsPrefix(OptionalFiles[I] + '/', FileName, not FileNameCaseSensitive) then // accept / also on Windows
        Exit(true);
    Result := false;
  end;

var
  I, FilesIndex: Integer;
  FindPath: String;
begin
  RequiredFilesList := TCastleStringList.Create;
  RequiredFilesList.CaseSensitive := FileNameCaseSensitive;
  for I := 0 to High(RequiredFiles) do
  begin
    FindPath := CgePathExpanded + 'src' + PathDelim + RequiredFiles[I] + PathDelim;
    FindFiles(FindPath, '*.inc', false, @GatherRequiredFiles, [ffRecursive]);
    FindFiles(FindPath, '*.pas', false, @GatherRequiredFiles, [ffRecursive]);
    FindFiles(FindPath, '*.image_data', false, @GatherRequiredFiles, [ffRecursive]);
    FindFiles(FindPath, '*.lrs', false, @GatherRequiredFiles, [ffRecursive]);
  end;
  Writeln('Found required files on disk: ', RequiredFilesList.Count);

  { remove ExcludedFromRequiredFiles }
  for I := 0 to High(ExcludedFromRequiredFiles) do
  begin
    FindPath := CgePathExpanded + 'src' + PathDelim + ExcludedFromRequiredFiles[I] + PathDelim;
    FindFiles(FindPath, '*.inc', false, @ExcludeFromRequiredFiles, [ffRecursive]);
    FindFiles(FindPath, '*.pas', false, @ExcludeFromRequiredFiles, [ffRecursive]);
    FindFiles(FindPath, '*.image_data', false, @ExcludeFromRequiredFiles, [ffRecursive]);
    FindFiles(FindPath, '*.lrs', false, @ExcludeFromRequiredFiles, [ffRecursive]);
  end;
  Writeln('Required files after removing exclusions: ', RequiredFilesList.Count);

  { verify that all RequiredFilesList are in package, remove them from Files }
  for I := 0 to RequiredFilesList.Count - 1 do
  begin
    FilesIndex := Files.IndexOf(RequiredFilesList[I]);
    if FilesIndex = -1 then
      PackageWarning('Required file "%s" is not present in package "%s"', [
        RequiredFilesList[I],
        FLpkFileName
      ])
    else
      Files.Delete(FilesIndex);
  end;

  { verify that rest of Files is in OptionalFiles }
  for I := 0 to Files.Count - 1 do
    if not InsideOptionalFiles(Files[I]) then
      PackageWarning('File "%s" in package "%s" is neither in OptionalFiles or RequiredFiles of this package, or it is in package but not existing on disk', [
        Files[I],
        FLpkFileName
      ]);

  FreeAndNil(RequiredFilesList);
end;

{ main routine --------------------------------------------------------------- }

var
  Lpk: TLazarusPackage;
begin
  ApplicationProperties.ApplicationName := 'check_lazarus_packages';
  ApplicationProperties.Version := CastleEngineVersion;
  ApplicationProperties.OnWarning.Add(@ApplicationProperties.WriteWarningOnConsole);

  Parameters.CheckHigh(1);
  CgePath := Parameters[1];

  CgePathExpanded := InclPathDelim(ExpandFileName(CgePath));
  CgePathExpanded := SReplaceChars(CgePathExpanded, PathDelim, '/'); // replace backslashes with slashes on Windows

  Lpk := TLazarusPackage.Create(CgePathExpanded + 'packages' + PathDelim + 'castle_base.lpk');
  try
    Lpk.CheckFiles([
     'common_includes',
     '3d',
     'audio',
     'base',
     'castlescript',
     'files',
     'fonts',
     'game',
     'images',
     'pasgltf',
     'physics',
     'services',
     'ui',
     'x3d',
     'deprecated_units'
    ],
    [
      'base/android',
      'files/indy'
    ],
    [ ]);
  finally FreeAndNil(Lpk) end;

  Lpk := TLazarusPackage.Create(CgePathExpanded + 'packages' + PathDelim + 'castle_window.lpk');
  try
    Lpk.CheckFiles([
     'window'
    ],
    [ ],
    [ ]);
  finally FreeAndNil(Lpk) end;

  Lpk := TLazarusPackage.Create(CgePathExpanded + 'packages' + PathDelim + 'alternative_castle_window_based_on_lcl.lpk');
  try
    Lpk.CheckFiles([
     'window'
    ],
    [ ],
    [ ]);
  finally FreeAndNil(Lpk) end;

  Lpk := TLazarusPackage.Create(CgePathExpanded + 'packages' + PathDelim + 'castle_components.lpk');
  try
    Lpk.CheckFiles([
     'lcl'
    ],
    [],
    [ ]);
  finally FreeAndNil(Lpk) end;

  Lpk := TLazarusPackage.Create(CgePathExpanded + 'packages' + PathDelim + 'castle_indy.lpk');
  try
    Lpk.CheckFiles([
     'files/indy'
    ],
    [ ],
    [ ]);
  finally FreeAndNil(Lpk) end;

  if HasWarnings then
  begin
    Writeln('Some package problems reported above, exiting with status 1');
    Halt(1);
  end;
end.
