{ -*- buffer-read-only: t -*-

  Copyright 2018-2018 Michalis Kamburelis.

  This file is part of "Castle Game Engine".

  "Castle Game Engine" is free software; see the file COPYING.txt,
  included in this distribution, for details about the copyright.

  "Castle Game Engine" is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

  ----------------------------------------------------------------------------
}

{ Automatically generated wrapper to make vectors/colors persistent.

  Do not edit this file manually!
  Instead
  - edit tools/internal/generate-persistent-vectors/persistent_vectors_input.txt
  - and run generate-persistent-vectors in that directory.
}

{$ifdef read_interface_class}
strict private
  FBorderColorPersistent: TCastleColorPersistent;
  function GetBorderColorForPersistent: TCastleColor;
  procedure SetBorderColorForPersistent(const AValue: TCastleColor);
published
  { @link(BorderColor) that can be visually edited in
    Castle Game Engine Editor, Lazarus and Delphi.
    Normal user code does not need to deal with this,
    instead read or write @link(BorderColor) directly.

    @seealso BorderColor }
  property BorderColorPersistent: TCastleColorPersistent read FBorderColorPersistent ;
{$endif read_interface_class}

{$ifdef read_implementation_methods}
function TCastleUserInterface.GetBorderColorForPersistent: TCastleColor;
begin
  Result := BorderColor;
end;

procedure TCastleUserInterface.SetBorderColorForPersistent(const AValue: TCastleColor);
begin
  BorderColor := AValue;
end;
{$endif read_implementation_methods}

{$ifdef read_implementation_constructor}
  FBorderColorPersistent := TCastleColorPersistent.Create;
  FBorderColorPersistent.InternalGetValue := {$ifdef FPC}@{$endif}GetBorderColorForPersistent;
  FBorderColorPersistent.InternalSetValue := {$ifdef FPC}@{$endif}SetBorderColorForPersistent;
  FBorderColorPersistent.InternalDefaultValue := BorderColor; // current value is default
{$endif read_implementation_constructor}

{$ifdef read_implementation_destructor}
  FreeAndNil(FBorderColorPersistent);
{$endif read_implementation_destructor}

