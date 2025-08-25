#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

#include<glad/glad.h>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<cerrno>
#include <stdexcept>

std::string get_contents(const char* filename);

class Shader
{
public:
	GLuint shaderRef;
	Shader(const char* vFile, const char* fFile);

	void Activate();
	void Delete();
};

#endif 

