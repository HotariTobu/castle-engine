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
    function GetAlphaFactor: Single;
    procedure SetAlphaFactor(const Value: Single);
    function GetAlphaTextureId: Integer;
    procedure SetAlphaTextureId(const Value: Integer);
    function GetAlphaTextureCoordinatesId: Integer;
    procedure SetAlphaTextureCoordinatesId(const Value: Integer);
    function GetAlphaTextureChannelMask: String;
    procedure SetAlphaTextureChannelMask(const Value: String);
    function GetAlphaTexture: TAbstractTextureNode;
    procedure SetAlphaTexture(const Value: TAbstractTextureNode);
    function GetAmbientFactor: TVector3;
    procedure SetAmbientFactor(const Value: TVector3);
    function GetAmbientTextureId: Integer;
    procedure SetAmbientTextureId(const Value: Integer);
    function GetAmbientTextureCoordinatesId: Integer;
    procedure SetAmbientTextureCoordinatesId(const Value: Integer);
    function GetAmbientTextureChannelMask: String;
    procedure SetAmbientTextureChannelMask(const Value: String);
    function GetAmbientTexture: TAbstractTextureNode;
    procedure SetAmbientTexture(const Value: TAbstractTextureNode);
    function GetDiffuseFactor: TVector3;
    procedure SetDiffuseFactor(const Value: TVector3);
    function GetDiffuseTextureId: Integer;
    procedure SetDiffuseTextureId(const Value: Integer);
    function GetDiffuseTextureCoordinatesId: Integer;
    procedure SetDiffuseTextureCoordinatesId(const Value: Integer);
    function GetDiffuseTextureChannelMask: String;
    procedure SetDiffuseTextureChannelMask(const Value: String);
    function GetDiffuseTexture: TAbstractTextureNode;
    procedure SetDiffuseTexture(const Value: TAbstractTextureNode);
    function GetDiffuseDisplacementTexture: TAbstractTextureNode;
    procedure SetDiffuseDisplacementTexture(const Value: TAbstractTextureNode);
    function GetDisplacementAxis: String;
    procedure SetDisplacementAxis(const Value: String);
    function GetDisplacementFactor: Single;
    procedure SetDisplacementFactor(const Value: Single);
    function GetDisplacementTextureId: Integer;
    procedure SetDisplacementTextureId(const Value: Integer);
    function GetDisplacementTextureCoordinatesId: Integer;
    procedure SetDisplacementTextureCoordinatesId(const Value: Integer);
    function GetDisplacementTexture: TAbstractTextureNode;
    procedure SetDisplacementTexture(const Value: TAbstractTextureNode);
    function GetEmissiveFactor: TVector3;
    procedure SetEmissiveFactor(const Value: TVector3);
    function GetEmissiveTextureId: Integer;
    procedure SetEmissiveTextureId(const Value: Integer);
    function GetEmissiveTextureCoordinatesId: Integer;
    procedure SetEmissiveTextureCoordinatesId(const Value: Integer);
    function GetEmissiveTextureChannelMask: String;
    procedure SetEmissiveTextureChannelMask(const Value: String);
    function GetEmissiveTexture: TAbstractTextureNode;
    procedure SetEmissiveTexture(const Value: TAbstractTextureNode);
    function GetEnvironmentFactor: TVector3;
    procedure SetEnvironmentFactor(const Value: TVector3);
    function GetEnvironmentTextureId: Integer;
    procedure SetEnvironmentTextureId(const Value: Integer);
    function GetEnvironmentTextureCoordinatesId: Integer;
    procedure SetEnvironmentTextureCoordinatesId(const Value: Integer);
    function GetEnvironmentTextureChannelMask: String;
    procedure SetEnvironmentTextureChannelMask(const Value: String);
    function GetEnvironmentTexture: TAbstractEnvironmentTextureNode;
    procedure SetEnvironmentTexture(const Value: TAbstractEnvironmentTextureNode);
    function GetMultiDiffuseAlphaTexture: TAbstractTextureNode;
    procedure SetMultiDiffuseAlphaTexture(const Value: TAbstractTextureNode);
    function GetMultiEmmisiveAmbientIntensityTexture: TAbstractTextureNode;
    procedure SetMultiEmmisiveAmbientIntensityTexture(const Value: TAbstractTextureNode);
    function GetMultiSpecularShininessTexture: TAbstractTextureNode;
    procedure SetMultiSpecularShininessTexture(const Value: TAbstractTextureNode);
    function GetMultiVisibilityTexture: TAbstractTextureNode;
    procedure SetMultiVisibilityTexture(const Value: TAbstractTextureNode);
    function GetNormalTextureId: Integer;
    procedure SetNormalTextureId(const Value: Integer);
    function GetNormalTextureCoordinatesId: Integer;
    procedure SetNormalTextureCoordinatesId(const Value: Integer);
    function GetNormalTextureChannelMask: String;
    procedure SetNormalTextureChannelMask(const Value: String);
    function GetNormalScale: TVector3;
    procedure SetNormalScale(const Value: TVector3);
    function GetNormalBias: TVector3;
    procedure SetNormalBias(const Value: TVector3);
    function GetNormalTexture: TAbstractTextureNode;
    procedure SetNormalTexture(const Value: TAbstractTextureNode);
    function GetNormalTextureParallaxHeight: Single;
    procedure SetNormalTextureParallaxHeight(const Value: Single);
    function GetReflectionFactor: TVector3;
    procedure SetReflectionFactor(const Value: TVector3);
    function GetReflectionTextureId: Integer;
    procedure SetReflectionTextureId(const Value: Integer);
    function GetReflectionTextureCoordinatesId: Integer;
    procedure SetReflectionTextureCoordinatesId(const Value: Integer);
    function GetReflectionTextureChannelMask: String;
    procedure SetReflectionTextureChannelMask(const Value: String);
    function GetReflectionTexture: TAbstractTextureNode;
    procedure SetReflectionTexture(const Value: TAbstractTextureNode);
    function GetShininessFactor: Single;
    procedure SetShininessFactor(const Value: Single);
    function GetShininessTextureId: Integer;
    procedure SetShininessTextureId(const Value: Integer);
    function GetShininessTextureCoordinatesId: Integer;
    procedure SetShininessTextureCoordinatesId(const Value: Integer);
    function GetShininessTextureChannelMask: String;
    procedure SetShininessTextureChannelMask(const Value: String);
    function GetShininessTexture: TAbstractTextureNode;
    procedure SetShininessTexture(const Value: TAbstractTextureNode);
    function GetSpecularFactor: TVector3;
    procedure SetSpecularFactor(const Value: TVector3);
    function GetSpecularTextureId: Integer;
    procedure SetSpecularTextureId(const Value: Integer);
    function GetSpecularTextureCoordinatesId: Integer;
    procedure SetSpecularTextureCoordinatesId(const Value: Integer);
    function GetSpecularTextureChannelMask: String;
    procedure SetSpecularTextureChannelMask(const Value: String);
    function GetSpecularTexture: TAbstractTextureNode;
    procedure SetSpecularTexture(const Value: TAbstractTextureNode);
    function GetTransmissionFactor: TVector3;
    procedure SetTransmissionFactor(const Value: TVector3);
    function GetTransmissionTextureId: Integer;
    procedure SetTransmissionTextureId(const Value: Integer);
    function GetTransmissionTextureCoordinatesId: Integer;
    procedure SetTransmissionTextureCoordinatesId(const Value: Integer);
    function GetTransmissionTextureChannelMask: String;
    procedure SetTransmissionTextureChannelMask(const Value: String);
    function GetTransmissionTexture: TAbstractTextureNode;
    procedure SetTransmissionTexture(const Value: TAbstractTextureNode);
    function GetTangentTextureCoordinatesId: Integer;
    procedure SetTangentTextureCoordinatesId(const Value: Integer);
    function GetBinormalTextureCoordinatesId: Integer;
    procedure SetBinormalTextureCoordinatesId(const Value: Integer);
    function GetInvertAlphaTexture: Boolean;
    procedure SetInvertAlphaTexture(const Value: Boolean);
    function GetRelativeIndexOfRefraction: Single;
    procedure SetRelativeIndexOfRefraction(const Value: Single);
    function GetFresnelBlend: Single;
    procedure SetFresnelBlend(const Value: Single);
  public
    { X3D field "alphaFactor". } { }
    property AlphaFactor: Single read GetAlphaFactor write SetAlphaFactor;
    { X3D field "alphaTextureId". } { }
    property AlphaTextureId: Integer read GetAlphaTextureId write SetAlphaTextureId;
    { X3D field "alphaTextureCoordinatesId". } { }
    property AlphaTextureCoordinatesId: Integer read GetAlphaTextureCoordinatesId write SetAlphaTextureCoordinatesId;
    { X3D field "alphaTextureChannelMask". } { }
    property AlphaTextureChannelMask: String read GetAlphaTextureChannelMask write SetAlphaTextureChannelMask;
    { X3D field "alphaTexture". } { }
    property AlphaTexture: TAbstractTextureNode read GetAlphaTexture write SetAlphaTexture;
    { X3D field "ambientFactor". } { }
    property AmbientFactor: TVector3 read GetAmbientFactor write SetAmbientFactor;
    { X3D field "ambientTextureId". } { }
    property AmbientTextureId: Integer read GetAmbientTextureId write SetAmbientTextureId;
    { X3D field "ambientTextureCoordinatesId". } { }
    property AmbientTextureCoordinatesId: Integer read GetAmbientTextureCoordinatesId write SetAmbientTextureCoordinatesId;
    { X3D field "ambientTextureChannelMask". } { }
    property AmbientTextureChannelMask: String read GetAmbientTextureChannelMask write SetAmbientTextureChannelMask;
    { X3D field "ambientTexture". } { }
    property AmbientTexture: TAbstractTextureNode read GetAmbientTexture write SetAmbientTexture;
    { X3D field "diffuseFactor". } { }
    property DiffuseFactor: TVector3 read GetDiffuseFactor write SetDiffuseFactor;
    { X3D field "diffuseTextureId". } { }
    property DiffuseTextureId: Integer read GetDiffuseTextureId write SetDiffuseTextureId;
    { X3D field "diffuseTextureCoordinatesId". } { }
    property DiffuseTextureCoordinatesId: Integer read GetDiffuseTextureCoordinatesId write SetDiffuseTextureCoordinatesId;
    { X3D field "diffuseTextureChannelMask". } { }
    property DiffuseTextureChannelMask: String read GetDiffuseTextureChannelMask write SetDiffuseTextureChannelMask;
    { X3D field "diffuseTexture". } { }
    property DiffuseTexture: TAbstractTextureNode read GetDiffuseTexture write SetDiffuseTexture;
    { X3D field "diffuseDisplacementTexture". } { }
    property DiffuseDisplacementTexture: TAbstractTextureNode read GetDiffuseDisplacementTexture write SetDiffuseDisplacementTexture;
    { X3D field "displacementAxis". } { }
    property DisplacementAxis: String read GetDisplacementAxis write SetDisplacementAxis;
    { X3D field "displacementFactor". } { }
    property DisplacementFactor: Single read GetDisplacementFactor write SetDisplacementFactor;
    { X3D field "displacementTextureId". } { }
    property DisplacementTextureId: Integer read GetDisplacementTextureId write SetDisplacementTextureId;
    { X3D field "displacementTextureCoordinatesId". } { }
    property DisplacementTextureCoordinatesId: Integer read GetDisplacementTextureCoordinatesId write SetDisplacementTextureCoordinatesId;
    { X3D field "displacementTexture". } { }
    property DisplacementTexture: TAbstractTextureNode read GetDisplacementTexture write SetDisplacementTexture;
    { X3D field "emissiveFactor". } { }
    property EmissiveFactor: TVector3 read GetEmissiveFactor write SetEmissiveFactor;
    { X3D field "emissiveTextureId". } { }
    property EmissiveTextureId: Integer read GetEmissiveTextureId write SetEmissiveTextureId;
    { X3D field "emissiveTextureCoordinatesId". } { }
    property EmissiveTextureCoordinatesId: Integer read GetEmissiveTextureCoordinatesId write SetEmissiveTextureCoordinatesId;
    { X3D field "emissiveTextureChannelMask". } { }
    property EmissiveTextureChannelMask: String read GetEmissiveTextureChannelMask write SetEmissiveTextureChannelMask;
    { X3D field "emissiveTexture". } { }
    property EmissiveTexture: TAbstractTextureNode read GetEmissiveTexture write SetEmissiveTexture;
    { X3D field "environmentFactor". } { }
    property EnvironmentFactor: TVector3 read GetEnvironmentFactor write SetEnvironmentFactor;
    { X3D field "environmentTextureId". } { }
    property EnvironmentTextureId: Integer read GetEnvironmentTextureId write SetEnvironmentTextureId;
    { X3D field "environmentTextureCoordinatesId". } { }
    property EnvironmentTextureCoordinatesId: Integer read GetEnvironmentTextureCoordinatesId write SetEnvironmentTextureCoordinatesId;
    { X3D field "environmentTextureChannelMask". } { }
    property EnvironmentTextureChannelMask: String read GetEnvironmentTextureChannelMask write SetEnvironmentTextureChannelMask;
    { X3D field "environmentTexture". } { }
    property EnvironmentTexture: TAbstractEnvironmentTextureNode read GetEnvironmentTexture write SetEnvironmentTexture;
    { X3D field "multiDiffuseAlphaTexture". } { }
    property MultiDiffuseAlphaTexture: TAbstractTextureNode read GetMultiDiffuseAlphaTexture write SetMultiDiffuseAlphaTexture;
    { X3D field "multiEmmisiveAmbientIntensityTexture". } { }
    property MultiEmmisiveAmbientIntensityTexture: TAbstractTextureNode read GetMultiEmmisiveAmbientIntensityTexture write SetMultiEmmisiveAmbientIntensityTexture;
    { X3D field "multiSpecularShininessTexture". } { }
    property MultiSpecularShininessTexture: TAbstractTextureNode read GetMultiSpecularShininessTexture write SetMultiSpecularShininessTexture;
    { X3D field "multiVisibilityTexture". } { }
    property MultiVisibilityTexture: TAbstractTextureNode read GetMultiVisibilityTexture write SetMultiVisibilityTexture;
    { X3D field "normalTextureId". } { }
    property NormalTextureId: Integer read GetNormalTextureId write SetNormalTextureId;
    { X3D field "normalTextureCoordinatesId". } { }
    property NormalTextureCoordinatesId: Integer read GetNormalTextureCoordinatesId write SetNormalTextureCoordinatesId;
    { X3D field "normalTextureChannelMask". } { }
    property NormalTextureChannelMask: String read GetNormalTextureChannelMask write SetNormalTextureChannelMask;
    { X3D field "normalScale". } { }
    property NormalScale: TVector3 read GetNormalScale write SetNormalScale;
    { X3D field "normalBias". } { }
    property NormalBias: TVector3 read GetNormalBias write SetNormalBias;
    { X3D field "normalTexture". } { }
    property NormalTexture: TAbstractTextureNode read GetNormalTexture write SetNormalTexture;
    { X3D field "normalTextureParallaxHeight". } { }
    property NormalTextureParallaxHeight: Single read GetNormalTextureParallaxHeight write SetNormalTextureParallaxHeight;
    { X3D field "reflectionFactor". } { }
    property ReflectionFactor: TVector3 read GetReflectionFactor write SetReflectionFactor;
    { X3D field "reflectionTextureId". } { }
    property ReflectionTextureId: Integer read GetReflectionTextureId write SetReflectionTextureId;
    { X3D field "reflectionTextureCoordinatesId". } { }
    property ReflectionTextureCoordinatesId: Integer read GetReflectionTextureCoordinatesId write SetReflectionTextureCoordinatesId;
    { X3D field "reflectionTextureChannelMask". } { }
    property ReflectionTextureChannelMask: String read GetReflectionTextureChannelMask write SetReflectionTextureChannelMask;
    { X3D field "reflectionTexture". } { }
    property ReflectionTexture: TAbstractTextureNode read GetReflectionTexture write SetReflectionTexture;
    { X3D field "shininessFactor". } { }
    property ShininessFactor: Single read GetShininessFactor write SetShininessFactor;
    { X3D field "shininessTextureId". } { }
    property ShininessTextureId: Integer read GetShininessTextureId write SetShininessTextureId;
    { X3D field "shininessTextureCoordinatesId". } { }
    property ShininessTextureCoordinatesId: Integer read GetShininessTextureCoordinatesId write SetShininessTextureCoordinatesId;
    { X3D field "shininessTextureChannelMask". } { }
    property ShininessTextureChannelMask: String read GetShininessTextureChannelMask write SetShininessTextureChannelMask;
    { X3D field "shininessTexture". } { }
    property ShininessTexture: TAbstractTextureNode read GetShininessTexture write SetShininessTexture;
    { X3D field "specularFactor". } { }
    property SpecularFactor: TVector3 read GetSpecularFactor write SetSpecularFactor;
    { X3D field "specularTextureId". } { }
    property SpecularTextureId: Integer read GetSpecularTextureId write SetSpecularTextureId;
    { X3D field "specularTextureCoordinatesId". } { }
    property SpecularTextureCoordinatesId: Integer read GetSpecularTextureCoordinatesId write SetSpecularTextureCoordinatesId;
    { X3D field "specularTextureChannelMask". } { }
    property SpecularTextureChannelMask: String read GetSpecularTextureChannelMask write SetSpecularTextureChannelMask;
    { X3D field "specularTexture". } { }
    property SpecularTexture: TAbstractTextureNode read GetSpecularTexture write SetSpecularTexture;
    { X3D field "transmissionFactor". } { }
    property TransmissionFactor: TVector3 read GetTransmissionFactor write SetTransmissionFactor;
    { X3D field "transmissionTextureId". } { }
    property TransmissionTextureId: Integer read GetTransmissionTextureId write SetTransmissionTextureId;
    { X3D field "transmissionTextureCoordinatesId". } { }
    property TransmissionTextureCoordinatesId: Integer read GetTransmissionTextureCoordinatesId write SetTransmissionTextureCoordinatesId;
    { X3D field "transmissionTextureChannelMask". } { }
    property TransmissionTextureChannelMask: String read GetTransmissionTextureChannelMask write SetTransmissionTextureChannelMask;
    { X3D field "transmissionTexture". } { }
    property TransmissionTexture: TAbstractTextureNode read GetTransmissionTexture write SetTransmissionTexture;
    { X3D field "tangentTextureCoordinatesId". } { }
    property TangentTextureCoordinatesId: Integer read GetTangentTextureCoordinatesId write SetTangentTextureCoordinatesId;
    { X3D field "binormalTextureCoordinatesId". } { }
    property BinormalTextureCoordinatesId: Integer read GetBinormalTextureCoordinatesId write SetBinormalTextureCoordinatesId;
    { X3D field "invertAlphaTexture". } { }
    property InvertAlphaTexture: Boolean read GetInvertAlphaTexture write SetInvertAlphaTexture;
    { X3D field "relativeIndexOfRefraction". } { }
    property RelativeIndexOfRefraction: Single read GetRelativeIndexOfRefraction write SetRelativeIndexOfRefraction;
    { X3D field "fresnelBlend". } { }
    property FresnelBlend: Single read GetFresnelBlend write SetFresnelBlend;
    { Set X3D field "textureTransformEnabled". } { }
    procedure SetTextureTransformEnabled(const Value: array of boolean); overload;
    { Set X3D field "textureTransformEnabled". } { }
    procedure SetTextureTransformEnabled(const Value: TBooleanList); overload;

{$endif read_interface}

{$ifdef read_implementation}

{ TCommonSurfaceShaderNode ----------------------------------------------- }

function TCommonSurfaceShaderNode.GetAlphaFactor: Single;
begin
  Result := FdAlphaFactor.Value;
end;

procedure TCommonSurfaceShaderNode.SetAlphaFactor(const Value: Single);
begin
  FdAlphaFactor.Send(Value);
end;

function TCommonSurfaceShaderNode.GetAlphaTextureId: Integer;
begin
  Result := FdAlphaTextureId.Value;
end;

procedure TCommonSurfaceShaderNode.SetAlphaTextureId(const Value: Integer);
begin
  FdAlphaTextureId.Send(Value);
end;

function TCommonSurfaceShaderNode.GetAlphaTextureCoordinatesId: Integer;
begin
  Result := FdAlphaTextureCoordinatesId.Value;
end;

procedure TCommonSurfaceShaderNode.SetAlphaTextureCoordinatesId(const Value: Integer);
begin
  FdAlphaTextureCoordinatesId.Send(Value);
end;

function TCommonSurfaceShaderNode.GetAlphaTextureChannelMask: String;
begin
  Result := FdAlphaTextureChannelMask.Value;
end;

procedure TCommonSurfaceShaderNode.SetAlphaTextureChannelMask(const Value: String);
begin
  FdAlphaTextureChannelMask.Send(Value);
end;

function TCommonSurfaceShaderNode.GetAlphaTexture: TAbstractTextureNode;
begin
  if FdAlphaTexture.Value is TAbstractTextureNode then
    Result := TAbstractTextureNode(FdAlphaTexture.Value)
  else
    Result := nil;
end;

procedure TCommonSurfaceShaderNode.SetAlphaTexture(const Value: TAbstractTextureNode);
begin
  FdAlphaTexture.Send(Value);
end;

function TCommonSurfaceShaderNode.GetAmbientFactor: TVector3;
begin
  Result := FdAmbientFactor.Value;
end;

procedure TCommonSurfaceShaderNode.SetAmbientFactor(const Value: TVector3);
begin
  FdAmbientFactor.Send(Value);
end;

function TCommonSurfaceShaderNode.GetAmbientTextureId: Integer;
begin
  Result := FdAmbientTextureId.Value;
end;

procedure TCommonSurfaceShaderNode.SetAmbientTextureId(const Value: Integer);
begin
  FdAmbientTextureId.Send(Value);
end;

function TCommonSurfaceShaderNode.GetAmbientTextureCoordinatesId: Integer;
begin
  Result := FdAmbientTextureCoordinatesId.Value;
end;

procedure TCommonSurfaceShaderNode.SetAmbientTextureCoordinatesId(const Value: Integer);
begin
  FdAmbientTextureCoordinatesId.Send(Value);
end;

function TCommonSurfaceShaderNode.GetAmbientTextureChannelMask: String;
begin
  Result := FdAmbientTextureChannelMask.Value;
end;

procedure TCommonSurfaceShaderNode.SetAmbientTextureChannelMask(const Value: String);
begin
  FdAmbientTextureChannelMask.Send(Value);
end;

function TCommonSurfaceShaderNode.GetAmbientTexture: TAbstractTextureNode;
begin
  if FdAmbientTexture.Value is TAbstractTextureNode then
    Result := TAbstractTextureNode(FdAmbientTexture.Value)
  else
    Result := nil;
end;

procedure TCommonSurfaceShaderNode.SetAmbientTexture(const Value: TAbstractTextureNode);
begin
  FdAmbientTexture.Send(Value);
end;

function TCommonSurfaceShaderNode.GetDiffuseFactor: TVector3;
begin
  Result := FdDiffuseFactor.Value;
end;

procedure TCommonSurfaceShaderNode.SetDiffuseFactor(const Value: TVector3);
begin
  FdDiffuseFactor.Send(Value);
end;

function TCommonSurfaceShaderNode.GetDiffuseTextureId: Integer;
begin
  Result := FdDiffuseTextureId.Value;
end;

procedure TCommonSurfaceShaderNode.SetDiffuseTextureId(const Value: Integer);
begin
  FdDiffuseTextureId.Send(Value);
end;

function TCommonSurfaceShaderNode.GetDiffuseTextureCoordinatesId: Integer;
begin
  Result := FdDiffuseTextureCoordinatesId.Value;
end;

procedure TCommonSurfaceShaderNode.SetDiffuseTextureCoordinatesId(const Value: Integer);
begin
  FdDiffuseTextureCoordinatesId.Send(Value);
end;

function TCommonSurfaceShaderNode.GetDiffuseTextureChannelMask: String;
begin
  Result := FdDiffuseTextureChannelMask.Value;
end;

procedure TCommonSurfaceShaderNode.SetDiffuseTextureChannelMask(const Value: String);
begin
  FdDiffuseTextureChannelMask.Send(Value);
end;

function TCommonSurfaceShaderNode.GetDiffuseTexture: TAbstractTextureNode;
begin
  if FdDiffuseTexture.Value is TAbstractTextureNode then
    Result := TAbstractTextureNode(FdDiffuseTexture.Value)
  else
    Result := nil;
end;

procedure TCommonSurfaceShaderNode.SetDiffuseTexture(const Value: TAbstractTextureNode);
begin
  FdDiffuseTexture.Send(Value);
end;

function TCommonSurfaceShaderNode.GetDiffuseDisplacementTexture: TAbstractTextureNode;
begin
  if FdDiffuseDisplacementTexture.Value is TAbstractTextureNode then
    Result := TAbstractTextureNode(FdDiffuseDisplacementTexture.Value)
  else
    Result := nil;
end;

procedure TCommonSurfaceShaderNode.SetDiffuseDisplacementTexture(const Value: TAbstractTextureNode);
begin
  FdDiffuseDisplacementTexture.Send(Value);
end;

function TCommonSurfaceShaderNode.GetDisplacementAxis: String;
begin
  Result := FdDisplacementAxis.Value;
end;

procedure TCommonSurfaceShaderNode.SetDisplacementAxis(const Value: String);
begin
  FdDisplacementAxis.Send(Value);
end;

function TCommonSurfaceShaderNode.GetDisplacementFactor: Single;
begin
  Result := FdDisplacementFactor.Value;
end;

procedure TCommonSurfaceShaderNode.SetDisplacementFactor(const Value: Single);
begin
  FdDisplacementFactor.Send(Value);
end;

function TCommonSurfaceShaderNode.GetDisplacementTextureId: Integer;
begin
  Result := FdDisplacementTextureId.Value;
end;

procedure TCommonSurfaceShaderNode.SetDisplacementTextureId(const Value: Integer);
begin
  FdDisplacementTextureId.Send(Value);
end;

function TCommonSurfaceShaderNode.GetDisplacementTextureCoordinatesId: Integer;
begin
  Result := FdDisplacementTextureCoordinatesId.Value;
end;

procedure TCommonSurfaceShaderNode.SetDisplacementTextureCoordinatesId(const Value: Integer);
begin
  FdDisplacementTextureCoordinatesId.Send(Value);
end;

function TCommonSurfaceShaderNode.GetDisplacementTexture: TAbstractTextureNode;
begin
  if FdDisplacementTexture.Value is TAbstractTextureNode then
    Result := TAbstractTextureNode(FdDisplacementTexture.Value)
  else
    Result := nil;
end;

procedure TCommonSurfaceShaderNode.SetDisplacementTexture(const Value: TAbstractTextureNode);
begin
  FdDisplacementTexture.Send(Value);
end;

function TCommonSurfaceShaderNode.GetEmissiveFactor: TVector3;
begin
  Result := FdEmissiveFactor.Value;
end;

procedure TCommonSurfaceShaderNode.SetEmissiveFactor(const Value: TVector3);
begin
  FdEmissiveFactor.Send(Value);
end;

function TCommonSurfaceShaderNode.GetEmissiveTextureId: Integer;
begin
  Result := FdEmissiveTextureId.Value;
end;

procedure TCommonSurfaceShaderNode.SetEmissiveTextureId(const Value: Integer);
begin
  FdEmissiveTextureId.Send(Value);
end;

function TCommonSurfaceShaderNode.GetEmissiveTextureCoordinatesId: Integer;
begin
  Result := FdEmissiveTextureCoordinatesId.Value;
end;

procedure TCommonSurfaceShaderNode.SetEmissiveTextureCoordinatesId(const Value: Integer);
begin
  FdEmissiveTextureCoordinatesId.Send(Value);
end;

function TCommonSurfaceShaderNode.GetEmissiveTextureChannelMask: String;
begin
  Result := FdEmissiveTextureChannelMask.Value;
end;

procedure TCommonSurfaceShaderNode.SetEmissiveTextureChannelMask(const Value: String);
begin
  FdEmissiveTextureChannelMask.Send(Value);
end;

function TCommonSurfaceShaderNode.GetEmissiveTexture: TAbstractTextureNode;
begin
  if FdEmissiveTexture.Value is TAbstractTextureNode then
    Result := TAbstractTextureNode(FdEmissiveTexture.Value)
  else
    Result := nil;
end;

procedure TCommonSurfaceShaderNode.SetEmissiveTexture(const Value: TAbstractTextureNode);
begin
  FdEmissiveTexture.Send(Value);
end;

function TCommonSurfaceShaderNode.GetEnvironmentFactor: TVector3;
begin
  Result := FdEnvironmentFactor.Value;
end;

procedure TCommonSurfaceShaderNode.SetEnvironmentFactor(const Value: TVector3);
begin
  FdEnvironmentFactor.Send(Value);
end;

function TCommonSurfaceShaderNode.GetEnvironmentTextureId: Integer;
begin
  Result := FdEnvironmentTextureId.Value;
end;

procedure TCommonSurfaceShaderNode.SetEnvironmentTextureId(const Value: Integer);
begin
  FdEnvironmentTextureId.Send(Value);
end;

function TCommonSurfaceShaderNode.GetEnvironmentTextureCoordinatesId: Integer;
begin
  Result := FdEnvironmentTextureCoordinatesId.Value;
end;

procedure TCommonSurfaceShaderNode.SetEnvironmentTextureCoordinatesId(const Value: Integer);
begin
  FdEnvironmentTextureCoordinatesId.Send(Value);
end;

function TCommonSurfaceShaderNode.GetEnvironmentTextureChannelMask: String;
begin
  Result := FdEnvironmentTextureChannelMask.Value;
end;

procedure TCommonSurfaceShaderNode.SetEnvironmentTextureChannelMask(const Value: String);
begin
  FdEnvironmentTextureChannelMask.Send(Value);
end;

function TCommonSurfaceShaderNode.GetEnvironmentTexture: TAbstractEnvironmentTextureNode;
begin
  if FdEnvironmentTexture.Value is TAbstractEnvironmentTextureNode then
    Result := TAbstractEnvironmentTextureNode(FdEnvironmentTexture.Value)
  else
    Result := nil;
end;

procedure TCommonSurfaceShaderNode.SetEnvironmentTexture(const Value: TAbstractEnvironmentTextureNode);
begin
  FdEnvironmentTexture.Send(Value);
end;

function TCommonSurfaceShaderNode.GetMultiDiffuseAlphaTexture: TAbstractTextureNode;
begin
  if FdMultiDiffuseAlphaTexture.Value is TAbstractTextureNode then
    Result := TAbstractTextureNode(FdMultiDiffuseAlphaTexture.Value)
  else
    Result := nil;
end;

procedure TCommonSurfaceShaderNode.SetMultiDiffuseAlphaTexture(const Value: TAbstractTextureNode);
begin
  FdMultiDiffuseAlphaTexture.Send(Value);
end;

function TCommonSurfaceShaderNode.GetMultiEmmisiveAmbientIntensityTexture: TAbstractTextureNode;
begin
  if FdMultiEmmisiveAmbientIntensityTexture.Value is TAbstractTextureNode then
    Result := TAbstractTextureNode(FdMultiEmmisiveAmbientIntensityTexture.Value)
  else
    Result := nil;
end;

procedure TCommonSurfaceShaderNode.SetMultiEmmisiveAmbientIntensityTexture(const Value: TAbstractTextureNode);
begin
  FdMultiEmmisiveAmbientIntensityTexture.Send(Value);
end;

function TCommonSurfaceShaderNode.GetMultiSpecularShininessTexture: TAbstractTextureNode;
begin
  if FdMultiSpecularShininessTexture.Value is TAbstractTextureNode then
    Result := TAbstractTextureNode(FdMultiSpecularShininessTexture.Value)
  else
    Result := nil;
end;

procedure TCommonSurfaceShaderNode.SetMultiSpecularShininessTexture(const Value: TAbstractTextureNode);
begin
  FdMultiSpecularShininessTexture.Send(Value);
end;

function TCommonSurfaceShaderNode.GetMultiVisibilityTexture: TAbstractTextureNode;
begin
  if FdMultiVisibilityTexture.Value is TAbstractTextureNode then
    Result := TAbstractTextureNode(FdMultiVisibilityTexture.Value)
  else
    Result := nil;
end;

procedure TCommonSurfaceShaderNode.SetMultiVisibilityTexture(const Value: TAbstractTextureNode);
begin
  FdMultiVisibilityTexture.Send(Value);
end;

function TCommonSurfaceShaderNode.GetNormalTextureId: Integer;
begin
  Result := FdNormalTextureId.Value;
end;

procedure TCommonSurfaceShaderNode.SetNormalTextureId(const Value: Integer);
begin
  FdNormalTextureId.Send(Value);
end;

function TCommonSurfaceShaderNode.GetNormalTextureCoordinatesId: Integer;
begin
  Result := FdNormalTextureCoordinatesId.Value;
end;

procedure TCommonSurfaceShaderNode.SetNormalTextureCoordinatesId(const Value: Integer);
begin
  FdNormalTextureCoordinatesId.Send(Value);
end;

function TCommonSurfaceShaderNode.GetNormalTextureChannelMask: String;
begin
  Result := FdNormalTextureChannelMask.Value;
end;

procedure TCommonSurfaceShaderNode.SetNormalTextureChannelMask(const Value: String);
begin
  FdNormalTextureChannelMask.Send(Value);
end;

function TCommonSurfaceShaderNode.GetNormalScale: TVector3;
begin
  Result := FdNormalScale.Value;
end;

procedure TCommonSurfaceShaderNode.SetNormalScale(const Value: TVector3);
begin
  FdNormalScale.Send(Value);
end;

function TCommonSurfaceShaderNode.GetNormalBias: TVector3;
begin
  Result := FdNormalBias.Value;
end;

procedure TCommonSurfaceShaderNode.SetNormalBias(const Value: TVector3);
begin
  FdNormalBias.Send(Value);
end;

function TCommonSurfaceShaderNode.GetNormalTexture: TAbstractTextureNode;
begin
  if FdNormalTexture.Value is TAbstractTextureNode then
    Result := TAbstractTextureNode(FdNormalTexture.Value)
  else
    Result := nil;
end;

procedure TCommonSurfaceShaderNode.SetNormalTexture(const Value: TAbstractTextureNode);
begin
  FdNormalTexture.Send(Value);
end;

function TCommonSurfaceShaderNode.GetNormalTextureParallaxHeight: Single;
begin
  Result := FdNormalTextureParallaxHeight.Value;
end;

procedure TCommonSurfaceShaderNode.SetNormalTextureParallaxHeight(const Value: Single);
begin
  FdNormalTextureParallaxHeight.Send(Value);
end;

function TCommonSurfaceShaderNode.GetReflectionFactor: TVector3;
begin
  Result := FdReflectionFactor.Value;
end;

procedure TCommonSurfaceShaderNode.SetReflectionFactor(const Value: TVector3);
begin
  FdReflectionFactor.Send(Value);
end;

function TCommonSurfaceShaderNode.GetReflectionTextureId: Integer;
begin
  Result := FdReflectionTextureId.Value;
end;

procedure TCommonSurfaceShaderNode.SetReflectionTextureId(const Value: Integer);
begin
  FdReflectionTextureId.Send(Value);
end;

function TCommonSurfaceShaderNode.GetReflectionTextureCoordinatesId: Integer;
begin
  Result := FdReflectionTextureCoordinatesId.Value;
end;

procedure TCommonSurfaceShaderNode.SetReflectionTextureCoordinatesId(const Value: Integer);
begin
  FdReflectionTextureCoordinatesId.Send(Value);
end;

function TCommonSurfaceShaderNode.GetReflectionTextureChannelMask: String;
begin
  Result := FdReflectionTextureChannelMask.Value;
end;

procedure TCommonSurfaceShaderNode.SetReflectionTextureChannelMask(const Value: String);
begin
  FdReflectionTextureChannelMask.Send(Value);
end;

function TCommonSurfaceShaderNode.GetReflectionTexture: TAbstractTextureNode;
begin
  if FdReflectionTexture.Value is TAbstractTextureNode then
    Result := TAbstractTextureNode(FdReflectionTexture.Value)
  else
    Result := nil;
end;

procedure TCommonSurfaceShaderNode.SetReflectionTexture(const Value: TAbstractTextureNode);
begin
  FdReflectionTexture.Send(Value);
end;

function TCommonSurfaceShaderNode.GetShininessFactor: Single;
begin
  Result := FdShininessFactor.Value;
end;

procedure TCommonSurfaceShaderNode.SetShininessFactor(const Value: Single);
begin
  FdShininessFactor.Send(Value);
end;

function TCommonSurfaceShaderNode.GetShininessTextureId: Integer;
begin
  Result := FdShininessTextureId.Value;
end;

procedure TCommonSurfaceShaderNode.SetShininessTextureId(const Value: Integer);
begin
  FdShininessTextureId.Send(Value);
end;

function TCommonSurfaceShaderNode.GetShininessTextureCoordinatesId: Integer;
begin
  Result := FdShininessTextureCoordinatesId.Value;
end;

procedure TCommonSurfaceShaderNode.SetShininessTextureCoordinatesId(const Value: Integer);
begin
  FdShininessTextureCoordinatesId.Send(Value);
end;

function TCommonSurfaceShaderNode.GetShininessTextureChannelMask: String;
begin
  Result := FdShininessTextureChannelMask.Value;
end;

procedure TCommonSurfaceShaderNode.SetShininessTextureChannelMask(const Value: String);
begin
  FdShininessTextureChannelMask.Send(Value);
end;

function TCommonSurfaceShaderNode.GetShininessTexture: TAbstractTextureNode;
begin
  if FdShininessTexture.Value is TAbstractTextureNode then
    Result := TAbstractTextureNode(FdShininessTexture.Value)
  else
    Result := nil;
end;

procedure TCommonSurfaceShaderNode.SetShininessTexture(const Value: TAbstractTextureNode);
begin
  FdShininessTexture.Send(Value);
end;

function TCommonSurfaceShaderNode.GetSpecularFactor: TVector3;
begin
  Result := FdSpecularFactor.Value;
end;

procedure TCommonSurfaceShaderNode.SetSpecularFactor(const Value: TVector3);
begin
  FdSpecularFactor.Send(Value);
end;

function TCommonSurfaceShaderNode.GetSpecularTextureId: Integer;
begin
  Result := FdSpecularTextureId.Value;
end;

procedure TCommonSurfaceShaderNode.SetSpecularTextureId(const Value: Integer);
begin
  FdSpecularTextureId.Send(Value);
end;

function TCommonSurfaceShaderNode.GetSpecularTextureCoordinatesId: Integer;
begin
  Result := FdSpecularTextureCoordinatesId.Value;
end;

procedure TCommonSurfaceShaderNode.SetSpecularTextureCoordinatesId(const Value: Integer);
begin
  FdSpecularTextureCoordinatesId.Send(Value);
end;

function TCommonSurfaceShaderNode.GetSpecularTextureChannelMask: String;
begin
  Result := FdSpecularTextureChannelMask.Value;
end;

procedure TCommonSurfaceShaderNode.SetSpecularTextureChannelMask(const Value: String);
begin
  FdSpecularTextureChannelMask.Send(Value);
end;

function TCommonSurfaceShaderNode.GetSpecularTexture: TAbstractTextureNode;
begin
  if FdSpecularTexture.Value is TAbstractTextureNode then
    Result := TAbstractTextureNode(FdSpecularTexture.Value)
  else
    Result := nil;
end;

procedure TCommonSurfaceShaderNode.SetSpecularTexture(const Value: TAbstractTextureNode);
begin
  FdSpecularTexture.Send(Value);
end;

function TCommonSurfaceShaderNode.GetTransmissionFactor: TVector3;
begin
  Result := FdTransmissionFactor.Value;
end;

procedure TCommonSurfaceShaderNode.SetTransmissionFactor(const Value: TVector3);
begin
  FdTransmissionFactor.Send(Value);
end;

function TCommonSurfaceShaderNode.GetTransmissionTextureId: Integer;
begin
  Result := FdTransmissionTextureId.Value;
end;

procedure TCommonSurfaceShaderNode.SetTransmissionTextureId(const Value: Integer);
begin
  FdTransmissionTextureId.Send(Value);
end;

function TCommonSurfaceShaderNode.GetTransmissionTextureCoordinatesId: Integer;
begin
  Result := FdTransmissionTextureCoordinatesId.Value;
end;

procedure TCommonSurfaceShaderNode.SetTransmissionTextureCoordinatesId(const Value: Integer);
begin
  FdTransmissionTextureCoordinatesId.Send(Value);
end;

function TCommonSurfaceShaderNode.GetTransmissionTextureChannelMask: String;
begin
  Result := FdTransmissionTextureChannelMask.Value;
end;

procedure TCommonSurfaceShaderNode.SetTransmissionTextureChannelMask(const Value: String);
begin
  FdTransmissionTextureChannelMask.Send(Value);
end;

function TCommonSurfaceShaderNode.GetTransmissionTexture: TAbstractTextureNode;
begin
  if FdTransmissionTexture.Value is TAbstractTextureNode then
    Result := TAbstractTextureNode(FdTransmissionTexture.Value)
  else
    Result := nil;
end;

procedure TCommonSurfaceShaderNode.SetTransmissionTexture(const Value: TAbstractTextureNode);
begin
  FdTransmissionTexture.Send(Value);
end;

function TCommonSurfaceShaderNode.GetTangentTextureCoordinatesId: Integer;
begin
  Result := FdTangentTextureCoordinatesId.Value;
end;

procedure TCommonSurfaceShaderNode.SetTangentTextureCoordinatesId(const Value: Integer);
begin
  FdTangentTextureCoordinatesId.Send(Value);
end;

function TCommonSurfaceShaderNode.GetBinormalTextureCoordinatesId: Integer;
begin
  Result := FdBinormalTextureCoordinatesId.Value;
end;

procedure TCommonSurfaceShaderNode.SetBinormalTextureCoordinatesId(const Value: Integer);
begin
  FdBinormalTextureCoordinatesId.Send(Value);
end;

function TCommonSurfaceShaderNode.GetInvertAlphaTexture: Boolean;
begin
  Result := FdInvertAlphaTexture.Value;
end;

procedure TCommonSurfaceShaderNode.SetInvertAlphaTexture(const Value: Boolean);
begin
  FdInvertAlphaTexture.Send(Value);
end;

function TCommonSurfaceShaderNode.GetRelativeIndexOfRefraction: Single;
begin
  Result := FdRelativeIndexOfRefraction.Value;
end;

procedure TCommonSurfaceShaderNode.SetRelativeIndexOfRefraction(const Value: Single);
begin
  FdRelativeIndexOfRefraction.Send(Value);
end;

function TCommonSurfaceShaderNode.GetFresnelBlend: Single;
begin
  Result := FdFresnelBlend.Value;
end;

procedure TCommonSurfaceShaderNode.SetFresnelBlend(const Value: Single);
begin
  FdFresnelBlend.Send(Value);
end;

procedure TCommonSurfaceShaderNode.SetTextureTransformEnabled(const Value: array of boolean);
begin
  FdTextureTransformEnabled.Send(Value);
end;

procedure TCommonSurfaceShaderNode.SetTextureTransformEnabled(const Value: TBooleanList);
begin
  FdTextureTransformEnabled.Send(Value);
end;

{$endif read_implementation}
