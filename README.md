# WASM Binding Test

Runs a WebGL / WebGPU test performing 10 trials of 100000 calls.
It's a super synthetic benchmark designed to do a tiny function call in each of
WebGL / WebGPU that should have minimal cost in the browser to try to isolate cost
of the bindings.
Note: The point isn't to compare WebGL and WebGPU.

It tests the calls in pure JS, in WASM using Emscripten, and in WASM "direct" mode
using custom bindings bound directly to the receiver.

Tests:
  - Running a WebGL glClearColor loop in Javascript
  - Running a WebGL glClearColor loop in WASM using Emscripten's WebGL bindings
  - Running a WebGL glClearColor loop in WASM using custom bindings with WASM imports bound
    directly to the WebGLRenderingContext object.
  - Running a WebGPU draw loop in Javascript
  - Running a WebGPU draw loop in WASM using Emscripten's WebGPU bindings.
  - Running a WebGPU draw loop in WASM using custom bindings with WASM imports bound
    directly to the GPURenderPassEncoder object.

Use a new --user-data-dir= for each configuration, and try running in Chrome with:
 - --enable-features=V8TurboFastApiCalls
 - --disable-features=V8TurboFastApiCalls
