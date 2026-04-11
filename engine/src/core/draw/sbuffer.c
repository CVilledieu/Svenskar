#include "sbuffer.h"
#include "core/config.h"
#include <stdlib.h>



SBO_t* SBufferObject_Init(void){
    SBO_t* sBuffer = malloc(sizeof(SBO_t));
    sBuffer->sliceCtx.count = SBO_SLICE_COUNT;
    sBuffer->sliceCtx.size = SBO_PEAK_SLICE_SIZE;
    sBuffer->sliceCtx.current = 0;

    sBuffer->buffer = malloc((size_t)SBO_BUFFER_SIZE);

    return sBuffer;
}