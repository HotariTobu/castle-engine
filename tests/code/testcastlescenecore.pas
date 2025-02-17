// -*- compile-command: "cd ../ && ./compile_console.sh && ./test_castle_game_engine --suite=TTestSceneCore" -*-
{
  Copyright 2020-2021 Michalis Kamburelis.

  This file is part of "Castle Game Engine".

  "Castle Game Engine" is free software; see the file COPYING.txt,
  included in this distribution, for details about the copyright.

  "Castle Game Engine" is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

  ----------------------------------------------------------------------------
}

{ Test CastleSceneCore unit. }
unit TestCastleSceneCore;

{$I tests.inc}

interface

uses
  Classes, SysUtils, FpcUnit, TestUtils, TestRegistry,
  CastleTestCase, CastleSceneCore, X3DNodes;

type
  TTestSceneCore = class(TCastleTestCase)
  strict private
    SearchingForDescription: string;
    WarningFlag: Boolean;
    function SearchingForDescriptionCallback(Node: TX3DNode): Pointer;
    procedure NodeMultipleTimesWarning(const Category, S: string);
    procedure OnWarningFlag(const Category, S: string);
    { Load scene and expect a warning during loading.
      Raises error if no warnings occurred. }
    procedure LoadSceneRequireWarning(const Scene: TCastleSceneCore; const Url: String);
  published
    procedure TestBorderManifoldEdges;
    procedure TestIterator;
    { $define ITERATOR_SPEED_TEST}
    {$ifdef ITERATOR_SPEED_TEST}
    procedure TestIteratorSpeed;
    {$endif ITERATOR_SPEED_TEST}
    procedure TestFind;
    procedure TestViewpointBillboardTricky;
    procedure TestManifold;
    procedure TestMultipleScenesOneNodeIncorrect;
    procedure TestMultipleScenesOneNodeCorrect;
    procedure TestSpineUtf8Names;
    procedure TestAnimsInSwitch;
    procedure TestLoadGzipped;
    procedure TestStarlingAndAnchors;
    procedure TestCocos;
    procedure TestImageAsNode;
    procedure TestPlayStopAnim;
    procedure TestFontStyleChanges;
    procedure TestUnassociate;
    procedure TestUnassociate2;
    procedure TestUnassociateChangeMaterialOneLeft;
    procedure TestUnassociateChangeMaterialSharedAppearance;
    procedure TestUnassociateChangeAppearance;
  end;

implementation

uses X3DLoad, CastleVectors, CastleShapes,
  CastleTimeUtils, CastleStringUtils, X3DFields, CastleSceneManager, CastleBoxes,
  CastleFilesUtils, CastleScene, CastleTransform, CastleApplicationProperties,
  CastleURIUtils;

procedure TTestSceneCore.TestBorderManifoldEdges;
var
  Scene: TCastleSceneCore;
  Manifold, Border: Cardinal;
begin
  Scene := TCastleSceneCore.Create(nil);
  try
    Scene.Load('data/model_manifold.wrl');
    Scene.EdgesCount(Manifold, Border);
    AssertEquals(0, Border);
  finally FreeAndNil(Scene) end;
end;

{$ifdef ITERATOR_SPEED_TEST}
procedure TTestSceneCore.TestIteratorSpeed;

  procedure CheckIteratorSpeed(const FileName: string;
    const TestCount: Integer = 1000);
  var
    Scene: TCastleSceneCore;
    List: TShapesList;
    SI: TShapeTreeIterator;
    OnlyActive: boolean;
    I: Integer;
    Test: Integer;
  begin
    Writeln('CheckIteratorSpeed on ', FileName);

    Scene := TCastleSceneCore.Create(nil);
    try
      Scene.Load(FileName);
      for OnlyActive := false to true do
      begin
        ProcessTimerBegin;
        for Test := 0 to TestCount - 1 do
        begin
          List := TShapesList.Create(Scene.Shapes, OnlyActive);
          for I := 0 to List.Count - 1 do
            { Just do anything that requires access to List[I] }
            PointerToStr(List[I].Geometry);
          FreeAndNil(List);
        end;
        Writeln('TShapesList traverse: ', ProcessTimerEnd:1:2);

        ProcessTimerBegin;
        for Test := 0 to TestCount - 1 do
        begin
          SI := TShapeTreeIterator.Create(Scene.Shapes, OnlyActive);
          while SI.GetNext do
            PointerToStr(SI.Current.Geometry);
          FreeAndNil(SI);
        end;
        Writeln('TShapeTreeIterator: ', ProcessTimerEnd:1:2);

      end;
    finally FreeAndNil(Scene) end;
  end;

begin
  CheckIteratorSpeed('../../demo_models/x3d/deranged_house_final.x3dv');
  CheckIteratorSpeed('../../demo_models/x3d/anchor_test.x3dv');
  CheckIteratorSpeed('../../demo_models/x3d/switches_and_transforms.x3dv');
  CheckIteratorSpeed('../../demo_models/x3d/key_sensor.x3dv');

  CheckIteratorSpeed('data/switches_and_transforms_2.x3dv');
  CheckIteratorSpeed('data/key_sensor_2.x3dv');

  CheckIteratorSpeed('/home/michalis/sources/rrtankticks2/rrtankticks3/rrtt.wrl',
    10); { smaller TestCount, as it's quite slow }
end;
{$endif ITERATOR_SPEED_TEST}

procedure TTestSceneCore.TestIterator;

  procedure CheckIterator(const FileName: string);
  var
    Scene: TCastleSceneCore;
    List: TShapeList;
    SI: TShapeTreeIterator;
    OnlyActive: boolean;
    I: Integer;
  begin
    Scene := TCastleSceneCore.Create(nil);
    try
      Scene.Load(FileName);
      for OnlyActive := false to true do
      begin
        { Compare the simple iterator implementation (that just calls
          Traverse and gathers results to the list) with actual sophisticated
          implementation in TShapeTreeIterator. }
        List := TShapeList.Create(Scene.Shapes, OnlyActive);
        SI := TShapeTreeIterator.Create(Scene.Shapes, OnlyActive);
        for I := 0 to List.Count - 1 do
        begin
          Check(SI.GetNext, 'SI.GetNext');
          Check(SI.Current = List[I], 'SI.Current');
        end;
        Check(not SI.GetNext, 'not SI.GetNext');

//        writeln('done for ', FileName, ' active: ', OnlyActive, ' count is ', List.Count);

        FreeAndNil(List);
        FreeAndNil(SI);
      end;
    finally FreeAndNil(Scene) end;
  end;

begin
  CheckIterator('data/demo-models-copy/deranged_house_final.x3dv');
  CheckIterator('data/demo-models-copy/anchor_test.x3dv');
  CheckIterator('data/switches_and_transforms_2.x3dv');
  CheckIterator('data/key_sensor_2.x3dv');
  CheckIterator('data/extrusion_empty_spine.x3dv');
  CheckIterator('data/extrusion_empty_spine_concave.x3dv');
  CheckIterator('data/extrusion_empty_spine_smooth.x3dv');

  // This once failed to be read with FPC 3.1.1
  CheckIterator('data/spine/escape_from_the_universe_boss/boss.json');

  // This once failed to be read, as the Spine has DefaultSkin = nil
  CheckIterator('data/spine/empty_spine.json');

  // This once failed with access violation because TClippingAttachment.BuildNodes didn't assign Material
  CheckIterator('data/spine/clip_region/skeleton.json');
end;

procedure TTestSceneCore.TestFind;
var
  Scene: TCastleSceneCore;
begin
  Scene := TCastleSceneCore.Create(nil);
  try
    try
      Scene.Node('Left');
      Fail('Should fail with EX3DNotFound');
    except on EX3DNotFound do ; end;

    try
      Scene.Field('Left', 'translation');
      Fail('Should fail with EX3DNotFound');
    except on EX3DNotFound do ; end;

    try
      Scene.Event('Left', 'addChildren');
      Fail('Should fail with EX3DNotFound');
    except on EX3DNotFound do ; end;

    Scene.URL := 'data/switches_and_transforms_2.x3dv';
    Scene.Node('Left');
    Scene.Field('Left', 'translation');
    Scene.Event('Left', 'addChildren');

    try
      Scene.Node('Blah');
      Fail('Should fail with EX3DNotFound');
    except on EX3DNotFound do ; end;

    try
      Scene.Field('Blah', 'translation');
      Fail('Should fail with EX3DNotFound');
    except on EX3DNotFound do ; end;

    try
      Scene.Event('Blah', 'addChildren');
      Fail('Should fail with EX3DNotFound');
    except on EX3DNotFound do ; end;

    try
      Scene.Field('Left', 'blah');
      Fail('Should fail with EX3DNotFound');
    except on EX3DNotFound do ; end;

    try
      Scene.Event('Left', 'blah');
      Fail('Should fail with EX3DNotFound');
    except on EX3DNotFound do ; end;
  finally FreeAndNil(Scene) end;
end;

function TTestSceneCore.SearchingForDescriptionCallback(Node: TX3DNode): Pointer;
begin
  if (Node is TAbstractViewpointNode) and
     (TAbstractViewpointNode(Node).SmartDescription = SearchingForDescription) then
    Result := Node else
    Result := nil;
end;

procedure TTestSceneCore.TestViewpointBillboardTricky;
{ Unfortunately, it cannot reproduce bug #38 for some reason...
  Probably it misses something that triggers it interactively. }
var
  Scene: TCastleScene;

  function FindViewpointByDescription(const Description: string): TAbstractViewpointNode;
  begin
    SearchingForDescription := Description;
    AssertTrue(Scene.RootNode <> nil);
    Result := TAbstractViewpointNode(
      Scene.RootNode.SearchNodes(@SearchingForDescriptionCallback, true));
    AssertTrue(Result <> nil);
  end;

var
  Viewpoint: TAbstractViewpointNode;
  SceneManager: TCastleSceneManager;
  FakeRemoveMe: TRemoveType;
begin
  SceneManager := TCastleSceneManager.Create(nil);
  try
    Scene := TCastleScene.Create(nil);
    try
      Scene.URL := 'castle-data:/city_from_bugreport_38.x3dv';
      Scene.ProcessEvents := true;
      Scene.Spatial := [ssRendering, ssDynamicCollisions];
      SceneManager.Items.Add(Scene);
      SceneManager.MainScene := Scene;

      Scene.InternalCameraChanged;
      FakeRemoveMe := rtNone;
      Scene.Update(1, FakeRemoveMe);

      Viewpoint := FindViewpointByDescription('City plan');
      Viewpoint.Bound := true;

      Scene.InternalCameraChanged;
      FakeRemoveMe := rtNone;
      Scene.Update(1, FakeRemoveMe);
    finally FreeAndNil(Scene) end;
  finally FreeAndNil(SceneManager) end;
end;

procedure TTestSceneCore.TestManifold;
var
  Scene: TCastleSceneCore;
  ManifoldEdges, BorderEdges: Cardinal;
begin
  Scene := TCastleSceneCore.Create(nil);
  try
    Scene.URL := 'castle-data:/shadow_volumes_tests/should_be_manifold.x3d';
    Scene.EdgesCount(ManifoldEdges, BorderEdges);
    AssertEquals(0, BorderEdges);
    AssertEquals(210, ManifoldEdges);
  finally FreeAndNil(Scene) end;
end;

type
  ENodeMultipleTimes = class(Exception);

procedure TTestSceneCore.NodeMultipleTimesWarning(const Category, S: string);
begin
  if Pos('is already part of another TCastleScene instance', S) <> 0 then
    raise ENodeMultipleTimes.Create('We want this warning, good: ' + S)
  else
    raise Exception.Create('Some invalid warning: ' + S);
end;

procedure TTestSceneCore.TestMultipleScenesOneNodeIncorrect;

{ Deliberately do something incorrect: place the same TX3DRootNode
  in multiple TCastleScene instances.
  Check that we make a warning about it. }

var
  Node: TX3DRootNode;
  Scene1, Scene2: TCastleScene;
begin
  ApplicationProperties.OnWarning.Add(@NodeMultipleTimesWarning);
  try
    try
      Node := nil;
      Scene1 := nil;
      Scene2 := nil;
      try
        Node := LoadNode('castle-data:/game/scene.x3d');
        Scene1 := TCastleScene.Create(nil);
        Scene2 := TCastleScene.Create(nil);
        Scene1.Load(Node, false);
        Scene2.Load(Node, false);
        raise Exception.Create('We should not get here, expected ENodeMultipleTimes on the way');
      finally
        FreeAndNil(Scene1);
        FreeAndNil(Scene2);
        // Note: you must free Node after freeing Scene1,2
        FreeAndNil(Node);
      end;
    except
      on ENodeMultipleTimes do ; { good, silence this for the sake of test }
    end;
  finally
    ApplicationProperties.OnWarning.Remove(@NodeMultipleTimesWarning);
  end;
end;

procedure TTestSceneCore.TestMultipleScenesOneNodeCorrect;
var
  Node: TX3DRootNode;
  Scene1, Scene2, SceneTemplate: TCastleScene;
begin
  // When using Static=true, it is allowed to have the same TX3DRootNode reused:

  Node := nil;
  Scene1 := nil;
  Scene2 := nil;
  try
    Node := LoadNode('castle-data:/game/scene.x3d');
    Scene1 := TCastleScene.Create(nil);
    Scene1.Static := true;
    Scene2 := TCastleScene.Create(nil);
    Scene2.Static := true;
    Scene1.Load(Node, false);
    Scene2.Load(Node, false);
  finally
    FreeAndNil(Scene1);
    FreeAndNil(Scene2);
    // Note: you must free Node after freeing Scene1,2
    FreeAndNil(Node);
  end;

  // Using DeepCopy you can overcome this limitation:

  Node := nil;
  Scene1 := nil;
  Scene2 := nil;
  try
    Node := LoadNode('castle-data:/game/scene.x3d');
    Scene1 := TCastleScene.Create(nil);
    Scene2 := TCastleScene.Create(nil);
    Scene1.Load(Node.DeepCopy as TX3DRootNode, true);
    Scene2.Load(Node.DeepCopy as TX3DRootNode, true);
  finally
    FreeAndNil(Node);
    FreeAndNil(Scene1);
    FreeAndNil(Scene2);
  end;

  // Using Clone you can overcome this limitation:

  SceneTemplate := nil;
  Scene1 := nil;
  Scene2 := nil;
  try
    SceneTemplate := TCastleScene.Create(nil);
    SceneTemplate.Load('castle-data:/game/scene.x3d');
    Scene1 := SceneTemplate.Clone(nil);
    Scene2 := SceneTemplate.Clone(nil);
  finally
    FreeAndNil(SceneTemplate);
    FreeAndNil(Scene1);
    FreeAndNil(Scene2);
  end;
end;

procedure TTestSceneCore.TestSpineUtf8Names;
var
  Scene: TCastleScene;
begin
  ApplicationProperties.OnWarning.Add(@OnWarningRaiseException);
  try
    Scene := TCastleScene.Create(nil);
    try
      Scene.Load('castle-data:/spine/uhholy_chapter_one_end/skeleton.json');
      Scene.Load('castle-data:/spine/unholy_transition/phone.json');
    finally FreeAndNil(Scene) end;
  finally
    ApplicationProperties.OnWarning.Remove(@OnWarningRaiseException);
  end;
end;

procedure TTestSceneCore.TestAnimsInSwitch;
var
  Scene: TCastleScene;
  Anims: TStrings;
begin
  Scene := TCastleScene.Create(nil);
  try
    Scene.Load('castle-data:/animation_under_switch/both.x3dv');
    Anims := Scene.AnimationsList;
    AssertTrue(Anims.IndexOf('Attack') <> -1);
    AssertTrue(Anims.IndexOf('Damaged') <> -1);
    AssertTrue(Anims.IndexOf('flying') <> -1);
    AssertTrue(Anims.IndexOf('flying_left') <> -1);
  finally FreeAndNil(Scene) end;
end;

procedure TTestSceneCore.TestLoadGzipped;

  procedure TestSphere(const Url: String);
  var
    Scene: TCastleScene;
    Shape: TShapeNode;
    Sphere: TSphereNode;
  begin
    Scene := TCastleScene.Create(nil);
    try
      Scene.Load(Url);
      AssertEquals(1, Scene.RootNode.FdChildren.Count);
      AssertTrue(Scene.RootNode.FdChildren[0] is TShapeNode);
      Shape := Scene.RootNode.FdChildren[0] as TShapeNode;
      AssertTrue(Shape.Geometry is TSphereNode);
      Sphere := Shape.Geometry as TSphereNode;
      { Special epsilon necessary to pass test on Raspberry Pi (Linux/Arm). }
      AssertSameValue(123.456, Sphere.Radius, 0.0001);
    finally FreeAndNil(Scene) end;
  end;

begin
  TestSphere('castle-data:/gzipped_x3d/sphere.wrl');
  TestSphere('castle-data:/gzipped_x3d/sphere.wrl.gz');
  TestSphere('castle-data:/gzipped_x3d/sphere.wrz');
  TestSphere('castle-data:/gzipped_x3d/sphere.x3d');
  TestSphere('castle-data:/gzipped_x3d/sphere.x3d.gz');
  TestSphere('castle-data:/gzipped_x3d/sphere.x3dv');
  TestSphere('castle-data:/gzipped_x3d/sphere.x3dv.gz');
  TestSphere('castle-data:/gzipped_x3d/sphere.x3dvz');
  TestSphere('castle-data:/gzipped_x3d/sphere.x3dz');
  TestSphere('castle-data:/gzipped_x3d/sphere_normal_extension_but_gzipped.wrl');
  TestSphere('castle-data:/gzipped_x3d/sphere_normal_extension_but_gzipped.x3dv');
end;

procedure TTestSceneCore.OnWarningFlag(const Category, S: string);
begin
  WarningFlag := true;
end;

procedure TTestSceneCore.LoadSceneRequireWarning(const Scene: TCastleSceneCore; const Url: String);
begin
  ApplicationProperties.OnWarning.Add(@OnWarningFlag);
  try
    WarningFlag := false;
    Scene.Load(Url);
    if not WarningFlag then
      Fail(Format('Expected to get some warning during loading of "%s"',
        [URIDisplay(Url)]));
  finally
    ApplicationProperties.OnWarning.Remove(@OnWarningFlag);
  end;
end;

procedure TTestSceneCore.TestStarlingAndAnchors;
var
  Scene: TCastleScene;
begin
  Scene := TCastleScene.Create(nil);
  try
    Scene.Load('castle-data:/sprite-sheets/starling_kenney_robot/character_robot_sheet.starling-xml');
    AssertEquals(45, Scene.AnimationsList.Count);
    AssertEquals(-1, Scene.AnimationsList.IndexOf('walk'));
  finally FreeAndNil(Scene) end;

  Scene := TCastleScene.Create(nil);
  try
    Scene.Load('castle-data:/sprite-sheets/starling_kenney_robot/character_robot_sheet.starling-xml#anim-naming:strict-underscore');
    AssertEquals(45, Scene.AnimationsList.Count);
    AssertEquals(-1, Scene.AnimationsList.IndexOf('walk'));
  finally FreeAndNil(Scene) end;

  Scene := TCastleScene.Create(nil);
  try
    Scene.Load('castle-data:/sprite-sheets/starling_kenney_robot/character_robot_sheet.starling-xml#fps:10,anim-naming:strict-underscore');
    AssertEquals(45, Scene.AnimationsList.Count);
    AssertEquals(-1, Scene.AnimationsList.IndexOf('walk'));
  finally FreeAndNil(Scene) end;

  Scene := TCastleScene.Create(nil);
  try
    Scene.Load('castle-data:/sprite-sheets/starling_kenney_robot/character_robot_sheet.starling-xml#anim-naming:trailing-number');
    AssertEquals(31, Scene.AnimationsList.Count);
    AssertTrue(-1 <> Scene.AnimationsList.IndexOf('walk'));
  finally FreeAndNil(Scene) end;

  Scene := TCastleScene.Create(nil);
  try
    Scene.Load('castle-data:/sprite-sheets/starling_kenney_robot/character_robot_sheet.starling-xml#fps:10,anim-naming:trailing-number');
    AssertEquals(31, Scene.AnimationsList.Count);
    AssertTrue(-1 <> Scene.AnimationsList.IndexOf('walk'));
  finally FreeAndNil(Scene) end;

  Scene := TCastleScene.Create(nil);
  try
    LoadSceneRequireWarning(Scene, 'castle-data:/sprite-sheets/starling_kenney_robot/character_robot_sheet.starling-xml#invalid-anchor,fps:10,anim-naming:trailing-number');
  finally FreeAndNil(Scene) end;

  Scene := TCastleScene.Create(nil);
  try
    LoadSceneRequireWarning(Scene, 'castle-data:/sprite-sheets/starling_kenney_robot/character_robot_sheet.starling-xml#invalid-anchor:blahblah,fps:10,anim-naming:trailing-number');
  finally FreeAndNil(Scene) end;

  Scene := TCastleScene.Create(nil);
  try
    LoadSceneRequireWarning(Scene, 'castle-data:/sprite-sheets/starling_kenney_robot/character_robot_sheet.starling-xml#fps:10,anim-naming:invalid-name');
  finally FreeAndNil(Scene) end;
end;

procedure TTestSceneCore.TestCocos;
var
  Scene: TCastleScene;
begin
  Scene := TCastleScene.Create(nil);
  try
    Scene.Load('castle-data:/sprite-sheets/cocos2d_wolf/wolf.plist');
    AssertEquals(4, Scene.AnimationsList.Count);
    AssertTrue(-1 <> Scene.AnimationsList.IndexOf('walk'));
  finally FreeAndNil(Scene) end;

  Scene := TCastleScene.Create(nil);
  try
    Scene.Load('castle-data:/sprite-sheets/cocos2d_wolf/wolf.plist#fps:10');
    AssertEquals(4, Scene.AnimationsList.Count);
    AssertTrue(-1 <> Scene.AnimationsList.IndexOf('walk'));
  finally FreeAndNil(Scene) end;

  Scene := TCastleScene.Create(nil);
  try
    LoadSceneRequireWarning(Scene, 'castle-data:/sprite-sheets/cocos2d_wolf/wolf.plist#fps:10,anim-naming:trailing-number');
    AssertEquals(4, Scene.AnimationsList.Count);
    AssertTrue(-1 <> Scene.AnimationsList.IndexOf('walk'));
  finally FreeAndNil(Scene) end;
end;

procedure TTestSceneCore.TestImageAsNode;
var
  Scene: TCastleScene;
begin
  Scene := TCastleScene.Create(nil);
  try
    Scene.Load('castle-data:/sprite-sheets/cocos2d_wolf/wolf.png');
    AssertEquals(0, Scene.AnimationsList.Count);
  finally FreeAndNil(Scene) end;

  Scene := TCastleScene.Create(nil);
  try
    Scene.Load('castle-data:/sprite-sheets/cocos2d_wolf/wolf.png#left:100,bottom:100,width:256,height:256');
    AssertEquals(0, Scene.AnimationsList.Count);
  finally FreeAndNil(Scene) end;
end;

procedure TTestSceneCore.TestPlayStopAnim;
var
  Scene: TCastleScene;
begin
  Scene := TCastleScene.Create(nil);
  try
    Scene.ProcessEvents := true;
    Scene.Load('castle-data:/spine/escape_from_the_universe_boss/boss.json');
    Scene.Exists := false; // doesn't matter for animation playing

    Scene.PlayAnimation('flying', true);
    AssertTrue(Scene.CurrentAnimation <> nil);
    AssertEquals('flying', Scene.CurrentAnimation.X3DName);

    Scene.StopAnimation;
    AssertTrue(Scene.CurrentAnimation = nil);
  finally FreeAndNil(Scene) end;
end;

procedure TTestSceneCore.TestFontStyleChanges;
var
  FontStyleNode: TFontStyleNode;
  TextNode: TTextNode;
  TextShape: TShapeNode;
  RootNode: TX3DRootNode;
  Scene: TCastleScene;
  Box: TBox3D;
begin
  FontStyleNode := TFontStyleNode.Create;

  TextNode := TTextNode.CreateWithShape(TextShape);
  TextNode.FontStyle := FontStyleNode;
  TextNode.SetString(['one line of text']);

  RootNode := TX3DRootNode.Create;
  RootNode.AddChildren(TextShape);

  Scene := TCastleScene.Create(nil);
  try
    // Scene.ProcessEvents := true; // this should work even without process events, TCastleText depends on it
    Scene.Load(RootNode, true);

    Box := Scene.BoundingBox;
    //Writeln(Box.ToString);
    AssertSameValue(1, Box.Size.Y);

    FontStyleNode.Size := 10;
    Box := Scene.BoundingBox;
    //Writeln(Box.ToString);
    AssertSameValue(10, Box.Size.Y);

    FontStyleNode.Size := 100;
    Box := Scene.BoundingBox;
    //Writeln(Box.ToString);
    AssertSameValue(100, Box.Size.Y);

  finally FreeAndNil(Scene) end;
end;

procedure TTestSceneCore.TestUnassociate;
var
  Box: TCastleBox;
begin
  ApplicationProperties.OnWarning.Add(@OnWarningRaiseException);
  try
    Box := TCastleBox.Create(nil);
    try
      Box.Material := pmUnlit;
      Box.Material := pmPhysical;
    finally FreeAndNil(Box) end;
  finally
    ApplicationProperties.OnWarning.Remove(@OnWarningRaiseException);
  end;
end;

procedure TTestSceneCore.TestUnassociate2;
var
  Shape: TShapeNode;
  NewMaterial: TMaterialNode;
  Scene: TCastleScene;
begin
  ApplicationProperties.OnWarning.Add(@OnWarningRaiseException);
  try
    Scene := TCastleScene.Create(nil);
    try
      Scene.Load('castle-data:/test_for_material_change.x3dv');
      Scene.Spatial := [ssRendering, ssDynamicCollisions];
      Scene.ProcessEvents := true;

      Shape := Scene.Node('MyShape') as TShapeNode;

      NewMaterial := TMaterialNode.Create;
      NewMaterial.Scene := Scene;
      NewMaterial.DiffuseColor := Vector3(0, 1, 1);
      Shape.Material := NewMaterial;
    finally FreeAndNil(Scene) end;
  finally
    ApplicationProperties.OnWarning.Remove(@OnWarningRaiseException);
  end;
end;

procedure TTestSceneCore.TestUnassociateChangeMaterialOneLeft;
var
  RootNode: TX3DRootNode;
  Shape1, Shape2: TShapeNode;
  OldMaterial: TMaterialNode;
  NewMaterial: TUnlitMaterialNode;
  Scene: TCastleScene;
begin
  ApplicationProperties.OnWarning.Add(@OnWarningRaiseException);
  try
    Scene := TCastleScene.Create(nil);
    try
      RootNode := TX3DRootNode.Create;

      OldMaterial := TMaterialNode.Create;

      Shape1 := TShapeNode.Create;
      Shape1.Material := OldMaterial; // will also auto-create Shape.Appearance, OK
      Shape1.Geometry := TBoxNode.Create; // anything non-nil, otherwise it's ignored in Scene.Shapes tree
      RootNode.AddChildren(Shape1);

      Shape2 := TShapeNode.Create;
      Shape2.Geometry := TBoxNode.Create; // anything non-nil, otherwise it's ignored in Scene.Shapes tree
      Shape2.Material := OldMaterial; // will also auto-create Shape.Appearance, OK
      RootNode.AddChildren(Shape2);

      Scene.Load(RootNode, true);
      Scene.Spatial := [ssRendering, ssDynamicCollisions];
      Scene.ProcessEvents := true;

      NewMaterial := TUnlitMaterialNode.Create;

      AssertTrue(OldMaterial.Scene <> nil);
      AssertTrue(NewMaterial.Scene = nil);
      AssertEquals(2, TShapeTree.AssociatedShapesCount(OldMaterial));
      AssertEquals(0, TShapeTree.AssociatedShapesCount(NewMaterial));
      AssertEquals(1, TShapeTree.AssociatedShapesCount(Shape1.Appearance));
      AssertEquals(1, TShapeTree.AssociatedShapesCount(Shape2.Appearance));

      // NewMaterial.Scene := Scene; // should work with and without this
      Shape1.Material := NewMaterial; // but leave Shape2 unchanged

      AssertEquals(1, TShapeTree.AssociatedShapesCount(OldMaterial));
      AssertEquals(1, TShapeTree.AssociatedShapesCount(NewMaterial));
      AssertEquals(1, TShapeTree.AssociatedShapesCount(Shape1.Appearance));
      AssertEquals(1, TShapeTree.AssociatedShapesCount(Shape2.Appearance));
    finally FreeAndNil(Scene) end;
  finally
    ApplicationProperties.OnWarning.Remove(@OnWarningRaiseException);
  end;
end;

procedure TTestSceneCore.TestUnassociateChangeMaterialSharedAppearance;
var
  RootNode: TX3DRootNode;
  Shape1, Shape2: TShapeNode;
  OldMaterial: TMaterialNode;
  NewMaterial: TUnlitMaterialNode;
  SharedAppearance: TAppearanceNode;
  Scene: TCastleScene;
begin
  ApplicationProperties.OnWarning.Add(@OnWarningRaiseException);
  try
    Scene := TCastleScene.Create(nil);
    try
      RootNode := TX3DRootNode.Create;

      OldMaterial := TMaterialNode.Create;
      OldMaterial.KeepExistingBegin; // otherwise it would be destroyed by assigning other node

      SharedAppearance := TAppearanceNode.Create;
      SharedAppearance.Material := OldMaterial;

      Shape1 := TShapeNode.Create;
      Shape1.Appearance := SharedAppearance;
      Shape1.Geometry := TBoxNode.Create; // anything non-nil, otherwise it's ignored in Scene.Shapes tree
      RootNode.AddChildren(Shape1);

      Shape2 := TShapeNode.Create;
      Shape2.Appearance := SharedAppearance;
      Shape2.Geometry := TBoxNode.Create; // anything non-nil, otherwise it's ignored in Scene.Shapes tree
      RootNode.AddChildren(Shape2);

      Scene.Load(RootNode, true);
      Scene.Spatial := [ssRendering, ssDynamicCollisions];
      Scene.ProcessEvents := true;

      NewMaterial := TUnlitMaterialNode.Create;

      AssertTrue(SharedAppearance.Scene <> nil);
      AssertTrue(OldMaterial.Scene <> nil);
      AssertTrue(NewMaterial.Scene = nil);
      AssertEquals(2, TShapeTree.AssociatedShapesCount(SharedAppearance));
      AssertEquals(2, TShapeTree.AssociatedShapesCount(OldMaterial));
      AssertEquals(0, TShapeTree.AssociatedShapesCount(NewMaterial));

      // NewMaterial.Scene := Scene; // should work with and without this
      Shape1.Material := NewMaterial; // equivalent to SharedAppearance.Material := NewMaterial;
      //SharedAppearance.Material := NewMaterial;

      AssertEquals(2, TShapeTree.AssociatedShapesCount(SharedAppearance));
      AssertEquals(0, TShapeTree.AssociatedShapesCount(OldMaterial));
      AssertEquals(2, TShapeTree.AssociatedShapesCount(NewMaterial));

      // OldMaterial now unused
      OldMaterial.KeepExistingEnd;
      FreeIfUnusedAndNil(OldMaterial);
      AssertTrue(OldMaterial = nil);
    finally FreeAndNil(Scene) end;
  finally
    ApplicationProperties.OnWarning.Remove(@OnWarningRaiseException);
  end;
end;

procedure TTestSceneCore.TestUnassociateChangeAppearance;
var
  RootNode: TX3DRootNode;
  Shape1, Shape2: TShapeNode;
  OldAppearance: TAppearanceNode;
  NewAppearance: TAppearanceNode;
  Scene: TCastleScene;
begin
  ApplicationProperties.OnWarning.Add(@OnWarningRaiseException);
  try
    Scene := TCastleScene.Create(nil);
    try
      RootNode := TX3DRootNode.Create;

      OldAppearance := TAppearanceNode.Create;
      OldAppearance.Material := TMaterialNode.Create;

      NewAppearance := TAppearanceNode.Create;
      NewAppearance.Material := TMaterialNode.Create;

      Shape1 := TShapeNode.Create;
      Shape1.Appearance := OldAppearance;
      Shape1.Geometry := TBoxNode.Create; // anything non-nil, otherwise it's ignored in Scene.Shapes tree
      RootNode.AddChildren(Shape1);

      Shape2 := TShapeNode.Create;
      Shape2.Appearance := OldAppearance;
      Shape2.Geometry := TBoxNode.Create; // anything non-nil, otherwise it's ignored in Scene.Shapes tree
      RootNode.AddChildren(Shape2);

      Scene.Load(RootNode, true);
      Scene.Spatial := [ssRendering, ssDynamicCollisions];
      Scene.ProcessEvents := true;

      AssertTrue(OldAppearance.Scene <> nil);
      AssertTrue(NewAppearance.Scene = nil);
      AssertEquals(2, TShapeTree.AssociatedShapesCount(OldAppearance));
      AssertEquals(0, TShapeTree.AssociatedShapesCount(NewAppearance));
      AssertEquals(2, TShapeTree.AssociatedShapesCount(OldAppearance.Material));
      AssertEquals(0, TShapeTree.AssociatedShapesCount(NewAppearance.Material));

      Shape1.Appearance := NewAppearance; // but leave Shape2 unchanged

      AssertEquals(1, TShapeTree.AssociatedShapesCount(OldAppearance));
      AssertEquals(1, TShapeTree.AssociatedShapesCount(NewAppearance));
      AssertEquals(1, TShapeTree.AssociatedShapesCount(OldAppearance.Material));
      AssertEquals(1, TShapeTree.AssociatedShapesCount(NewAppearance.Material));
    finally FreeAndNil(Scene) end;
  finally
    ApplicationProperties.OnWarning.Remove(@OnWarningRaiseException);
  end;
end;

initialization
  RegisterTest(TTestSceneCore);
end.
