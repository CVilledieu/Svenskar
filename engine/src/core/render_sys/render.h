#pragma once
#include "core/config.h"

typedef struct RenderSystem_t{
    FrameBuffer_t* frameBuffer;
    Canvas_t* mainCanvas;
} RenderSystem_t;

uint8_t RenderSystem_Init(RenderSystem_t* rSys);
