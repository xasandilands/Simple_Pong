#version 330


layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aColor;
layout(location = 2) in vec2 aTexCoord;

out vec3 Color;
out vec2 Tex;

void main()
{
	gl_Position = vec4(aPos, 1.0);
	aTexCoord = Tex;
	aColor = aColor;
}