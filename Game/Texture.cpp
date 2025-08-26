#include"Texture.h"

Texture::Texture(const char* img, GLenum texType, GLuint slot)
{
	type = texType;

	stbi_set_flip_vertically_on_load(true);

	int width, height, numCh;

	unsigned char* data = stbi_load(img, &width, &height, &numCh, 0);

	glGenTextures(1, &texRef); 
	glActiveTexture(GL_TEXTURE0 + slot);
	unit = slot;

	glBindTexture(GL_TEXTURE_2D, texRef);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	if (numCh == 4)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	}
	else if (numCh == 3)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	}
	else if (numCh == 1)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, width, height, 0, GL_RED, GL_UNSIGNED_BYTE, data);
	}
	else
	{
		throw std::runtime_error("ERROR, UNABLE TO FIND NUMBER OF COLOR CHANNELS FOR TEXTURE");
	}

	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(data);
	
	glBindTexture(GL_TEXTURE_2D, 0);

}

void Texture::texUnit(Shader& shader, const char* uniform, GLuint unit)
{
	GLuint texUni = glGetUniformLocation(shader.shaderRef, uniform);
	shader.Activate();
	glUniform1i(texUni, unit);
}

void Texture::Bind()
{
	glActiveTexture(GL_TEXTURE0 + unit);
	glBindTexture(GL_TEXTURE_2D, texRef);
}

void Texture::unBind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::Delete()
{
	glDeleteTextures(1, &texRef);
}