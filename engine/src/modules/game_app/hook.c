#include "modules/game_app/hook.h"


/*  Due to the engine and the API having different Coding conventions the Game_app module
    shares a Coding convention with the API instead of the engine


    Acronyms:
    SVGE: Svenskar Game Engine
  
*/



uint8_t HookIntoAppLayer(EngineCore_t* eCore){
    SVGE_t wrapper;
    wrapper.hook = &eCore->appHook;

    return AppRoot(&wrapper);
}



void ShutdownAppLayer(AppHook_t* appHook){
    if(!appHook || !appHook->ShutdownCallback){
        return;
    }
    

    appHook->ShutdownCallback()
}