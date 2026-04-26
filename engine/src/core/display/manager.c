#include "display/manager.h"
#include "display/dispatch.h"
#include "display/canvas.h"


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


void DisplayManager_Shutdown(DisplayManager_t* dm){
    dm->open = 0;
    Canvas_Shutdown(&dm->window);
    Dispatch_Shutdown(&dm->dispatch);
}

uint8_t DisplayManager_ShowWindow(DisplayManager_t* dm){
    if(!dm){
        return 0;
    }
    Canvas_Show(dm->window);
    

}