#ifndef BULLET_H
#define BULLET_H

#pragma once
#include "MovingGameObj.h"
#include "Enemy.h"
#include "RombEnemy.h"
#include "Game.h"
#include <QList>
#include <QObject>
#include "MovingGameObj.h"

class Bullet : public QObject, public MovingGameObj
{
	Q_OBJECT

	public:
		Bullet();
		~Bullet();

	public slots:
		void move();
};

#endif //BULLET_H