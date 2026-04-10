#include "core/core.h"
#include "core/config/config.h"
#include "core/render/render.h"
#include <stdlib.h>



EngCore_t* Core_Init(void){
    EngCore_t* core = malloc(sizeof(EngCore_t));

    return core;
}