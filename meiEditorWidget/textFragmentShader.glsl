#version 330 core

uniform sampler2D myTextureSampler;

in vec2 uv;

out vec4 outColor;

void main(){
    outColor = vec4(0.0,0.0,0.0,0.0);//texture(myTextureSampler, uv);
}
