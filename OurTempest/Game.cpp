#include "Game.h"
#include "Enemy.h"
#include <QColor>
#include <QTimer>
Game::Game()
{
	//Skapar en scen och s�tter storleken
	QGraphicsScene *scene = new QGraphicsScene();
	scene->setSceneRect(0, 0, 600, 450);

	//Skapar en view och storleken p� den samt s�tter scenen till viewn
	QGraphicsView *view = new QGraphicsView(scene);
	view->setFixedSize(900, 900);

	//Tar bort scrollbarsen
	view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


	//L�gger till playern i scenen
	Player *_player = new Player();
	scene->addItem(_player);
	_gameObjVector.push_back(_player);

	//G�r playern "focusable"
	_player->setFlag(QGraphicsItem::ItemIsFocusable);
	_player->setFocus();

	//Spawnar enemies
	QTimer * timer = new QTimer();
	QObject::connect(timer, SIGNAL(timeout()), _rombEnemy, SLOT(spawnEnemies()));
	timer->start(2000);


	update();
	view->show();
	



	


	


	

																																						//TODO: flytta detta till courseklassen. s� att det funkar som Playerklassen.
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


																																						//ui.setupUi(this);
}

Game::~Game()
{
}

void Game::spawnEnemies(GameObj *)
{
	//L�gger till fiende i scenen.
	_rombEnemy = new RombEnemy();
	_scene->addItem(_rombEnemy);

	//L�gger till fiende i vectorn.
	_gameObjVector.push_back(_rombEnemy);
}


void Game::update()
{
	for (int i = 0; i <= _gameObjVector.size(); i++){}

}


