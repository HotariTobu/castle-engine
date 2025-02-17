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
    function GetShaderType: TShaderType;
    procedure SetShaderType(const Value: TShaderType);
  public
    { Set X3D field "url". } { }
    procedure SetUrl(const Value: array of string); overload;
    { Set X3D field "url". } { }
    procedure SetUrl(const Value: TCastleStringList); overload;
    { X3D field "type". } { }
    property ShaderType: TShaderType read GetShaderType write SetShaderType;

{$endif read_interface}

{$ifdef read_implementation}

{ TShaderPartNode ----------------------------------------------- }

procedure TShaderPartNode.SetUrl(const Value: array of string);
begin
  FdUrl.Send(Value);
end;

procedure TShaderPartNode.SetUrl(const Value: TCastleStringList);
begin
  FdUrl.Send(Value);
end;

function TShaderPartNode.GetShaderType: TShaderType;
begin
  Result := TShaderType(FdType.EnumValue);
end;

procedure TShaderPartNode.SetShaderType(const Value: TShaderType);
begin
  FdType.SendEnumValue(Ord(Value));
end;

{$endif read_implementation}
