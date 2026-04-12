#include "shadereffect.h"
#include <stdlib.h>



SPIndex ShaderProgram_New(ShaderList_t* sList,){
    if(!sList){
        return 0;
    }


    return 1; 
}


uint8_t ShaderList_Init(ShaderList_t* sList, size_t listLength){
    if(!sList || listLength){
        return 0;
    }

    sList->count = 0;
    sList->programs = malloc(sizeof(ShaderProgram_t) * listLength);
    if(!sList->programs){
        return 0;
    }

    return 1;
}


uint8_t ShaderEffectCompile(ShaderEffect_t* sEffect, GLenum sType, const char* data){
    sEffect->programID = glCreateShader(sType);
    glShaderSource(sEffect->programID, 1, &data, NULL);
    
    glCompileShader(sEffect->programID);
    int success = 0;
    char infoLog[512];
    glGetShaderiv(sEffect->programID, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(sEffect->programID, 512, NULL, infoLog);
        return 0;
    }

    return 1;
}