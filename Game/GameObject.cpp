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
	model = glm::translate(model, glm::vec3(-0.5f, -0.5f, 0.0f));
	model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::scale(model, glm::vec3(scale, 1.0f));

	glUniformMatrix4fv(glGetUniformLocation(shader.shaderRef, "model"), 1, GL_FALSE, glm::value_ptr(model));

	Tex.Bind();
	VAO.Bind();
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

