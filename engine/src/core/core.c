#include "core/core.h"
#include "core/config.h"

#include <stdlib.h>


EngCore_t* Core_Init(void){
    EngCore_t* core = malloc(sizeof(EngCore_t));

    core->fBuffer = RingBufferInit();

    return core;
}