#include"Shader.h"

//reads file and returns contents in string
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
	//set string vars to shader files contents
	std::string vShader = get_contents(vertexPath);
	std::string fShader = get_contents(fragmentPath);

	//convert strings to const chars*
	const char* vShaderCode = vShader.c_str();
	const char* fShaderCode = fShader.c_str();

	//create shader objects and success and infolog for error checking
	GLuint vertex, fragment;
	GLint success;
	GLchar infoLog[512];

	//create and compile vertex shader
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);

	//check for errors
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertex, 512, NULL, infoLog);
		std::cout << "COMPILATION ERROR IN VERTEX SHADER" << infoLog << std::endl;
	}

	//create and compile fragment shader
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode, NULL);
	glCompileShader(fragment);

	//create shader program, attach shadera and link program
	ShaderRef = glCreateProgram();
	glAttachShader(ShaderRef, vertex);
	glAttachShader(ShaderRef, fragment);
	glLinkProgram(ShaderRef);

	//delete shaders not needed
	glDeleteShader(vertex);
	glDeleteShader(fragment);

}

//activate shader
void Shader::Activate()
{
	glUseProgram(ShaderRef);
}

//delete shader
void Shader::Delete()
{
	glDeleteProgram(ShaderRef);
}

//various uniform functions
void Shader::SetInt(const std::string& name, int value) const
{
	glUniform1i(glGetUniformLocation(ShaderRef, name.c_str()), value);
}

void Shader::SetFloat(const std::string& name, float value) const
{
	glUniform1f(glGetUniformLocation(ShaderRef, name.c_str()), value);
}

void Shader::SetMat4(const std::string& name, const glm::mat4 &mat) const
{
	glUniformMatrix4fv(glGetUniformLocation(ShaderRef, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
}

void Shader::SetVec4f(const std::string& name, const glm::vec4 &value) const
{
	glUniform4f(glGetUniformLocation(ShaderRef, name.c_str()), value.x, value.y, value.z, value.w);
}

void Shader::SetVec4f(const std::string& name, float x, float y, float z, float w) const
{
	glUniform4f(glGetUniformLocation(ShaderRef, name.c_str()), x, y, z, w);
}

void Shader::SetVec3f(const std::string& name, const glm::vec3& value) const
{
	glUniform3f(glGetUniformLocation(ShaderRef, name.c_str()), value.x, value.y, value.z);
}

void Shader::SetVec3f(const std::string& name, float x, float y, float z) const
{
	glUniform3f(glGetUniformLocation(ShaderRef, name.c_str()), x, y, z);
}

void Shader::SetVec2f(const std::string& name, const glm::vec2& value) const
{
	glUniform2f(glGetUniformLocation(ShaderRef, name.c_str()), value.x, value.y);
}

void Shader::SetVec2f(const std::string& name, float x, float y) const
{
	glUniform2f(glGetUniformLocation(ShaderRef, name.c_str()), x, y);
}