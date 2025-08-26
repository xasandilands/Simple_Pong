#version 330

out vec4 Fragcolor;

in vec3 color;
in vec2 Tex;

uniform sampler2D tex0;

void main()
{
	Fragcolor = texture(tex0, Tex);
}