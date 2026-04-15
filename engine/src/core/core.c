#include "core.h"
#include <stdint.h>



uint8_t EngineCore_Init(EngineCore_t* eCore){
    if(!eCore || !HookIntoAppLayer(&eCore->appHook)){
        return 0;
    }





    return 1;
}


void EngineCore_Shutdown(EngineCore_t* eCore){
    
    GraphicsEngine_Shutdown(eCore->renderer);
    ShutdownAppLayer(eCore);
}




uint8_t EngineCore_Main(EngineCore_t* eCore){
    

    EngineCore_Shutdown(eCore);
    return 1;
}



