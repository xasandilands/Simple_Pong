#include"Shader.h"

Shader::Shader(const char* vFile, const char* fFile)
{
	GLint success;
	GLchar infoLog[1024];

	std::string vConts = get_contents(vFile);
	std::string fConts = get_contents(fFile);

	const char* vCode = vConts.c_str();
	const char* fCode = fConts.c_str();

	GLuint vShader, fShader;

	vShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vShader, 1, &vCode, NULL);

	glCompileShader(vShader);
	glGetShaderiv(vShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vShader, 1024, NULL, infoLog);
		std::cout << "ERROR IN VERTEX SHADER COMPILATION " << infoLog << std::endl;
	}

	fShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fShader, 1, &fCode, NULL);

	glCompileShader(fShader);
	glGetShaderiv(fShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fShader, 1024, NULL, infoLog);
		std::cout << "ERROR IN FRAGMENT SHADER COMPILATION " << infoLog << std::endl;
	}

	shaderRef = glCreateProgram();
	glAttachShader(shaderRef, vShader);
	glAttachShader(shaderRef, fShader);

	glLinkProgram(shaderRef);
	glGetProgramiv(shaderRef, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(shaderRef, 1024, NULL, infoLog);
		std::cout << "ERROR IN SHADER PROGRAM LINKING " << infoLog << std::endl;
	}

	glDeleteShader(vShader);
	glDeleteShader(fShader);
	
}

void Shader::Activate()
{
	glUseProgram(shaderRef);
}

void Shader::Delete()
{
	glDeleteProgram(shaderRef);
}

std::string get_contents(const char* filename)
{
	std::ifstream in(filename, std::ios::binary);
	if (in)
	{
		std::string Conts;
		in.seekg(0, std::ios::end);
		Conts.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&Conts[0], Conts.size());
		in.close();
		return (Conts);
	}
	throw std::runtime_error("ERROR, FAILED TO GET SHADER FILE CONTENTS");
}