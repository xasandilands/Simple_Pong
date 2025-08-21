#ifndef TEXTURE_CLASS_H
#define TEXTURE_CLASS_H

#include<glad/glad.h>
#include "stb_image.h"

#include"Shader.h"

class Texture
{
	public:
		//reference to texture
		GLuint texRef;
		//type of texture
		const char* type;
		//tex unit
		GLuint unit;
		//constructor
		Texture(const char* image, const char* texType, GLuint slot);
		~Texture();
		//set tex unit for shader
		void texUnit(Shader& shader, const char* uniform, GLuint unit);
		//bind texture
		void Bind();
		//unbind texture
		void Unbind();
		

};

#endif
