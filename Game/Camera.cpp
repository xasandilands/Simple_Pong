#include"Camera.h"


Camera::Camera(int width, int height, glm::vec3 pos)
{
	Camera::width = width;
	Camera::height = height;
	Pos = pos;
}

void Camera::Matrix(float FOVdeg, float nearPlane, float farPlane, Shader& shader, const char* uniform)
{
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);

	view = glm::lookAt(Pos, Pos + Ori, Up);

	projection = glm::perspective(glm::radians(FOVdeg), (float)width / height, nearPlane, farPlane);

	glUniformMatrix4fv(glGetUniformLocation(shader.shaderRef, uniform), 1, GL_FALSE, glm::value_ptr(projection * view));
}