#version 330 core
layout(location=0) in vec3 aPositionNDC;
layout(location=1) in vec2 aUV;

out vec2 vUV;

void main(){
	gl_Position = vec4(aPositionNDC.x,aPositionNDC.y,aPositionNDC.z,1.0f);
	vUV = aUV;
}