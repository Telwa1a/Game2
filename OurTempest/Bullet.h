#ifndef BULLET_H
#define BULLET_H

#pragma once

#include "MovingGameObj.h"
#include "Enemy.h"
#include "Game.h"
#include <QList>
#include <QObject>
#include <QTimer>

class Bullet : public QObject, public MovingGameObj
{
	Q_OBJECT

	public:
		Bullet(float xpos, float ypos);
		~Bullet();
		bool removeBullet = false;
		bool shallBulletGo = false;
		int getAddedScore();

	private:
		int scoreToAdd;
		void destroyBullet(bool goThroughCollisionObjects);
		QTimer * timer;

	public slots:
		void move();
};

#endif //BULLET_H