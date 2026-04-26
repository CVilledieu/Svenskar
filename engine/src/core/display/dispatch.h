#pragma once

#include "display/config.h"

// Batch segment layout
#define BATCH_CAMERA_SLICE

typedef struct MeshID_t MeshID_t;


typedef struct Batch_t{
    size_t offset;
    GLsync fence;
}Batch_t;


typedef struct Dispatch_t{
    uint8_t nextBatchID;
    Batch_t batches[BATCH_ROTATION_COUNT];
    uint8_t* buffer;
    uint32_t ssboID;
}Dispatch_t;


void Dispatch_Init(Dispatch_t* dispatch);
void Dispatch_Shutdown(Dispatch_t* dispatch);

void Dispatch_NewBatch(Dispatch_t* dispatch, MeshID_t* meshList, uint32_t listLength);

