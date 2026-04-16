#include "display/render/objstream/objbuffer.h"
#include <stdlib.h>



static inline uint8_t FenceSyncCheck(Frame_t* sliceCtx ){
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





static inline void BatchList_SetOffsets(Batch_t* list){
    for (size_t i = 0; i < (size_t)FBUFFER_FRAME_COUNT; i++){
        list[i].offset = i * FRAME_BYTES;
    }
}



uint8_t ObjectStream_Init(ObjectStream_t* objStream){
    if(!objStream){
        return 0;
    }

    objStream->currentBatchIndex = 0;
    glGenBuffers(1, &objStream->ssboID);
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, objStream->ssboID);
    glBufferStorage(GL_SHADER_STORAGE_BUFFER, FBUFFER_TOTAL_BYTES, NULL, GL_FLAGS_STORAGE);
    objStream->buffer = (uint8_t)glMapBufferRange(GL_SHADER_STORAGE_BUFFER, 0, FBUFFER_TOTAL_BYTES, GL_FLAGS_MAP);

    glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
    if(!objStream->buffer){
        glDeleteBuffers(1, &objStream->ssboID);
        return 0;
    }

    BatchList_SetOffsets(&objStream->batchList);

    return 1;
}


void ObjectStream_Shutdown(ObjectStream_t* objStream){
    if(!objStream){
        return;
    }

    for (uint32_t i = 0; i < FBUFFER_FRAME_COUNT; i++) {
		if (objStream->batchList[i].fence) {
			glDeleteSync(objStream->batchList[i].fence);
		}
	}

	if (objStream->buffer) {
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, objStream->buffer);
		glUnmapBuffer(GL_SHADER_STORAGE_BUFFER);
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
		glDeleteBuffers(1, &objStream->buffer);
	}
}