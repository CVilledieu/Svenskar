#pragma once

#include <stdint.h>
#include "glad/glad.h"
#include <glfw/glfw3.h>



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



#define GEOM_VBO_BYTES (4 * 1024 * 1024)
#define GEOM_IBO_BYTES (2 * 1024 * 1024)
#define GEOM_MAX_MESHES 256


// Uber-shader feature flags (bitmask)
typedef uint32_t ShaderFeatureFlags_t;

#define SHADER_FEATURE_NONE        0
#define SHADER_FEATURE_TEXTURED    (1 << 0)
#define SHADER_FEATURE_NORMAL_MAP  (1 << 1)
#define SHADER_FEATURE_SKINNED     (1 << 2)
#define SHADER_FEATURE_LIT         (1 << 3)

#define SHADER_FEATURE_COUNT       4
#define SHADER_MAX_VARIANTS        (1 << SHADER_FEATURE_COUNT)   // 16