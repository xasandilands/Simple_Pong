#include"Texture.h"

Texture::Texture(const char* image, const char* texType, GLuint slot)
{
	type = texType;

	//flip texture so facing up
	stbi_set_flip_vertically_on_load(true);

	//vars for width height and color channels
	int width, height, numCh;

	//image data
	unsigned char* data = stbi_load(image, &width, &height, &numCh, 0);
	
	//genereate texture obj
	glGenTextures(1, &texRef);

	//assign texture to unit
	glActiveTexture(GL_TEXTURE0 + slot);
	unit = slot;
	glBindTexture(GL_TEXTURE_2D, texRef);

	//config image algo for scaling up and down
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	//config image wrapping patteren
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	//checks how many color channels image has and defines it
	if (numCh == 4)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	}
	else if(numCh == 3)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	}
	else if (numCh == 1)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, width, height, 0, GL_RED, GL_UNSIGNED_BYTE, data);
	}
	else
	{
		throw std::invalid_argument("error in automatic texture processing");
	}


	//genrate minimap
	glGenerateMipmap(GL_TEXTURE_2D);

	//free img data
	stbi_image_free(data);

	//Unbind
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::texUnit(Shader& shader, const char* uniform, GLuint unit)
{
	GLuint texUni = glGetUniformLocation(shader.ShaderRef, uniform);
	shader.Activate();
	glUniform1i(texUni, unit);
}

void Texture::Bind()
{
	glActiveTexture(GL_TEXTURE0 + unit);
	glBindTexture(GL_TEXTURE_2D, texRef);
}

void Texture::Unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::Delete()
{
	glDeleteTextures(1, &texRef);
}