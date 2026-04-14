#pragma once

#include "core.h"
#include "svenskar/engine.h"
#include <stdint.h>


typedef struct UserEventCallbacks_t{
    
}UserEventCallbacks_t;


typedef struct EngineEventCallbacks_t{
    void (*UpdateCallback)(SEcontext_t* ctx);
    void (*ShutdownCallback)(void);
}EngineEventCallbacks_t;

// Handler for wrapping and unwrapping GameApp context
typedef struct AppHook_t{
    EngineCore_t* core;
    SEcontext_t wrapper;
    void (*ShutdownCallback)(void);

}AppHook_t;


typedef struct SEcontext_t{
    AppHook_t* hook;
}SEcontext_t;

uint8_t HookIntoGameApp(EngineCore_t* eCore);
void ShutdownGameApp(AppHook_t* appHook);