#ifndef BALL_CLASS_H
#define BALL_CLASS_H

#include<iostream>
#include<glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include<GLFW/glfw3.h>

#include"GameObject.h"

class Ball : public GameObject
{
	public:
		bool stuck;
		
		Ball(glm::vec2 Pos, glm::vec2 Scale);
		glm::vec2 movement(float dtime, glm::vec2 speed);
		void reset(glm::vec2 Start);
};

#endif 
