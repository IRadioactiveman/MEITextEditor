#version 330 core

uniform vec3 color;
//in vec3 fragmentColor;
out vec4 outColor;

void main(){
        outColor = vec4(color, 0.0);
}
