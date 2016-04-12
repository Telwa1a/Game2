#pragma once
#include <QObject>
#include "MovingGameObj.h"

class Enemy : public QObject ,public MovingGameObj
{
	Q_OBJECT
public:
	Enemy();
	~Enemy();
	 
protected:


private slots:
	void enemyMoves();
	void makeEnemyBigger();

private:
	float _scale = 0;
	float _xPos = 100;
	float _yPos = 100;
	float _width = 10;
	float _height = 10;
};

