#include "buffer.h"
#include <stdlib.h>





FrameBuffer_t* RingBufferInit(void){
    FrameBuffer_t* rBuffer = malloc(sizeof(FrameBuffer_t));

    glGenBuffers(1, &rBuffer->bufferID);
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, rBuffer->bufferID);
    glBufferStorage(GL_SHADER_STORAGE_BUFFER, RB_TOTAL_BYTES, NULL, GL_FLAGS_STORAGE);
    rBuffer->buffer = (uint8_t)glMapBufferRange(GL_SHADER_STORAGE_BUFFER, 0, RB_TOTAL_BYTES, GL_FLAGS_MAP);

    glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
    if(!rBuffer->buffer){
        glDeleteBuffers(1, &rBuffer->bufferID);
        return NULL;
    }

    for (size_t i = 0; i < (size_t)BUFFERED_FRAME_COUNT; i++){
        rBuffer->frameList[i].offset = i * FRAME_PEAK_BYTES;
    }

    rBuffer->currentSlice = 0;

    return rBuffer;
}




static inline uint8_t FrameReadyCheck(Frame_t* sliceCtx ){
    GLenum fenceState = glClientWaitSync(sliceCtx->fence, GL_SYNC_FLUSH_COMMANDS_BIT, FENCE_SYNC_TIMEOUT);

    while(fenceState != GL_ALREADY_SIGNALED  || fenceState != GL_CONDITION_SATISFIED){
        fenceState = glClientWaitSync(sliceCtx->fence, GL_SYNC_FLUSH_COMMANDS_BIT, FENCE_SYNC_TIMEOUT);
        if(fenceState == GL_WAIT_FAILED){
            return 0;
        }
    }


    glDeleteSync(sliceCtx->fence);


    return 1;
}



uint8_t GetFrame(FrameBuffer_t* fBuffer, uint8_t** destPtr){
    if(!fBuffer || !destPtr){
        return 0;
    }
    Frame_t* sliceCtx = &fBuffer->frameList[fBuffer->currentSlice];
    if(!FrameReadyCheck(sliceCtx)){
        return 0;
    }

    *destPtr = &fBuffer->buffer[sliceCtx->offset];

    return 1;
}