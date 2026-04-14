#include "graphics/materials/internal.h"





uint8_t GeometryBuffer_Upload(GeometryBuffer_t* geom, MeshID_t* idPtr, const void* vertices, size_t vertexBytes, const uint32_t* indices, uint32_t indexCount, size_t vertexStride){
    if(!geom || geom->count >= GEOM_MAX_MESHES){
        return 0;
    }

    size_t indexBytes = indexCount * sizeof(uint32_t);

    if(geom->vertexHead + vertexBytes > GEOM_VBO_BYTES ||
       geom->indexHead + indexBytes > GEOM_IBO_BYTES){
        return 0;
    }

    memcpy(geom->vertexPtr + geom->vertexHead, vertices, vertexBytes);
    memcpy(geom->indexPtr + geom->indexHead, indices, indexBytes);

    *idPtr = geom->count;
    MeshHandle_t* handle = &geom->meshes[*idPtr];
    handle->indexCount = indexCount;
    handle->indexOffset = geom->indexHead;
    handle->baseVertex = (uint32_t)(geom->vertexHead / vertexStride);

    geom->vertexHead += vertexBytes;
    geom->indexHead += indexBytes;
    geom->count++;

    return 1;
}




uint8_t GeometryBuffer_Init(GeometryBuffer_t* geom){
    if(!geom){
        return 0;
    }

    geom->count = 0;
    geom->vertexHead = 0;
    geom->indexHead = 0;

    glGenVertexArrays(1, &geom->vao);
    glBindVertexArray(geom->vao);

    glGenBuffers(1, &geom->vbo);
    glBindBuffer(GL_ARRAY_BUFFER, geom->vbo);
    glBufferStorage(GL_ARRAY_BUFFER, GEOM_VBO_BYTES, NULL, GL_FLAGS_STORAGE);
    geom->vertexPtr = (uint8_t*)glMapBufferRange(GL_ARRAY_BUFFER, 0, GEOM_VBO_BYTES, GL_FLAGS_MAP);
    if(!geom->vertexPtr){
        glDeleteBuffers(1, &geom->vbo);
        glDeleteVertexArrays(1, &geom->vao);
        return 0;
    }

    glGenBuffers(1, &geom->ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, geom->ibo);
    glBufferStorage(GL_ELEMENT_ARRAY_BUFFER, GEOM_IBO_BYTES, NULL, GL_FLAGS_STORAGE);
    geom->indexPtr = (uint8_t*)glMapBufferRange(GL_ELEMENT_ARRAY_BUFFER, 0, GEOM_IBO_BYTES, GL_FLAGS_MAP);
    if(!geom->indexPtr){
        glBindBuffer(GL_ARRAY_BUFFER, geom->vbo);
        glUnmapBuffer(GL_ARRAY_BUFFER);
        glDeleteBuffers(1, &geom->vbo);
        glDeleteBuffers(1, &geom->ibo);
        glDeleteVertexArrays(1, &geom->vao);
        return 0;
    }

    glBindVertexArray(0);

    return 1;
}
