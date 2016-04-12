#pragma once
#include <QObject>

class Enemy : public QObject //:public MovingGameObject
{
	Q_OBJECT
public:
	Enemy();
	Enemy(RombEnemy * rombEnemy);
	~Enemy();
	 
protected:
	void makeEnemyBigger();

private slots:
	void enemyMoves();

private:
	int _xPos = 100;
	int _yPos = 100;
	int _width = 10;
	int _hight = 10;
};

