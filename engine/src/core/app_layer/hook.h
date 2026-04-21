#pragma once

#include "core.h"
#include "svenskar/engine.h"
#include <stdint.h>


typedef struct UserEventCallbacks_t{
    
}UserEventCallbacks_t;


typedef struct EngineEventCallbacks_t{
    void (*UpdateCallback)(SVGE_t* ctx);
    void (*ShutdownCallback)(void);
}EngineEventCallbacks_t;

// Handler for wrapping and unwrapping GameApp context
typedef struct AppHook_t{
    EngineCore_t* core;
    SVGE_t wrapper;
    void (*ShutdownCallback)(void);

}AppHook_t;


typedef struct SVGE_t{
    AppHook_t* hook;
}SVGE_t;

uint8_t HookIntoAppLayer(EngineCore_t* eCore);
void ShutdownAppLayer(AppHook_t* appHook);