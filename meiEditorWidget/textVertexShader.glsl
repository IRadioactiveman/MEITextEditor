#version 330 core

layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec2 vertexUv;

uniform mat4 model;
uniform mat4 projection;
uniform float pointSize;

out vec2 uv;

void main(){
        gl_PointSize = pointSize;
        gl_Position = projection * model * vec4(vertexPosition, 1.0);
        uv = vertexUv;
}
