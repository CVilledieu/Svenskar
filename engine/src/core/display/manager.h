#pragma once

#include <stdint.h>

typedef struct DisplayManager_t{
    Canvas_t* mainWindow;
    Dispatch_t dispatch;

}DisplayManager_t;

uint8_t DisplayManager_Init(DisplayManager_t* dm);
void DisplayManager_Shutdown(DisplayManager_t* dm);



uint8_t DisplayManager_Run(DisplayManager_t* dm);

