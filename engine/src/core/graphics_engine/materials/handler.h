#pragma once



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


