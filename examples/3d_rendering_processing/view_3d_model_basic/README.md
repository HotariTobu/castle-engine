# Basic Application To View 3D Model

Demo how to load and render a 3D model. This is just a single program source file (`view_3d_model_basic.dpr`).

This presents the simplest code that manually sets up

- TCastleWindowBase (window where Castle Game Engine can work)
- TCastleViewport
- TCastleScene

If you want to create a 3D viewer application yourself, we highly recommend starting from the Castle Game Engine editor _"New Project -> 3D Model Viewer"_ template, and thus have something cross-platform and with a UI designed in CGE editor. This demo presents a different approach, more manual, just to show that we can: this example is *not* designed using CGE editor.

Using [Castle Game Engine](https://castle-engine.io/).

## Building

Compile by:

- [CGE editor](https://castle-engine.io/manual_editor.php). Just use menu item _"Compile"_.

- Or use [CGE command-line build tool](https://castle-engine.io/build_tool). Run `castle-engine compile` in this directory.

- Or use [Lazarus](https://www.lazarus-ide.org/). Open in Lazarus `cars_demo_standalone.lpi` file and compile / run from Lazarus. Make sure to first register [CGE Lazarus packages](https://castle-engine.io/documentation.php).
