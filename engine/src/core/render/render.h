#pragma once

#include <stdint.h>





typedef struct GraphicsEngine_t{
    FrameBuffer_t* frameBuffer;
    Canvas_t* mainCanvas;
    Materials_t* materials;
}GraphicsEngine_t;



uint8_t GraphicsEngine_Init(GraphicsEngine_t* eng);
void DrawStep(GraphicsEngine_t* eng);