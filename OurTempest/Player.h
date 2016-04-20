#ifndef PLAYER_H
#define PLAYER_H

#pragma once

#include <QKeyEvent>
#include <QObject>
#include <QTimer>

#include "HUD.h"
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

		HUD * hud;

		void addScoreToHUD();
		void getSubtractedHealth();
		bool removeEnemy = false;
		bool shallEnemyGo = false;
		//void addHealthToHUD();
		//void subractALife();

	private:
		//bool isKeyPressed = false;
		QTimer *updateTimer;
		//Player *_player1;
		//QMap<int, bool> keys;
		QSet<int> pressedKeys;
		//std::vector<Bullet> bulletArray;

		bool upwardsAllowed = true;
		bool downwardsAllowed = true;
		bool leftAllowed = true;
		bool rightAllowed = true;
		bool bulletAllowed = true;
		bool controlsAllowed = true;

		int _score;
		int _health = 4;
		//int _health(int n, int lower, int upper);
			
		int healthToSub;

	private slots:
		//void keyPressEvent(QKeyEvent *e);
		//void keyReleaseEvent(QKeyEvent *e);
		void playerUpdate();
};

#endif //PLAYER_H