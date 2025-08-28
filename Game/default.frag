#version 330

out vec4 FragColor;

in vec3 color;
in vec2 Tex;

uniform sampler2D tex0;
uniform sampler2D tex1;
uniform int useTex;

void main()
{
	if(useTex == 0)
	{
		FragColor = texture(tex0, Tex);
	}
	else if(useTex == 1)
	{
		FragColor = texture(tex1, Tex);
	}
}