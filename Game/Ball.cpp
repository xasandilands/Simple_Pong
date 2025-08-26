#include"Ball.h"


Ball::Ball(glm::vec2 Pos, glm::vec2 Scale)
	:GameObject(Pos, Scale)
{
	stuck = true;
}

glm::vec2 Ball::movement(float dtime, glm::vec2 speed)
{
	if (!stuck)
	{
		pos += speed * dtime;
		if (pos.x <= -1.0f)
		{
			speed.x = -speed.x;
			pos.x = 0;
		}
		else if (pos.x + scale.x >= 1.0f)
		{
			speed.x = -speed.x;
			pos.x = 1.0f - scale.x;
		}
		if (pos.y <= -1.0f)
		{
			speed.y = -speed.y;
			pos.y = 0.0f;
		}
	}
	return pos;
}

void Ball::reset(glm::vec2 start)
{
	pos = start;
}

