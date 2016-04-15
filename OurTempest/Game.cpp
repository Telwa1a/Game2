#include "Game.h"
#include "Enemy.h"
#include <QColor>
#include <QTimer>
Game::Game()
{
	//Definiera enum
	GameState state = IngameState;

	//Skapar en scen och sätter storleken
	//QGraphicsScene *scene = new QGraphicsScene();
	scene.setSceneRect(0, 0, 600, 450);

	//Lägger till playern i scenen
	player = new Player();
	//Player * player = new Player();
	scene.addItem(player);

	//Lägger till RombEnemy i scenen
	//RombEnemy *_romb = new RombEnemy();
	//ombenemy = new RombEnemy();
	//scene.addItem(rombenemy);

	QTimer * timer = new QTimer();
	QObject::connect(timer, SIGNAL(timeout()), rombenemy, SLOT(spawnEnemies()));
	timer->start(2000);

	//Gör playern "focusable"
	//clearFocus();
	player->setFlag(QGraphicsItem::ItemIsFocusable);
	player->setFocus();
	//view.mouse

	//QGraphicsItem *i = scene.focusItem();

	//setAttribute(Qt::WA_TransparentForMouseEvents);
	//view.setAttribute(Qt::WA_TransparentForMouseEvents);

	//scene.setFocusItem(player);
	//setFocusPolicy(Qt::NoFocus);
	//view.setFocusPolicy(Qt::NoFocus); 
	//scene.setFocusItem(player);
	//setWindowFlags(Qt::FramelessWindowHint | Qt::SubWindow);

	//Skapar en view och storleken på den samt sätter scenen till viewn
	//QGraphicsView *view = new QGraphicsView(&scene);
	view.setScene(&scene);
	view.setFixedSize(900, 900);
	//view->setViewportUpdateMode(QGraphicsView::inter);

	//Tar bort scrollbarsen
	view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	/*QTimer * timer = new QTimer();
	connect(timer, SIGNAL(timeout()), this, SLOT(enemyMoves()));
	timer->start(50);*/

	//Game update interval
	QTimer * updateTimer = new QTimer;
	updateTimer->setTimerType(Qt::PreciseTimer);
	connect(updateTimer, SIGNAL(timeout()), this, SLOT(update()));
	//timer->start(_gameUpdateInterval * 1000); //ms
	updateTimer->start(1000 / 60); //ms

	//Spawnar enemies
	QTimer * timer = new QTimer();
	QObject::connect(timer, SIGNAL(timeout()), this, SLOT(spawnEnemies(1)));
	timer->start(2000);

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
	
	view.show();
	//view.mousePressEvent()
	//ui.setupUi(this);

	//Sätt fönsterläge på spelet
	//view.setWindowState(Qt::WindowFullScreen);
}

Game::~Game()
{
}

//void QGraphicsView::mousePressEvent(QMouseEvent *event)
//{
	
//}

//void Game::updateFrameTime()
//{
	//qDebug() << _fps;
	//_fps = 0;
//}

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
	//player->playerUpdate(QKeyEvent e*);

	/*double frameTime = _frameTime->elapsed();
	_frameTime->restart();

	_accumulator += frameTime;
	//qDebug() << frameTime;
	if (_accumulator >= _physicsUpdateInterval * 1000){
		_physicsSystem.run();
		_accumulator -= _physicsUpdateInterval * 1000;
	}
	_fps += 1;

	_scene.update();
	_view.centerOn(_player->getPos().x + _view.rect().width() / 5, _player->getPos().y);*/

	for (int i = 0; i <= _rombVector.size(); i++){}

}
