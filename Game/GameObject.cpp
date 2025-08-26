#include"GameObject.h"

GameObject::GameObject(glm::vec2 Pos, glm::vec2 Scale)
{
	pos = Pos;
	scale = Scale;
}

void GameObject::Draw(Shader& shader, VAO& VAO, Texture& Tex)
{
	shader.Activate();

	glm::mat4 model = glm::mat4(1.0f);

	model = glm::translate(model, glm::vec3(pos, 0.0f));

	model = glm::scale(model, glm::vec3(scale, 1.0f));

	model = glm::translate(model, glm::vec3(scale.x * 0.5f, scale.y * 0.5f, 0.0f));
	model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::translate(model, glm::vec3(scale.x * -0.5f, scale.y * -0.5f, 0.0f));

	glUniformMatrix4fv(glGetUniformLocation(shader.shaderRef, "model"), 1, GL_FALSE, glm::value_ptr(model));

	Tex.Bind();
	VAO.Bind();
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void GameObject::Inputs(float dtime, GLFWwindow* win)
{
	float speed = 1.5f;
	if (glfwGetKey(win, GLFW_KEY_DOWN) == GLFW_PRESS)
	{
		pos.y -= speed * dtime;
	}
	if (glfwGetKey(win, GLFW_KEY_UP) == GLFW_PRESS)
	{
		pos.y += speed * dtime;
	}

	float halfHeight = scale.y / 2.0f;
	if (pos.y + halfHeight > 1.0f) pos.y = 1.0f - halfHeight;
	if (pos.y - halfHeight < -1.0f) pos.y = -1.0f + halfHeight;
}