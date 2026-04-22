#pragma once

#include <stdint.h>

typedef uint32_t MeshID_t;

typedef struct Mesh_t{

}Mesh_t;

typedef struct MeshIdStack_t{
    
}MeshIdStack_t;

typedef struct AssetManager_t{
    uint32_t count;
    MeshIdStack_t* idStack;
    Mesh_t* list;
}AssetManager_t;


void AssetManager_Init(AssetManager_t* manger);
uint8_t AssetManager_Shutdown(AssetManager_t* manger);

uint8_t AssetClerk_NewAsset(AssetManager_t* manger, MeshID_t* meshIdPtr);
uint8_t AssetClerk_DrawMeshList(MeshID_t* idList, uint32_t listCount); 