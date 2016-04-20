#include "Game.h"
#include "Enemy.h"
#include <QColor>
#include <QTimer>

Game::Game()
{
	//Definiera enum
	GameState state = IngameState;

	//Skapar en scen och s�tter storleken
	//QGraphicsScene *scene = new QGraphicsScene();
	scene.setSceneRect(0, 0, 1600, 900); //DEFAULT RESOLUTION IS 1600X900 FOR THIS GAME

	//Definiera spelaren och s�tter fokus p� spelaren
	player = new Player();
	player->setFlag(QGraphicsItem::ItemIsFocusable);
	player->setFocus();
	//Player * player = new Player();
	//scene.addItem(player);
	//scene.removeItem(player);

	//Definierar spelbanan
	course = new Course(12, 24);

	//L�gger till RombEnemy i scenen
	//RombEnemy *_romb = new RombEnemy();
	//rombEnemy = new RombEnemy();
	//scene.addItem(rombEnemy);

	//clearFocus();
	//player->setEnabled(false);
	//view.mouse

	//QGraphicsItem *i = scene.focusItem();

	//setAttribute(Qt::WA_TransparentForMouseEvents);
	//view.setAttribute(Qt::WA_TransparentForMouseEvents);

	//scene.setFocusItem(player);
	//setFocusPolicy(Qt::NoFocus);
	//view.setFocusPolicy(Qt::NoFocus); 
	//scene.setFocusItem(player);
	//setWindowFlags(Qt::FramelessWindowHint | Qt::SubWindow);

	//Skapar en view och storleken p� den samt s�tter scenen till viewn
	//QGraphicsView *view = new QGraphicsView(&scene);
	view.setScene(&scene);
	view.setFixedSize(scene.width(), scene.height());
	view.setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

	//Tar bort scrollbarsen
	view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	/*QTimer * timer = new QTimer();
	connect(timer, SIGNAL(timeout()), this, SLOT(enemyMoves()));
	timer->start(50);*/
	signalMapper = new QSignalMapper(this);

	//Game update interval
	updateTimer = new QTimer(this);
	updateTimer->setTimerType(Qt::PreciseTimer);
	connect(updateTimer, SIGNAL(timeout()), this, SLOT(updateGame()));
	//timer->start(_gameUpdateInterval * 1000); //ms
	updateTimer->start(1000 / 60); //ms

	//Spawnar enemies
	enemySpawnTimer = new QTimer(this);
	connect(enemySpawnTimer, SIGNAL(timeout()), signalMapper, SLOT(map()));
	signalMapper->setMapping(enemySpawnTimer, 1);
	connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(spawnEnemies(int)));
	//connect(action1, SIGNAL(triggered()), signalMapper, SLOT(map()));
	//QObject::connect(enemySpawnTimer, SIGNAL(timeout()), this, SLOT(spawnEnemies()));
	enemySpawnTimer->start(2000);
	//view.setOptimizationFlag(QGraphicsView::IndirectPainting);

	//Initierar score
	//hud = new HUD();
	//scene.addItem(hud);

	//TODO: g�r en koll som kollar om fienden �r nedanf�r viewn. om detta �r sant s� subtrahera ett liv. scrap this shit
	/*for (int i = 0; i < _rombVector.size(); i++)
	{
		if ( [........] scene.height)
		{
			player->hud->_health -= 1;

			if (player->hud->_health == 0);
			{
				//Print "GAME OVER"
			}
			//subractALife();
	
		}
	}
	*/
	
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
	addSceneItems();

	view.show();
	//view.mousePressEvent()
	//ui.setupUi(this);

	//S�tt f�nsterl�ge p� spelet
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
		//L�gger till fiende i scenen.
		rombEnemy = new RombEnemy();
		scene.addItem(rombEnemy);

		//L�gger till fiende i vectorn.
		rombVector.push_back(rombEnemy);
	}
}

void Game::updateGame()
{
	//QScreen
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

	//for (int i = 0; i <= _rombVector.size(); i++){}

	if (player->getHealth() <= 0 && !isGameOver)
	{
		scene.setFocus();
		player->setControls(false);

		QList <QGraphicsItem*> allItems = scene.items();
		for (int i = 0; i < allItems.length(); i++)
		{
			MovingGameObj * moveObj;

			if (moveObj = dynamic_cast<MovingGameObj*>(allItems[i]))
				moveObj->stopMovement();
		}

		enemySpawnTimer->stop();
		isGameOver = true;
	}
	
	if (!player->hasFocus() && !isGameOver)
		player->setFocus();
	//grabKeyboard();
	//update();
}

void Game::addSceneItems()
{
	scene.addItem(player);
	scene.addItem(course);
	//scene.addItem(player->hud);
	course->addLinesToScene(scene);
	
	scene.addItem(player->hud);
	scene.addItem(player->hud->textItemScore);
	scene.addItem(player->hud->textItemHealth);
	scene.addItem(player->hud->textItemGAMEOVER);
}

void Game::removeSceneItems()
{
	scene.clear();
}

void Game::disableSceneItems()
{
	foreach(QGraphicsItem* gameObj, scene.items())
	{
		gameObj->setEnabled(false);
	}
}

void Game::enableSceneItems()
{
	foreach(QGraphicsItem* gameObj, scene.items())
	{
		gameObj->setEnabled(true);
	}
}
