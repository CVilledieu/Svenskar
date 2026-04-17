#include "display/dispatch/dispatch.h"
#include "display/assets/clerk.h"



// Supporting functions for Dispatch_NewBatch
static inline uint8_t SyncCheck(Batch_t* batch);
static inline uint32_t Dispatch_ViewData(uint8_t* writeBuffer);
static inline uint32_t Dispatch_ModelData(uint8_t* writeBuffer);
static inline uint8_t Dispatch_ApplyGeometry(MeshID_t* meshList, uint32_t count);


void Dispatch_Init(Dispatch_t* dispatch){
    dispatch->nextBatchID = 0;
    glGenBuffers(1, &dispatch->ssboID);
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, dispatch->ssboID);
}




void Dispatch_NewBatch(Dispatch_t* dispatch){
    uint8_t batchID = dispatch->nextBatchID;
    Batch_t* batch = &dispatch->batches[batchID];
    if(!SyncCheck(batch)){
        //Do something? Dropped frame ?
        return;
    }
    uint8_t* batchStart = &dispatch->buffer[batch->offset];
    uint8_t* currentPos = batchStart; // extra point so I can move the pointer
    
    *currentPos += Dispatch_ViewData(currentPos);
    *currentPos = Dispatch_ModelData(currentPos);
    //Dispatch_LightingData(currentPos);

    Dispatch_ApplyGeometry(&dispatch->meshList, dispatch->meshCount);

    //Submit Batch
    //Set Batch Fence

    dispatch->nextBatchID = (dispatch->nextBatchID + 1) % (BUFFER_BATCH_COUNT + 1);

}




static inline uint8_t SyncCheck(Batch_t* batch){

}


//Sends buffer to have View data written into buffer 
//(or collects and writes into buffer so buffer never leaves dispatcher)
static inline uint32_t Dispatch_ViewData(uint8_t* writeBuffer){
    return CameraSys_UploadView(writeBuffer);
}



static inline uint32_t Dispatch_ModelData(uint8_t* writeBuffer){
    return SceneSys_UploadModels(writeBuffer);
}



static inline uint8_t Dispatch_ApplyGeometry(MeshID_t* meshList, uint32_t count){
    return AssetClerk_DrawMeshIDList(meshList, count);
}

