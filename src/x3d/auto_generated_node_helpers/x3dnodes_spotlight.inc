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
    function GetBeamWidth: Single;
    procedure SetBeamWidth(const Value: Single);
    function GetCutOffAngle: Single;
    procedure SetCutOffAngle(const Value: Single);
    function GetDirection: TVector3;
    procedure SetDirection(const Value: TVector3);
    function GetProjectionAngle: Single;
    procedure SetProjectionAngle(const Value: Single);
  public
    procedure CreateNode; override;
    class function ClassX3DType: string; override;

    strict private FFdBeamWidth: TSFFloat;
    { X3D field "beamWidth". } { }
    public property FdBeamWidth: TSFFloat read FFdBeamWidth;
    { X3D field "beamWidth". } { }
    property BeamWidth: Single read GetBeamWidth write SetBeamWidth;

    strict private FFdCutOffAngle: TSFFloat;
    { X3D field "cutOffAngle". } { }
    public property FdCutOffAngle: TSFFloat read FFdCutOffAngle;
    { X3D field "cutOffAngle". } { }
    property CutOffAngle: Single read GetCutOffAngle write SetCutOffAngle;

    strict private FFdDirection: TSFVec3f;
    { X3D field "direction". } { }
    public property FdDirection: TSFVec3f read FFdDirection;
    { X3D field "direction". } { }
    property Direction: TVector3 read GetDirection write SetDirection;

    strict private FFdProjectionAngle: TSFFloat;
    { X3D field "projectionAngle". } { }
    public property FdProjectionAngle: TSFFloat read FFdProjectionAngle;
    { X3D field "projectionAngle". } { }
    property ProjectionAngle: Single read GetProjectionAngle write SetProjectionAngle;

{$endif read_interface}

{$ifdef read_implementation}

{ TSpotLightNode ----------------------------------------------- }

function TSpotLightNode.GetBeamWidth: Single;
begin
  Result := FdBeamWidth.Value;
end;

procedure TSpotLightNode.SetBeamWidth(const Value: Single);
begin
  FdBeamWidth.Send(Value);
end;

function TSpotLightNode.GetCutOffAngle: Single;
begin
  Result := FdCutOffAngle.Value;
end;

procedure TSpotLightNode.SetCutOffAngle(const Value: Single);
begin
  FdCutOffAngle.Send(Value);
end;

function TSpotLightNode.GetDirection: TVector3;
begin
  Result := FdDirection.Value;
end;

procedure TSpotLightNode.SetDirection(const Value: TVector3);
begin
  FdDirection.Send(Value);
end;

function TSpotLightNode.GetProjectionAngle: Single;
begin
  Result := FdProjectionAngle.Value;
end;

procedure TSpotLightNode.SetProjectionAngle(const Value: Single);
begin
  FdProjectionAngle.Send(Value);
end;

class function TSpotLightNode.ClassX3DType: String;
begin
  Result := 'SpotLight';
end;

procedure TSpotLightNode.CreateNode;
begin
  inherited;

  FFdBeamWidth := TSFFloat.Create(Self, True, 'beamWidth', Pi/2);
   FdBeamWidth.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdBeamWidth);

  FFdCutOffAngle := TSFFloat.Create(Self, True, 'cutOffAngle', Pi/4);
   FdCutOffAngle.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdCutOffAngle);

  FFdDirection := TSFVec3f.Create(Self, True, 'direction', Vector3(0, 0, -1));
   FdDirection.ChangeAlways := chLightLocationDirection;
  AddField(FFdDirection);

  FFdProjectionAngle := TSFFloat.Create(Self, True, 'projectionAngle', 0);
   FdProjectionAngle.ChangeAlways := chVisibleGeometry;
   FdProjectionAngle.Angle := true;
  AddField(FFdProjectionAngle);
end;

{$endif read_implementation}
