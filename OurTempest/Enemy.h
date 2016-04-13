#pragma once
#include <QObject>
#include "MovingGameObj.h"

class Enemy : public QObject ,public MovingGameObj
{
	Q_OBJECT
	public:
		Enemy();
		~Enemy();

	private slots:
		void enemyMoves();
		void makeEnemyBigger();
		void spawnEnemies();
};

