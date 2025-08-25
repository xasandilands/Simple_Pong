#ifndef EBO_CLASS_H
#define EBO_CLASS_H

#include<glad/glad.h>

class EBO
{
	public:
		GLuint EBOref;
		EBO(GLuint* indices, GLsizeiptr size);

		void Bind();
		void unBind();
		void Delete();
};

#endif 
