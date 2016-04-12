#include "GameObj.h"

GameObj::GameObj()
{
	setRect(0, 0, 0, 0);
	setPos(0, 0);
}

GameObj::GameObj(const float xpos, const float ypos, const float width, const float height)
{
	setPos(xpos, ypos);
	setRect(xpos, ypos, width, height);
}

GameObj::~GameObj()
{
}

struct Vector2
{
	float x;
	float y;
};
