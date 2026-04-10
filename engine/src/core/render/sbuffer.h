#pragma once

#include <stdint.h>

typedef struct {
    size_t offset;
    GLsync fence;
} Slice_t;

typedef struct {
    uint8_t current;
    uint8_t count;
    size_t size;
} SliceContext_t;


typedef struct {
    SliceContext_t sliceCtx;
    uint32_t bufferID;
    Slice_t* slices;
    uint8_t* buffer;
}SBO_t;


SBO_t* ShaderBufferObject_Init(size_t sliceSize, uint8_t sliceCount);