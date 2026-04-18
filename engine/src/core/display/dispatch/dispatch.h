#pragma once

#include "display/config.h"


typedef struct MeshID_t MeshID_t;


typedef struct Batch_t{
    size_t offset;
    GLsync fence;
}Batch_t;


typedef struct Dispatch_t{
    uint8_t nextBatchID;
    Batch_t batches[BUFFER_BATCH_COUNT];
    uint8_t* buffer;
    uint32_t ssboID;

    uint32_t meshCount;
    MeshID_t* meshList;
}Dispatch_t;


void Dispatch_Init(Dispatch_t* dispatch);
void Dispatch_Shutdown(Dispatch_t* dispatch);

void Dispatch_NewBatch(Dispatch_t* dispatch);

