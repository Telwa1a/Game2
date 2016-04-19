#include "Enemy.h"
#include "RombEnemy.h"
#include <QTimer>
#include <stdlib.h>

Enemy::Enemy() : QGraphicsPixmapItem () //: MovingGameObj()
{
	// set random position
	int randomNumber = rand() % 400;
	position.x = randomNumber;
	position.y = 0;
	setPos(position.x, position.y);

	//Set values for player variables
	size.x = 10;
	size.y = 10;
	scale = 0;
	/*velocity.x = 0;
	velocity.y = 0; //5 in speed
	velocityMax.x = 10;
	velocityMax.y = 10;
	direction.x = 0;
	direction.y = 1; //Go downwards*/

	//Set player scale
	setScale(scale);

	//Set player rect
	setRect(position.x, position.y, size.x, size.y);
	
	

	timerMove = new QTimer();
	connect(timerMove, SIGNAL(timeout()), this, SLOT(enemyMoves()));
	timerMove->start(1000/60);

	timerScale = new QTimer();
	connect(timerScale, SIGNAL(timeout()), this, SLOT(makeEnemyBigger()));
	timerScale->start(1000/60);
}

Enemy::~Enemy()
{
}

void Enemy::makeEnemyBigger()
{
	float currentScale = scale;

	if (currentScale >= 1)
	{
		timerScale->stop();
		return;
	}
	
	scale = scale + 0.05f;

	setScale(scale);
}

void Enemy::enemyMoves()
{
	//setPos(x(), y() + 5);
	updateVelocity();
	setPos(position.x, position.y);

 	if (zValue() == 1)
		stopMovement();
}