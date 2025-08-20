#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include"Game.h"
#include"Shader.h"
#include"Texture.h"


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

//window width and height
const unsigned int width = 800;
const unsigned int height = 600;

Game Pong(width, height);

int main()
{
	//initialize GLFW
	glfwInit();

	//telling GLFW what ver of openGL is used
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	//tells GLFW we are using CORE profile (mordern functions only)
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//create window
	GLFWwindow* window = glfwCreateWindow(width, height, "OpenGL Window", NULL, NULL);
	if (!window)
	{
		std::cout << "Game window creation failed" << std::endl;
		glfwTerminate();
		return -1;
	}
	//sets window to current context
	glfwMakeContextCurrent(window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) 
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//set viewport
	glViewport(0, 0, width, height);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	Pong.Activate();


	float deltaTime = 0.0f;
	float prevFrame = 0.0f;
	//keeps program and wimdow running/open until user closes
	while (!glfwWindowShouldClose(window))
	{
		float currFrame = glfwGetTime();
		deltaTime = currFrame - prevFrame;
		prevFrame = currFrame;
		glfwPollEvents();

		Pong.Inputs(deltaTime);
		Pong.Update(deltaTime);

		//bg color, clear color buffer
		glClearColor(0.2f, 0.0f, 0.7f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		//swap back buffer to front
		Pong.Render();
		glfwSwapBuffers(window);
	}
	//terminate program
	glfwDestroyWindow(window);
	glfwTerminate();
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwWindowShouldClose(window) == true;
	}

	if (key >= 0 && key <= 1024)
	{
		if (action == GLFW_PRESS)
		{
			Pong.Keys[key] = true;
		}
		else if(action == GLFW_RELEASE)
		{
			Pong.Keys[key] = false;
		}
	}
}