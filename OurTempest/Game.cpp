#include "Game.h"
#include <QColor>
#include <QTimer>
Game::Game()
{
	//Skapar en scen och sätter storleken
	QGraphicsScene *scene = new QGraphicsScene();
	scene->setSceneRect(0, 0, 600, 450);

	//Lägger till playern i scenen
	Player *_player = new Player();
	scene->addItem(_player);

	//Lägger till RombEnemy i scenen
	RombEnemy *_romb = new RombEnemy();
	scene->addItem(_romb);

	//Gör playern "focusable"
	_player->setFlag(QGraphicsItem::ItemIsFocusable);
	_player->setFocus();

	//Skapar en view och storleken på den samt sätter scenen till viewn
	QGraphicsView *view = new QGraphicsView(scene);
	view->setFixedSize(900, 900);
	//view->setViewportUpdateMode(QGraphicsView::inter);
	

	//Tar bort scrollbarsen
	view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);





	/*QTimer * timer = new QTimer();
	connect(timer, SIGNAL(timeout()), this, SLOT(enemyMoves()));
	timer->start(50);*/


	

	//TODO: flytta detta till courseklassen. så att det funkar som Playerklassen.
	/*scene->addLine(150, 30, 350, 30);
	scene->addLine(150, 400, 350, 400);
	scene->addLine(150, 30, 150, 150);
	scene->addLine(350, 30, 350, 150);
	scene->addLine(10, 150, 150, 150);
	scene->addLine(350, 150, 490, 150);


	scene->addLine(350, 400, 350, 290);
	scene->addLine(150, 400, 150, 290);

	scene->addLine(10, 290, 150, 290);
	scene->addLine(350, 290, 490, 290);

	scene->addLine(490, 150, 490, 290);
	scene->addLine(10, 150, 10, 290);*/

	/*Course *_course = new Course(*_course);
	scene->addItem(_course);*/
	view->show();

	//ui.setupUi(this);
}

Game::~Game()
{
}
