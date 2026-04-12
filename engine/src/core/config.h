#pragma once

#include <stdint.h>
#include "glad/glad.h"
#include <glfw/glfw3.h>


// Graphics Buffer config

// Graphics Buffer sizing config
#define FBUFFER_FRAME_COUNT 3
#define FRAME_PEAK_MODEL_BYTES 1024 //Place holders until a peak byte count can be accurately calculated
#define FRAME_PEAK_LIGHTING_BYTES 0 //Place holders until a peak byte count can be accurately calculated 



#define GL_FLAGS_STORAGE (GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT | GL_MAP_COHERENT_BIT) 
#define GL_FLAGS_MAP (GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT | GL_MAP_COHERENT_BIT)

#define MODEL_BINDING_INDEX 0
#define LIGHT_BINDING_INDEX 1

#define FENCE_SYNC_TIMEOUT 1000000ULL



