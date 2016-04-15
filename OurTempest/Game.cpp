#include "Game.h"
#include "Enemy.h"
#include <QColor>
#include <QTimer>
Game::Game()
{
	//Skapar en scen och sätter storleken
	QGraphicsScene *scene = new QGraphicsScene();
	scene->setSceneRect(0, 0, 600, 450);

	//Skapar en view och storleken på den samt sätter scenen till viewn
	QGraphicsView *view = new QGraphicsView(scene);
	view->setFixedSize(900, 900);

	//Tar bort scrollbarsen
	view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	//Lägger till playern i scenen
	Player *_player = new Player();
	scene->addItem(_player);
	//_rombVector.push_back(_player);

	//Gör playern "focusable"
	_player->setFlag(QGraphicsItem::ItemIsFocusable);
	_player->setFocus();

	//Spawnar enemies
	QTimer * timer = new QTimer();
	QObject::connect(timer, SIGNAL(timeout()), this, SLOT(spawnEnemies(1)));
	timer->start(2000);

	update();
	view->show();

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

	//ui.setupUi(this);
}

Game::~Game()
{
}

void Game::spawnEnemies(int enemyNumber)
{
	if (enemyNumber < 1 || enemyNumber > 4)
		return;

	if (enemyNumber == 1)
	{
		//Lägger till fiende i scenen.
		RombEnemy * _rombEnemy = new RombEnemy();
		_scene->addItem(_rombEnemy);

		//Lägger till fiende i vectorn.
		_rombVector.push_back(_rombEnemy);
	}
}


void Game::update()
{
	for (int i = 0; i <= _rombVector.size(); i++){}

}


