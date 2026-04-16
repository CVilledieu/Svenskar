#pragma once
#include "display/config.h"



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

FrameBuffer_t* FrameBuffer_Init(void);
uint8_t FrameBuffer_GetFrame(FrameBuffer_t* fBuffer, uint8_t** destPtr);
void FrameBuffer_Shutdown(FrameBuffer_t* fBuffer);




typedef struct Batch_t{
    size_t offset;
    GLsync fence;
}Batch_t;


typedef struct ObjectStream_t{
    uint8_t currentBatchIndex;
    Batch_t batchList[FBUFFER_FRAME_COUNT];
    uint8_t* buffer;
    uint32_t ssboID;
}ObjectStream_t;



uint8_t ObjectStream_Init(ObjectStream_t* objStream);
void ObjectStream_Shutdown(ObjectStream_t* objStream);


