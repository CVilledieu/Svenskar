#pragma once

#include <stdint.h>
typedef struct CameraSys_t{
    float projection[16];
    float view[16];
}CameraSys_t;



FuncRes_t Camera_Init(CameraSys_t* cam);