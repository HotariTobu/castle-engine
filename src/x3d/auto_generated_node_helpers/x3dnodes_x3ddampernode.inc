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
    function GetTau: TFloatTime;
    procedure SetTau(const Value: TFloatTime);
    function GetTolerance: Single;
    procedure SetTolerance(const Value: Single);
    function GetOrder: Integer;
    procedure SetOrder(const Value: Integer);
  public
    procedure CreateNode; override;
    class function ClassX3DType: string; override;

    strict private FFdTau: TSFTime;
    { X3D field "tau". } { }
    public property FdTau: TSFTime read FFdTau;
    { X3D field "tau". } { }
    property Tau: TFloatTime read GetTau write SetTau;

    strict private FFdTolerance: TSFFloat;
    { X3D field "tolerance". } { }
    public property FdTolerance: TSFFloat read FFdTolerance;
    { X3D field "tolerance". } { }
    property Tolerance: Single read GetTolerance write SetTolerance;

    strict private FFdOrder: TSFInt32;
    { X3D field "order". } { }
    public property FdOrder: TSFInt32 read FFdOrder;
    { X3D field "order". } { }
    property Order: Integer read GetOrder write SetOrder;

{$endif read_interface}

{$ifdef read_implementation}

{ TAbstractDamperNode ----------------------------------------------- }

function TAbstractDamperNode.GetTau: TFloatTime;
begin
  Result := FdTau.Value;
end;

procedure TAbstractDamperNode.SetTau(const Value: TFloatTime);
begin
  FdTau.Send(Value);
end;

function TAbstractDamperNode.GetTolerance: Single;
begin
  Result := FdTolerance.Value;
end;

procedure TAbstractDamperNode.SetTolerance(const Value: Single);
begin
  FdTolerance.Send(Value);
end;

function TAbstractDamperNode.GetOrder: Integer;
begin
  Result := FdOrder.Value;
end;

procedure TAbstractDamperNode.SetOrder(const Value: Integer);
begin
  FdOrder.Send(Value);
end;

class function TAbstractDamperNode.ClassX3DType: String;
begin
  Result := 'X3DDamperNode';
end;

procedure TAbstractDamperNode.CreateNode;
begin
  inherited;

  FFdTau := TSFTime.Create(Self, True, 'tau', 0);
   FdTau.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdTau);

  FFdTolerance := TSFFloat.Create(Self, True, 'tolerance', -1);
   FdTolerance.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdTolerance);

  FFdOrder := TSFInt32.Create(Self, False, 'order', 0);
   FdOrder.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdOrder);
end;

{$endif read_implementation}
