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
    function GetCategory: Integer;
    procedure SetCategory(const Value: Integer);
    function GetCountry: Integer;
    procedure SetCountry(const Value: Integer);
    function GetDomain: Integer;
    procedure SetDomain(const Value: Integer);
    function GetExtra: Integer;
    procedure SetExtra(const Value: Integer);
    function GetKind: Integer;
    procedure SetKind(const Value: Integer);
    function GetSpecific: Integer;
    procedure SetSpecific(const Value: Integer);
    function GetSubcategory: Integer;
    procedure SetSubcategory(const Value: Integer);
  public
    procedure CreateNode; override;
    class function ClassX3DType: string; override;

    strict private FFdUrl: TMFString;
    { X3D field "url". } { }
    public property FdUrl: TMFString read FFdUrl;
    { Set X3D field "url". } { }
    procedure SetUrl(const Value: array of string); overload;
    { Set X3D field "url". } { }
    procedure SetUrl(const Value: TCastleStringList); overload;

    strict private FFdCategory: TSFInt32;
    { X3D field "category". } { }
    public property FdCategory: TSFInt32 read FFdCategory;
    { X3D field "category". } { }
    property Category: Integer read GetCategory write SetCategory;

    strict private FFdCountry: TSFInt32;
    { X3D field "country". } { }
    public property FdCountry: TSFInt32 read FFdCountry;
    { X3D field "country". } { }
    property Country: Integer read GetCountry write SetCountry;

    strict private FFdDomain: TSFInt32;
    { X3D field "domain". } { }
    public property FdDomain: TSFInt32 read FFdDomain;
    { X3D field "domain". } { }
    property Domain: Integer read GetDomain write SetDomain;

    strict private FFdExtra: TSFInt32;
    { X3D field "extra". } { }
    public property FdExtra: TSFInt32 read FFdExtra;
    { X3D field "extra". } { }
    property Extra: Integer read GetExtra write SetExtra;

    strict private FFdKind: TSFInt32;
    { X3D field "kind". } { }
    public property FdKind: TSFInt32 read FFdKind;
    { X3D field "kind". } { }
    property Kind: Integer read GetKind write SetKind;

    strict private FFdSpecific: TSFInt32;
    { X3D field "specific". } { }
    public property FdSpecific: TSFInt32 read FFdSpecific;
    { X3D field "specific". } { }
    property Specific: Integer read GetSpecific write SetSpecific;

    strict private FFdSubcategory: TSFInt32;
    { X3D field "subcategory". } { }
    public property FdSubcategory: TSFInt32 read FFdSubcategory;
    { X3D field "subcategory". } { }
    property Subcategory: Integer read GetSubcategory write SetSubcategory;

{$endif read_interface}

{$ifdef read_implementation}

{ TDISEntityTypeMappingNode ----------------------------------------------- }

procedure TDISEntityTypeMappingNode.SetUrl(const Value: array of string);
begin
  FdUrl.Send(Value);
end;

procedure TDISEntityTypeMappingNode.SetUrl(const Value: TCastleStringList);
begin
  FdUrl.Send(Value);
end;

function TDISEntityTypeMappingNode.GetCategory: Integer;
begin
  Result := FdCategory.Value;
end;

procedure TDISEntityTypeMappingNode.SetCategory(const Value: Integer);
begin
  FdCategory.Send(Value);
end;

function TDISEntityTypeMappingNode.GetCountry: Integer;
begin
  Result := FdCountry.Value;
end;

procedure TDISEntityTypeMappingNode.SetCountry(const Value: Integer);
begin
  FdCountry.Send(Value);
end;

function TDISEntityTypeMappingNode.GetDomain: Integer;
begin
  Result := FdDomain.Value;
end;

procedure TDISEntityTypeMappingNode.SetDomain(const Value: Integer);
begin
  FdDomain.Send(Value);
end;

function TDISEntityTypeMappingNode.GetExtra: Integer;
begin
  Result := FdExtra.Value;
end;

procedure TDISEntityTypeMappingNode.SetExtra(const Value: Integer);
begin
  FdExtra.Send(Value);
end;

function TDISEntityTypeMappingNode.GetKind: Integer;
begin
  Result := FdKind.Value;
end;

procedure TDISEntityTypeMappingNode.SetKind(const Value: Integer);
begin
  FdKind.Send(Value);
end;

function TDISEntityTypeMappingNode.GetSpecific: Integer;
begin
  Result := FdSpecific.Value;
end;

procedure TDISEntityTypeMappingNode.SetSpecific(const Value: Integer);
begin
  FdSpecific.Send(Value);
end;

function TDISEntityTypeMappingNode.GetSubcategory: Integer;
begin
  Result := FdSubcategory.Value;
end;

procedure TDISEntityTypeMappingNode.SetSubcategory(const Value: Integer);
begin
  FdSubcategory.Send(Value);
end;

class function TDISEntityTypeMappingNode.ClassX3DType: String;
begin
  Result := 'DISEntityTypeMapping';
end;

procedure TDISEntityTypeMappingNode.CreateNode;
begin
  inherited;

  FFdUrl := TMFString.Create(Self, True, 'url', []);
   FdUrl.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdUrl);

  FFdCategory := TSFInt32.Create(Self, False, 'category', 0);
   FdCategory.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdCategory);

  FFdCountry := TSFInt32.Create(Self, False, 'country', 0);
   FdCountry.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdCountry);

  FFdDomain := TSFInt32.Create(Self, False, 'domain', 0);
   FdDomain.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdDomain);

  FFdExtra := TSFInt32.Create(Self, False, 'extra', 0);
   FdExtra.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdExtra);

  FFdKind := TSFInt32.Create(Self, False, 'kind', 0);
   FdKind.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdKind);

  FFdSpecific := TSFInt32.Create(Self, False, 'specific', 0);
   FdSpecific.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdSpecific);

  FFdSubcategory := TSFInt32.Create(Self, False, 'subcategory', 0);
   FdSubcategory.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdSubcategory);
end;

{$endif read_implementation}
