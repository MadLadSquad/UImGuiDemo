#!/usr/bin/env bash
# Builds the WASM version of the demo for Cloudflare Pages.
#
# Cloudflare Pages project settings:
#   Build command:          ./cloudflare-build.sh
#   Build output directory: dist
#
# Also works locally: an existing emcc/cmake on the PATH is used as-is, and the
# framework checkout, emsdk and build directory are reused between runs.
set -eo pipefail

cd "$(dirname "$0")"
cpus=$(nproc 2> /dev/null || grep -c processor /proc/cpuinfo)

# The Cloudflare build image does not guarantee CMake, so fetch it from PyPI if missing
if ! command -v cmake &> /dev/null; then
  python3 -m pip install --user cmake
  export PATH="${HOME}/.local/bin:${PATH}"
fi

if ! command -v emcc &> /dev/null; then
  [ -d .emsdk ] || git clone --depth=1 https://github.com/emscripten-core/emsdk.git .emsdk
  ./.emsdk/emsdk install latest
  ./.emsdk/emsdk activate latest
  # shellcheck disable=SC1091
  source ./.emsdk/emsdk_env.sh
fi
emcc -v

# Always build against the latest framework master
if [ ! -d UntitledImGuiFramework ]; then
  git clone https://github.com/MadLadSquad/UntitledImGuiFramework.git --recursive --depth=1
fi
if [ ! -x UntitledImGuiFramework/UVKBuildTool/build/UVKBuildTool ]; then
  (cd UntitledImGuiFramework && ./install.sh ci)
fi
(cd UntitledImGuiFramework/UVKBuildTool/build && ./UVKBuildTool --generate ../../../)

# Minify the hand-written web files. Only done on Cloudflare, since it rewrites tracked files in place
if [ -n "${CF_PAGES}" ]; then
  find Config/WASM -type f -iname "*.js" -exec npx --yes terser {} --compress -o {} \;
  find Config/WASM -type f -iname "*.css" -exec npx --yes -p csso-cli csso {} -o {} \;
fi

mkdir -p build-wasm
(cd build-wasm && emcmake cmake .. -DCMAKE_BUILD_TYPE=RELEASE && make -j "${cpus}")

# Assemble the site: build output minus CMake leftovers, with the custom index.html replacing the generated one
rm -rf dist
cp -r build-wasm dist
(cd dist && rm -rf CMake* CPack* Framework/ Makefile cmake_* test_fs_support* lib*.a compile_commands.json UImGuiDemo.html)
cp Config/WASM/* dist/
