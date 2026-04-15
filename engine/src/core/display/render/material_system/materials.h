#pragma once
#include "display/config.h"


typedef uint32_t ShaderEffectID_t;

typedef struct ShaderEffect_t{
    uint32_t program;
    ShaderFeatureFlags_t features;
}ShaderEffect_t;

typedef struct ShaderRegistry_t{
    ShaderEffect_t variants[SHADER_MAX_VARIANTS];
    uint8_t ready;
}ShaderRegistry_t;



uint8_t ShaderRegistry_Init(ShaderRegistry_t* sRegistry);
uint8_t ShaderRegistry_LoadSource(ShaderRegistry_t* sRegistry, const char* vertexPath, const char* fragmentPath);
uint32_t ShaderRegistry_GetProgram(ShaderRegistry_t* sRegistry, ShaderFeatureFlags_t features);
void ShaderRegistry_Shutdown(ShaderRegistry_t* sRegistry);



typedef uint32_t MeshID_t;

typedef struct MeshHandle_t{
    uint32_t indexCount;
    uint32_t baseVertex;
    size_t indexOffset;
} MeshHandle_t;



typedef struct GeometryBuffer_t{
    uint32_t vao;
    uint32_t vbo;
    uint32_t ibo;
    uint8_t* vertexPtr;
    uint8_t* indexPtr;
    size_t vertexHead;
    size_t indexHead;
    MeshHandle_t meshes[GEOM_MAX_MESHES];
    MeshID_t count;
} GeometryBuffer_t;

uint8_t GeometryBuffer_Init(GeometryBuffer_t* geom);
uint8_t GeometryBuffer_Upload(GeometryBuffer_t* geom, MeshID_t* idPtr, const void* vertices, size_t vertexBytes, const uint32_t* indices, uint32_t indexCount, size_t vertexStride);





typedef struct Materials_t{
    ShaderRegistry_t shaderEffects;
    GeometryBuffer_t geometry;
}Materials_t;

Materials_t* Materials_Init(void);
void Materials_Shutdown(Materials_t* mats);

uint8_t Materials_LoadShaders(Materials_t* mats, const char* vertexPath, const char* fragmentPath);
uint8_t Materials_BindShader(Materials_t* mats, ShaderFeatureFlags_t features);

uint8_t Materials_UploadMesh(Materials_t* mats, MeshID_t* idPtr, const void* vertices, size_t vertexBytes, const uint32_t* indices, uint32_t indexCount, size_t vertexStride);
uint8_t Materials_DrawMesh(Materials_t* mats, MeshID_t meshId);


