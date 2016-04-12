#include "Enemy.h"
#include "RombEnemy.h"
#include <QTimer>

Enemy::Enemy(RombEnemy * rombEnemy)
{
	

	
	
	QTimer * timer = new QTimer();
	connect(timer, SIGNAL(timeout()), this, SLOT(enemyMoves()));

	timer->start(50);
}

Enemy::~Enemy()
{
}

void Enemy::makeEnemyBigger()
{
	//for (int i = 0; )
}

void Enemy::enemyMoves()
{
	setPos(x(), y() + 10); //Denna får vi från MovingGameObject
}

