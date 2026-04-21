#include "architect/drafting.h"
#include "architect/assets/clerk.h"



void Architect_Init(Architect_t* architect){
    AssetManager_Init(&architect->assMan);
}




uint8_t Architect_Submit(uint8_t* displayBuffer){
    if(!displayBuffer){
        return 0;
    }

    

    return 1;
}