#pragma once

#include <stdint.h>

typedef uint32_t MeshID_t;

typedef struct Mesh_t{

}Mesh_t;

typedef struct MeshIdStack_t{
    
}MeshIdStack_t;

typedef struct AssetClerk_t{
    uint32_t count;
    MeshIdStack_t* idStack;
    Mesh_t* list;
}AssetClerk_t;


void AssetClerk_Init(AssetClerk_t* ac);
uint8_t AssetClerk_Shutdown(AssetClerk_t* ac);

uint8_t AssetClerk_NewAsset(AssetClerk_t* ac);
uint8_t AssetClerk_DrawMeshList(MeshID_t* idList, uint32_t listCount);