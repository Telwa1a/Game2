#ifndef OURTEMPEST_H
#define OURTEMPEST_H

#pragma once
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QApplication>
#include <QGraphicsScene>
#include <QgraphicsView>

//#include "ui_ourtempest.h"
#include "Player.h"
#include "Course.h"

class OurTempest : public QMainWindow
{
	Q_OBJECT

public:
	OurTempest();
	~OurTempest();

private:
	//Ui::OurTempestClass ui;
	Player *_player;
	//Course *_course;
};

#endif // OURTEMPEST_H
