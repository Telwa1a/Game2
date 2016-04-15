#ifndef GAME_H
#define GAME_H

#pragma once
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QApplication>
#include <QGraphicsScene>
#include <QgraphicsView>
#include <vector>

//#include "ui_ourtempest.h"
#include "Player.h"
#include "Course.h"
#include "RombEnemy.h"
#include <QGraphicsScene>

class Game : public QMainWindow
{
	Q_OBJECT
	public:
		Game();
		~Game();

	private slots:
		void spawnEnemies(int enemyNumber);

	private:
		//Ui::OurTempestClass ui;
		//Player *_player;
		//RombEnemy *_rombEnemy;
		//Course *_course;
		std::vector<RombEnemy *> _rombVector;
		QGraphicsScene scene;
		QGraphicsView view;
		//PhysicsSystem _physicsSystem;
		Player *player;
		//RombEnemy *rombenemy;
		//const float _physicsUpdateInterval; //seconds / update
		//const float _gameUpdateInterval; //seconds / update
		//long double _accumulator;
		//QTimer *_frameTimer;
		//QElapsedTimer *_frameTime;
		//int _fps;

		enum GameState
		{
			MainMenuState,
			IngameState,
			PauseMenuState
		};

	private slots:
		void update();
		//void updateFrameTime();
};

#endif //GAME_H

