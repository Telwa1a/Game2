#include "RombEnemy.h"
#include <qdebug.h>


RombEnemy::RombEnemy()
{
	//Set values for player variables
	velocity.x = 0;
	velocity.y = 5; //5 in speed
	velocityMax.x = 10;
	velocityMax.y = 10;
	direction.x = 0;
	direction.y = 1; //Go downwards
	size.x = 50;
	size.y = 50;
	//qDebug() << pos();
	//qDebug() << scenePos();

	//TODO: make enemy in the shape of a romb
	setRect(position.x, position.y, size.x, size.y); 

	// Gör att fienden inte "driftar åt sidan utan förblir stationär när den skalas upp
	setPos(position.x, position.y);
	setTransformOriginPoint(position.x + (size.x / 2), position.y + (size.y / 2));
}


RombEnemy::~RombEnemy()
{
}

//TODO: make virtual in enemy
void RombEnemy::isRombEnemyActive()
{
	//om positionen av en RombEnemy är < 0 så ska ett liv subraheras.
	if (pos().y() < 0)
	{
		subractALife();
	}
}