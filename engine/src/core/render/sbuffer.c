#include "sbuffer.h"
#include <stdlib.h>



SBO_t* ShaderBufferObject_Init(size_t sliceSize, uint8_t sliceCount){
    SBO_t* sBuffer = malloc(sizeof(SBO_t));
    sBuffer->sliceCtx.count = sliceCount;
    sBuffer->sliceCtx.size = sliceSize;
    sBuffer->sliceCtx.current = 0;

    sBuffer->buffer = malloc(sliceSize * sliceCount);

    return sBuffer;
}