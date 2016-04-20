#include "GameObj.h"

GameObj::GameObj()
{
	position.x = 0;
	position.y = 0;
	size.x = 0;
	size.y = 0;
	setRect(position.x, position.y, size.x, size.y);
	setPos(position.x, position.y);
}

GameObj::GameObj(const float xpos, const float ypos, const float width, const float height)
{
	position.x = xpos;
	position.y = ypos;
	size.x = width;
	size.y = height;
	setPos(position.x, position.y);
	setRect(position.x, position.y, size.x, size.y);
}

GameObj::GameObj(const Vector2 _position, const Vector2 _size)
{
	position = _position;
	size = _size;
	setPos(position.x, position.y);
	setRect(position.x, position.y, size.x, size.y);
}

GameObj::~GameObj()
{
}

void GameObj::setObjPos(float posx, float posy)
{
	position.x = posx;
	position.y = posy;
}


