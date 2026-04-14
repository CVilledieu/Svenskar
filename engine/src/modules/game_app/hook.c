#include "modules/game_app/hook.h"



//
uint8_t HookIntoGameApp(EngineCore_t* eCore){
    SEcontext_t wrapper;
    wrapper.hook = &eCore->appHook;

    return Game_Init(&wrapper);
}


void ShutdownGameApp(AppHook_t* appHook){
    if(!appHook || !appHook->ShutdownCallback){
        return;
    }
    

    appHook->ShutdownCallback()
}