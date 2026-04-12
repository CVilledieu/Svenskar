#pragma 
#include "core/config.h"


typedef uint16_t AssetID;
typedef uint16_t ShaderRegistryID;
typedef uint16_t ShaderEffectID;

typedef struct ShaderEffect_t{
    char* effectName;
    uint16_t effectAddress;
}ShaderEffect_t;

typedef struct Shader_t{
    uint16_t programID;
    uint16_t effectCount;
    AssetID assetID;
    ShaderEffect_t* effectList;
}Shader_t;



typedef struct ShaderRegistry_t{
    uint16_t count;
    size_t maxLength;
    Shader_t* programs;
}ShaderRegistry_t;

uint8_t ShaderRegistry_Init(ShaderRegistry_t* sRegistry, size_t listLength);
uint8_t ShaderRegistry_RegisterShader(ShaderRegistry_t* sRegistry, ShaderRegistryID* dest, AssetID assetID, uint16_t effectCount, const char** effectNames);