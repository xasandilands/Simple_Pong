#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//window width and height
int width = 800;
int height = 600;

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
	//set viewport
	glViewport(0, 0, width, height);

	//keeps program and wimdow running/open until user closes
	while (!glfwWindowShouldClose(window))
	{
		//bg color, clear color buffer
		glClearColor(0.2f, 0.0f, 0.7f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		//swap back buffer to front
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	//terminate program
	glfwDestroyWindow(window);
	glfwTerminate();
}