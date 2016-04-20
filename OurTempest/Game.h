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
		Course *course;
		std::vector<RombEnemy *> rombVector;
		QGraphicsScene scene;
		QGraphicsView view;
		//PhysicsSystem _physicsSystem;
		Player *player;
		RombEnemy *rombEnemy;
		QTimer *updateTimer;
		QTimer *enemySpawnTimer;
		QSignalMapper *signalMapper;
		bool isGameOver = false;
		

		//HUD * hud;
		//const float _physicsUpdateInterval; //seconds / update
		//const float _gameUpdateInterval; //seconds / update
		//long double _accumulator;
		//QTimer *_frameTimer;
		//QElapsedTimer *_frameTime;
		//int _fps;

		QGraphicsTextItem mainMenuTitle; //"THUMPEST - THE THUMPIEST OF THUMPS"
		QGraphicsTextItem pauseMenuTitle; //"THE GAME IS PAUSED"
		QGraphicsTextItem gameOverTitle; //"GAME OVER"
		QGraphicsTextItem highScoreTitle; //"THE HIGHEST OF HIGH SCORES"
		std::list<QGraphicsTextItem> highScoreList; //Array of size 20, filled with made-up mock names and mock scores - Highest score is 100000 points.

		enum GameState
		{
			MainMenuState,
			IngameState,
			PauseMenuState,
			GameOverState,
			HighScoreState
		};

		void addSceneItems(); //Adds all the neccessary items to the scene when switching over from main menu to ingame
		void removeSceneItems(); //Removes all scene items when switching over from ingame/game over to main menu/high score
		void disableSceneItems(); //Disables all the items in the scene when switching over from ingame to pause menu/game over
		void enableSceneItems(); //Enables all the items in the scene when switching over from pause menu to ingame
		//void 

	private slots:
		void spawnEnemies(int enemyNumber);
		void updateGame();
		//void updateFrameTime();
};

#endif //GAME_H

