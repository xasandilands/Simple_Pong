#include"Shader.h"

std::string get_contents(const char* file)
{
	std::ifstream in(file, std::ios::binary);
	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	throw std::runtime_error("Could not open file: " + std::string(file));
}

Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
	const char* vShaderCode = get_contents(vertexPath).c_str();
	const char* fShaderCode = get_contents(fragmentPath).c_str();

	GLuint vertex, fragment;
	GLint success;
	GLchar infoLog[512];

	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);

	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertex, 512, NULL, infoLog);
		std::cout << "COMPILATION ERROR IN VERTEX SHADER" << infoLog << std::endl;
	}


	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode, NULL);
	glCompileShader(fragment);

	ShaderRef = glCreateProgram();
	glAttachShader(ShaderRef, vertex);
	glAttachShader(ShaderRef, fragment);
	glLinkProgram(ShaderRef);

	glDeleteShader(vertex);
	glDeleteShader(fragment);

}

void Shader::Activate()
{
	glUseProgram(ShaderRef);
}

void Shader::Delete()
{
	glDeleteProgram(ShaderRef);
}