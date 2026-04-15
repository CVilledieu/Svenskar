#include "display/render/material_system/materials.h"


// Material shader effect
uint8_t Materials_LoadShaders(Materials_t* mats, const char* vertexPath, const char* fragmentPath){
    if(!mats){
        return 0;
    }
    return ShaderRegistry_LoadSource(&mats->shaderEffects, vertexPath, fragmentPath);
}


uint8_t Materials_BindShader(Materials_t* mats, ShaderFeatureFlags_t features){
    if(!mats){
        return 0;
    }
    uint32_t program = ShaderRegistry_GetProgram(&mats->shaderEffects, features);
    if(!program){
        return 0;
    }
    glUseProgram(program);
    return 1;
}





// Material mesh 
uint8_t Materials_DrawMesh(Materials_t* mats, MeshID_t meshId){
    if(!mats){
        return 0;
    }

    MeshHandle_t* mesh = &mats->geometry.meshes[meshId];
    if(!mesh){
        return 0;
    }

    glDrawElementsBaseVertex(GL_TRIANGLES, mesh->indexCount, GL_UNSIGNED_INT, (void*)mesh->indexOffset, mesh->baseVertex);

    return 1;
}


uint8_t Materials_UploadMesh(Materials_t* mats, MeshID_t* idPtr, const void* vertices, size_t vertexBytes, const uint32_t* indices, uint32_t indexCount, size_t vertexStride){
    if(!mats){
        return 0;
    }
    if(!GeometryBuffer_Upload(&mats->geometry, idPtr, vertices, vertexBytes,indices, indexCount, vertexStride)){
        return 0;
    }
    return 1;
}




// Material direct
void Materials_Shutdown(Materials_t* mats){
    if(!mats){
        return;
    }

    ShaderRegistry_Shutdown(&mats->shaderEffects);
    free(mats);
}



Materials_t* Materials_Init(void){
    Materials_t* mats = malloc(sizeof(Materials_t));
    if(!mats){
        return NULL;
    }

    if(!ShaderRegistry_Init(&mats->shaderEffects)){
        free(mats);
        return NULL;
    }

    if(!GeometryBuffer_Init(&mats->geometry)){
        free(mats);
        return NULL;
    }

    return mats;
}


