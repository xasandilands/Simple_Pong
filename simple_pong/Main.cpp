#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

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

	GLFWwindow* window = glfwCreateWindow(width, height, "OpenGL Window", NULL, NULL);
	if (!window)
	{
		std::cout << "Game window creation failed" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) 
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	glViewport(0, 0, width, height);

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.2f, 0.0f, 0.7f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	
	glfwDestroyWindow(window);
	glfwTerminate();
}