#pragma once

#include "core/config.h"

#define FRAME_BYTES (FRAME_PEAK_MODEL_BYTES + FRAME_PEAK_LIGHTING_BYTES)
#define FBUFFER_TOTAL_BYTES (FBUFFER_FRAME_COUNT * FRAME_BYTES)



typedef struct Frame_t{
    size_t offset;
    GLsync fence;
} Frame_t;


typedef struct FrameBuffer_t{
    uint8_t currentSlice;
    Frame_t frameList[FBUFFER_FRAME_COUNT];
    uint8_t* buffer;
    uint32_t bufferID;
}FrameBuffer_t;

 
FrameBuffer_t* FrameBufferInit(void);
uint8_t GetFrame(FrameBuffer_t* fBuffer, uint8_t** destPtr);
void FrameBufferShutdown(FrameBuffer_t* fBuffer);