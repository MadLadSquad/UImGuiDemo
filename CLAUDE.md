# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## What this repository is

UImGuiDemo is the web showcase for UntitledImGuiFramework, deployed at <https://uimgui.madladsquad.com>. It is a standard framework project that lives at `Projects/UImGuiDemo/` inside a framework checkout, but it is **its own git repository**. The framework-level `../../CLAUDE.md` covers framework architecture, conventions and error-handling rules. Everything here is specific to this repo.

WASM is the primary target. Native builds work too, but CI only builds and deploys the WASM version.

## What is tracked vs. generated

Only `Source/`, `Config/`, `uvproj.yaml` and `.github/` are committed. The following are gitignored and must not be committed or hand-edited:

- `Framework`, `UVKBuildTool`: symlinks to the enclosing framework checkout.
- `Generated/`, `CMakeLists.txt`, `export.sh`: produced by UVKBuildTool.
- `Source/UImGuiRendererExamples`, `bgfx.cmake/`: optional local checkouts for experimenting with custom renderers. They are not part of the demo.

In this repo, `Config/` and `Content/` are real directories, not symlinks to the framework templates. Edits to them change only this project.

## Build commands

After changing `uvproj.yaml` (for example, toggling modules), regenerate the build files:
```bash
cd UVKBuildTool/build && ./UVKBuildTool --generate ../../Projects/UImGuiDemo
```

WASM build (this matches CI in `.github/workflows/static.yml`):
```bash
mkdir -p build && cd build
emcmake cmake .. -DCMAKE_BUILD_TYPE=RELEASE
make -j$(nproc)
emrun UImGuiDemo.html
```
CI then renames `UImGuiDemo.html` to `index.html` and copies `Config/WASM/*` (the custom `index.html`, `main.css`, `favicon.png`, `pre.js`, `post.js`) next to it. `ENABLE_PRE_SCRIPT`/`ENABLE_POST_SCRIPT` are turned on in `Config/cmake/UImGuiDemo.cmake`.

Native build: use the same steps with plain `cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=RELEASE`.

The project has no tests and no linter.

## CI / release

- **`static.yml`** deploys to GitHub Pages on every push to `master`, nightly, and on manual dispatch. It clones the **latest framework `master`** instead of a pinned version, so the demo must keep compiling against framework HEAD. A breaking framework API change shows up here as a nightly deploy failure.
- **`release.yml`** runs on `v*` tags. It rewrites `set(APP_VERSION ...)` in `Config/cmake/UImGuiDemo.cmake` from the tag, commits the change back to `master`, and publishes a source tarball. Bump the version by tagging, not by hand. The `version:` field in `uvproj.yaml` is not what gets bumped.

## Application structure

`Instance` registers one `TitlebarComponent` (`Title`) and one `WindowComponent` (`DemoWindow`):

- `DemoWindow::begin()` loads the Ubuntu and JetBrains Mono fonts from `Content/` and passes them to `UImGui::TextUtils::initTextUtilsData`. The `TextUtilsData` is `static` because TextUtils keeps a pointer to it.
- `DemoWindow::tick()` renders the dear imgui, ImPlot and TextUtils demo windows, plus inline demos for spinners, toggles and knobs. These are exactly the modules enabled in `uvproj.yaml` (`plotting`, `knobs`, `spinners`, `toggles`, `text-utils`). Adding a showcase for another module means enabling it there and regenerating first. OS, DBus and XDG are unavailable on WASM regardless.
- `Title` uses `TitlebarBuilder`. It adds default macOS menus under `#ifdef __APPLE__` and otherwise builds an empty bar.

Runtime config worth knowing: `Config/Core/Renderer.yaml` selects `renderer: webgpu`. It sets no `emscripten.canvas-selector`, so the framework default `#canvas` applies, which matches `<canvas id="canvas">` in `Config/WASM/index.html`. If you rename one, rename the other.

## graphify

This project has a knowledge graph at graphify-out/ with god nodes, community structure, and cross-file relationships.

Rules:
- For codebase questions, first run `graphify query "<question>"` when graphify-out/graph.json exists. Use `graphify path "<A>" "<B>"` for relationships and `graphify explain "<concept>"` for focused concepts. These return a scoped subgraph, usually much smaller than GRAPH_REPORT.md or raw grep output.
- If graphify-out/wiki/index.md exists, use it for broad navigation instead of raw source browsing.
- Read graphify-out/GRAPH_REPORT.md only for broad architecture review or when query/path/explain do not surface enough context.
- After modifying code, run `graphify update .` to keep the graph current (AST-only, no API cost).
