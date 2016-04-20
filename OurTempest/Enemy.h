#ifndef ENEMY_H
#define ENEMY_H

#pragma once
#include <QObject>
#include "MovingGameObj.h"

class Enemy : public QObject, public MovingGameObj
{
	Q_OBJECT

	public:
		Enemy();
		~Enemy();

	private:
		QTimer * timerScale;
		QTimer * timerMove;

	private slots:
		void enemyMoves();
		void makeEnemyBigger();
		//typeid(*this) getBaseEnemyName();
};

#endif //ENEMY_H
