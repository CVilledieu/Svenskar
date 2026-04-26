#include "core.h"
#include <stdint.h>
#include "display/manager.h"


uint8_t EngineCore_Init(EngineCore_t* eCore){
    if(!eCore || !HookIntoAppLayer(&eCore->appHook)){
        return 0;
    }

    DisplayManager_Init(&eCore->display);




    return 1;
}


void EngineCore_Shutdown(EngineCore_t* eCore){
    if(!eCore){
        return 0;
    }

    GraphicsEngine_Shutdown(eCore->display);
    ShutdownAppLayer(eCore);



}




void EngineCore_Main(EngineCore_t* eCore){

    DisplayManager_t* display = &eCore->display;

    while(display->open){

    }
    

    EngineCore_Shutdown(eCore);

}



