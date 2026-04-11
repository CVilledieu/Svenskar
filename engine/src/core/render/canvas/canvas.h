#pragma once

#include "core/config.h"


typedef struct GLFWwindow Canvas_t;

// typedef struct {
//     const char* title;
//     int width;
//     int height;
//     GLFWwindow* wndFrame;
// } CanvasCtx_t;


uint8_t NewCanvas(Canvas_t* canvas, int width, int height, const char* title);
