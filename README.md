# WASM Binding Test

Runs a WebGL / WebGPU test performing several trials of many draws.
It tests:
  - Running a WebGL draw loop in Javascript
  - Running a WebGL draw loop in WASM using Emscripten's WebGL bindings
  - Running a WebGL draw loop in WASM using custom bindings with WASM imports bound
    directly to the WebGLRenderingContext object.
  - Running a WebGPU draw loop in Javascript
  - Running a WebGPU draw loop in WASM using Emscripten's WebGPU bindings.
  - Running a WebGPU draw loop in WASM using custom bindings with WASM imports bound
    directly to the GPURenderPassEncoder object.

Try running with:
 - --enable-features=V8TurboFastApiCalls
 - --disable-features=V8TurboFastApiCalls
