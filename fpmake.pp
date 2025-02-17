{ Compile Castle Game Engine by fpmake.
  This can be used to compile and install the engine units.

  See https://castle-engine.io/fpmake
  for the detailed instructions.
}

program fpmake;

// FPC defines iOS as a separate OS since FPC 3.2.2.
{$define HAS_SEPARATE_IOS}
{$ifdef VER3_0} {$undef HAS_SEPARATE_IOS} {$endif}
{$ifdef VER3_2_0} {$undef HAS_SEPARATE_IOS} {$endif}

uses
  { It seems that FPC > 3.0.x requires thread support for FpMkUnit. }
  {$ifdef UNIX} {$ifndef VER3_0} CThreads, {$endif} {$endif}
  SysUtils, fpmkunit;

var
  P: TPackage;
  LikeIOS: boolean; //< compiling for iOS target (physical or simulator)
  Xlib: boolean; //< OS has working Xlib packages
begin
  with Installer do
  begin
    P := AddPackage('castle-game-engine');

    { Should work on AllUnixOSes, actually.
      But let's limit the list only to the OSes actually tested. }
    P.OSes := [Darwin, Linux, Freebsd, Win32, Win64, IPhoneSim, Android
      {$ifdef HAS_SEPARATE_IOS} , iOS {$endif}
    ];

    P.Options.Text := '@castle-fpc.cfg';

    { Some variables derived from Defaults.OS/CPU. }
    LikeIOS := (Defaults.OS = IPhoneSim) or
      {$ifdef HAS_SEPARATE_IOS}
      (Defaults.OS = iOS)
      {$else}
      // FPC 3.0.2 and 3.0.4 do not define AArch64
      ((Defaults.OS = Darwin) and (Defaults.CPU in [Arm {$ifndef VER3_0} , AArch64 {$endif}]))
      {$endif};
    Xlib := Defaults.OS in (AllUnixOSes - [Android]);

    { Add dependencies on FPC packages.
      These aren't really needed, as your default fpc.cfg should
      point to them anyway. They are needed only when compiling with --nofpccfg.
      Anyway, maybe this is a good place to document my dependencies
      on FPC packages --- so let's do this. }
    if (Defaults.OS <> Android) and (not LikeIOS) then
      P.Dependencies.Add('opengl');
    P.Dependencies.Add('fcl-base');
    P.Dependencies.Add('fcl-image');
    P.Dependencies.Add('fcl-xml');
    P.Dependencies.Add('fcl-process');
    P.Dependencies.Add('hash'); { CRC unit used by CastleInternalGzio }
    if Defaults.OS <> Android then
      P.Dependencies.Add('fcl-web');
    P.Dependencies.Add('pasjpeg');
    P.Dependencies.Add('paszlib'); { used by FpReadTiff, we don't use paszlib in CGE }
    P.Dependencies.Add('regexpr');
    if Xlib then
    begin
      P.Dependencies.Add('x11');
      P.Dependencies.Add('gtk2');
      P.Dependencies.Add('cairo');
    end else
    if Defaults.OS in AllWindowsOSes then
    begin
      P.Dependencies.Add('winunits-base');
      P.Dependencies.Add('winunits-jedi'); // our CastleWindow uses JwaWinUser
      P.Dependencies.Add('fcl-registry');
    end;
    {$ifndef VER2}
    {$ifndef VER3_0}
    P.Dependencies.Add('rtl-generics');
    {$endif}
    {$endif}

    { Some general variables, visible only (as far as I can see) when
      using "./fpmake manifest". }
    P.Author := 'Michalis Kamburelis';
    P.License := 'LGPL >= 2 (with static linking exception)';
    P.HomepageURL := 'https://castle-engine.io/';
    P.Email := 'michalis.kambi' + '@gmail.com'; { at least protect sources from spammers }
    P.Version := {$I src/base/castleversion.inc};

    { Add our unit groups.
      For simplicity, keep things in alphabetical order in each group. }

    { Add local version of Generics.Collections for FPC < 3.1.1 }
    {$if defined(VER3_0)}
    P.SourcePath.Add('src' + PathDelim + 'compatibility' + PathDelim + 'generics.collections' + PathDelim + 'src' + PathDelim);
    P.Targets.AddUnit('generics.collections.pas');
    P.Targets.AddUnit('generics.defaults.pas');
    P.Targets.AddUnit('generics.hashes.pas');
    P.Targets.AddUnit('generics.helpers.pas');
    P.Targets.AddUnit('generics.memoryexpanders.pas');
    P.Targets.AddUnit('generics.strings.pas');
    {$endif}

    P.SourcePath.Add('src' + PathDelim + '2d');
    P.Targets.AddUnit('castleinternalspritesheet.pas');

    P.SourcePath.Add('src' + PathDelim + '3d');
    P.Targets.AddUnit('castleboxes.pas');
    P.Targets.AddUnit('castlecameras.pas');
    P.Targets.AddUnit('castlethirdpersonnavigation.pas');
    P.Targets.AddUnit('castlecomponentserialize.pas');
    P.Targets.AddUnit('castlecubemaps.pas');
    P.Targets.AddUnit('castlefrustum.pas');
    P.Targets.AddUnit('castleinternalgeometryarrays.pas');
    P.Targets.AddUnit('castleinternaloctree.pas');
    P.Targets.AddUnit('castlenurbs.pas');
    P.Targets.AddUnit('castlequaternions.pas');
    P.Targets.AddUnit('castlerandom.pas');
    P.Targets.AddUnit('castlerays.pas');
    P.Targets.AddUnit('castlerenderingcamera.pas');
    P.Targets.AddUnit('castlesectors.pas');
    P.Targets.AddUnit('castlespacefillingcurves.pas');
    P.Targets.AddUnit('castlespheresampling.pas');
    P.Targets.AddUnit('castlesphericalharmonics.pas');
    P.Targets.AddUnit('castletransform.pas');
    P.Targets.AddUnit('castletriangles.pas');
    P.Targets.AddUnit('castletriangulate.pas');

    P.SourcePath.Add('src' + PathDelim + '3d' + PathDelim + 'opengl');
    P.Targets.AddUnit('castleinternalglshadowvolumes.pas');

    P.SourcePath.Add('src' + PathDelim + 'audio');
    P.Targets.AddUnit('castleinternalsoundfile.pas');
    P.Targets.AddUnit('castlesoundengine.pas');
    P.Targets.AddUnit('castlesoundbase.pas');
    P.Targets.AddUnit('castleinternalabstractsoundbackend.pas');
    P.Targets.AddUnit('castleinternalsoxsoundbackend.pas');

    P.SourcePath.Add('src' + PathDelim + 'audio' + PathDelim + 'fmod');
    P.Targets.AddUnit('castleinternalfmod.pas');
    P.Targets.AddUnit('castlefmodsoundbackend.pas');

    P.SourcePath.Add('src' + PathDelim + 'audio' + PathDelim + 'openal');
    P.Targets.AddUnit('castleinternalefx.pas');
    P.Targets.AddUnit('castleinternalalutils.pas');
    P.Targets.AddUnit('castleinternalopenal.pas');
    P.Targets.AddUnit('castleopenalsoundbackend.pas');

    P.SourcePath.Add('src' + PathDelim + 'audio' + PathDelim + 'ogg_vorbis');
    P.Targets.AddUnit('castleinternalogg.pas');
    P.Targets.AddUnit('castleinternalvorbiscodec.pas');
    P.Targets.AddUnit('castleinternalvorbisdecoder.pas');
    P.Targets.AddUnit('castleinternalvorbisfile.pas');

    P.SourcePath.Add('src' + PathDelim + 'deprecated_units');
    P.Targets.AddUnit('castlefontfamily.pas');
    P.Targets.AddUnit('castle2dscenemanager.pas');
    P.Targets.AddUnit('castle3d.pas');
    P.Targets.AddUnit('castlegenericlists.pas');
    P.Targets.AddUnit('castleglboxes.pas');
    P.Targets.AddUnit('castleglcontainer.pas');
    P.Targets.AddUnit('castlegoogleplaygames.pas');
    P.Targets.AddUnit('castleinternalusedeprecatedunits.pas');
    P.Targets.AddUnit('castlelocalization.pas');
    P.Targets.AddUnit('castlelocalizationfileloader.pas');
    P.Targets.AddUnit('castlerenderer.pas');
    P.Targets.AddUnit('castlerendererbasetypes.pas');
    P.Targets.AddUnit('castlescenemanager.pas');
    P.Targets.AddUnit('castlesoundallocator.pas');
    P.Targets.AddUnit('castleshaders.pas');
    P.Targets.AddUnit('castlewarnings.pas');
    if Defaults.OS in AllWindowsOSes then
      P.Targets.AddUnit('castlewindowsfonts.pas');

    P.SourcePath.Add('src' + PathDelim + 'common_includes');
    // No units inside

    P.SourcePath.Add('src' + PathDelim + 'base');
    P.Targets.AddUnit('castleapplicationproperties.pas');
    P.Targets.AddUnit('castleclassutils.pas');
    P.Targets.AddUnit('castlecolors.pas');
    P.Targets.AddUnit('castledynlib.pas');
    P.Targets.AddUnit('castlefilefilters.pas');
    P.Targets.AddUnit('castleinternalgzio.pas');
    P.Targets.AddUnit('castleinternalzlib.pas');
    P.Targets.AddUnit('castleinternalzstream.pas');
    P.Targets.AddUnit('castlelog.pas');
    P.Targets.AddUnit('castlemessaging.pas');
    P.Targets.AddUnit('castleparameters.pas');
    P.Targets.AddUnit('castleprogress.pas');
    P.Targets.AddUnit('castleprogressconsole.pas');
    P.Targets.AddUnit('castleprojection.pas');
    P.Targets.AddUnit('castlerectangles.pas');
    P.Targets.AddUnit('castlerenderoptions.pas');
    P.Targets.AddUnit('castlestreamutils.pas');
    P.Targets.AddUnit('castlestringutils.pas');
    P.Targets.AddUnit('castlesystemlanguage.pas');
    P.Targets.AddUnit('castletimeutils.pas');
    P.Targets.AddUnit('castleunicode.pas');
    P.Targets.AddUnit('castleutils.pas');
    P.Targets.AddUnit('castlevectors.pas');
    P.Targets.AddUnit('castlevectorsinternalsingle.pas');
    P.Targets.AddUnit('castlevectorsinternaldouble.pas');

    P.SourcePath.Add('src' + PathDelim + 'base' + PathDelim + 'opengl');
    P.Targets.AddUnit('castlegles.pas');
    P.Targets.AddUnit('castleglversion.pas');

    P.SourcePath.Add('src' + PathDelim + 'services');
    P.Targets.AddUnit('castleads.pas');
    P.Targets.AddUnit('castleanalytics.pas');
    P.Targets.AddUnit('castlefacebook.pas');
    P.Targets.AddUnit('castlegameservice.pas');
    P.Targets.AddUnit('castlehelpshift.pas');
    P.Targets.AddUnit('castleinapppurchases.pas');
    P.Targets.AddUnit('castlephotoservice.pas');
    P.Targets.AddUnit('castleopendocument.pas');
    P.Targets.AddUnit('castletenjin.pas');

    P.SourcePath.Add('src' + PathDelim + 'services' + PathDelim + 'opengl');
    P.Targets.AddUnit('castlegiftiz.pas');

    if Defaults.OS = Android then
    begin
      P.SourcePath.Add('src' + PathDelim + 'base' + PathDelim + 'android');
      P.Targets.AddUnit('castleandroidinternalassetmanager.pas');
      P.Targets.AddUnit('castleandroidinternalconfiguration.pas');
      P.Targets.AddUnit('castleandroidinternalinput.pas');
      P.Targets.AddUnit('castleandroidinternalkeycodes.pas');
      P.Targets.AddUnit('castleandroidinternallog.pas');
      P.Targets.AddUnit('castleandroidinternallog.pas');
      P.Targets.AddUnit('castleandroidinternallooper.pas');
      P.Targets.AddUnit('castleandroidinternalnativeactivity.pas');
      P.Targets.AddUnit('castleandroidinternalnativewindow.pas');
      P.Targets.AddUnit('castleandroidinternalrect.pas');
      P.Targets.AddUnit('castleandroidnativeappglue.pas');
    end;

    P.SourcePath.Add('src' + PathDelim + 'castlescript');
    P.Targets.AddUnit('castlecurves.pas');
    P.Targets.AddUnit('castlenoise.pas');
    P.Targets.AddUnit('castlescript.pas');
    P.Targets.AddUnit('castlescriptarrays.pas');
    P.Targets.AddUnit('castlescriptcorefunctions.pas');
    P.Targets.AddUnit('castlescriptimages.pas');
    P.Targets.AddUnit('castlescriptlexer.pas');
    P.Targets.AddUnit('castlescriptparser.pas');
    P.Targets.AddUnit('castlescriptvectors.pas');
    P.Targets.AddUnit('castlescriptxml.pas');

    P.SourcePath.Add('src' + PathDelim + 'fonts');
    P.Targets.AddUnit('castleinternalfreetype.pas');
    P.Targets.AddUnit('castleinternalfreetypeh.pas');
    P.Targets.AddUnit('castleinternalftfont.pas');
    P.Targets.AddUnit('castletexturefont_dejavusans_10.pas');
    P.Targets.AddUnit('castletexturefont_dejavusansmono_18.pas');
    P.Targets.AddUnit('castletexturefont_dejavusansmonobold_15.pas');
    P.Targets.AddUnit('castletexturefont_djvmono_20.pas');
    P.Targets.AddUnit('castletexturefont_djvmonob_20.pas');
    P.Targets.AddUnit('castletexturefont_djvmonobo_20.pas');
    P.Targets.AddUnit('castletexturefont_djvmonoo_20.pas');
    P.Targets.AddUnit('castletexturefont_djvsans_20.pas');
    P.Targets.AddUnit('castletexturefont_djvsansb_20.pas');
    P.Targets.AddUnit('castletexturefont_djvsansbo_20.pas');
    P.Targets.AddUnit('castletexturefont_djvsanso_20.pas');
    P.Targets.AddUnit('castletexturefont_djvserif_20.pas');
    P.Targets.AddUnit('castletexturefont_djvserifb_20.pas');
    P.Targets.AddUnit('castletexturefont_djvserifbi_20.pas');
    P.Targets.AddUnit('castletexturefont_djvserifi_20.pas');
    P.Targets.AddUnit('castletexturefontdata.pas');

    P.SourcePath.Add('src' + PathDelim + 'fonts' + PathDelim + 'opengl');
    P.Targets.AddUnit('castlefonts.pas');
    P.Targets.AddUnit('castleinternalrichtext.pas');

    P.SourcePath.Add('src' + PathDelim + 'game');
    P.Targets.AddUnit('castlebehaviors.pas');
    P.Targets.AddUnit('castlecreatures.pas');
    P.Targets.AddUnit('castledebugtransform.pas');
    P.Targets.AddUnit('castlegamenotifications.pas');
    P.Targets.AddUnit('castleitems.pas');
    P.Targets.AddUnit('castlelevels.pas');
    P.Targets.AddUnit('castleplayer.pas');
    P.Targets.AddUnit('castleresources.pas');
    P.Targets.AddUnit('castletransformextra.pas');

    P.SourcePath.Add('src' + PathDelim + 'images');
    P.Targets.AddUnit('castlecompositeimage.pas');
    P.Targets.AddUnit('castleimages.pas');
    P.Targets.AddUnit('castleinternalpng.pas');
    P.Targets.AddUnit('castletextureimages.pas');
    P.Targets.AddUnit('castlevideos.pas');

    P.SourcePath.Add('src' + PathDelim + 'images' + PathDelim + 'opengl');
    P.Targets.AddUnit('castleglimages.pas');
    P.Targets.AddUnit('castleglutils.pas');
    P.Targets.AddUnit('castleglshaders.pas');
    P.Targets.AddUnit('castlerendercontext.pas');

    P.SourcePath.Add('src' + PathDelim + 'files');
    P.Targets.AddUnit('castleconfig.pas');
    P.Targets.AddUnit('castledatauri.pas');
    P.Targets.AddUnit('castledownload.pas');
    P.Targets.AddUnit('castlefilesutils.pas');
    P.Targets.AddUnit('castlefindfiles.pas');
    P.Targets.AddUnit('castleinternaldirectoryinformation.pas');
    P.Targets.AddUnit('castlelocalizationgettext.pas');
    P.Targets.AddUnit('castlerecentfiles.pas');
    P.Targets.AddUnit('castleuriutils.pas');
    P.Targets.AddUnit('castlexmlcfginternal.pas');
    P.Targets.AddUnit('castlexmlconfig.pas');
    P.Targets.AddUnit('castlexmlutils.pas');

    P.SourcePath.Add('src' + PathDelim + 'physics' + PathDelim + 'kraft');
    P.Targets.AddUnit('kraft.pas');

    P.SourcePath.Add('src' + PathDelim + 'ui');
    P.Targets.AddUnit('castleinputs.pas');
    P.Targets.AddUnit('castleinternalcameragestures.pas');
    P.Targets.AddUnit('castlekeysmouse.pas');
    P.Targets.AddUnit('castleinternalpk3dconnexion.pas');
    P.Targets.AddUnit('castlejoysticks.pas');
    P.Targets.AddUnit('castleinternaljoysticksexplicit.pas');
    if Defaults.OS in AllWindowsOSes then
    begin
      P.SourcePath.Add('src' + PathDelim + 'ui' + PathDelim + 'windows');
      P.Targets.AddUnit('castleinternaltdxinput_tlb.pas');
      P.Targets.AddUnit('castleinternaljoystickswindows.pas');
    end;
    if Defaults.OS = Linux then
    begin
      P.Targets.AddUnit('castleinternaljoystickslinux.pas');
    end;

    P.SourcePath.Add('src' + PathDelim + 'ui' + PathDelim + 'opengl');
    P.Targets.AddUnit('castlecontrols.pas');
    P.Targets.AddUnit('castlecontrolsimages.pas');
    P.Targets.AddUnit('castledialogstates.pas');
    P.Targets.AddUnit('castleflasheffect.pas');
    P.Targets.AddUnit('castleinternalinspector.pas');
    P.Targets.AddUnit('castleinternalinspectorutils.pas');
    P.Targets.AddUnit('castleinternalsettings.pas');
    P.Targets.AddUnit('castlenotifications.pas');
    P.Targets.AddUnit('castleonscreenmenu.pas');
    P.Targets.AddUnit('castletiledmap.pas');
    P.Targets.AddUnit('castleuicontrols.pas');
    P.Targets.AddUnit('castleuistate.pas');

    P.SourcePath.Add('src' + PathDelim + 'window');
    P.Targets.AddUnit('castleinternalwindowmodes.pas');
    P.Targets.AddUnit('castlemessages.pas');
    P.Targets.AddUnit('castlewindowrecentfiles.pas');
    P.Targets.AddUnit('castlesoundmenu.pas');
    P.Targets.AddUnit('castlewindow.pas');
    P.Targets.AddUnit('castlewindowprogress.pas');
    if Xlib then
    begin
      P.SourcePath.Add('src' + PathDelim + 'window' + PathDelim + 'unix');
      P.Targets.AddUnit('castleinternalxlib.pas');
    end;

    P.SourcePath.Add('src' + PathDelim + 'window' + PathDelim + 'deprecated_units');
    P.Targets.AddUnit('castlewindowmodes.pas');
    P.Targets.AddUnit('castlewindowtouch.pas');

    P.SourcePath.Add('src' + PathDelim + 'x3d');
    P.Targets.AddUnit('castleinternalarraysgenerator.pas');
    P.Targets.AddUnit('castleinternalnodeinterpolator.pas');
    P.Targets.AddUnit('castleinternalnormals.pas');
    P.Targets.AddUnit('castleinternalshadowmaps.pas');
    P.Targets.AddUnit('castleinternalshapeoctree.pas');
    P.Targets.AddUnit('castleinternaltriangleoctree.pas');
    P.Targets.AddUnit('castleinternalautogenerated.pas');
    P.Targets.AddUnit('castleloadgltf.pas');
    P.Targets.AddUnit('castlematerialproperties.pas');
    P.Targets.AddUnit('castleraytracer.pas');
    P.Targets.AddUnit('castlescenecore.pas');
    P.Targets.AddUnit('castleshapeinternalshadowvolumes.pas');
    P.Targets.AddUnit('castleshapes.pas');
    P.Targets.AddUnit('castleterrain.pas');
    P.Targets.AddUnit('x3dcamerautils.pas');
    P.Targets.AddUnit('x3dfields.pas');
    P.Targets.AddUnit('castleinternalx3dlexer.pas');
    P.Targets.AddUnit('x3dload.pas');
    P.Targets.AddUnit('x3dloadinternalcollada.pas');
    P.Targets.AddUnit('x3dloadinternalgeo.pas');
    P.Targets.AddUnit('x3dloadinternalgltf.pas');
    P.Targets.AddUnit('x3dloadinternalmd3.pas');
    P.Targets.AddUnit('x3dloadinternalobj.pas');
    P.Targets.AddUnit('x3dloadinternal3ds.pas');
    P.Targets.AddUnit('x3dloadinternalspine.pas');
    P.Targets.AddUnit('x3dloadinternalstl.pas');
    P.Targets.AddUnit('x3dloadinternalutils.pas');
    P.Targets.AddUnit('x3dnodes.pas');
    P.Targets.AddUnit('x3dtime.pas');
    P.Targets.AddUnit('x3dtriangles.pas');
    P.Targets.AddUnit('x3dcastlescript.pas');

    P.SourcePath.Add('src' + PathDelim + 'x3d' + PathDelim + 'opengl');
    P.Targets.AddUnit('castleglcubemaps.pas');
    P.Targets.AddUnit('castleinternalbackground.pas');
    P.Targets.AddUnit('castleinternalbatchshapes.pas');
    P.Targets.AddUnit('castleinternalrenderer.pas');
    P.Targets.AddUnit('castlerendererinternallights.pas');
    P.Targets.AddUnit('castlerendererinternalshader.pas');
    P.Targets.AddUnit('castlerendererinternaltextureenv.pas');
    P.Targets.AddUnit('castlescene.pas');
    P.Targets.AddUnit('castlesceneinternalblending.pas');
    P.Targets.AddUnit('castlesceneinternalocclusion.pas');
    P.Targets.AddUnit('castlesceneinternalshape.pas');
    P.Targets.AddUnit('castlescreeneffects.pas');
    P.Targets.AddUnit('castleshapeinternalrendershadowvolumes.pas');
    P.Targets.AddUnit('castleviewport.pas');

    P.SourcePath.Add('src' + PathDelim + 'pasgltf');
    P.Targets.AddUnit('PasDblStrUtils.pas');
    P.Targets.AddUnit('PasGLTF.pas');
    P.Targets.AddUnit('PasJSON.pas');

    { Vampyre Imaging Library.
      We do not list particular units, as it simpler, and listing units is not necessary. }
    P.SourcePath.Add('src' + PathDelim + 'vampyre_imaginglib' + PathDelim + 'src' + PathDelim + 'Source');
    P.SourcePath.Add('src' + PathDelim + 'vampyre_imaginglib' + PathDelim + 'src' + PathDelim + 'Source' + PathDelim + 'JpegLib');
    P.SourcePath.Add('src' + PathDelim + 'vampyre_imaginglib' + PathDelim + 'src' + PathDelim + 'Source' + PathDelim + 'ZLib');
    P.SourcePath.Add('src' + PathDelim + 'vampyre_imaginglib' + PathDelim + 'src' + PathDelim + 'Extras' + PathDelim + 'Extensions');
    P.SourcePath.Add('src' + PathDelim + 'vampyre_imaginglib' + PathDelim + 'src' + PathDelim + 'Extensions' + PathDelim + 'J2KObjects');
    P.SourcePath.Add('src' + PathDelim + 'vampyre_imaginglib' + PathDelim + 'src' + PathDelim + 'Extensions' + PathDelim + 'LibTiff');
    P.SourcePath.Add('src' + PathDelim + 'vampyre_imaginglib' + PathDelim + 'src' + PathDelim + 'Extensions');

    Run;
  end;
end.
