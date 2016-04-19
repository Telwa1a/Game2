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
#include "HUD.h"

#include <QGraphicsScene>
#include <QSignalMapper>

class Game : public QMainWindow
{
	Q_OBJECT

	public:
		Game();
		~Game();

	//protected:
		
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
		RombEnemy *rombEnemy;
		QTimer *updateTimer;
		QTimer *enemySpawnTimer;
		QSignalMapper *signalMapper;

		//HUD * hud;
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
		void spawnEnemies(int enemyNumber);
		void updateGame();
		//void updateFrameTime();
};

#endif //GAME_H

