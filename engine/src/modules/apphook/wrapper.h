#pragma once

#include "svenskar/engine.h"
#include <stdint.h>

typedef struct AppHook_t{
    SEng_t appWrapper;
}AppHook_t;

// Svenskar Engine Context
typedef struct SEng_t{
    AppHook_t* engHook;
}SEng_t;



static inline uint8_t AppHook_Init(AppHook_t* appHook){
    if(!appHook){
        return 0;
    }
    appHook->appWrapper.engHook = &appHook;
    return Sven_Init(&appHook->appWrapper);
}