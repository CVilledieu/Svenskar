#include "render/render_internal.h"
#include <stdlib.h>
#include <string.h>



static inline uint8_t ShaderRegistry_Init(ShaderRegistry_t* sRegistry){
    if(!sRegistry){
        return 0;
    }

    sRegistry->count = 0;

    return 1;
}



static inline uint8_t GeometryBuffer_Init(GeometryBuffer_t* geom){
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



MeshID_t GeometryBuffer_Upload(GeometryBuffer_t* geom, const void* vertices, size_t vertexBytes, const uint32_t* indices, uint32_t indexCount, size_t vertexStride){
    if(!geom || geom->count >= GEOM_MAX_MESHES){
        return (MeshID_t)-1;
    }

    size_t indexBytes = indexCount * sizeof(uint32_t);

    if(geom->vertexHead + vertexBytes > GEOM_VBO_BYTES ||
       geom->indexHead + indexBytes > GEOM_IBO_BYTES){
        return (MeshID_t)-1;
    }

    memcpy(geom->vertexPtr + geom->vertexHead, vertices, vertexBytes);
    memcpy(geom->indexPtr + geom->indexHead, indices, indexBytes);

    MeshID_t id = geom->count;
    MeshHandle_t* handle = &geom->meshes[id];
    handle->indexCount = indexCount;
    handle->indexOffset = geom->indexHead;
    handle->baseVertex = (uint32_t)(geom->vertexHead / vertexStride);

    geom->vertexHead += vertexBytes;
    geom->indexHead += indexBytes;
    geom->count++;

    return id;
}



MeshID_t Materials_UploadMesh(Materials_t* mats, const void* vertices, size_t vertexBytes, const uint32_t* indices, uint32_t indexCount, size_t vertexStride){
    if(!mats){
        return (MeshID_t)-1;
    }
    return GeometryBuffer_Upload(&mats->geometry, vertices, vertexBytes,indices, indexCount, vertexStride);
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