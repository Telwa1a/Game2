#include "RombEnemy.h"


RombEnemy::RombEnemy()
{
	//TODO: make enemy in the shape of a romb
	setRect(_xPos, _yPos, _width, _hight); //Får vi från movingGameObject
	setPos(_xPos, _yPos);
	setTransformOriginPoint(_xPos, _yPos);
}


RombEnemy::~RombEnemy()
{
}
