#include "RombEnemy.h"


RombEnemy::RombEnemy()
{
	//TODO: make enemy in the shape of a romb
	setRect(_xPos, _yPos, _width, _hight); 

	// G�r att fienden inte "driftar �t sidan utan f�rblir station�r n�r den skalas upp
	setPos(_xPos, _yPos);
	setTransformOriginPoint(_xPos, _yPos);
}


RombEnemy::~RombEnemy()
{
}
