{
  Copyright 2002-2018 Michalis Kamburelis.

  This file is part of "Castle Game Engine".

  "Castle Game Engine" is free software; see the file COPYING.txt,
  included in this distribution, for details about the copyright.

  "Castle Game Engine" is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

  ----------------------------------------------------------------------------
}
{$ifdef FPC}
{$ifdef read_interface}
  TAbstractCubicBezierInterpolatorNode = class(TAbstractInterpolatorNode)
  strict private
    type
      TCalculatedCurve2D = array [0..10] of TVector2;
      TCalculatedCurve2DList = {$ifdef FPC}specialize{$endif} TStructList<TCalculatedCurve2D>;
    var
      FCalculatedCurves: TCalculatedCurve2DList;
      CubicBezierValueWarningDone: boolean;

    { Like KeyRange, but looking at X coordinates of the points in Key array. }
    class function KeyRangeArray2D(Key: array of TVector2;
      const Fraction: Single; out T: Single): Integer; static;

    class function CubicBezierPercent(const T: Single;
      const ControlPoints: TVector4;
      const Curve: TCalculatedCurve2D): Single; static;

    { For a Bezier curve segment, expressed as 4D vector with the meaning
      like in Spine "curve" specification (it specifies XY values of
      2 middle cubic Bezier curve points), calculate the curve. }
    class procedure CalculatedCurve2D(const KeyValue: TVector4;
      out Curve: TCalculatedCurve2D); static;

  strict protected
    { Calculate curve value for the range inside
      FdControlPoints[ControlPointsIndex]. }
    function CubicBezierValue(
      const T: Single; const ControlPointsIndex: Integer): Single;

  protected
    function DeepCopyCore(CopyState: TX3DNodeDeepCopyState): TX3DNode; override;

  public
    destructor Destroy; override;

    { Once the FdControlPoints value is settled, call this to precalculate
      curve parameters. This makes the following interpolation using this node
      work fast. }
    procedure OptimizeControlPoints;

  {$I auto_generated_node_helpers/x3dnodes_x3dcubicbezierinterpolator.inc}
  end;

  { Basis for all nodes interpolating (animating) an array of values using cubic Bezier curve. }
  {$ifdef FPC}generic{$endif}
  TAbstractCubicBezierArrayInterpolatorNode<
    // TInterpolatedValue, // unused for now
    TKeyValue,
    TKeyValueEvent> = class(TAbstractCubicBezierInterpolatorNode)
  strict private
    function KeyValue(const Index, KeyCount: Integer): TKeyValue;
    function KeyValueLerp(const T: Single; const Index1, Index2, KeyCount: Integer): TKeyValue;
    procedure EventSet_FractionReceive(const Event: TX3DEvent; const Value: TX3DField;
      const Time: TX3DTime);
  strict protected
    procedure InterpolatorLerp(const Target: TKeyValue;
      const Fraction: Single; const F1, F2: TKeyValue;
      const Index1, Index2, ACount: Integer); virtual;
  public
    constructor Create(const AX3DName: String = ''; const ABaseUrl: String = ''); override;
    procedure CreateNode; override;

    strict private FFdKeyValue: TKeyValue;
    public property FdKeyValue: TKeyValue read FFdKeyValue;

    { Event out } { }
    strict private FEventValue_changed: TKeyValueEvent;
    public property EventValue_changed: TKeyValueEvent read FEventValue_changed;
  end;

  { Interpolate (animate) a set of 2D rotations,
    using cubic Bezier curve instead of linear interpolation.
    See https://castle-engine.io/x3d_implementation_interpolation_extensions.php . }
  TCubicBezier2DOrientationInterpolatorNode = class(TAbstractCubicBezierInterpolatorNode)
  strict private
    procedure EventSet_FractionReceive(const Event: TX3DEvent; const Value: TX3DField;
      const Time: TX3DTime);
  public
    constructor Create(const AX3DName: String = ''; const ABaseUrl: String = ''); override;
  {$I auto_generated_node_helpers/x3dnodes_cubicbezier2dorientationinterpolator.inc}
  end;

  { Interpolate (animate) a set of 3D positions,
    using cubic Bezier curve instead of linear interpolation.
    See https://castle-engine.io/x3d_implementation_interpolation_extensions.php . }
  TCubicBezierPositionInterpolatorNode = class(TAbstractCubicBezierInterpolatorNode)
  strict private
    procedure EventSet_FractionReceive(const Event: TX3DEvent; const Value: TX3DField;
      const Time: TX3DTime);
  public
    constructor Create(const AX3DName: String = ''; const ABaseUrl: String = ''); override;
  {$I auto_generated_node_helpers/x3dnodes_cubicbezierpositioninterpolator.inc}
  end;

  { Interpolate (animate) a set of 3D vertices,
    using cubic Bezier curve instead of linear interpolation.
    See https://castle-engine.io/x3d_implementation_interpolation_extensions.php . }
  TCubicBezierCoordinateInterpolatorNode = class({$ifdef FPC}specialize{$endif}
    TAbstractCubicBezierArrayInterpolatorNode<
    // TVector3, // unused for now
    TMFVec3f,
    TMFVec3fEvent>)
  {$I auto_generated_node_helpers/x3dnodes_cubicbeziercoordinateinterpolator.inc}
  end;
{$endif read_interface}

{$ifdef read_implementation}

{ TAbstractCubicBezierInterpolatorNode --------------------------------------- }

class function TAbstractCubicBezierInterpolatorNode.KeyRangeArray2D(
  Key: array of TVector2;
  const Fraction: Single; out T: Single): Integer; {$ifdef FPC}static;{$endif}
var
  KeyCount, A, B: Integer;
begin
  KeyCount := High(Key) + 1;

  Assert(KeyCount > 0);
  Assert(not IsNan(Fraction));

  if Fraction <= Key[0].Data[0] then
    Result := 0 else
  if Fraction >= Key[KeyCount - 1].Data[0] then
    Result := KeyCount else
  begin
    { Then for sure we're between two Key values.
      Note that we know that KeyCount > 1 (otherwise, Key.First = Key.Last
      so one of <= or >= comparisons above would occur; we check
      IsNan(Fraction) at the beginning to eliminate Fraction=NaN case). }
    Assert(KeyCount > 1);

    { Always A < B.
      We're considering range from Key[A].X to Key[B].X.

      Remember that we cannot actually depend on the fact that
      Key values are non-decreasing. They should be non-decreasing,
      and we have to output correct result only when they are non-decreasing,
      but we also have to terminate (with any result) in any situation.
      Reason: Key values are supplied in X3D file, so they may be broken
      in every possible way. }

    A := 0;
    B := KeyCount - 1;
    while B - A > 1 do
    begin
      Result := (A + B) div 2;
      { A < B => (A + B) < 2B => (A + B) div 2 < B => Result < B.
        Also, Result > A (the only way how Result could be = A
        would be when B = A + 1, but we eliminated this case by "while"
        condition".

        This is good, it means A < Result < B, so Result is good candidate
        for next A or B, it will for sure shorten the distance
        between A and B. }
      Assert(A < Result);
      Assert(Result < B);
      if Fraction <= Key[Result].Data[0] then
        B := Result else
        A := Result;
    end;
    Result := B;

    if Key[B].Data[0] > Key[A].Data[0] then
      T := (Fraction - Key[A].Data[0]) / (Key[B].Data[0] - Key[A].Data[0])
    else
      T := 0;
  end;
end;

class function TAbstractCubicBezierInterpolatorNode.CubicBezierPercent(
  const T: Single;
  const ControlPoints: TVector4;
  const Curve: TCalculatedCurve2D): Single; {$ifdef FPC}static;{$endif}
var
  Range: Integer;
  FractionBetweenCurvePoints: Single;
begin
  { use T as the X value, to search appropriate Y on the curve graph }
  Range := KeyRangeArray2D(Curve, T, FractionBetweenCurvePoints);

  if Range = 0 then
    Result := Curve[0].Data[1]
  else
  if Range = High(Curve) + 1 then
    Result := Curve[High(Curve)].Data[1]
  else
    Result := Lerp(FractionBetweenCurvePoints,
      Curve[Range - 1].Data[1],
      Curve[Range].Data[1]);
end;

class procedure TAbstractCubicBezierInterpolatorNode.CalculatedCurve2D(
  const KeyValue: TVector4;
  out Curve: TCalculatedCurve2D); {$ifdef FPC}static;{$endif}
var
  CurvePoints: TCubicBezier2DPoints;
  I: Integer;
begin
  CurvePoints[0] := Vector2(0, 0);
  CurvePoints[1] := Vector2(KeyValue[0], KeyValue[1]);
  CurvePoints[2] := Vector2(KeyValue[2], KeyValue[3]);
  CurvePoints[3] := Vector2(1, 1);

  { calculate Curve in 2D for curve parameter (T parameter of CubicBezier2D())
    in 0..1 }
  for I := 0 to High(Curve) do
    Curve[I] := CubicBezier2D(I / High(Curve), CurvePoints);
end;

procedure TAbstractCubicBezierInterpolatorNode.OptimizeControlPoints;
var
  I: Integer;
begin
  FreeAndNil(FCalculatedCurves);
  FCalculatedCurves := TCalculatedCurve2DList.Create;
  FCalculatedCurves.Count := FdControlPoints.Items.Count;
  for I := 0 to FdControlPoints.Items.Count - 1 do
    CalculatedCurve2D(FdControlPoints.Items.List^[I], FCalculatedCurves.List^[I]);
end;

function TAbstractCubicBezierInterpolatorNode.CubicBezierValue(
  const T: Single; const ControlPointsIndex: Integer): Single;
var
  ControlPointPtr: PVector4;
  Curve: TCalculatedCurve2D;
begin
  { Call CubicBezierPercent, using ready FCalculatedCurves
    if possible. }
  ControlPointPtr := PVector4(FdControlPoints.Items.Ptr(ControlPointsIndex));
  if (FCalculatedCurves <> nil) and
     (FCalculatedCurves.Count = FdControlPoints.Count) then
  begin
    Result := CubicBezierPercent(T, ControlPointPtr^,
      FCalculatedCurves.List^[ControlPointsIndex]);
  end else
  begin
    if not CubicBezierValueWarningDone then
    begin
      WritelnWarning('Using CubicBezierXxxInterpolator without calling OptimizeControlPoints beforehand, this is slow. Better call OptimizeControlPoints once the FdControlPoints is settled.');
      // use CubicBezierValueWarningDone to avoid spamming with warnings
      CubicBezierValueWarningDone := true;
    end;
    CalculatedCurve2D(ControlPointPtr^, Curve);
    Result := CubicBezierPercent(T, ControlPointPtr^, Curve);
  end;
end;

destructor TAbstractCubicBezierInterpolatorNode.Destroy;
begin
  FreeAndNil(FCalculatedCurves);
  inherited;
end;

function TAbstractCubicBezierInterpolatorNode.DeepCopyCore(CopyState: TX3DNodeDeepCopyState): TX3DNode;
var
  Res: TAbstractCubicBezierInterpolatorNode;
begin
  Result := inherited;
  Res := Result as TAbstractCubicBezierInterpolatorNode;
  Res.OptimizeControlPoints;
end;

{ TAbstractCubicBezierArrayInterpolatorNode --------------------------------------------- }

constructor TAbstractCubicBezierArrayInterpolatorNode {$ifndef FPC} <
  TKeyValue,
  TKeyValueEvent>{$endif} .Create(const AX3DName, ABaseUrl: String);
begin
  inherited;
  EventSet_Fraction.AddNotification(
    {$ifdef FPC}@{$endif} EventSet_FractionReceive);
end;

procedure TAbstractCubicBezierArrayInterpolatorNode {$ifndef FPC} <
  TKeyValue,
  TKeyValueEvent>{$endif} .
  CreateNode;
begin
  inherited;

  FFdKeyValue := TKeyValue.Create(Self, true, 'keyValue', []);
  AddField(FFdKeyValue);

  FEventValue_changed := TKeyValueEvent.Create(Self, 'value_changed', false);
  AddEvent(FEventValue_changed);
end;

function TAbstractCubicBezierArrayInterpolatorNode {$ifndef FPC} <
  TKeyValue,
  TKeyValueEvent>{$endif} .
  KeyValue(const Index, KeyCount: Integer): TKeyValue;
var
  FrameValues: Integer;
begin
  FrameValues := FdKeyValue.Items.Count div KeyCount;

  // We pass Self as ParentNode to
  // TKeyValue.CreateUndefined.
  // This is not required, ParentNode could be @nil and everything
  // will work Ok, but setting ParentNode allows InstantReality Logger node
  // to display "sending node" information, useful for debugging.
  Result := TKeyValue.CreateUndefined(Self, false, '');

  if (Index + 1) * FrameValues <= FdKeyValue.Items.Count then
  begin
    Result.Items.AddSubRange(FdKeyValue.Items, Index * FrameValues, FrameValues);
  end else
    WritelnWarning('VRML/X3D', Format('Not enough keyValue items for %s interpolator',
      [X3DType]));
end;

function TAbstractCubicBezierArrayInterpolatorNode {$ifndef FPC} <
  TKeyValue,
  TKeyValueEvent>{$endif} .
  KeyValueLerp(const T: Single; const Index1, Index2, KeyCount: Integer): TKeyValue;
var
  FrameValues: Integer;
begin
  // This actually knows that Index2 = Index1 + 1, but assumes only
  // Index2 > Index1

  FrameValues := FdKeyValue.Items.Count div KeyCount;
  Result := TKeyValue.CreateUndefined(Self, false, '');

  if (Index2 + 1) * FrameValues <= FdKeyValue.Items.Count then
  begin
    InterpolatorLerp(Result, T, FdKeyValue, FdKeyValue,
      Index1 * FrameValues, Index2 * FrameValues, FrameValues);
  end else
    WritelnWarning('VRML/X3D', Format('Not enough keyValue items for %s interpolator',
      [X3DType]));
end;

procedure TAbstractCubicBezierArrayInterpolatorNode {$ifndef FPC} <
  TKeyValue,
  TKeyValueEvent>{$endif} .
  EventSet_FractionReceive(const Event: TX3DEvent; const Value: TX3DField; const Time: TX3DTime);
var
  KeyCount: Integer;
  T: Single;
  OutputValue: TKeyValue;
  Range: Integer;
begin
  if not EventValue_Changed.SendNeeded then Exit;

  KeyCount := FdKey.Items.Count;
  if KeyCount = 0 then
  begin
    // Interpolator nodes containing no keys in the key field
    // shall not produce any events.
    // Moreover, "div KeyCount" would cause errors if we would try
    // to get some KeyValue or KeyValueLerp.
    Exit;
  end;

  Assert(Value is TSFFloat, 'EventSet_FractionReceive (for multiple-value field) can only process SFFloat input events');
  Assert(not IsNan((Value as TSFFloat).Value), 'EventSet_FractionReceive (for multiple-value field) cannot handle fraction = NaN');
  Range := KeyRange((Value as TSFFloat).Value, T);
  if Range = 0 then
    OutputValue := KeyValue(0, KeyCount)
  else
  if Range = KeyCount then
    OutputValue := KeyValue(KeyCount - 1, KeyCount)
  else
  begin
    if Range - 1 < FdControlPoints.Items.Count then
      T := CubicBezierValue(T, Range - 1);
    OutputValue := KeyValueLerp(T, Range - 1, Range, KeyCount);
  end;
  OutputValue.InternalPartialSend := Value.InternalPartialSend;
  try
    EventValue_Changed.Send(OutputValue, Time);
  finally
    FreeAndNil(OutputValue);
  end;
end;

procedure TAbstractCubicBezierArrayInterpolatorNode {$ifndef FPC} <
  TKeyValue,
  TKeyValueEvent>{$endif} .
  InterpolatorLerp(const Target: TKeyValue;
  const Fraction: Single; const F1, F2: TKeyValue;
  const Index1, Index2, ACount: Integer);
begin
  Target.Items.AssignLerpRange(Fraction, F1.Items, F2.Items, Index1, Index2, ACount);
end;

{ TCubicBezier2DOrientationInterpolatorNode ---------------------------------- }

constructor TCubicBezier2DOrientationInterpolatorNode.Create(const AX3DName, ABaseUrl: String);
begin
  inherited;
  EventSet_Fraction.AddNotification(
    {$ifdef FPC}@{$endif} EventSet_FractionReceive);
end;

procedure TCubicBezier2DOrientationInterpolatorNode.EventSet_FractionReceive(
  const Event: TX3DEvent; const Value: TX3DField; const Time: TX3DTime);

  function KeyValue(Index: Integer): Single;
  begin
    if Index < FdKeyValue.Items.Count then
      Result := FdKeyValue.Items.List^[Index] else
      Result := 0;
  end;

var
  T: Single;
  OutputValueAngle: Single;
  KeyCount, Range: Integer;
begin
  if not EventValue_Changed.SendNeeded then Exit;

  KeyCount := FdKey.Items.Count;
  if KeyCount = 0 then
  begin
    // Interpolator nodes containing no keys in the key field
    // shall not produce any events.
    Exit;
  end else
  begin
    Range := KeyRange((Value as TSFFloat).Value, T);
    if Range = 0 then
      OutputValueAngle := KeyValue(0) else
    if Range = KeyCount then
      OutputValueAngle := KeyValue(KeyCount - 1) else
    begin
      if Range - 1 < FdControlPoints.Items.Count then
        T := CubicBezierValue(T, Range - 1);
      OutputValueAngle := AngleLerp(T, KeyValue(Range - 1), KeyValue(Range));
    end;
  end;
  EventValue_Changed.Send(Vector4(FdAxis.Value, OutputValueAngle), Time, Value.InternalPartialSend);
end;

{ TCubicBezierPositionInterpolatorNode --------------------------------------- }

constructor TCubicBezierPositionInterpolatorNode.Create(const AX3DName, ABaseUrl: String);
begin
  inherited;
  EventSet_Fraction.AddNotification(
    {$ifdef FPC}@{$endif} EventSet_FractionReceive);
end;

procedure TCubicBezierPositionInterpolatorNode.EventSet_FractionReceive(
  const Event: TX3DEvent; const Value: TX3DField; const Time: TX3DTime);

  function KeyValue(Index: Integer): TVector3;
  begin
    if Index < FdKeyValue.Items.Count then
      Result := FdKeyValue.Items.List^[Index] else
      Result := TVector3.Zero;
  end;

var
  T: Single;
  OutputValue: TVector3;
  KeyCount, Range: Integer;
begin
  if not EventValue_Changed.SendNeeded then Exit;

  KeyCount := FdKey.Items.Count;
  if KeyCount = 0 then
  begin
    // Interpolator nodes containing no keys in the key field
    // shall not produce any events.
    Exit;
  end else
  begin
    Range := KeyRange((Value as TSFFloat).Value, T);
    if Range = 0 then
      OutputValue := KeyValue(0) else
    if Range = KeyCount then
      OutputValue := KeyValue(KeyCount - 1) else
    begin
      if Range - 1 < FdControlPoints.Items.Count then
        T := CubicBezierValue(T, Range - 1);
      OutputValue := Lerp(T, KeyValue(Range - 1), KeyValue(Range));
    end;
  end;
  EventValue_Changed.Send(OutputValue, Time, Value.InternalPartialSend);
end;

{ registration --------------------------------------------------------------- }

procedure RegisterInterpolationCubicBezierNodes;
begin
  NodesManager.RegisterNodeClasses([
    TCubicBezier2DOrientationInterpolatorNode,
    TCubicBezierPositionInterpolatorNode,
    TCubicBezierCoordinateInterpolatorNode
  ]);
end;

{$endif read_implementation}

{$endif FPC}
