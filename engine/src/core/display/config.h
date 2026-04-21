#pragma once

#include <stdint.h>
#include "glad/glad.h"
#include <glfw/glfw3.h>

/*
    Dispatch controls a ring buffer
    The ring buffer is broken into segments
    Each segment a complete batch of data to be sent to the GPU

    The segment is then broken further broken into segments
    Which represents a shader layout binding's data
*/



// Rendering Batch config
#define BATCH_SYNC_TIMEOUT 1000000ULL

// CAMERA_LAYOUT_SEGMENT 

#define PROJECTION_MATRIX_LENGTH sizeof(float) * 16
#define VIEW_MATRIX_LENGTH sizeof(float) * 16
#define CAMERA_SEGMENT_LENGTH (PROJECTION_MATRIX_LENGTH + VIEW_MATRIX_LENGTH)


// MODEL_LAYOUT_SEGMENT
#define MAX_MODEL_COUNT 512
#define MODEL_LENGTH sizeof(float) * 16
#define MODEL_SEGMENT_LENGTH (MODEL_LENGTH * MAX_MODEL_COUNT)


// LIGHTING_LAYOUT_SEGMENT
#define BATCH_MAX_LIGHT_BYTES 0 //Zero'd due to not currently supported






// Rendering Buffer config

#define BATCH_ROTATION_COUNT 3

#define SEGMENTS_TOTAL_LENGTH (CAMERA_SEGMENT_LENGTH + MODEL_SEGMENT_LENGTH)
#define BUFFER_TOTAL_BYTES (SEGMENTS_TOTAL_LENGTH * BATCH_ROTATION_COUNT)



#define GL_FLAGS_STORAGE (GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT | GL_MAP_COHERENT_BIT) 
#define GL_FLAGS_MAP (GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT | GL_MAP_COHERENT_BIT)