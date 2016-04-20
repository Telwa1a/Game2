#ifndef LLCR_H
#define LLCR_H

#pragma once

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QRect>
#include <QGraphicsItem>
#include "GameObj.h"
#include "Player.h"

class LLCR : public QGraphicsRectItem//, public QObject //public QRect, //public GameObj//: QRect// : public GameObj//LLCR stands for "Level Line Collision Rectangle"
{
	//Q_OBJECT

	public:
		LLCR();
		~LLCR();

	private:
		QTimer updateTimer;
		float centerX;
		float centerY;
		bool isTriggerEnabled;
		bool collisionEnabled;
		//void whenTriggerEnabled(Player &player);
		std::vector<float> allowedDirections[4];

};

#endif //LLCR_H

