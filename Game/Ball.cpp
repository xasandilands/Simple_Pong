#include"Ball.h"

Ball::Ball(glm::vec2 pos, float radius, glm::vec2 speed)
	:GameObject(pos, glm::vec2(radius*2.0f, radius*2.0f))
{
	this->speed = speed;
	this->radius = radius;
	stuck = true;
}

void Ball::Movement(float dTime, glm::vec2 windowSize)
{
	if (stuck)
	{
		pos += speed * dTime;

		if (pos.x - radius <= 0.0f)
		{
			speed.x = -speed.x;
			pos.x = radius;
		}
		else if (pos.x + radius >= windowSize.x)
		{
			speed.x = -speed.x;
			pos.x = windowSize.x - radius;
		}

		if (pos.y - radius <= 0.0f)
		{
			speed.y = -speed.y;
			pos.y = radius;
		}
		else if(pos.y + radius >= windowSize.y)
		{
			speed.y = -speed.y;
			pos.y = windowSize.y - radius;
		}
	}
}

bool Ball::hasCollided(GameObject& paddle)
{
	{
		if (pos.x < paddle.pos.x + paddle.scale.x &&
			pos.x + scale.x/2.0f > paddle.pos.x &&
			pos.y < paddle.pos.y + paddle.scale.y &&
			pos.y + scale.y/2.0f > paddle.pos.y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

void Ball::handleCollision()
{
	speed = glm::vec2(-speed.x - 10.0f, -speed.y - 10.0f);
	std::cout << speed.y << speed.x << std::endl;
}