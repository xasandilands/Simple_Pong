#ifndef BALL_CLASS_H
#define BALL_CLASS_H

#include"GameObject.h"

class Ball : public GameObject
{
	public:
		glm::vec2 speed;
		float radius;
		bool stuck;

		Ball(glm::vec2 pos, float radius, glm::vec2 speed);
		void Movement(float dTime, glm::vec2 windowSize);
		bool hasCollided(GameObject& paddle);
};

#endif