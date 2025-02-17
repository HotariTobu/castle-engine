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
    function GetColor: TAbstractColorNode;
    procedure SetColor(const Value: TAbstractColorNode);
    function GetCoord: TAbstractCoordinateNode;
    procedure SetCoord(const Value: TAbstractCoordinateNode);
{$ifndef CASTLE_SLIM_NODES}
    function GetFogCoord: TFogCoordinateNode;
    procedure SetFogCoord(const Value: TFogCoordinateNode);
{$endif not CASTLE_SLIM_NODES}
  public
    procedure CreateNode; override;
    class function ClassX3DType: string; override;

{$ifndef CASTLE_SLIM_NODES}
    strict private FFdAttrib: TMFNode;
    { X3D field "attrib". } { }
    public property FdAttrib: TMFNode read FFdAttrib;
{$endif not CASTLE_SLIM_NODES}
{$ifndef CASTLE_SLIM_NODES}
    { Set X3D field "attrib". } { }
    procedure SetAttrib(const Value: array of TAbstractVertexAttributeNode);
{$endif not CASTLE_SLIM_NODES}

    strict private FFdColor: TSFNode;
    { X3D field "color". } { }
    public property FdColor: TSFNode read FFdColor;
    { X3D field "color". } { }
    property Color: TAbstractColorNode read GetColor write SetColor;

    strict private FFdCoord: TSFNode;
    { X3D field "coord". } { }
    public property FdCoord: TSFNode read FFdCoord;
    { X3D field "coord". } { }
    property Coord: TAbstractCoordinateNode read GetCoord write SetCoord;

{$ifndef CASTLE_SLIM_NODES}
    strict private FFdFogCoord: TSFNode;
    { X3D field "fogCoord". } { }
    public property FdFogCoord: TSFNode read FFdFogCoord;
{$endif not CASTLE_SLIM_NODES}
{$ifndef CASTLE_SLIM_NODES}
    { X3D field "fogCoord". } { }
    property FogCoord: TFogCoordinateNode read GetFogCoord write SetFogCoord;
{$endif not CASTLE_SLIM_NODES}

    strict private FFdVertexCount: TMFInt32;
    { X3D field "vertexCount". } { }
    public property FdVertexCount: TMFInt32 read FFdVertexCount;
    { Set X3D field "vertexCount". } { }
    procedure SetVertexCount(const Value: array of LongInt); overload;
    { Set X3D field "vertexCount". } { }
    procedure SetVertexCount(const Value: TLongIntList); overload;

{$endif read_interface}

{$ifdef read_implementation}

{ TLineSetNode ----------------------------------------------- }

{$ifndef CASTLE_SLIM_NODES}
procedure TLineSetNode.SetAttrib(const Value: array of TAbstractVertexAttributeNode);
var
  L: Integer;
  A: array of TX3DNode;
begin
  L := High(Value) + 1;
  SetLength(A, L);
  if L > 0 then
    Move(Value[0], A[0], L * SizeOf(TAbstractVertexAttributeNode));
  FdAttrib.Send(A);
end;

{$endif not CASTLE_SLIM_NODES}
function TLineSetNode.GetColor: TAbstractColorNode;
begin
  if FdColor.Value is TAbstractColorNode then
    Result := TAbstractColorNode(FdColor.Value)
  else
    Result := nil;
end;

procedure TLineSetNode.SetColor(const Value: TAbstractColorNode);
begin
  FdColor.Send(Value);
end;

function TLineSetNode.GetCoord: TAbstractCoordinateNode;
begin
  if FdCoord.Value is TAbstractCoordinateNode then
    Result := TAbstractCoordinateNode(FdCoord.Value)
  else
    Result := nil;
end;

procedure TLineSetNode.SetCoord(const Value: TAbstractCoordinateNode);
begin
  FdCoord.Send(Value);
end;

{$ifndef CASTLE_SLIM_NODES}
function TLineSetNode.GetFogCoord: TFogCoordinateNode;
begin
  if FdFogCoord.Value is TFogCoordinateNode then
    Result := TFogCoordinateNode(FdFogCoord.Value)
  else
    Result := nil;
end;

procedure TLineSetNode.SetFogCoord(const Value: TFogCoordinateNode);
begin
  FdFogCoord.Send(Value);
end;

{$endif not CASTLE_SLIM_NODES}
procedure TLineSetNode.SetVertexCount(const Value: array of LongInt);
begin
  FdVertexCount.Send(Value);
end;

procedure TLineSetNode.SetVertexCount(const Value: TLongIntList);
begin
  FdVertexCount.Send(Value);
end;

class function TLineSetNode.ClassX3DType: String;
begin
  Result := 'LineSet';
end;

procedure TLineSetNode.CreateNode;
begin
  inherited;

{$ifndef CASTLE_SLIM_NODES}
  FFdAttrib := TMFNode.Create(Self, True, 'attrib', [TAbstractVertexAttributeNode]);
   FdAttrib.ChangeAlways := chGeometry;
  AddField(FFdAttrib);
{$endif not CASTLE_SLIM_NODES}

  FFdColor := TSFNode.Create(Self, True, 'color', [TAbstractColorNode]);
   FdColor.ChangeAlways := chGeometry;
  AddField(FFdColor);

  FFdCoord := TSFNode.Create(Self, True, 'coord', [TAbstractCoordinateNode]);
   FdCoord.ChangeAlways := chGeometry;
  AddField(FFdCoord);

{$ifndef CASTLE_SLIM_NODES}
  FFdFogCoord := TSFNode.Create(Self, True, 'fogCoord', [TFogCoordinateNode]);
   FdFogCoord.ChangeAlways := chGeometry;
  AddField(FFdFogCoord);
{$endif not CASTLE_SLIM_NODES}

  FFdVertexCount := TMFInt32.Create(Self, True, 'vertexCount', []);
   FdVertexCount.ChangeAlways := chGeometry;
  AddField(FFdVertexCount);
end;

{$endif read_implementation}
