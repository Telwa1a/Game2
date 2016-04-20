#ifndef ENEMY_H
#define ENEMY_H

#pragma once

#include "MovingGameObj.h"
#include "Player.h"
#include <QList>
#include <QObject>

class Enemy : public QObject, public MovingGameObj
{
	Q_OBJECT

	public:
		Enemy();
		~Enemy();
		bool removeEnemy = false;
		//bool shallEnemyGo = false;
		//int getSubtractedHealth();

	private:
		QTimer * timerScale;
		QTimer * timerMove;
		//int healthToSub;
		void destroyEnemy();

	private slots:
		void enemyMoves();
		void makeEnemyBigger();
		//typeid(*this) getBaseEnemyName();
};

#endif //ENEMY_H
