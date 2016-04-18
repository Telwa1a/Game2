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

	// G�r att fienden inte "driftar �t sidan utan f�rblir station�r n�r den skalas upp
	setPos(position.x, position.y);
	setTransformOriginPoint(position.x + (size.x / 2), position.y + (size.y / 2));
}


RombEnemy::~RombEnemy()
{
}

//TODO: make virtual in enemy
void RombEnemy::isRombEnemyActive()
{
	//om positionen av en RombEnemy �r < 0 s� ska ett liv subraheras.
	if (pos().y() < 0)
	{
		subractALife();
	}
}