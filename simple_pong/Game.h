#ifndef GAME_CLASS_H
#define GAME_CLASS_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include"Shader.h"
#include"Texture.h"
#include"Sprite_Render.h"

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
		unsigned int Width, Height;

		//constructor and destructor
		Game(unsigned int width, unsigned int height);
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
