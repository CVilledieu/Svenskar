#include "SvenSkar/Hooks.h"
#include "core/core.h"

int main(void){
    AppHook_Init();
    GraphicsEngine_Init();
    Module_Init();


    GraphicsEngine_Run();

    return 0;
}