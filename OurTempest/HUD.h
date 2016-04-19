#ifndef HUD_H
#define HUD_H

#pragma once

#include <QGraphicsTextItem>
#include <QFont>
#include <QTimer>
#include <QObject>
#include <QLabel>
#include <QTextEdit>
#include <QLCDNumber>
#include "GameObj.h"

class HUD : public QObject, public GameObj
{
	Q_OBJECT

	public:
		HUD();
		~HUD();
		//QLabel * labelina;
		QGraphicsTextItem * textItemScore;
		QGraphicsTextItem * textItemHealth;

		void getPlayerScore(int score);
		void getPlayerHealth(int health);
		
		int _health = 4;

	private:
		int _score = 0;
		//int _health = 4;
		QTimer * updateTimer;
		//QTextLine maddafacka();
		//QTextEdit * scoreText;
		//QLabel * labelina;
		//QText
		//QGraphicsItem * iteum;
		//QLCDNumber * scoar;
		void testUpdate();

	private slots:
		void updateHUD();
};

#endif //HUD_H

