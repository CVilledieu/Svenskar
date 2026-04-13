#include "render/materials/internal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



static uint32_t CompileShaderStage(GLenum stage, const char* preamble, const char* source){
    const char* sources[2] = { preamble, source };

    uint32_t shader = glCreateShader(stage);
    glShaderSource(shader, 2, sources, NULL);
    glCompileShader(shader);

    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success){
        char log[512];
        glGetShaderInfoLog(shader, sizeof(log), NULL, log);
        fprintf(stderr, "Shader compile error:\n%s\n", log);
        glDeleteShader(shader);
        return 0;
    }

    return shader;
}



static uint32_t LinkProgram(uint32_t vert, uint32_t frag){
    uint32_t program = glCreateProgram();
    glAttachShader(program, vert);
    glAttachShader(program, frag);
    glLinkProgram(program);

    int success;
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if(!success){
        char log[512];
        glGetProgramInfoLog(program, sizeof(log), NULL, log);
        fprintf(stderr, "Shader link error:\n%s\n", log);
        glDeleteProgram(program);
        return 0;
    }

    return program;
}



static void BuildPreamble(char* buf, size_t bufSize, ShaderFeatureFlags_t flags){
    int offset = snprintf(buf, bufSize, "#version 430 core\n");

    if(flags & SHADER_FEATURE_TEXTURED){
        offset += snprintf(buf + offset, bufSize - offset, "#define HAS_TEXTURE\n");
    }
    if(flags & SHADER_FEATURE_NORMAL_MAP){
        offset += snprintf(buf + offset, bufSize - offset, "#define HAS_NORMAL_MAP\n");
    }
    if(flags & SHADER_FEATURE_SKINNED){
        offset += snprintf(buf + offset, bufSize - offset, "#define HAS_SKINNING\n");
    }
    if(flags & SHADER_FEATURE_LIT){
        offset += snprintf(buf + offset, bufSize - offset, "#define HAS_LIGHTING\n");
    }
}



static char* LoadFileContents(const char* path){
    FILE* f = fopen(path, "rb");
    if(!f){
        fprintf(stderr, "Failed to open shader file: %s\n", path);
        return NULL;
    }

    fseek(f, 0, SEEK_END);
    long len = ftell(f);
    fseek(f, 0, SEEK_SET);

    char* buf = malloc(len + 1);
    if(!buf){
        fclose(f);
        return NULL;
    }

    fread(buf, 1, len, f);
    buf[len] = '\0';
    fclose(f);

    return buf;
}



uint8_t ShaderRegistry_Init(ShaderRegistry_t* sRegistry){
    if(!sRegistry){
        return 0;
    }

    memset(sRegistry->variants, 0, sizeof(sRegistry->variants));
    sRegistry->ready = 0;

    return 1;
}



uint8_t ShaderRegistry_LoadSource(ShaderRegistry_t* sRegistry, const char* vertexPath, const char* fragmentPath){
    if(!sRegistry){
        return 0;
    }

    char* vertSrc = LoadFileContents(vertexPath);
    char* fragSrc = LoadFileContents(fragmentPath);
    if(!vertSrc || !fragSrc){
        free(vertSrc);
        free(fragSrc);
        return 0;
    }

    char preamble[512];

    for(uint32_t flags = 0; flags < SHADER_MAX_VARIANTS; flags++){
        BuildPreamble(preamble, sizeof(preamble), (ShaderFeatureFlags_t)flags);

        uint32_t vert = CompileShaderStage(GL_VERTEX_SHADER, preamble, vertSrc);
        uint32_t frag = CompileShaderStage(GL_FRAGMENT_SHADER, preamble, fragSrc);

        if(!vert || !frag){
            if(vert) glDeleteShader(vert);
            if(frag) glDeleteShader(frag);
            sRegistry->variants[flags].program = 0;
            continue;
        }

        uint32_t program = LinkProgram(vert, frag);
        glDeleteShader(vert);
        glDeleteShader(frag);

        sRegistry->variants[flags].program = program;
        sRegistry->variants[flags].features = (ShaderFeatureFlags_t)flags;
    }

    free(vertSrc);
    free(fragSrc);
    sRegistry->ready = 1;

    return 1;
}



uint32_t ShaderRegistry_GetProgram(ShaderRegistry_t* sRegistry, ShaderFeatureFlags_t features){
    if(!sRegistry || !sRegistry->ready){
        return 0;
    }

    uint32_t index = features & (SHADER_MAX_VARIANTS - 1);
    return sRegistry->variants[index].program;
}



void ShaderRegistry_Shutdown(ShaderRegistry_t* sRegistry){
    if(!sRegistry){
        return;
    }

    for(uint32_t i = 0; i < SHADER_MAX_VARIANTS; i++){
        if(sRegistry->variants[i].program){
            glDeleteProgram(sRegistry->variants[i].program);
            sRegistry->variants[i].program = 0;
        }
    }

    sRegistry->ready = 0;
}