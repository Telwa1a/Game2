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

class Game : public QMainWindow
{
	Q_OBJECT

	public:
		Game();
		~Game();
		void update();

	private slots:
		void spawnEnemies(GameObj *);

	private:
		//Ui::OurTempestClass ui;
		//Player *_player;
		RombEnemy *_rombEnemy;
		//Course *_course;
		QGraphicsScene * _scene;
		std::vector<GameObj *> _gameObjVector;
};

#endif //GAME_H

