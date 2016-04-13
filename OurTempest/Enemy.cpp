#include "Enemy.h"
#include "RombEnemy.h"
#include "Game.h"
#include <QTimer>
#include <stdlib.h>


Enemy::Enemy() : MovingGameObj()
{
	// set random position
	int randomNumber = rand() % 400;
	setPos(randomNumber, 0);

	_width = 10;
	_height = 10;

	setScale(_scale);

	setRect(randomNumber, 0, _width, _height);
	
	
	QTimer * timerMove = new QTimer();
	connect(timerMove, SIGNAL(timeout()), this, SLOT(enemyMoves()));
	timerMove->start(50);



	QTimer * timerScale = new QTimer();
	connect(timerScale, SIGNAL(timeout()), this, SLOT(makeEnemyBigger()));
	timerScale->start(50);

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
	setPos(x(), y() + 5);
}

void Enemy::spawnEnemies()
{
	//skapa en fiende
	RombEnemy * rombenemy = new RombEnemy();
	scene()->addItem(rombenemy);
}