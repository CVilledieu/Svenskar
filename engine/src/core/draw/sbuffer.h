#pragma once

#include <stdint.h>
#include "glad/glad.h"
#include <glfw/glfw3.h>



typedef struct {
    size_t offset;
    GLsync fence;
} Slice_t;


typedef struct {
    uint8_t currentSlice;
    Slice_t* slices;
    uint8_t* buffer;
    uint32_t bufferID;
}SBO_t;


SBO_t* SBufferObject_Init(void);