#include "shaders.h"
#include <stdlib.h>
#include <string.h>



static inline void UpdateShaderEffects(Shader_t* shader, uint16_t effectCount, const char** effectNames){
    shader->effectCount = effectCount;
    shader->effectList = malloc(sizeof(ShaderEffect_t)* effectCount);
    if(!shader->effectList){
        return 0;
    }

    for (int i = 0; i < effectCount; i++){
        ShaderEffect_t* effect = &shader->effectList[i];
        size_t nameSize = sizeof(effectNames[i]);
        effect->effectName = malloc(nameSize);
        if(!effect->effectName){
            break;
        }
        memcpy(effect->effectName, effectNames[i], nameSize);
    }
}



uint8_t ShaderRegistry_RegisterShader(ShaderRegistry_t* sRegistry, ShaderRegistryID* dest, AssetID assetID, uint16_t effectCount, const char** effectNames){
    if(!sRegistry || sRegistry->count >= sRegistry->maxLength){
        return 0;
    }
    ShaderRegistryID registryID = sRegistry->count;
    sRegistry->count++;
    Shader_t* shader = &sRegistry->programs[registryID];
    shader->assetID = assetID;
    UpdateShaderEffects(shader, effectCount, effectNames);


    return 1; 
}


uint8_t ShaderRegistry_Init(ShaderRegistry_t* sRegistry, size_t listLength){
    if(!sRegistry || listLength){
        return 0;
    }

    sRegistry->count = 0;
    sRegistry->maxLength = listLength;
    sRegistry->programs = malloc(sizeof(Shader_t) * listLength);
    if(!sRegistry->programs){
        return 0;
    }

    return 1;
}


