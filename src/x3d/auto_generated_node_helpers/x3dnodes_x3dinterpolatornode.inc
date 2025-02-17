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

  public
    procedure CreateNode; override;
    class function ClassX3DType: string; override;

    strict private FEventSet_fraction: TSFFloatEvent;
    { X3D in event "set_fraction". } { }
    public property EventSet_fraction: TSFFloatEvent read FEventSet_fraction;

    strict private FFdKey: TMFFloat;
    { X3D field "key". } { }
    public property FdKey: TMFFloat read FFdKey;
    { Set X3D field "key". } { }
    procedure SetKey(const Value: array of Single); overload;
    { Set X3D field "key". } { }
    procedure SetKey(const Value: TSingleList); overload;

{$endif read_interface}

{$ifdef read_implementation}

{ TAbstractInterpolatorNode ----------------------------------------------- }

procedure TAbstractInterpolatorNode.SetKey(const Value: array of Single);
begin
  FdKey.Send(Value);
end;

procedure TAbstractInterpolatorNode.SetKey(const Value: TSingleList);
begin
  FdKey.Send(Value);
end;

class function TAbstractInterpolatorNode.ClassX3DType: String;
begin
  Result := 'X3DInterpolatorNode';
end;

procedure TAbstractInterpolatorNode.CreateNode;
begin
  inherited;

  FEventSet_fraction := TSFFloatEvent.Create(Self, 'set_fraction', true);
  AddEvent(FEventSet_fraction);

  FFdKey := TMFFloat.Create(Self, True, 'key', []);
   FdKey.ChangeAlways := chNone;
  AddField(FFdKey);
end;

{$endif read_implementation}
