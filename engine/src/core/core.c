#include "core/core.h"
#include "core/config.h"
#include "render_sys/render.h"

#include <stdlib.h>


EngCore_t* Core_Init(void){
    EngCore_t* core = malloc(sizeof(EngCore_t));
    RenderSystem_Init(core->renderSys);


    return core;
}


void Core_MainLoop(EngCore_t* eCore){

}