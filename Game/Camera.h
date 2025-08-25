#ifndef CAMERA_CLASS_H
#define CAMERA_CLASS_H

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<glm/gtx/rotate_vector.hpp>
#include<glm/gtx/vector_angle.hpp>

#include"Shader.h"

class Camera
{
	public:
		glm::vec3 Pos;
		glm::vec3 Ori = glm::vec3(0.0f, 0.0f, -1.0f);
		glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);

		bool firstClick;

		int width, height;

		float speed = 0.1f;
		float sens = 100.0f;

		Camera(int width, int height, glm::vec3 pos);

		void Matrix(float FOVdeg, float nearPlane, float farPlane, Shader& shader, const char* uniform);

		void Inputs(GLFWwindow* window);
};

#endif
