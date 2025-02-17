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
    function GetRepeatR: Boolean;
    procedure SetRepeatR(const Value: Boolean);
    function GetTextureProperties: TTexturePropertiesNode;
    procedure SetTextureProperties(const Value: TTexturePropertiesNode);
  public
    procedure CreateNode; override;
    class function ClassX3DType: string; override;

    strict private FFdRepeatS: TSFBool;
    { X3D field "repeatS". } { }
    public property FdRepeatS: TSFBool read FFdRepeatS;

    strict private FFdRepeatT: TSFBool;
    { X3D field "repeatT". } { }
    public property FdRepeatT: TSFBool read FFdRepeatT;

    strict private FFdRepeatR: TSFBool;
    { X3D field "repeatR". } { }
    public property FdRepeatR: TSFBool read FFdRepeatR;
    { X3D field "repeatR". } { }
    property RepeatR: Boolean read GetRepeatR write SetRepeatR;

    strict private FFdTextureProperties: TSFNode;
    { X3D field "textureProperties". } { }
    public property FdTextureProperties: TSFNode read FFdTextureProperties;
    { X3D field "textureProperties". } { }
    property TextureProperties: TTexturePropertiesNode read GetTextureProperties write SetTextureProperties;

{$endif read_interface}

{$ifdef read_implementation}

{ TAbstractTexture3DNode ----------------------------------------------- }

function TAbstractTexture3DNode.GetRepeatR: Boolean;
begin
  Result := FdRepeatR.Value;
end;

procedure TAbstractTexture3DNode.SetRepeatR(const Value: Boolean);
begin
  FdRepeatR.Send(Value);
end;

function TAbstractTexture3DNode.GetTextureProperties: TTexturePropertiesNode;
begin
  if FdTextureProperties.Value is TTexturePropertiesNode then
    Result := TTexturePropertiesNode(FdTextureProperties.Value)
  else
    Result := nil;
end;

procedure TAbstractTexture3DNode.SetTextureProperties(const Value: TTexturePropertiesNode);
begin
  FdTextureProperties.Send(Value);
end;

class function TAbstractTexture3DNode.ClassX3DType: String;
begin
  Result := 'X3DTexture3DNode';
end;

procedure TAbstractTexture3DNode.CreateNode;
begin
  inherited;

  FFdRepeatS := TSFBool.Create(Self, False, 'repeatS', false);
   FdRepeatS.ChangeAlways := chTextureRendererProperties;
  AddField(FFdRepeatS);

  FFdRepeatT := TSFBool.Create(Self, False, 'repeatT', false);
   FdRepeatT.ChangeAlways := chTextureRendererProperties;
  AddField(FFdRepeatT);

  FFdRepeatR := TSFBool.Create(Self, False, 'repeatR', false);
   FdRepeatR.ChangeAlways := chTextureRendererProperties;
  AddField(FFdRepeatR);

  FFdTextureProperties := TSFNode.Create(Self, False, 'textureProperties', [TTexturePropertiesNode]);
   FdTextureProperties.ChangeAlways := chTextureRendererProperties;
  AddField(FFdTextureProperties);
end;

{$endif read_implementation}
