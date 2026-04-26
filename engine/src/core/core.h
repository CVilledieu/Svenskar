#pragma once

typedef struct AppLayer_t AppLayer_t;

typedef struct EngineCore_t{
    DisplayManager_t display;
    AppLayer_t* app;
}EngineCore_t;

// Called by main.c
uint8_t EngineCore_Init(EngineCore_t* eCore);
void EngineCore_Shutdown(EngineCore_t* eCore);
uint8_t EngineCore_Main(EngineCore_t* eCore);