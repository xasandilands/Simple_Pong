#ifndef TEXTURE_CLASS_H
#define TEXTURE_CLASS_H

#include<glad/glad.h>
#include"stb_image.h"

#include"Shader.h"

class Texture
{
	public:
		GLuint texRef;
		GLuint unit;
		GLenum type;
		Texture(const char* img, GLenum texType, GLuint slot);

		void texUnit(Shader& shader, const char* uniform, GLuint unit);

		void Bind();
		void unBind();
		void Delete();
};

#endif 
