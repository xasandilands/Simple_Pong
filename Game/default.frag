#version 330

out vec4 Fragcolor;

in vec3 color;

void main()
{
	Fragcolor = vec4(color, 1.0f);
}