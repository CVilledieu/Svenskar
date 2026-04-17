#pragma once

#include <stdint.h>
#include "glad/glad.h"
#include <glfw/glfw3.h>

// Rendering Buffer config

#define GL_FLAGS_STORAGE (GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT | GL_MAP_COHERENT_BIT) 
#define GL_FLAGS_MAP (GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT | GL_MAP_COHERENT_BIT)




// Rendering Batch config
#define BUFFER_BATCH_COUNT 3

#define BATCH_LENGTH_MESH 1024
#define BATCH_LENGTH_LIGHT 0 //Zero'd due to not currently supported

#define AWAIT_FENCE_TIMEOUT 1000000ULL



