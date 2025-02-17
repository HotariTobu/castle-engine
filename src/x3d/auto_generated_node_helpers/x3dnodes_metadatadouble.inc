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

  public
    procedure CreateNode; override;
    class function ClassX3DType: string; override;

    strict private FFdValue: TMFDouble;
    { X3D field "value". } { }
    public property FdValue: TMFDouble read FFdValue;
    { Set X3D field "value". } { }
    procedure SetValue(const Value: array of Double); overload;
    { Set X3D field "value". } { }
    procedure SetValue(const Value: TDoubleList); overload;

{$endif read_interface}

{$ifdef read_implementation}

{ TMetadataDoubleNode ----------------------------------------------- }

procedure TMetadataDoubleNode.SetValue(const Value: array of Double);
begin
  FdValue.Send(Value);
end;

procedure TMetadataDoubleNode.SetValue(const Value: TDoubleList);
begin
  FdValue.Send(Value);
end;

class function TMetadataDoubleNode.ClassX3DType: String;
begin
  Result := 'MetadataDouble';
end;

procedure TMetadataDoubleNode.CreateNode;
begin
  inherited;

  FFdValue := TMFDouble.Create(Self, True, 'value', []);
   FdValue.ChangeAlways := chNone;
  AddField(FFdValue);
end;

{$endif read_implementation}
