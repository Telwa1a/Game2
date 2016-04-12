#ifndef GAME_H
#define GAME_H

#pragma once
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QApplication>
#include <QGraphicsScene>
#include <QgraphicsView>

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

	private:
		//Ui::OurTempestClass ui;
		//Player *_player;
		//RombEnemy *_rombEnemy;
		//Course *_course;
};

#endif //GAME_H

