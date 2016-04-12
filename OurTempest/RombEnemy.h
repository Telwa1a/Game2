#pragma once
#include "Enemy.h"

class RombEnemy :
	public Enemy
{
public:
	RombEnemy();
	~RombEnemy();



private:
	float _xPos = 200;
	float _yPos = 0; 
	float _width = 50;
	float _hight = 50;
};

