#include "ourtempest.h"


OurTempest::OurTempest()

{

	QGraphicsScene *scene = new QGraphicsScene();
	scene->setSceneRect(0, 0, 600, 450);
	QGraphicsView *view = new QGraphicsView(scene);
	view->setFixedSize(600, 450);
	view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	Player *_player = new Player();
	scene->addItem(_player);
	

	scene->addLine(150, 30, 450, 30);
	scene->addLine(150, 400, 450, 400);
	scene->addLine(150, 30, 150, 150);
	scene->addLine(450, 30, 450, 150);
	scene->addLine(10, 150, 150, 150);
	scene->addLine(450, 150, 590, 150);

	/*Course *_course = new Course(*_course);
	scene->addItem(_course);*/
	view->show();

	//ui.setupUi(this);
}

OurTempest::~OurTempest()
{

}
