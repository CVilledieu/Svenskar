#include "display/dispatch/dispatch.h"
#include "world/architect.h"


// Dev note: Is waiting for the fence the best option?
static inline uint8_t SyncError(Batch_t* batch){
    GLenum result = glClientWaitSync(batch->fence, GL_SYNC_FLUSH_COMMANDS_BIT, BATCH_SYNC_TIMEOUT);
    while(result != GL_ALREADY_SIGNALED && result != GL_CONDITION_SATISFIED){
        if(result == GL_WAIT_FAILED){
            return 1;
        }
        GLenum result = glClientWaitSync(batch->fence, 0, BATCH_SYNC_TIMEOUT);    
    }
    
    glDeleteSync(batch->fence);

    return 0;
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
    return AssetClerk_DrawMeshList(meshList, count);
}





void Dispatch_Init(Dispatch_t* dispatch){
    dispatch->nextBatchID = 0;
    glGenBuffers(1, &dispatch->ssboID);
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, dispatch->ssboID);

    glBufferStorage(GL_SHADER_STORAGE_BUFFER, BUFFER_TOTAL_BYTES, NULL, GL_FLAGS_STORAGE);
    dispatch->buffer = (uint8_t)glMapBufferRange(GL_SHADER_STORAGE_BUFFER, 0, BUFFER_TOTAL_BYTES, GL_FLAGS_MAP);


}




void Dispatch_Shutdown(Dispatch_t* dispatch){
    if(!dispatch){
        return;
    }

    free(dispatch->buffer);
}




void Dispatch_NewBatch(Dispatch_t* dispatch, MeshID_t* meshList, uint32_t listLength){
    uint8_t batchID = dispatch->nextBatchID;
    Batch_t* batch = &dispatch->batches[batchID];
    if(batch->fence != NULL){
        if(SyncError(batch)){
            //Do something? Dropped frame ?
            return;
        }
    }
    uint8_t* writer = &dispatch->buffer[batch->offset];
    
    uint32_t viewLength = Dispatch_ViewData(writer);
    writer += viewLength;

    uint32_t modelLength = Dispatch_ModelData(writer);
    writer += modelLength;


    //uint32_t lightLength = Dispatch_LightingData(writer);
    //writer += lightLength;
    uint32_t totalLength = (uint32_t)(writer - &dispatch->buffer[batch->offset]);
    
    //Submit Batch
    glBindBufferRange(GL_SHADER_STORAGE_BUFFER, 0, dispatch->ssboID, batch->offset, totalLength);

    Dispatch_ApplyGeometry(meshList, listLength);


    batch->fence = glFenceSync(GL_SYNC_GPU_COMMANDS_COMPLETE, 0);
    
    dispatch->nextBatchID = (dispatch->nextBatchID + 1) % BATCH_ROTATION_COUNT;

}
