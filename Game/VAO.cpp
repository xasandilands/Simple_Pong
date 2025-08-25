#include"VAO.h"

VAO::VAO()
{
	glGenVertexArrays(1, &VAOref);
}

void VAO::LinkAttrib(VBO& VBO, GLuint layout, GLuint numComponets, GLenum type, GLsizeiptr stride, void* offset)
{
	VBO.Bind();
	glVertexAttribPointer(layout, numComponets, type, GL_FALSE, stride, offset);
	glEnableVertexAttribArray(layout);
	VBO.unBind();
}

void VAO::Bind()
{
	glBindVertexArray(VAOref);
}

void VAO::unBind()
{
	glBindVertexArray(0);
}

void VAO::Delete()
{
	glDeleteVertexArrays(1, &VAOref);
}