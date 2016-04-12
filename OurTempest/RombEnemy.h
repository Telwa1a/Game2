#pragma once
#include "Enemy.h"

class RombEnemy :
	public Enemy
{
public:
	RombEnemy();
	~RombEnemy();



private:
	int _xPos = 100;
	int _yPos = 100;
	int _width = 10;
	int _hight = 10;
};

