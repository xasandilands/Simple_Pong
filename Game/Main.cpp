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
#include"GameObject.h"

unsigned int width = 1800, height = 900;

// Vertices coordinates
GLfloat vertices[] =
{ //     COORDINATES     /        COLORS      /   TexCoord  //
	 0.5f, -0.025f, 0.0f,    0.44f, 0.89f, 0.33f,   1.0f, 0.0f,
	 0.5f,  0.025f, 0.0f,    0.44f, 0.89f, 0.33f,   1.0f, 1.0f,
	-0.5f,  0.025f, 0.0f,    0.44f, 0.89f, 0.33f,   0.0f, 1.0f,
	-0.5f, -0.025f, 0.0f,    0.44f, 0.89f, 0.33f,    0.0f, 0.0f
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
	
	Texture Bricks("brick.jpg", GL_TEXTURE_2D, GL_TEXTURE0);;
	Bricks.texUnit(spriteShader, "tex0", 0);

	GameObject Paddle(glm::vec2(0.7f, 0.25f), glm::vec2(0.5f, 0.5f));

	glEnable(GL_DEPTH_TEST);

	float deltaTime = 0.0f;
	float lastFrame = 0.0f;

	while (!glfwWindowShouldClose(window))
	{
		float currFrame = glfwGetTime();
		deltaTime = currFrame - lastFrame;
		lastFrame = currFrame;

		glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//spriteShader.Activate();
		//Bricks.Bind();
		//VAO1.Bind();
		//glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);

		Paddle.Draw(spriteShader, VAO1, Bricks);
		Paddle.Inputs(deltaTime, window);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	return 0;
}