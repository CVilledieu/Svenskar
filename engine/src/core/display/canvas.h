#pragma once

#include <stdint.h>
#include "glad/glad.h"
#include <glfw/glfw3.h>




//Canvas
typedef struct GLFWwindow Canvas_t;

Canvas_t* Canvas_Init(int width, int height, const char* title);
void Canvas_Shutdown(Canvas_t* canvas);


uint8_t Canvas_Show(Canvas_t* canvas);

