#ifndef GAME_CLASS_H
#define GAME_CLASS_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

enum GameState
{
	PLAYING,
	WIN,
	LOSE,
	MENU
};

class Game
{
	public:
		GameState State;
		bool Keys[1024];
		GLuint Width, Height;

		Game(GLuint width, GLuint height);
		~Game();

		void Activate();
		void Inputs(float dTime);
		void Update(float dTime);
		void Render();
};

#endif
