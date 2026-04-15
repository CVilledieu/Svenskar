#pragma once
#include "display/config.h"


//Canvas
typedef struct GLFWwindow Canvas_t;

Canvas_t* Canvas_Init(int width, int height, const char* title);
uint8_t Canvas_Show(Canvas_t* canvas);


