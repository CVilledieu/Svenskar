#pragma once
/* Hook in api for root to access core functions

*/
typedef struct Renderer_t{

} Renderer_t;

typedef struct {
    FrameBuffer_t* fBuffer;
    Canvas_t* canvas;
}EngCore_t;



EngCore_t* Core_Init(void);