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
    function GetColor: TCastleColorRGB;
    procedure SetColor(const Value: TCastleColorRGB);
    function GetFogType: TFogType;
    procedure SetFogType(const Value: TFogType);
    function GetVisibilityRange: Single;
    procedure SetVisibilityRange(const Value: Single);
    function GetVolumetric: Boolean;
    procedure SetVolumetric(const Value: Boolean);
    function GetVolumetricDirection: TVector3;
    procedure SetVolumetricDirection(const Value: TVector3);
    function GetVolumetricVisibilityStart: Single;
    procedure SetVolumetricVisibilityStart(const Value: Single);
  public
    procedure CreateNode; override;
    class function ClassX3DType: string; override;

    strict private FFdColor: TSFColor;
    { X3D field "color". } { }
    public property FdColor: TSFColor read FFdColor;
    { X3D field "color". } { }
    property Color: TCastleColorRGB read GetColor write SetColor;

    strict private FFdFogType: TSFStringEnum;
    { X3D field "fogType". } { }
    public property FdFogType: TSFStringEnum read FFdFogType;
    { X3D field "fogType". } { }
    property FogType: TFogType read GetFogType write SetFogType;

    strict private FFdVisibilityRange: TSFFloat;
    { X3D field "visibilityRange". } { }
    public property FdVisibilityRange: TSFFloat read FFdVisibilityRange;
    { X3D field "visibilityRange". } { }
    property VisibilityRange: Single read GetVisibilityRange write SetVisibilityRange;

    strict private FFdVolumetric: TSFBool;
    { X3D field "volumetric". } { }
    public property FdVolumetric: TSFBool read FFdVolumetric;
    { X3D field "volumetric". } { }
    property Volumetric: Boolean read GetVolumetric write SetVolumetric;

    strict private FFdVolumetricDirection: TSFVec3f;
    { X3D field "volumetricDirection". } { }
    public property FdVolumetricDirection: TSFVec3f read FFdVolumetricDirection;
    { X3D field "volumetricDirection". } { }
    property VolumetricDirection: TVector3 read GetVolumetricDirection write SetVolumetricDirection;

    strict private FFdVolumetricVisibilityStart: TSFFloat;
    { X3D field "volumetricVisibilityStart". } { }
    public property FdVolumetricVisibilityStart: TSFFloat read FFdVolumetricVisibilityStart;
    { X3D field "volumetricVisibilityStart". } { }
    property VolumetricVisibilityStart: Single read GetVolumetricVisibilityStart write SetVolumetricVisibilityStart;

{$endif read_interface}

{$ifdef read_implementation}

{ TFogNode ----------------------------------------------- }

function TFogNode.GetColor: TCastleColorRGB;
begin
  Result := FdColor.Value;
end;

procedure TFogNode.SetColor(const Value: TCastleColorRGB);
begin
  FdColor.Send(Value);
end;

function TFogNode.GetFogType: TFogType;
begin
  Result := TFogType(FdFogType.EnumValue);
end;

procedure TFogNode.SetFogType(const Value: TFogType);
begin
  FdFogType.SendEnumValue(Ord(Value));
end;

function TFogNode.GetVisibilityRange: Single;
begin
  Result := FdVisibilityRange.Value;
end;

procedure TFogNode.SetVisibilityRange(const Value: Single);
begin
  FdVisibilityRange.Send(Value);
end;

function TFogNode.GetVolumetric: Boolean;
begin
  Result := FdVolumetric.Value;
end;

procedure TFogNode.SetVolumetric(const Value: Boolean);
begin
  FdVolumetric.Send(Value);
end;

function TFogNode.GetVolumetricDirection: TVector3;
begin
  Result := FdVolumetricDirection.Value;
end;

procedure TFogNode.SetVolumetricDirection(const Value: TVector3);
begin
  FdVolumetricDirection.Send(Value);
end;

function TFogNode.GetVolumetricVisibilityStart: Single;
begin
  Result := FdVolumetricVisibilityStart.Value;
end;

procedure TFogNode.SetVolumetricVisibilityStart(const Value: Single);
begin
  FdVolumetricVisibilityStart.Send(Value);
end;

class function TFogNode.ClassX3DType: String;
begin
  Result := 'Fog';
end;

procedure TFogNode.CreateNode;
begin
  inherited;

  FFdColor := TSFColor.Create(Self, True, 'color', Vector3(1, 1, 1));
   FdColor.ChangeAlways := chRedisplay;
  AddField(FFdColor);

  FFdFogType := TSFStringEnum.Create(Self, True, 'fogType', FogTypeNames, Ord(ftLinear));
   FdFogType.ChangeAlways := chRedisplay;
  AddField(FFdFogType);

  FFdVisibilityRange := TSFFloat.Create(Self, True, 'visibilityRange', 0);
   FdVisibilityRange.ChangeAlways := chRedisplay;
  AddField(FFdVisibilityRange);

  FFdVolumetric := TSFBool.Create(Self, True, 'volumetric', false);
   FdVolumetric.ChangeAlways := chRedisplay;
  AddField(FFdVolumetric);

  FFdVolumetricDirection := TSFVec3f.Create(Self, True, 'volumetricDirection', Vector3(0, -1, 0));
   FdVolumetricDirection.ChangeAlways := chRedisplay;
  AddField(FFdVolumetricDirection);

  FFdVolumetricVisibilityStart := TSFFloat.Create(Self, True, 'volumetricVisibilityStart', 0);
   FdVolumetricVisibilityStart.ChangeAlways := chRedisplay;
  AddField(FFdVolumetricVisibilityStart);
end;

{$endif read_implementation}
