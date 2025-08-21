#include"Game.h"

//constructor
Game::Game(GLuint width, GLuint height)
{

}

//destructor
Game::~Game()
{

}

//activates game and initializes needed objs
void Game::Activate()
{
	Shader spriteShader;
	spriteShader.shaderCompile("default.vert", "default.frag");

	glm::mat4 projection = glm::ortho(0.0f, (float)Width, (float)Height, 0.0f, -1.0f, 1.0f);

	spriteShader.Activate().SetInt("img1", 0);
	spriteShader.SetMat4("projection", projection);
}
//interprets inputs per delta time frame
void Game::Inputs(float dTime)
{

}

//updates position, score ect per delta time frame
void Game::Update(float dTime)
{

}

//renders
void Game::Render()
{

}
