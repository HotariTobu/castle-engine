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

{$ifdef read_interface}

type
  { Plane with configurable size, position and material. }
  TCastlePlane = class(TCastleAbstractPrimitive)
  strict private
    FQuadSetNode: TQuadSetNode;
    FCoordinateNode: TCoordinateNode;
    FSize: TVector2;
    FAxis: T3DAxis;
    FDoubleSided: Boolean;
    procedure SetSize(const Value: TVector2);
    procedure SetAxis(const Value: T3DAxis);
    { Update FCoordinateNode based on FSize, FAxis }
    procedure UpdateCoordinateNode;
    procedure SetDoubleSided(const Value: Boolean);
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    function PropertySections(const PropertyName: String): TPropertySections; override;

    { Size of the plane in XZ plane. By default (2, 2). }
    property Size: TVector2 read FSize write SetSize;
  published
    { Axis where the plane is constant.
      That is:

      @unorderedList(
        @item Axis = 0 means the plane is in YZ (at constant X = 0).
        @item Axis = 1 means the plane is in XZ (at constant Y = 0). In particular useful for floors in 3D games.
        @item Axis = 2 means the plane is in XY (at constant Z = 0). In particular useful for rectangles in 2D games.
      )
    }
    property Axis: T3DAxis read FAxis write SetAxis default 1;

    { When this is @true, the object is visible (and lit) from both sides. }
    property DoubleSided: Boolean read FDoubleSided write SetDoubleSided default false;

  {$define read_interface_class}
  {$I auto_generated_persistent_vectors/tcastleplane_persistent_vectors.inc}
  {$undef read_interface_class}
  end;

{$endif read_interface}

{$ifdef read_implementation}

{ TCastlePlane ---------------------------------------------------------------- }

constructor TCastlePlane.Create(AOwner: TComponent);
begin
  inherited;

  { default properties values }
  FSize := Vector2(2, 2);
  FAxis := 1;

  FCoordinateNode := TCoordinateNode.Create;
  UpdateCoordinateNode;

  FQuadSetNode := TQuadSetNode.Create;
  FQuadSetNode.Coord := FCoordinateNode;
  ShapeNode.Geometry := FQuadSetNode;

  {$define read_implementation_constructor}
  {$I auto_generated_persistent_vectors/tcastleplane_persistent_vectors.inc}
  {$undef read_implementation_constructor}
end;

destructor TCastlePlane.Destroy;
begin
  {$define read_implementation_destructor}
  {$I auto_generated_persistent_vectors/tcastleplane_persistent_vectors.inc}
  {$undef read_implementation_destructor}

  inherited;
end;

procedure TCastlePlane.UpdateCoordinateNode;
var
  V: array [0..3] of TVector2;
  V3D: array [0..3] of TVector3;
  I: Integer;
  C1, C2: T3DAxis;
begin
  V[0] := Vector2(-FSize.X, -FSize.Y);
  V[1] := Vector2( FSize.X, -FSize.Y);
  V[2] := Vector2( FSize.X,  FSize.Y);
  V[3] := Vector2(-FSize.X,  FSize.Y);

  RestOf3DCoordsCycle(FAxis, C1, C2);
  for I := Low(V) to High(V) do
  begin
    V3D[I].Data[FAxis] := 0;
    V3D[I].Data[C1] := V[I].Data[0];
    V3D[I].Data[C2] := V[I].Data[1];
  end;

  FCoordinateNode.SetPoint(V3D);
end;

function TCastlePlane.PropertySections(const PropertyName: String): TPropertySections;
begin
  if (PropertyName = 'SizePersistent') or
     (PropertyName = 'Axis') or
     (PropertyName = 'DoubleSided') then
    Result := [psBasic]
  else
    Result := inherited PropertySections(PropertyName);
end;

procedure TCastlePlane.SetSize(const Value: TVector2);
begin
  if not TVector2.PerfectlyEquals(FSize, Value) then
  begin
    FSize := Value;
    UpdateCoordinateNode;
  end;
end;

procedure TCastlePlane.SetAxis(const Value: T3DAxis);
begin
  if FAxis <> Value then
  begin
    FAxis := Value;
    UpdateCoordinateNode;
  end;
end;

procedure TCastlePlane.SetDoubleSided(const Value: Boolean);
begin
  if FDoubleSided <> Value then
  begin
    FDoubleSided := Value;
    FQuadSetNode.Solid := not Value;
  end;
end;

{$define read_implementation_methods}
{$I auto_generated_persistent_vectors/tcastleplane_persistent_vectors.inc}
{$undef read_implementation_methods}

{$endif read_implementation}
