#version 410 core

layout (location = 0) in vec3 inPos;
layout (location = 1) in vec3 inNorm;

uniform mat4 uMatModel;
uniform mat4 uMatView;
uniform mat4 uMatProjection;

out vec3 resultPos;
out vec3 resultNorm;

void main() {
    resultPos = (uMatModel * vec4(inPos, 1)).xyz;
    resultNorm = (mat3(uMatModel) * inNorm).xyz;
    gl_Position = uMatProjection * inverse(uMatView) * uMatModel * vec4(inPos, 1);
}