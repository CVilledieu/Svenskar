#include "world/architect.h"
#include "world/assets/manager.h"



void Architect_Init(Architect_t* architect){
    AssetManager_Init(&architect->assMan);
    Entities_Init()
}






FuncRes_t Architect_Submit(FuncRes_t* displayBuffer){
    if(!displayBuffer){
        return 0;
    }

    

    return 1;
}