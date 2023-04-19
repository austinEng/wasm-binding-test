#include <stdio.h>
#include <emscripten/html5.h>
#include <emscripten.h>
#include <GLES2/gl2.h>
#include <webgpu/webgpu.h>
#include <emscripten/html5_webgpu.h>

extern void directGLClearColor(float r, float g, float b, float a);

extern void directRenderPassEncoderDraw(
  unsigned int vertexCount, unsigned int instanceCount,
  unsigned int firstVertex, unsigned int firstInstance);

EMSCRIPTEN_KEEPALIVE
void setupGL() {
  EmscriptenWebGLContextAttributes attr;
	emscripten_webgl_init_context_attributes(&attr);

  EMSCRIPTEN_WEBGL_CONTEXT_HANDLE ctx = emscripten_webgl_create_context("canvas", &attr);
	emscripten_webgl_make_context_current(ctx);
}

EMSCRIPTEN_KEEPALIVE
void runGL(int iterations) {
  for (int i = 0; i < iterations; ++i) {
    glClearColor(0.1, 0.2, 0.3, 0.4);
  }
}

EMSCRIPTEN_KEEPALIVE
void runDirectGL(int iterations) {
  for (int i = 0; i < iterations; ++i) {
    directGLClearColor(0.1, 0.2, 0.3, 0.4);
  }
}

WGPURenderPassEncoder renderPassEncoder;
EMSCRIPTEN_KEEPALIVE
void setRenderPassHandle(WGPURenderPassEncoder handle) {
  renderPassEncoder = handle;
}

EMSCRIPTEN_KEEPALIVE
void runWebGPU(int iterations) {
  for (int i = 0; i < iterations; ++i) {
    wgpuRenderPassEncoderDraw(renderPassEncoder, 3, 1, 0, 0);
  }
}

EMSCRIPTEN_KEEPALIVE
void runDirectWebGPU(int iterations) {
  for (int i = 0; i < iterations; ++i) {
    directRenderPassEncoderDraw(3, 1, 0, 0);
  }
}