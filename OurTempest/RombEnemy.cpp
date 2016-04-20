#include "RombEnemy.h"
#include <qdebug.h>
//#include "Player.h"
#include "HUD.h"


RombEnemy::RombEnemy() : Enemy()
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

	//TODO: gör en koll som kollar om fienden är nedanför viewn. om detta är sant så subtrahera ett liv.
	/*if (position.y < 300)
	{
		 _health - 1;

		if (_health == 0);
		{
			//Print "GAME OVER"
		}
		//subractALife();
	}
	*/
	setTransformOriginPoint(position.x + (size.x / 2), position.y + (size.y / 2));
}


RombEnemy::~RombEnemy()
{
}

//TODO: make virtual in enemy
/*void RombEnemy::isRombEnemyActive()
{
	//om positionen av en RombEnemy är < 0 så ska ett liv subraheras.
	if (pos().y() < 300)
	{
		int newHealth = _health - 1;
		//subractALife();
	}
}
*/
