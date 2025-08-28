#include"Collisions.h"


Collisions::Collisions()
{

}

bool Collisions::hasCollided(GameObject& ball, GameObject& paddle)
{
	if (ball.pos.x < paddle.pos.x + paddle.scale.x &&
		ball.pos.x + ball.scale.x > paddle.pos.x &&
		ball.pos.y < paddle.pos.y + paddle.scale.y &&
		ball.pos.y + ball.scale.y > paddle.pos.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}