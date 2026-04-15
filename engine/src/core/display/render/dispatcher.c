#include "display/render/dispatcher.h"
#include "display/config.h"
#include "display/render/objstream/objbuffer.h"
#include "display/render/material_system/materials.h"


uint8_t Dispatcher_Init(Dispatcher_t* dispatch){

}



uint8_t GraphicsEngine_Init(GraphicsEngine_t* gEngine){
    if(!gEngine){
        return 0;
    }

    gEngine->mainCanvas = Canvas_Init(800, 600, "Game Title");
    gEngine->materialSystem = Materials_Init();


    return 1;
}


uint8_t GraphicsEngine_Shutdown(GraphicsEngine_t* gEngine){
    if(!gEngine){
        return 0;
    }

    Materials_Shutdown(&gEngine->materialSystem);


    return 1;
}



void GraphicsEngine_Render(GraphicsEngine_t* gEngine){

}


