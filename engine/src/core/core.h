#pragma once


typedef struct EngineCore_t{
    AppHook_t appHook;
    DisplayManager_t display;
}EngineCore_t;

// Called by main.c
uint8_t EngineCore_Init(EngineCore_t* eCore);
void EngineCore_Shutdown(EngineCore_t* eCore);
uint8_t EngineCore_Main(EngineCore_t* eCore);