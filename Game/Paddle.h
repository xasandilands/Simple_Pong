#ifndef PADDLE_CLASS_H
#define PADDLE_CLASS_H

#include"GameObject.h"

class Paddle : public GameObject
{
	public:
		Paddle(glm::vec2 pos, glm::vec2 scale);
		void Inputs(float dtime, GLFWwindow* win, unsigned int height);
};

#endif

