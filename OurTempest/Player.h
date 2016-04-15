#ifndef PLAYER_H
#define PLAYER_H

#pragma once
#include <QKeyEvent>
#include <QObject>
#include <QTimer>

#include "MovingGameObj.h"

class Player : public QObject, public MovingGameObj
{
	Q_OBJECT
	public:
		Player();
		~Player();

		//void paint (QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0);
		//void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;

		void keyPressEvent(QKeyEvent *e);
		void keyReleaseEvent(QKeyEvent *e);
		void mousePressEvent(QMouseEvent *e);
		void mouseReleaseEvent(QMouseEvent *e);
		//void timerEvent(QTimerEvent *);
		//void playerUpdate(QKeyEvent * e);

	private:
		//bool isKeyPressed = false;
		QTimer *updateTimer;
		//Player *_player1;
		//QMap<int, bool> keys;
		QSet<int> pressedKeys;

	private slots:
		//void keyPressEvent(QKeyEvent *e);
		//void keyReleaseEvent(QKeyEvent *e);
		void playerUpdate();
};

#endif //PLAYER_H