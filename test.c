#include <stdio.h>
#include <emscripten/html5.h>
#include <emscripten.h>
#include <GLES2/gl2.h>
#include <webgpu/webgpu.h>
#include <emscripten/html5_webgpu.h>

extern void directGLClear(unsigned int bitfield);
extern void directGLDrawArrays(unsigned int mode, int first, int count);

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
    glDrawArrays(GL_TRIANGLES, 0, 3);
  }
}

EMSCRIPTEN_KEEPALIVE
void runDirectGL(int iterations) {
  for (int i = 0; i < iterations; ++i) {
    directGLDrawArrays(GL_TRIANGLES, 0, 3);
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