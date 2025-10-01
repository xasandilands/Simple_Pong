#ifndef AI_PADDLE_CLASS_H
#define AI_PADDLE_CLASS_H

#include "GameObject.h"

class AI_Paddle : public GameObject
{
public:
	AI_Paddle(glm::vec2 pos, glm::vec2 scale);
	void Move(glm::vec2 BallPos, float dtime, unsigned int height);
};

#endif

