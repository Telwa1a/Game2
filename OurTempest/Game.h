#ifndef GAME_H
#define GAME_H

#pragma once
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QApplication>
#include <QGraphicsScene>
#include <QgraphicsView>
#include <vector>

#include <QSignalMapper>
#include <QTMultimedia/QMediaPlayer>
#include <QUrl>
#include <QTMultimedia/QMediaContent>

//#include "ui_ourtempest.h"
#include "Player.h"
#include "Course.h"
#include "RombEnemy.h"
#include "HUD.h"

class highScore
{
	public:
		highScore(std::string &_name, int _score) : score(_score), name(_name){}
		highScore(){ name = ""; score = 0; };
		~highScore(){};

		std::string name;
		int score;
		//friend bool operator < (const highScore &A, const highScore &B);
		inline bool operator < (const highScore &A) const
		{
			return score < A.score;
		}
};

class Game : public QMainWindow
{
	Q_OBJECT

	public:
		Game();
		~Game();
		void keyPressEvent(QKeyEvent * e);
		void highScoreVector();

		//int sceneWidth = 1600;
		//int sceneHeight = 900;


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

		QMediaPlayer *bgMusic;
		
		//HUD * hud;
		//const float _physicsUpdateInterval; //seconds / update
		//const float _gameUpdateInterval; //seconds / update
		//long double _accumulator;
		//QTimer *_frameTimer;
		//QElapsedTimer *_frameTime;
		//int _fps;

		/*class highScore
		{
			highScore(std::string &_name, int _score) : score(_score), name(_name){}

			public:
				std::string name;
				int score;
				highScore& operator < (highScore);
		};

		highScore& highScore::operator < (highScore h)
		{
			return A.score < B.score;
		}*/

		QGraphicsTextItem mainMenuTitle; //"THUMPEST - THE THUMPIEST OF THUMPS"
		QGraphicsTextItem pauseMenuTitle; //"THE GAME IS PAUSED"
		QGraphicsTextItem gameOverTitle; //"GAME OVER"
		QGraphicsTextItem highScoreTitle; //"THE HIGHEST OF HIGH SCORES"
		std::list<highScore> highScoreList; //Array of size 20, filled with made-up mock names and mock scores - Highest score is 100000 points.

		enum GameState
		{
			MainMenuState,
			IngameState,
			PauseMenuState,
			GameOverState,
			HighScoreState
		};

		GameState state;

		//bool cmpScore(const highScore &A, const highScore &B);
		//{
		//	return A.score < B.score;
		//}

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

//inline bool operator < (const highScore &A, const highScore &B)
//{
//	return A.score < B.score;
//}

//highScore& highScore::operator < (highScore h)
//{
//	return score < h.score;
//}

#endif //GAME_H

