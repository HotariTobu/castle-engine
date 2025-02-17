{%MainUnit castlecontrols.pas}
{
  Copyright 2018-2018 Michalis Kamburelis.

  This file is part of "Castle Game Engine".

  "Castle Game Engine" is free software; see the file COPYING.txt,
  included in this distribution, for details about the copyright.

  "Castle Game Engine" is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

  ----------------------------------------------------------------------------
}

{$ifdef read_interface}

  { Contents of this user-interface control are loaded from an indicated file
    (by the @link(URL) property).

    The file should be in the format created by Castle Game Engine Editor
    (see CastleComponentSerialize unit) with .castle-user-interface extension. }
  TCastleDesign = class(TCastleUserInterface)
  strict private
    FDesign: TCastleUserInterface;
    FDesignObserver: TFreeNotificationObserver;
    FURL: String;
    FStretchWhenNotLoaded: Boolean;
    procedure SetURL(const Value: String);
    function GetStretch: Boolean;
    procedure SetStretch(const Value: Boolean);
    procedure DesignFreeNotification(const Sender: TFreeNotificationObserver);
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    function PropertySections(const PropertyName: String): TPropertySections; override;
  published
    { Load file with the user interface design.
      The file should be in the format created by Castle Game Engine Editor
      (see CastleComponentSerialize unit) with .castle-user-interface extension.
      Setting this property automatically unloads the previous design,
      and loads a new one (if the value is <> '').

      After loading a design, you can use FindComponent or
      @link(TComponentHelper.FindRequiredComponent) to find the components inside.
      The owner of the design is this TCastleDesign instance. So e.g. this works:

      @longCode(#
      var
        MyDesign: TCastleDesign;
        MyButton: TCastleButton;
      begin
        MyDesign := TCastleDesign.Create(...);
        MyDesign.URL := 'castle-data:/my_user_interface.castle-user-interface';
        MyButton := MyDesign.FindRequiredComponent('MyButton') as TCastleButton;
        MyButton.OnClick := ...;
      end;
      #)
    }
    property URL: String read FURL write SetURL;

    { Whether the loaded component (from @link(URL)) fills the rectangle
      of this TCastleDesign instance.

      By default this is @true, which makes sense if the loaded component
      can be freely stretched. In this case, the loaded component will have
      @link(FullSize) set to @true, so it fills this TCastleDesign instance.
      And you can control the size of everything by controlling the size
      of this TCastleDesign instance.

      You can set this to @false if the loaded component should not
      be arbitrarily stretched. E.g. maybe it is a TCastleImageControl
      with @link(TCastleImageControl.Stretch) = @true.
      Maybe it is TCastleButton with @link(TCastleButton.AutoSize) = @true.
      While every component can be forced to be stretched (by setting FullSize
      to @true), it may look bad in some circumstances.
      In such case, you should set this property to @false.
      You can also set @link(AutoSizeToChildren) to @true, to adjust the size of this
      TCastleDesign instance to the child.
    }
    property Stretch: Boolean read GetStretch write SetStretch default true;
  end;

{$endif read_interface}

{$ifdef read_implementation}

{ TCastleDesign -------------------------------------------------------------- }

constructor TCastleDesign.Create(AOwner: TComponent);
begin
  inherited;
  FDesignObserver := TFreeNotificationObserver.Create(Self);
  FDesignObserver.OnFreeNotification := {$ifdef FPC}@{$endif}DesignFreeNotification;
  FStretchWhenNotLoaded := true;
end;

destructor TCastleDesign.Destroy;
begin
  inherited;
end;

procedure TCastleDesign.DesignFreeNotification(const Sender: TFreeNotificationObserver);
begin
  FDesign := nil;
end;

procedure TCastleDesign.SetURL(const Value: String);
begin
  if FURL <> Value then
  begin
    if FDesign <> nil then
    begin
      FStretchWhenNotLoaded := FDesign.FullSize;
      FreeAndNil(FDesign);
    end;

    FURL := Value;

    if Value <> '' then
    begin
      try
        FDesign := UserInterfaceLoad(Value, Self);
      except
        { If loading design file failed, and we're inside CGE editor,
          merely report a warning. This allows deserializing in CGE editor
          designs with broken URLs. }
        on E: Exception do
        begin
          if CastleDesignMode then
          begin
            WritelnWarning('TCastleDesign', 'Failed to load design "%s": %s', [URIDisplay(URL), ExceptMessage(E)]);
            Exit;
          end else
            raise;
        end;
      end;

      { This prevents this child from
        - being serialized (in case TCastleDesign is placed inside
          a hierachy saved using UserInterfaceSave. Only URL should be saved.)
        - or even be visible in the hierachy of castle-editor.
      }
      FDesign.SetTransient;
      FDesign.FullSize := FStretchWhenNotLoaded;
      FDesignObserver.Observed := FDesign;
      InsertFront(FDesign);
    end;
  end;
end;

function TCastleDesign.GetStretch: Boolean;
begin
  { Keep this property synchronized with FDesign.FullSize, when FDesign exists.
    This way when user changes FDesign.FullSize directly,
    then the TCastleDesign.Stretch property also changes automatically. }
  if FDesign <> nil then
    Result := FDesign.FullSize
  else
    Result := FStretchWhenNotLoaded;
end;

procedure TCastleDesign.SetStretch(const Value: Boolean);
begin
  if FDesign <> nil then
    FDesign.FullSize := Value
  else
    FStretchWhenNotLoaded := Value;
end;

function TCastleDesign.PropertySections(
  const PropertyName: String): TPropertySections;
begin
  if (PropertyName = 'URL') or
     (PropertyName = 'Stretch') then
    Result := [psBasic]
  else
    Result := inherited PropertySections(PropertyName);
end;

{$endif read_implementation}
