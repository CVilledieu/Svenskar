#pragma once

#include <stdint.h>


typedef AssetManager_t AssetManager_t;
typedef BluePrints_t BluePrints_t;

typedef struct Architect_t{
    AssetManager_t* assMan;
    BluePrints_t* bPrints;
}Architect_t;

void Architect_Init(Architect_t* architect);

FuncRes_t Architect_Submit(FuncRes_t* displayBuffer);