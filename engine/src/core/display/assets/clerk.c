#include "display/assets/clerk.h"
#include "display/config.h"

static inline void MeshIdStack_Init(MeshIdStack_t* mStack){}

void AssetClerk_Init(AssetClerk_t* ac){
    ac->count = 0;

    ac->list = malloc(sizeof(Mesh_t) * BATCH_MAX_MESH_COUNT);

}

uint8_t AssetClerk_Shutdown(AssetClerk_t* ac){

}




uint8_t AssetClerk_NewAsset(AssetClerk_t* ac){
    
}



uint8_t AssetClerk_RemoveAsset(AssetClerk_t* ac){

}



uint8_t AssetClerk_DrawMeshList(MeshID_t* idList, uint32_t listCount){

}