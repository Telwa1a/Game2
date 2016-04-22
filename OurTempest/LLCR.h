#ifndef LLCR_H
#define LLCR_H

#pragma once

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QRect>
#include <QGraphicsItem>
#include "GameObj.h"
#include "Player.h"

class LLCR : public QObject, public GameObj//, public QObject //public QRect, //public GameObj//: QRect// : public GameObj//LLCR stands for "Level Line Collision Rectangle"
{
	//Q_OBJECT

	public:
		LLCR();
		~LLCR();
		bool hasPlayerCollidedPreviously(Player *player);
		bool hasBeenCollidedWith = false;
		void setCurrentLLCR(Player *player);

	private:
		QTimer updateTimer;
		float centerX;
		float centerY;
		bool isTriggerEnabled;
		bool collisionEnabled;
		//bool hasBeenCollidedWith = false;
		//void whenTriggerEnabled(Player &player);
		std::vector<float> allowedDirections[4];
		Player * attachedPlayer; //ADDRESS TO THE PLAYER ATTACHED TO THE CURRENT LLCR
};

#endif //LLCR_H

