#ifndef GAME_CLASS_H
#define GAME_CLASS_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

//enum for game state so switching between is easier
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
		//GameState, keys(array for inputs), width and height vars
		GameState State;
		bool Keys[1024];
		GLuint Width, Height;

		//constructor and destructor
		Game(GLuint width, GLuint height);
		~Game();
		//activate game
		void Activate();

		//interpret inputs
		void Inputs(float dTime);
		//update position, score ect
		void Update(float dTime);
		//render primitives
		void Render();

		
};

#endif
