#include "AI_Paddle.h"

AI_Paddle::AI_Paddle(glm::vec2 pos, glm::vec2 scale)
	:GameObject(pos, scale)
{

}

void AI_Paddle::Move(glm::vec2 BallPos, float dtime, unsigned int height)
{
	float speed = 400.0f;
	if (BallPos.y > pos.y)
	{
		pos.y += speed * dtime;
	}
	else if (BallPos.y < pos.y)
	{
		pos.y -= speed * dtime;
	}

	float halfHeight = scale.y / 4.0f;
	if (pos.y + halfHeight > height) pos.y = height - halfHeight;
	if (pos.y - halfHeight < 0.0f) pos.y = halfHeight;

}