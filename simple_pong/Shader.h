#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

#include <glad/glad.h>
#include <string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<cerrno>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//reads shader files and returns string of shader code
std::string get_contents(const char* file);

class Shader
{
	public:
		//refrence to shader
		GLuint ShaderRef;
		//constructor
		Shader(const char* vertexPath, const char* fragmentPath);
		~Shader();
		//activate shader
		void Activate();
	

		//various uniform passing functions
		void SetInt(const std::string& name, int value) const;
		void SetFloat(const std::string& name, float value) const;
		void SetMat4(const std::string& name, const glm::mat4 &mat) const;
		void SetVec4f(const std::string& name, const glm::vec4 &value) const;
		void SetVec4f(const std::string& name, float x, float y, float z, float w) const;
		void SetVec3f(const std::string& name, const glm::vec3 &value) const;
		void SetVec3f(const std::string& name, float x, float y, float z) const;
		void SetVec2f(const std::string& name, const glm::vec2 &value) const;
		void SetVec2f(const std::string& name, float x, float y) const;



};

#endif
