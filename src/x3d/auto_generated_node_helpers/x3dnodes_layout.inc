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

    strict private FFdAlign: TMFString;
    { X3D field "align". } { }
    public property FdAlign: TMFString read FFdAlign;
    { Set X3D field "align". } { }
    procedure SetAlign(const Value: array of string); overload;
    { Set X3D field "align". } { }
    procedure SetAlign(const Value: TCastleStringList); overload;

    strict private FFdOffset: TMFFloat;
    { X3D field "offset". } { }
    public property FdOffset: TMFFloat read FFdOffset;
    { Set X3D field "offset". } { }
    procedure SetOffset(const Value: array of Single); overload;
    { Set X3D field "offset". } { }
    procedure SetOffset(const Value: TSingleList); overload;

    strict private FFdOffsetUnits: TMFString;
    { X3D field "offsetUnits". } { }
    public property FdOffsetUnits: TMFString read FFdOffsetUnits;
    { Set X3D field "offsetUnits". } { }
    procedure SetOffsetUnits(const Value: array of string); overload;
    { Set X3D field "offsetUnits". } { }
    procedure SetOffsetUnits(const Value: TCastleStringList); overload;

    strict private FFdScaleMode: TMFString;
    { X3D field "scaleMode". } { }
    public property FdScaleMode: TMFString read FFdScaleMode;
    { Set X3D field "scaleMode". } { }
    procedure SetScaleMode(const Value: array of string); overload;
    { Set X3D field "scaleMode". } { }
    procedure SetScaleMode(const Value: TCastleStringList); overload;

    strict private FFdSize: TMFFloat;
    { X3D field "size". } { }
    public property FdSize: TMFFloat read FFdSize;
    { Set X3D field "size". } { }
    procedure SetSize(const Value: array of Single); overload;
    { Set X3D field "size". } { }
    procedure SetSize(const Value: TSingleList); overload;

    strict private FFdSizeUnits: TMFString;
    { X3D field "sizeUnits". } { }
    public property FdSizeUnits: TMFString read FFdSizeUnits;
    { Set X3D field "sizeUnits". } { }
    procedure SetSizeUnits(const Value: array of string); overload;
    { Set X3D field "sizeUnits". } { }
    procedure SetSizeUnits(const Value: TCastleStringList); overload;

{$endif read_interface}

{$ifdef read_implementation}

{ TLayoutNode ----------------------------------------------- }

procedure TLayoutNode.SetAlign(const Value: array of string);
begin
  FdAlign.Send(Value);
end;

procedure TLayoutNode.SetAlign(const Value: TCastleStringList);
begin
  FdAlign.Send(Value);
end;

procedure TLayoutNode.SetOffset(const Value: array of Single);
begin
  FdOffset.Send(Value);
end;

procedure TLayoutNode.SetOffset(const Value: TSingleList);
begin
  FdOffset.Send(Value);
end;

procedure TLayoutNode.SetOffsetUnits(const Value: array of string);
begin
  FdOffsetUnits.Send(Value);
end;

procedure TLayoutNode.SetOffsetUnits(const Value: TCastleStringList);
begin
  FdOffsetUnits.Send(Value);
end;

procedure TLayoutNode.SetScaleMode(const Value: array of string);
begin
  FdScaleMode.Send(Value);
end;

procedure TLayoutNode.SetScaleMode(const Value: TCastleStringList);
begin
  FdScaleMode.Send(Value);
end;

procedure TLayoutNode.SetSize(const Value: array of Single);
begin
  FdSize.Send(Value);
end;

procedure TLayoutNode.SetSize(const Value: TSingleList);
begin
  FdSize.Send(Value);
end;

procedure TLayoutNode.SetSizeUnits(const Value: array of string);
begin
  FdSizeUnits.Send(Value);
end;

procedure TLayoutNode.SetSizeUnits(const Value: TCastleStringList);
begin
  FdSizeUnits.Send(Value);
end;

class function TLayoutNode.ClassX3DType: String;
begin
  Result := 'Layout';
end;

procedure TLayoutNode.CreateNode;
begin
  inherited;

  FFdAlign := TMFString.Create(Self, True, 'align', ['CENTER','CENTER']);
   FdAlign.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdAlign);

  FFdOffset := TMFFloat.Create(Self, True, 'offset', [0,0]);
   FdOffset.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdOffset);

  FFdOffsetUnits := TMFString.Create(Self, True, 'offsetUnits', ['WORLD','WORLD']);
   FdOffsetUnits.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdOffsetUnits);

  FFdScaleMode := TMFString.Create(Self, True, 'scaleMode', ['NONE','NONE']);
   FdScaleMode.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdScaleMode);

  FFdSize := TMFFloat.Create(Self, True, 'size', [1,1]);
   FdSize.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdSize);

  FFdSizeUnits := TMFString.Create(Self, True, 'sizeUnits', ['WORLD','WORLD']);
   FdSizeUnits.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdSizeUnits);
end;

{$endif read_implementation}
