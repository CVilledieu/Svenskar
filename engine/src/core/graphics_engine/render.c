#include "render/render.h"
#include "render/render_internal.h"

uint8_t GraphicsEngine_Init(GraphicsEngine_t* gEngine){
    if(!gEngine){
        return 0;
    }

    gEngine->mainCanvas = Canvas_Init(800, 600, "Game Title");
    gEngine->frameBuffer = 


    return 0;
}


