#include "Enemy.h"
#include "RombEnemy.h"
#include <QTimer>


Enemy::Enemy() : MovingGameObj()
{
	_width = 10;
	_height = 10;

	setScale(_scale);

	setRect(0, 0, _width, _height);
	
	
	QTimer * timer = new QTimer();
	connect(timer, SIGNAL(timeout()), this, SLOT(enemyMoves()));
	timer->start(50);



	QTimer * timer2 = new QTimer();
	connect(timer2, SIGNAL(timeout()), this, SLOT(makeEnemyBigger()));
	timer2->start(50);

}

Enemy::~Enemy()
{
}


void Enemy::makeEnemyBigger()
{
	float currentScale = scale();

	if (currentScale >= 1)
		return;
	
	_scale = _scale + 0.01f;

	setScale(_scale);

	//update();
}

void Enemy::enemyMoves()
{
	setPos(x(), y() + 5); //Denna får vi från MovingGameObject
}

