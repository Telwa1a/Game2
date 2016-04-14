#ifndef PLAYER_H
#define PLAYER_H

#pragma once
#include "MovingGameObj.h"
#include <QKeyEvent>

class Player : public MovingGameObj //,QGraphicsItem
{
	//Q_OBJECT

	public:
		Player();
		~Player();

		//void paint (QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0);
		//void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;

		void keyPressEvent(QKeyEvent *e);
		void keyReleaseEvent(QKeyEvent *e);
		//void timerEvent(QTimerEvent *);

	private:
		bool isKeyPressed;
		//Player *_player1;
		//QMap<int, bool> keys;

};

#endif //PLAYER_H