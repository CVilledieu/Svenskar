#pragma once

#include "glad/glad.h"
#include <glfw/glfw3.h>



//Canvas
typedef struct GLFWwindow Canvas_t;

Canvas_t* Canvas_New(int width, int height, const char* title);
uint8_t Canvas_Show(Canvas_t* canvas);





//Materials
typedef uint32_t ShaderEffectID_t;
typedef uint32_t ShaderProgramObject_t;

typedef struct ShaderEffect_t{
    ShaderProgramObject_t sProgram;
    int32_t effectaddress;
}ShaderEffect_t;

typedef struct ShaderRegistry_t{
    ShaderEffectID_t count;
    ShaderEffect_t* list;
}ShaderRegistry_t;



typedef uint32_t MeshID_t;

typedef struct MeshHandle_t{
    uint32_t indexCount;
    uint32_t baseVertex;
    size_t indexOffset;
} MeshHandle_t;

#define GEOM_VBO_BYTES (4 * 1024 * 1024)
#define GEOM_IBO_BYTES (2 * 1024 * 1024)
#define GEOM_MAX_MESHES 256

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


typedef struct Materials_t{
    ShaderRegistry_t shaderEffects;
    GeometryBuffer_t geometry;
}Materials_t;










// Frame Buffer
#define FBUFFER_FRAME_COUNT 3
#define FRAME_PEAK_BYTES_MESH 1024 //Place holders until a peak byte count can be accurately calculated
#define FRAME_PEAK_BYTES_LIGHTING 0 //Place holders until a peak byte count can be accurately calculated 

#define FRAME_BYTES (FRAME_PEAK_BYTES_MESH + FRAME_PEAK_BYTES_LIGHTING)
#define FBUFFER_TOTAL_BYTES (FBUFFER_FRAME_COUNT * FRAME_BYTES)


#define GL_FLAGS_STORAGE (GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT | GL_MAP_COHERENT_BIT) 
#define GL_FLAGS_MAP (GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT | GL_MAP_COHERENT_BIT)

#define MODEL_BINDING_INDEX 0
#define LIGHT_BINDING_INDEX 1

#define FENCE_SYNC_TIMEOUT 1000000ULL


typedef struct Frame_t{
    size_t offset;
    GLsync fence;
} Frame_t;


typedef struct FrameBuffer_t{
    uint8_t currentSlice;
    Frame_t frameList[FBUFFER_FRAME_COUNT];
    uint8_t* buffer;
    uint32_t bufferID;
}FrameBuffer_t;
