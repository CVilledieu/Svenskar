#pragma once

#include <stdint.h>

typedef Canvas_t Canvas_t;
typedef Dispatch_t Dispatch_t;

typedef struct DisplayManager_t{
    uint8_t open;
    Canvas_t* window;
    Dispatch_t dispatch;   
}DisplayManager_t;

uint8_t DisplayManager_Init(DisplayManager_t* dm);
void DisplayManager_Shutdown(DisplayManager_t* dm);



uint8_t DisplayManager_ShowWindow(DisplayManager_t* dm);
