#pragma once

#include <stdint.h>

struct Camera_t{
    float projection[16];
    float view[16];
};



//Temp solution
#define MAX_ENTITIES 128
struct Entities_t{
    uint8_t PosX[MAX_ENTITIES];
    uint8_t PosY[MAX_ENTITIES];
    uint8_t PosZ[MAX_ENTITIES];

};

typedef struct Architect_t{
    struct Camera_t camera;
    struct Entities_t entities;
}Architect_t;

void WorldArchitect_Init(Architect_t* architect);

uint8_t World_SubmitView(uint8_t* viewBuffer);
uint8_t World_SubmitEntities(uint8_t* displayBuffer);

uint8_t Architect_AddEntity(Architect_t* arch, ModelID_t* modID);

uint8_t Architect_UpdateCamera(Architect_t* arch );