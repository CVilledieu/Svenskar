#include "core.h"


int main(void){
    EngineCore_t eCore = {0};

    if(!EngineCore_Init(&eCore)){
        return 1;
    }

    EngineCore_Main(&eCore);

    return 0;
}