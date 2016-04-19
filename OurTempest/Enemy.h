#ifndef ENEMY_H
#define ENEMY_H

#pragma once
#include <QObject>
//#include "MovingGameObj.h"
#include <QGraphicsPixmapItem>

class Enemy : public QObject, public QGraphicsPixmapItem//, public MovingGameObj
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
};

#endif //ENEMY_H
