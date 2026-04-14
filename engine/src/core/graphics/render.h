#pragma once

#include <stdint.h>

typedef struct Canvas_t Canvas_t;
typedef struct Materials_t Materials_t;


typedef struct GraphicsEngine_t{
    Canvas_t* mainCanvas;
    Materials_t* materialSystem;
}GraphicsEngine_t;



uint8_t GraphicsEngine_Init(GraphicsEngine_t* eng);
void DrawStep(GraphicsEngine_t* eng);