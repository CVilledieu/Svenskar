#pragma once

#include <stdint.h>


typedef AssetManager_t AssetManager_t;

typedef struct Architect_t{
    AssetManager_t* assMan;
}Architect_t;

void Architect_Init(Architect_t* architect);

uint8_t Architect_Submit(uint8_t* displayBuffer);