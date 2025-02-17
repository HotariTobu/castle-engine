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
    function GetAddress: String;
    procedure SetAddress(const Value: String);
    function GetApplicationID: Integer;
    procedure SetApplicationID(const Value: Integer);
    function GetEntityID: Integer;
    procedure SetEntityID(const Value: Integer);
    function GetMulticastRelayHost: String;
    procedure SetMulticastRelayHost(const Value: String);
    function GetMulticastRelayPort: Integer;
    procedure SetMulticastRelayPort(const Value: Integer);
    function GetNetworkMode: TDISNetworkMode;
    procedure SetNetworkMode(const Value: TDISNetworkMode);
    function GetPort: Integer;
    procedure SetPort(const Value: Integer);
    function GetRadioID: Integer;
    procedure SetRadioID(const Value: Integer);
    function GetReadInterval: Single;
    procedure SetReadInterval(const Value: Single);
    function GetReceivedPower: Single;
    procedure SetReceivedPower(const Value: Single);
    function GetReceiverState: Integer;
    procedure SetReceiverState(const Value: Integer);
    function GetRtpHeaderExpected: Boolean;
    procedure SetRtpHeaderExpected(const Value: Boolean);
    function GetSiteID: Integer;
    procedure SetSiteID(const Value: Integer);
    function GetTransmitterApplicationID: Integer;
    procedure SetTransmitterApplicationID(const Value: Integer);
    function GetTransmitterEntityID: Integer;
    procedure SetTransmitterEntityID(const Value: Integer);
    function GetTransmitterRadioID: Integer;
    procedure SetTransmitterRadioID(const Value: Integer);
    function GetTransmitterSiteID: Integer;
    procedure SetTransmitterSiteID(const Value: Integer);
    function GetWhichGeometry: Integer;
    procedure SetWhichGeometry(const Value: Integer);
    function GetWriteInterval: Single;
    procedure SetWriteInterval(const Value: Single);
    function GetBBox: TBox3D;
    procedure SetBBox(const Value: TBox3D);
  public
    procedure CreateNode; override;
    class function ClassX3DType: string; override;

    strict private FFdAddress: TSFString;
    { X3D field "address". } { }
    public property FdAddress: TSFString read FFdAddress;
    { X3D field "address". } { }
    property Address: String read GetAddress write SetAddress;

    strict private FFdApplicationID: TSFInt32;
    { X3D field "applicationID". } { }
    public property FdApplicationID: TSFInt32 read FFdApplicationID;
    { X3D field "applicationID". } { }
    property ApplicationID: Integer read GetApplicationID write SetApplicationID;

    strict private FFdEntityID: TSFInt32;
    { X3D field "entityID". } { }
    public property FdEntityID: TSFInt32 read FFdEntityID;
    { X3D field "entityID". } { }
    property EntityID: Integer read GetEntityID write SetEntityID;

    strict private FFdMulticastRelayHost: TSFString;
    { X3D field "multicastRelayHost". } { }
    public property FdMulticastRelayHost: TSFString read FFdMulticastRelayHost;
    { X3D field "multicastRelayHost". } { }
    property MulticastRelayHost: String read GetMulticastRelayHost write SetMulticastRelayHost;

    strict private FFdMulticastRelayPort: TSFInt32;
    { X3D field "multicastRelayPort". } { }
    public property FdMulticastRelayPort: TSFInt32 read FFdMulticastRelayPort;
    { X3D field "multicastRelayPort". } { }
    property MulticastRelayPort: Integer read GetMulticastRelayPort write SetMulticastRelayPort;

    strict private FFdNetworkMode: TSFStringEnum;
    { X3D field "networkMode". } { }
    public property FdNetworkMode: TSFStringEnum read FFdNetworkMode;
    { X3D field "networkMode". } { }
    property NetworkMode: TDISNetworkMode read GetNetworkMode write SetNetworkMode;

    strict private FFdPort: TSFInt32;
    { X3D field "port". } { }
    public property FdPort: TSFInt32 read FFdPort;
    { X3D field "port". } { }
    property Port: Integer read GetPort write SetPort;

    strict private FFdRadioID: TSFInt32;
    { X3D field "radioID". } { }
    public property FdRadioID: TSFInt32 read FFdRadioID;
    { X3D field "radioID". } { }
    property RadioID: Integer read GetRadioID write SetRadioID;

    strict private FFdReadInterval: TSFFloat;
    { X3D field "readInterval". } { }
    public property FdReadInterval: TSFFloat read FFdReadInterval;
    { X3D field "readInterval". } { }
    property ReadInterval: Single read GetReadInterval write SetReadInterval;

    strict private FFdReceivedPower: TSFFloat;
    { X3D field "receivedPower". } { }
    public property FdReceivedPower: TSFFloat read FFdReceivedPower;
    { X3D field "receivedPower". } { }
    property ReceivedPower: Single read GetReceivedPower write SetReceivedPower;

    strict private FFdReceiverState: TSFInt32;
    { X3D field "receiverState". } { }
    public property FdReceiverState: TSFInt32 read FFdReceiverState;
    { X3D field "receiverState". } { }
    property ReceiverState: Integer read GetReceiverState write SetReceiverState;

    strict private FFdRtpHeaderExpected: TSFBool;
    { X3D field "rtpHeaderExpected". } { }
    public property FdRtpHeaderExpected: TSFBool read FFdRtpHeaderExpected;
    { X3D field "rtpHeaderExpected". } { }
    property RtpHeaderExpected: Boolean read GetRtpHeaderExpected write SetRtpHeaderExpected;

    strict private FFdSiteID: TSFInt32;
    { X3D field "siteID". } { }
    public property FdSiteID: TSFInt32 read FFdSiteID;
    { X3D field "siteID". } { }
    property SiteID: Integer read GetSiteID write SetSiteID;

    strict private FFdTransmitterApplicationID: TSFInt32;
    { X3D field "transmitterApplicationID". } { }
    public property FdTransmitterApplicationID: TSFInt32 read FFdTransmitterApplicationID;
    { X3D field "transmitterApplicationID". } { }
    property TransmitterApplicationID: Integer read GetTransmitterApplicationID write SetTransmitterApplicationID;

    strict private FFdTransmitterEntityID: TSFInt32;
    { X3D field "transmitterEntityID". } { }
    public property FdTransmitterEntityID: TSFInt32 read FFdTransmitterEntityID;
    { X3D field "transmitterEntityID". } { }
    property TransmitterEntityID: Integer read GetTransmitterEntityID write SetTransmitterEntityID;

    strict private FFdTransmitterRadioID: TSFInt32;
    { X3D field "transmitterRadioID". } { }
    public property FdTransmitterRadioID: TSFInt32 read FFdTransmitterRadioID;
    { X3D field "transmitterRadioID". } { }
    property TransmitterRadioID: Integer read GetTransmitterRadioID write SetTransmitterRadioID;

    strict private FFdTransmitterSiteID: TSFInt32;
    { X3D field "transmitterSiteID". } { }
    public property FdTransmitterSiteID: TSFInt32 read FFdTransmitterSiteID;
    { X3D field "transmitterSiteID". } { }
    property TransmitterSiteID: Integer read GetTransmitterSiteID write SetTransmitterSiteID;

    strict private FFdWhichGeometry: TSFInt32;
    { X3D field "whichGeometry". } { }
    public property FdWhichGeometry: TSFInt32 read FFdWhichGeometry;
    { X3D field "whichGeometry". } { }
    property WhichGeometry: Integer read GetWhichGeometry write SetWhichGeometry;

    strict private FFdWriteInterval: TSFFloat;
    { X3D field "writeInterval". } { }
    public property FdWriteInterval: TSFFloat read FFdWriteInterval;
    { X3D field "writeInterval". } { }
    property WriteInterval: Single read GetWriteInterval write SetWriteInterval;

    strict private FEventIsNetworkReader: TSFBoolEvent;
    { X3D out event "isNetworkReader". } { }
    public property EventIsNetworkReader: TSFBoolEvent read FEventIsNetworkReader;

    strict private FEventIsNetworkWriter: TSFBoolEvent;
    { X3D out event "isNetworkWriter". } { }
    public property EventIsNetworkWriter: TSFBoolEvent read FEventIsNetworkWriter;

    strict private FEventIsRtpHeaderHeard: TSFBoolEvent;
    { X3D out event "isRtpHeaderHeard". } { }
    public property EventIsRtpHeaderHeard: TSFBoolEvent read FEventIsRtpHeaderHeard;

    strict private FEventIsStandAlone: TSFBoolEvent;
    { X3D out event "isStandAlone". } { }
    public property EventIsStandAlone: TSFBoolEvent read FEventIsStandAlone;

    strict private FEventTimestamp: TSFTimeEvent;
    { X3D out event "timestamp". } { }
    public property EventTimestamp: TSFTimeEvent read FEventTimestamp;

    strict private FFdBboxCenter: TSFVec3f;
    { X3D field "bboxCenter". } { }
    public property FdBboxCenter: TSFVec3f read FFdBboxCenter;
    { X3D fields "bboxCenter" and "bboxSize" are get/set as TBox3D. } { }
    property BBox: TBox3D read GetBBox write SetBBox;

    strict private FFdBboxSize: TSFVec3f;
    { X3D field "bboxSize". } { }
    public property FdBboxSize: TSFVec3f read FFdBboxSize;

{$endif read_interface}

{$ifdef read_implementation}

{ TReceiverPduNode ----------------------------------------------- }

function TReceiverPduNode.GetAddress: String;
begin
  Result := FdAddress.Value;
end;

procedure TReceiverPduNode.SetAddress(const Value: String);
begin
  FdAddress.Send(Value);
end;

function TReceiverPduNode.GetApplicationID: Integer;
begin
  Result := FdApplicationID.Value;
end;

procedure TReceiverPduNode.SetApplicationID(const Value: Integer);
begin
  FdApplicationID.Send(Value);
end;

function TReceiverPduNode.GetEntityID: Integer;
begin
  Result := FdEntityID.Value;
end;

procedure TReceiverPduNode.SetEntityID(const Value: Integer);
begin
  FdEntityID.Send(Value);
end;

function TReceiverPduNode.GetMulticastRelayHost: String;
begin
  Result := FdMulticastRelayHost.Value;
end;

procedure TReceiverPduNode.SetMulticastRelayHost(const Value: String);
begin
  FdMulticastRelayHost.Send(Value);
end;

function TReceiverPduNode.GetMulticastRelayPort: Integer;
begin
  Result := FdMulticastRelayPort.Value;
end;

procedure TReceiverPduNode.SetMulticastRelayPort(const Value: Integer);
begin
  FdMulticastRelayPort.Send(Value);
end;

function TReceiverPduNode.GetNetworkMode: TDISNetworkMode;
begin
  Result := TDISNetworkMode(FdNetworkMode.EnumValue);
end;

procedure TReceiverPduNode.SetNetworkMode(const Value: TDISNetworkMode);
begin
  FdNetworkMode.SendEnumValue(Ord(Value));
end;

function TReceiverPduNode.GetPort: Integer;
begin
  Result := FdPort.Value;
end;

procedure TReceiverPduNode.SetPort(const Value: Integer);
begin
  FdPort.Send(Value);
end;

function TReceiverPduNode.GetRadioID: Integer;
begin
  Result := FdRadioID.Value;
end;

procedure TReceiverPduNode.SetRadioID(const Value: Integer);
begin
  FdRadioID.Send(Value);
end;

function TReceiverPduNode.GetReadInterval: Single;
begin
  Result := FdReadInterval.Value;
end;

procedure TReceiverPduNode.SetReadInterval(const Value: Single);
begin
  FdReadInterval.Send(Value);
end;

function TReceiverPduNode.GetReceivedPower: Single;
begin
  Result := FdReceivedPower.Value;
end;

procedure TReceiverPduNode.SetReceivedPower(const Value: Single);
begin
  FdReceivedPower.Send(Value);
end;

function TReceiverPduNode.GetReceiverState: Integer;
begin
  Result := FdReceiverState.Value;
end;

procedure TReceiverPduNode.SetReceiverState(const Value: Integer);
begin
  FdReceiverState.Send(Value);
end;

function TReceiverPduNode.GetRtpHeaderExpected: Boolean;
begin
  Result := FdRtpHeaderExpected.Value;
end;

procedure TReceiverPduNode.SetRtpHeaderExpected(const Value: Boolean);
begin
  FdRtpHeaderExpected.Send(Value);
end;

function TReceiverPduNode.GetSiteID: Integer;
begin
  Result := FdSiteID.Value;
end;

procedure TReceiverPduNode.SetSiteID(const Value: Integer);
begin
  FdSiteID.Send(Value);
end;

function TReceiverPduNode.GetTransmitterApplicationID: Integer;
begin
  Result := FdTransmitterApplicationID.Value;
end;

procedure TReceiverPduNode.SetTransmitterApplicationID(const Value: Integer);
begin
  FdTransmitterApplicationID.Send(Value);
end;

function TReceiverPduNode.GetTransmitterEntityID: Integer;
begin
  Result := FdTransmitterEntityID.Value;
end;

procedure TReceiverPduNode.SetTransmitterEntityID(const Value: Integer);
begin
  FdTransmitterEntityID.Send(Value);
end;

function TReceiverPduNode.GetTransmitterRadioID: Integer;
begin
  Result := FdTransmitterRadioID.Value;
end;

procedure TReceiverPduNode.SetTransmitterRadioID(const Value: Integer);
begin
  FdTransmitterRadioID.Send(Value);
end;

function TReceiverPduNode.GetTransmitterSiteID: Integer;
begin
  Result := FdTransmitterSiteID.Value;
end;

procedure TReceiverPduNode.SetTransmitterSiteID(const Value: Integer);
begin
  FdTransmitterSiteID.Send(Value);
end;

function TReceiverPduNode.GetWhichGeometry: Integer;
begin
  Result := FdWhichGeometry.Value;
end;

procedure TReceiverPduNode.SetWhichGeometry(const Value: Integer);
begin
  FdWhichGeometry.Send(Value);
end;

function TReceiverPduNode.GetWriteInterval: Single;
begin
  Result := FdWriteInterval.Value;
end;

procedure TReceiverPduNode.SetWriteInterval(const Value: Single);
begin
  FdWriteInterval.Send(Value);
end;

function TReceiverPduNode.GetBBox: TBox3D;
begin
  Result := TBox3D.FromCenterSize(FdBBoxCenter.Value, FdBBoxSize.Value);
end;

procedure TReceiverPduNode.SetBBox(const Value: TBox3D);
var
  ValueCenter, ValueSize: TVector3;
begin
  Value.ToCenterSize(ValueCenter, ValueSize);
  FdBBoxCenter.Send(ValueCenter);
  FdBBoxSize.Send(ValueSize);
end;

class function TReceiverPduNode.ClassX3DType: String;
begin
  Result := 'ReceiverPdu';
end;

procedure TReceiverPduNode.CreateNode;
begin
  inherited;

  FFdAddress := TSFString.Create(Self, True, 'address', 'localhost');
   FdAddress.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdAddress);

  FFdApplicationID := TSFInt32.Create(Self, True, 'applicationID', 1);
   FdApplicationID.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdApplicationID);

  FFdEntityID := TSFInt32.Create(Self, True, 'entityID', 0);
   FdEntityID.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdEntityID);

  FFdMulticastRelayHost := TSFString.Create(Self, True, 'multicastRelayHost', '');
   FdMulticastRelayHost.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdMulticastRelayHost);

  FFdMulticastRelayPort := TSFInt32.Create(Self, True, 'multicastRelayPort', 0);
   FdMulticastRelayPort.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdMulticastRelayPort);

  FFdNetworkMode := TSFStringEnum.Create(Self, True, 'networkMode', DISNetworkModeNames, Ord(nmStandAlone));
   FdNetworkMode.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdNetworkMode);

  FFdPort := TSFInt32.Create(Self, True, 'port', 0);
   FdPort.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdPort);

  FFdRadioID := TSFInt32.Create(Self, True, 'radioID', 0);
   FdRadioID.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdRadioID);

  FFdReadInterval := TSFFloat.Create(Self, True, 'readInterval', 0.1);
   FdReadInterval.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdReadInterval);

  FFdReceivedPower := TSFFloat.Create(Self, True, 'receivedPower', 0.0);
   FdReceivedPower.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdReceivedPower);

  FFdReceiverState := TSFInt32.Create(Self, True, 'receiverState', 0);
   FdReceiverState.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdReceiverState);

  FFdRtpHeaderExpected := TSFBool.Create(Self, True, 'rtpHeaderExpected', false);
   FdRtpHeaderExpected.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdRtpHeaderExpected);

  FFdSiteID := TSFInt32.Create(Self, True, 'siteID', 0);
   FdSiteID.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdSiteID);

  FFdTransmitterApplicationID := TSFInt32.Create(Self, True, 'transmitterApplicationID', 1);
   FdTransmitterApplicationID.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdTransmitterApplicationID);

  FFdTransmitterEntityID := TSFInt32.Create(Self, True, 'transmitterEntityID', 0);
   FdTransmitterEntityID.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdTransmitterEntityID);

  FFdTransmitterRadioID := TSFInt32.Create(Self, True, 'transmitterRadioID', 0);
   FdTransmitterRadioID.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdTransmitterRadioID);

  FFdTransmitterSiteID := TSFInt32.Create(Self, True, 'transmitterSiteID', 0);
   FdTransmitterSiteID.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdTransmitterSiteID);

  FFdWhichGeometry := TSFInt32.Create(Self, True, 'whichGeometry', 1);
   FdWhichGeometry.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdWhichGeometry);

  FFdWriteInterval := TSFFloat.Create(Self, True, 'writeInterval', 1.0);
   FdWriteInterval.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdWriteInterval);

  FEventIsNetworkReader := TSFBoolEvent.Create(Self, 'isNetworkReader', false);
  AddEvent(FEventIsNetworkReader);

  FEventIsNetworkWriter := TSFBoolEvent.Create(Self, 'isNetworkWriter', false);
  AddEvent(FEventIsNetworkWriter);

  FEventIsRtpHeaderHeard := TSFBoolEvent.Create(Self, 'isRtpHeaderHeard', false);
  AddEvent(FEventIsRtpHeaderHeard);

  FEventIsStandAlone := TSFBoolEvent.Create(Self, 'isStandAlone', false);
  AddEvent(FEventIsStandAlone);

  FEventTimestamp := TSFTimeEvent.Create(Self, 'timestamp', false);
  AddEvent(FEventTimestamp);

  FFdBboxCenter := TSFVec3f.Create(Self, False, 'bboxCenter', Vector3(0, 0, 0));
   FdBboxCenter.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdBboxCenter);

  FFdBboxSize := TSFVec3f.Create(Self, False, 'bboxSize', Vector3(-1, -1, -1));
   FdBboxSize.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdBboxSize);
end;

{$endif read_implementation}
