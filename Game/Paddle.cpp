#include"Paddle.h"


Paddle::Paddle(glm::vec2 pos, glm::vec2 scale)
	:GameObject(pos, scale)
{

}

void Paddle::Inputs(float dtime, GLFWwindow* win, unsigned int height)
{
	float speed = 300.0f;
	if (glfwGetKey(win, GLFW_KEY_DOWN) == GLFW_PRESS)
	{
		pos.y -= speed * dtime;
	}
	if (glfwGetKey(win, GLFW_KEY_UP) == GLFW_PRESS)
	{
		pos.y += speed * dtime;
	}

	float halfHeight = scale.y / 2.0f;
	if (pos.y + halfHeight > height) pos.y = height - halfHeight;
	if (pos.y - halfHeight < 0.0f) pos.y = halfHeight;
}