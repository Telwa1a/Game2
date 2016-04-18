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
		QGraphicsTextItem * iteum;

		void getPlayerScore(int score);
		
	private:
		int _score = 0;
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

