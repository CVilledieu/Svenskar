#version 460 core

layout(location = 0) in vec3 pos;
layout(location = 1) in vec2 texCoords;

out vec2 fragTexCoords;



layout(std430, binding = ) readonly buffer TransformData {
    mat4 projectionMatrix;
    mat4 viewMatrix;
    mat4 modelMatrix[];
};


void main() {
    fragTexCoords = texCoords;
    gl_Position = projectionMatrix * viewMatrix * modelMatrix[gl_DrawID] * vec4(pos, 1.0);
}