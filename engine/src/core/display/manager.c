#include "display/manager.h"
#include "display/renderer/dispatch/dispatch.h"
#include "display/canvas/canvas.h"


uint8_t DisplayManager_Init(DisplayManager_t* dm){
    if(!dm){
        return 0;
    }

    dm->window = Canvas_Init(800, 600, "Default title");
    if(!dm->window){
        return 0;
    }
    
    Dispatch_Init(&dm->dispatch);

    return 1;
}

uint8_t DisplayManager_Run(DisplayManager_t* dm){
    if(!dm){
        return 0;
    }
    Canvas_Show(dm->window);
    

}