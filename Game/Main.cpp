#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include"Shader.h"
#include"VBO.h"
#include"VAO.h"
#include"EBO.h"
#include"Texture.h"
#include"Paddle.h"
#include"Ball.h"

unsigned int width = 900, height = 900;

// Vertices coordinates
GLfloat vertices[] =
{ //     COORDINATES     /        COLORS      /   TexCoord  //
	 0.5f, -0.025f, 0.0f,    0.44f, 0.89f, 0.33f,   1.0f, 0.0f,
	 0.5f,  0.025f, 0.0f,    0.44f, 0.89f, 0.33f,   1.0f, 1.0f,
	-0.5f,  0.025f, 0.0f,    0.44f, 0.89f, 0.33f,   0.0f, 1.0f,
	-0.5f, -0.025f, 0.0f,    0.44f, 0.89f, 0.33f,   0.0f, 0.0f
};

GLfloat BallVertices[] =
{
	0.5f, -0.5f, 0.0f,    0.44f, 0.89f, 0.33f,   1.0f, 0.0f,
	0.5f,  0.5f, 0.0f,    0.44f, 0.89f, 0.33f,   1.0f, 1.0f,
	-0.5f,  0.5f, 0.0f,   0.44f, 0.89f, 0.33f,   0.0f, 1.0f,
	-0.5f, -0.5f, 0.0f,   0.44f, 0.89f, 0.33f,   0.0f, 0.0f
};

// Indices for vertices order
GLuint indices[] =
{
	0, 1, 2, 
	0, 2, 3
};

int main()
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(width, height, "Game_Window", NULL, NULL);
	if (!window)
	{
		std::cout << "window creation failed" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Glad failed to be initialized" << std::endl;
		return -1;
	}
	gladLoadGL();

	glViewport(0, 0, width, height);

	Shader spriteShader("default.vert", "default.frag");

	VAO VAO1;
	VAO1.Bind();

	VBO VBO1(vertices, sizeof(vertices));
	EBO EBO1(indices, sizeof(indices));

	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));

	VAO1.unBind();
	VBO1.unBind();
	EBO1.unBind();

	VAO VAO2;
	VAO2.Bind();

	VBO VBO2(BallVertices, sizeof(BallVertices));
	EBO EBO2(indices, sizeof(indices));

	VAO2.LinkAttrib(VBO2, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
	VAO2.LinkAttrib(VBO2, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO2.LinkAttrib(VBO2, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));

	VAO2.unBind();
	VBO2.unBind();
	EBO2.unBind();
	
	Texture Bricks("brick.jpg", GL_TEXTURE_2D, GL_TEXTURE0);
	Bricks.texUnit(spriteShader, "tex0", 0);

	Texture Grass("grass.png", GL_TEXTURE_2D, GL_TEXTURE1);
	Grass.texUnit(spriteShader, "tex1", 1);

	glm::mat4 projection = glm::ortho(0.0f, (float)width, 0.0f, (float)height, -1.0f, 1.0f);

	Paddle paddle(glm::vec2(700.0f, 450.0f), glm::vec2(200.0f, 300.0f));
	Ball ball(glm::vec2(900.0f, 200.0f), 50.0f, glm::vec2(300.0f, 300.0f));

	float deltaTime = 0.0f;
	float lastFrame = 0.0f;

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	while (!glfwWindowShouldClose(window))
	{
		float currFrame = glfwGetTime();
		deltaTime = currFrame - lastFrame;
		lastFrame = currFrame;

		glClearColor(0.0f, 0.7f, 0.9f, 0.5f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		spriteShader.Activate();
		
		glUniformMatrix4fv(glGetUniformLocation(spriteShader.shaderRef, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
		glUniform1i(glGetUniformLocation(spriteShader.shaderRef, "useTex"), 0);
		paddle.Draw(spriteShader, VAO1, Bricks);
		paddle.Inputs(deltaTime, window, height);

		glUniform1i(glGetUniformLocation(spriteShader.shaderRef, "useTex"), 1);
		ball.Draw(spriteShader, VAO2, Grass);
		ball.Movement(deltaTime, glm::vec2((float)width, (float)height));
		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	return 0;
}