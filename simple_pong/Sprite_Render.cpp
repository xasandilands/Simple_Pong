#include"Sprite_Render.h"

Sprite_Render::Sprite_Render(Shader &s)
	: shader(shader)
{
	GLuint VBO;
	//vertices data
	float vertices[] = {
		//  coords      //    tex
			0.0f, 1.0f,     0.0f, 1.0f,
			1.0f, 0.0f,     1.0f, 0.0f,
			0.0f, 0.0f,     0.0f, 0.0f,

			0.0f, 1.0f,     0.0f, 1.0f,
			1.0f, 1.0f,     1.0f, 1.0f,
			1.0f, 0.0f,     1.0f, 0.0f
	};

	//generate VBO and quadVAO
	glGenVertexArrays(1, &quadVAO);
	glGenBuffers(1, &VBO);

	//bind VBO and stores vertices in VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindVertexArray(quadVAO);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

Sprite_Render::~Sprite_Render()
{
	glDeleteVertexArrays(1, &quadVAO);
}

void Sprite_Render::Draw(Texture& texture, glm::vec2 position, glm::vec2 size, float rotate, glm::vec3 color)
{
	//activate shader
	shader.Activate();

	//create model mat4 and translate to pos
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(position, 0.0f));

	//rotation (translating so rotation pivot falls at center of sprite
	model = glm::translate(model, glm::vec3(size.x * 0.5f, size.y * 0.5f, 0.0f));
	model = glm::rotate(model, glm::radians(rotate), glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::translate(model, glm::vec3(size.x * -0.5f, size.y * -0.5f, 0.0f));

	//scale model to desired size
	model = glm::scale(model, glm::vec3(size, 1.0f));

	//send information to shaders
	shader.SetMat4("model", model);
	shader.SetVec3f("color", color);
	
	//bind texture
	glActiveTexture(GL_TEXTURE0);
	texture.Bind();

	//draw
	glBindVertexArray(quadVAO);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);

}