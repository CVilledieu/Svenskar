#include "render.h"
#include "frame/fbuffer.h"
#include "canvas/canvas.h"

uint8_t RenderSystem_Init(RenderSystem_t* rSys){
    if(!rSys){
        return 0;
    }

    rSys->frameBuffer = FrameBufferInit();
    rSys->mainCanvas = NewCanvas(800, 600, "My game");


    return 1;
}


uint8_t DrawStep(RenderSystem_t* rSys){
    if(!rSys){
        return 0;
    }
    



    return 1;
}