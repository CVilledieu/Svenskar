#include "core.h"
#include "render/render.h"
#include <stdlib.h>
#include "glad/glad.h"
#include <glfw/glfw3.h>

uint8_t GraphicsEngine_Init(GraphicsEngine_t* eng){
    if(!eng){
        return 0;
    }
    
    eng->mainCanvas = Canvas_Init(800, 600, "Game Engine");
    eng->frameBuffer = FrameBuffer_Init();



    return 1;
}





void DrawStep(GraphicsEngine_t* eng){
    

    


}