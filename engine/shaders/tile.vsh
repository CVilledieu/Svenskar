// #version and #defines injected by preamble

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormal;
layout(location = 2) in vec2 aTexCoord;

#ifdef HAS_SKINNING
layout(location = 3) in ivec4 aBoneIDs;
layout(location = 4) in vec4 aBoneWeights;
#endif

uniform mat4 uModel;
uniform mat4 uViewProj;

out vec3 vWorldPos;
out vec3 vNormal;
out vec2 vTexCoord;

#ifdef HAS_SKINNING
#define MAX_BONES 64
uniform mat4 uBones[MAX_BONES];
#endif

void main(){
    vec4 localPos = vec4(aPos, 1.0);

#ifdef HAS_SKINNING
    mat4 skinMat = uBones[aBoneIDs[0]] * aBoneWeights[0]
                 + uBones[aBoneIDs[1]] * aBoneWeights[1]
                 + uBones[aBoneIDs[2]] * aBoneWeights[2]
                 + uBones[aBoneIDs[3]] * aBoneWeights[3];
    localPos = skinMat * localPos;
    vNormal = mat3(skinMat) * aNormal;
#else
    vNormal = mat3(uModel) * aNormal;
#endif

    vec4 worldPos = uModel * localPos;
    vWorldPos = worldPos.xyz;
    vTexCoord = aTexCoord;

    gl_Position = uViewProj * worldPos;
}
