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
    function GetTessellation: Integer;
    procedure SetTessellation(const Value: Integer);
    function GetClosed: Boolean;
    procedure SetClosed(const Value: Boolean);
    function GetOrder: Integer;
    procedure SetOrder(const Value: Integer);
  public
    procedure CreateNode; override;
    class function ClassX3DType: string; override;

    strict private FFdTessellation: TSFInt32;
    { X3D field "tessellation". } { }
    public property FdTessellation: TSFInt32 read FFdTessellation;
    { X3D field "tessellation". } { }
    property Tessellation: Integer read GetTessellation write SetTessellation;

    strict private FFdWeight: TMFDouble;
    { X3D field "weight". } { }
    public property FdWeight: TMFDouble read FFdWeight;
    { Set X3D field "weight". } { }
    procedure SetWeight(const Value: array of Double); overload;
    { Set X3D field "weight". } { }
    procedure SetWeight(const Value: TDoubleList); overload;

    strict private FFdClosed: TSFBool;
    { X3D field "closed". } { }
    public property FdClosed: TSFBool read FFdClosed;
    { X3D field "closed". } { }
    property Closed: Boolean read GetClosed write SetClosed;

    strict private FFdKnot: TMFDouble;
    { X3D field "knot". } { }
    public property FdKnot: TMFDouble read FFdKnot;
    { Set X3D field "knot". } { }
    procedure SetKnot(const Value: array of Double); overload;
    { Set X3D field "knot". } { }
    procedure SetKnot(const Value: TDoubleList); overload;

    strict private FFdOrder: TSFInt32;
    { X3D field "order". } { }
    public property FdOrder: TSFInt32 read FFdOrder;
    { X3D field "order". } { }
    property Order: Integer read GetOrder write SetOrder;

{$endif read_interface}

{$ifdef read_implementation}

{ TNurbsCurve2DNode ----------------------------------------------- }

function TNurbsCurve2DNode.GetTessellation: Integer;
begin
  Result := FdTessellation.Value;
end;

procedure TNurbsCurve2DNode.SetTessellation(const Value: Integer);
begin
  FdTessellation.Send(Value);
end;

procedure TNurbsCurve2DNode.SetWeight(const Value: array of Double);
begin
  FdWeight.Send(Value);
end;

procedure TNurbsCurve2DNode.SetWeight(const Value: TDoubleList);
begin
  FdWeight.Send(Value);
end;

function TNurbsCurve2DNode.GetClosed: Boolean;
begin
  Result := FdClosed.Value;
end;

procedure TNurbsCurve2DNode.SetClosed(const Value: Boolean);
begin
  FdClosed.Send(Value);
end;

procedure TNurbsCurve2DNode.SetKnot(const Value: array of Double);
begin
  FdKnot.Send(Value);
end;

procedure TNurbsCurve2DNode.SetKnot(const Value: TDoubleList);
begin
  FdKnot.Send(Value);
end;

function TNurbsCurve2DNode.GetOrder: Integer;
begin
  Result := FdOrder.Value;
end;

procedure TNurbsCurve2DNode.SetOrder(const Value: Integer);
begin
  FdOrder.Send(Value);
end;

class function TNurbsCurve2DNode.ClassX3DType: String;
begin
  Result := 'NurbsCurve2D';
end;

procedure TNurbsCurve2DNode.CreateNode;
begin
  inherited;

  FFdTessellation := TSFInt32.Create(Self, True, 'tessellation', 0);
   FdTessellation.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdTessellation);

  FFdWeight := TMFDouble.Create(Self, True, 'weight', []);
   FdWeight.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdWeight);

  FFdClosed := TSFBool.Create(Self, False, 'closed', false);
   FdClosed.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdClosed);

  FFdKnot := TMFDouble.Create(Self, False, 'knot', []);
   FdKnot.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdKnot);

  FFdOrder := TSFInt32.Create(Self, False, 'order', 3);
   FdOrder.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdOrder);
end;

{$endif read_implementation}
