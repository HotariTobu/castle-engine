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
    function GetCoord: TAbstractCoordinateNode;
    procedure SetCoord(const Value: TAbstractCoordinateNode);
    function GetDirection: TVector3;
    procedure SetDirection(const Value: TVector3);
  public
    procedure CreateNode; override;
    class function ClassX3DType: string; override;

    strict private FEventSet_coordIndex: TMFInt32Event;
    { X3D in event "set_coordIndex". } { }
    public property EventSet_coordIndex: TMFInt32Event read FEventSet_coordIndex;

    strict private FFdCoord: TSFNode;
    { X3D field "coord". } { }
    public property FdCoord: TSFNode read FFdCoord;
    { X3D field "coord". } { }
    property Coord: TAbstractCoordinateNode read GetCoord write SetCoord;

    strict private FFdDirection: TSFVec3f;
    { X3D field "direction". } { }
    public property FdDirection: TSFVec3f read FFdDirection;
    { X3D field "direction". } { }
    property Direction: TVector3 read GetDirection write SetDirection;

    strict private FFdCoordIndex: TMFInt32;
    { X3D field "coordIndex". } { }
    public property FdCoordIndex: TMFInt32 read FFdCoordIndex;
    { Set X3D field "coordIndex". } { }
    procedure SetCoordIndex(const Value: array of LongInt); overload;
    { Set X3D field "coordIndex". } { }
    procedure SetCoordIndex(const Value: TLongIntList); overload;

{$endif read_interface}

{$ifdef read_implementation}

{ TPolylineEmitterNode ----------------------------------------------- }

function TPolylineEmitterNode.GetCoord: TAbstractCoordinateNode;
begin
  if FdCoord.Value is TAbstractCoordinateNode then
    Result := TAbstractCoordinateNode(FdCoord.Value)
  else
    Result := nil;
end;

procedure TPolylineEmitterNode.SetCoord(const Value: TAbstractCoordinateNode);
begin
  FdCoord.Send(Value);
end;

function TPolylineEmitterNode.GetDirection: TVector3;
begin
  Result := FdDirection.Value;
end;

procedure TPolylineEmitterNode.SetDirection(const Value: TVector3);
begin
  FdDirection.Send(Value);
end;

procedure TPolylineEmitterNode.SetCoordIndex(const Value: array of LongInt);
begin
  FdCoordIndex.Send(Value);
end;

procedure TPolylineEmitterNode.SetCoordIndex(const Value: TLongIntList);
begin
  FdCoordIndex.Send(Value);
end;

class function TPolylineEmitterNode.ClassX3DType: String;
begin
  Result := 'PolylineEmitter';
end;

procedure TPolylineEmitterNode.CreateNode;
begin
  inherited;

  FEventSet_coordIndex := TMFInt32Event.Create(Self, 'set_coordIndex', true);
  AddEvent(FEventSet_coordIndex);

  FFdCoord := TSFNode.Create(Self, True, 'coord', [TAbstractCoordinateNode]);
   FdCoord.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdCoord);

  FFdDirection := TSFVec3f.Create(Self, True, 'direction', Vector3(0, 1, 0));
   FdDirection.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdDirection);

  FFdCoordIndex := TMFInt32.Create(Self, False, 'coordIndex', [-1]);
   FdCoordIndex.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdCoordIndex);
end;

{$endif read_implementation}
