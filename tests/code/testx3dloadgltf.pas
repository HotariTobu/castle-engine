// -*- compile-command: "cd ../ && ./compile_console.sh && ./test_castle_game_engine --suite=TTestX3DLoadGltf" -*-
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

{ Test X3DLoadInternalGltf unit. }
unit TestX3DLoadGltf;

{$I tests.inc}

interface

uses
  Classes, SysUtils, FpcUnit, TestUtils, TestRegistry,
  CastleTestCase;

type
  TTestX3DLoadGltf = class(TCastleTestCase)
  published
    { Nothing to test now, glTF loading is extensively tested as part of other TCastleScene tests.
      But we need at least 1st test here, otherwise failure
      "No valid tests found in TTestX3DLoadGltf" }
    procedure TestDummy;
  end;

implementation

uses X3DLoad, CastleVectors, X3DLoadInternalGltf, CastleUtils;

procedure TTestX3DLoadGltf.TestDummy;
begin
end;

initialization
  RegisterTest(TTestX3DLoadGltf);
end.
