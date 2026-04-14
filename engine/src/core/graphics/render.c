#include "graphics/render.h"
#include "graphics/config.h"
#include "graphics/canvas/canvas.h"
#include "graphics/materials/handler.h"
#include "graphics/draw/handler.h"





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


