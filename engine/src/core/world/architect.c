#include "world/architect.h"
#include "world/assets/manager.h"



void Architect_Init(Architect_t* architect){
    AssetManager_Init(&architect->assMan);
    Entities_Init()
}






uint8_t Architect_Submit(uint8_t* displayBuffer){
    if(!displayBuffer){
        return 0;
    }

    

    return 1;
}