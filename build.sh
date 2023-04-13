#!/bin/bash

SCRIPTDIR=$(dirname "$0")
pushd "$SCRIPTDIR"

mkdir -p out
emcc test.c -o out/test.js -O2           \
     -s MODULARIZE -s EXPORT_ES6=1       \
     -s 'EXPORT_NAME="initializeModule"' \
     -s ERROR_ON_UNDEFINED_SYMBOLS=0     \
     -sGL_PREINITIALIZED_CONTEXT         \
     -sUSE_WEBGPU=1                      \
     -sEXPORTED_RUNTIME_METHODS="['WebGPU', 'JsValStore']"
