#pragma once

#include "core/config.h"


typedef struct GLFWwindow Canvas_t;

// typedef struct {
//     const char* title;
//     int width;
//     int height;
//     GLFWwindow* wndFrame;
// } CanvasCtx_t;


Canvas_t* NewCanvas(int width, int height, const char* title);
uint8_t DisplayCanvas(Canvas_t* canvas);