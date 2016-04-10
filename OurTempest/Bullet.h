#ifndef BULLET_H
#define BULLET_H

#pragma once

#include "Aircraft.h"
#include <QObject>



class Bullet : public QObject, public Aircraft
{
		Q_OBJECT
	public:
		Bullet();
		~Bullet();

	//public slots:
		//void move();
};

#endif //BULLET_H