#include "svenSkar/engine.h"
#include "core/core.h"
#include "modules/apphook/wrapper.h"




int main(void){
    GraphicsEngine_Init();

    AppHook_Init();
    
    Module_Init();


    GraphicsEngine_Run();

    return 0;
}