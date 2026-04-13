#pragma once

#include <stdint.h>





typedef struct Canvas_t Canvas_t;

Canvas_t* Canvas_Init(int width, int height, const char* title);
void Canvas_Destroy(Canvas_t* canvas);
uint8_t Canvas_Show(Canvas_t* canvas);
uint8_t Canvas_Hide(Canvas_t* canvas);



typedef struct Frame_t Frame_t;
typedef struct FrameBuffer_t FrameBuffer_t;

FrameBuffer_t* FrameBuffer_Init(void);
uint8_t FrameBuffer_GetFrame(FrameBuffer_t* fBuffer, uint8_t** destPtr);
void FrameBuffer_Shutdown(FrameBuffer_t* fBuffer);



typedef struct Materials_t Materials_t;
typedef uint32_t MeshID_t;

Materials_t* Materials_Init(void);
MeshID_t Materials_UploadMesh(Materials_t* mats, const void* vertices, size_t vertexBytes, const uint32_t* indices, uint32_t indexCount, size_t vertexStride);
uint8_t Materials_DrawMesh(Materials_t* mats, MeshID_t meshId);

