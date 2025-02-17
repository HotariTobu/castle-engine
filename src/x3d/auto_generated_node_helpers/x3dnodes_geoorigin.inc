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
    function GetGeoCoords: TVector3Double;
    procedure SetGeoCoords(const Value: TVector3Double);
    function GetRotateYUp: Boolean;
    procedure SetRotateYUp(const Value: Boolean);
  public
    procedure CreateNode; override;
    class function ClassX3DType: string; override;

    strict private FFdGeoCoords: TSFVec3d;
    { X3D field "geoCoords". } { }
    public property FdGeoCoords: TSFVec3d read FFdGeoCoords;
    { X3D field "geoCoords". } { }
    property GeoCoords: TVector3Double read GetGeoCoords write SetGeoCoords;

    strict private FFdGeoSystem: TMFString;
    { X3D field "geoSystem". } { }
    public property FdGeoSystem: TMFString read FFdGeoSystem;
    { Set X3D field "geoSystem". } { }
    procedure SetGeoSystem(const Value: array of string); overload;
    { Set X3D field "geoSystem". } { }
    procedure SetGeoSystem(const Value: TCastleStringList); overload;

    strict private FFdRotateYUp: TSFBool;
    { X3D field "rotateYUp". } { }
    public property FdRotateYUp: TSFBool read FFdRotateYUp;
    { X3D field "rotateYUp". } { }
    property RotateYUp: Boolean read GetRotateYUp write SetRotateYUp;

{$endif read_interface}

{$ifdef read_implementation}

{ TGeoOriginNode ----------------------------------------------- }

function TGeoOriginNode.GetGeoCoords: TVector3Double;
begin
  Result := FdGeoCoords.Value;
end;

procedure TGeoOriginNode.SetGeoCoords(const Value: TVector3Double);
begin
  FdGeoCoords.Send(Value);
end;

procedure TGeoOriginNode.SetGeoSystem(const Value: array of string);
begin
  FdGeoSystem.Send(Value);
end;

procedure TGeoOriginNode.SetGeoSystem(const Value: TCastleStringList);
begin
  FdGeoSystem.Send(Value);
end;

function TGeoOriginNode.GetRotateYUp: Boolean;
begin
  Result := FdRotateYUp.Value;
end;

procedure TGeoOriginNode.SetRotateYUp(const Value: Boolean);
begin
  FdRotateYUp.Send(Value);
end;

class function TGeoOriginNode.ClassX3DType: String;
begin
  Result := 'GeoOrigin';
end;

procedure TGeoOriginNode.CreateNode;
begin
  inherited;

  FFdGeoCoords := TSFVec3d.Create(Self, True, 'geoCoords', Vector3Double(0, 0, 0));
   FdGeoCoords.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdGeoCoords);

  FFdGeoSystem := TMFString.Create(Self, False, 'geoSystem', ['GD','WE']);
   FdGeoSystem.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdGeoSystem);

  FFdRotateYUp := TSFBool.Create(Self, False, 'rotateYUp', false);
   FdRotateYUp.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdRotateYUp);

  DefaultContainerField := 'geoOrigin';
end;

{$endif read_implementation}
