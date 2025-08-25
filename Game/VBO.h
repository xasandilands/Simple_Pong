#ifndef VBO_CLASS_H
#define VBO_CLASS_H

#include<glad/glad.h>

class VBO
{
	public:
		GLuint VBOref;
		VBO(GLfloat* vertices, GLsizeiptr size);

		void Bind();
		void unBind();
		void Delete();
};

#endif

