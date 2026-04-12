#include "render_sys.h"
#include "frame/fbuffer.h"
#include "canvas/canvas.h"

uint8_t RenderSystemInit(RenderSystem_t* rSys){
    if(!rSys){
        return 0;
    }

    rSys->frameBuffer = FrameBufferInit();
    rSys->mainCanvas = NewCanvas(800, 600, "My game");


    return 1;
}