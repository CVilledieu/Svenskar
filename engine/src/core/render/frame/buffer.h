#pragma once

#include "core/config.h"

#define FRAME_PEAK_BYTES (GB_PEAK_MODEL_BYTES + GB_PEAK_LIGHTING_BYTES)
#define RB_TOTAL_BYTES (BUFFERED_FRAME_COUNT * FRAME_PEAK_BYTES)



typedef struct Frame_t{
    size_t offset;
    GLsync fence;
} Frame_t;


typedef struct FrameBuffer_t{
    uint8_t currentSlice;
    Frame_t frameList[BUFFERED_FRAME_COUNT];
    uint8_t* buffer;
    uint32_t bufferID;
}FrameBuffer_t;

 
FrameBuffer_t* RingBufferInit(void);
uint8_t GetFrame(FrameBuffer_t* fBuffer, uint8_t** destPtr);