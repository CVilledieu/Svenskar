#pragma 
#include "core/config.h"



typedef uint16_t SPIndex;

typedef struct ShaderEffect_t{
    char* name;
    uint16_t effectAddress;
}ShaderEffect_t;

typedef struct ShaderProgram_t{
    uint16_t id;
    uint16_t effectCount;
    ShaderEffect_t* effectList;
}ShaderProgram_t;



typedef struct ShaderList_t{
    uint16_t count;
    ShaderProgram_t* programs;
}ShaderList_t;

