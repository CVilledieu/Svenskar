#include "fbuffer.h"
#include <stdlib.h>



static inline uint8_t FrameSyncCheck(Frame_t* sliceCtx ){
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




void FrameBufferShutdown(FrameBuffer_t* fBuffer){
    if(!fBuffer){
        return;
    }

    for (uint32_t i = 0; i < FBUFFER_FRAME_COUNT; i++) {
		if (fBuffer->frameList[i].fence) {
			glDeleteSync(fBuffer->frameList[i].fence);
		}
	}

	if (fBuffer->buffer) {
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, fBuffer->buffer);
		glUnmapBuffer(GL_SHADER_STORAGE_BUFFER);
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
		glDeleteBuffers(1, &fBuffer->buffer);
	}
}




FrameBuffer_t* FrameBufferInit(void){
    FrameBuffer_t* rBuffer = malloc(sizeof(FrameBuffer_t));

    glGenBuffers(1, &rBuffer->bufferID);
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, rBuffer->bufferID);
    glBufferStorage(GL_SHADER_STORAGE_BUFFER, FBUFFER_TOTAL_BYTES, NULL, GL_FLAGS_STORAGE);
    rBuffer->buffer = (uint8_t)glMapBufferRange(GL_SHADER_STORAGE_BUFFER, 0, FBUFFER_TOTAL_BYTES, GL_FLAGS_MAP);

    glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
    if(!rBuffer->buffer){
        glDeleteBuffers(1, &rBuffer->bufferID);
        return NULL;
    }

    for (size_t i = 0; i < (size_t)FBUFFER_FRAME_COUNT; i++){
        rBuffer->frameList[i].offset = i * FRAME_BYTES;
    }

    rBuffer->currentSlice = 0;

    return rBuffer;
}







uint8_t GetFrame(FrameBuffer_t* fBuffer, uint8_t** destPtr){
    if(!fBuffer || !destPtr){
        return 0;
    }
    Frame_t* sliceCtx = &fBuffer->frameList[fBuffer->currentSlice];
    if(!FrameSyncCheck(sliceCtx)){
        return 0;
    }

    

    return 1;
}


