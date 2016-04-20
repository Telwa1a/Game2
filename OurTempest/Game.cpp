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
	scene.setSceneRect(0, 0, 1600, 900); //DEFAULT RESOLUTION IS 1600X900 FOR THIS GAME

	//Definiera spelaren och sätter fokus på spelaren
	player = new Player();
	player->setFlag(QGraphicsItem::ItemIsFocusable);
	player->setFocus();
	//Player * player = new Player();
	//scene.addItem(player);
	//scene.removeItem(player);

	//Definierar spelbanan
	course = new Course(12, 24);

	//Lägger till RombEnemy i scenen
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

	//Skapar en view och storleken på den samt sätter scenen till viewn
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
	updateTimer = new QTimer;
	updateTimer->setTimerType(Qt::PreciseTimer);
	connect(updateTimer, SIGNAL(timeout()), this, SLOT(updateGame()));
	//timer->start(_gameUpdateInterval * 1000); //ms
	updateTimer->start(1000 / 60); //ms

	//Spawnar enemies
	enemySpawnTimer = new QTimer();
	connect(enemySpawnTimer, SIGNAL(timeout()), signalMapper, SLOT(map()));
	signalMapper->setMapping(enemySpawnTimer, 1);
	connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(spawnEnemies(int)));
	//connect(action1, SIGNAL(triggered()), signalMapper, SLOT(map()));
	//QObject::connect(enemySpawnTimer, SIGNAL(timeout()), this, SLOT(spawnEnemies()));
	enemySpawnTimer->start(2000);
	//view.setOptimizationFlag(QGraphicsView::IndirectPainting);

	addSceneItems();
	
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
		rombEnemy = new RombEnemy();
		scene.addItem(rombEnemy);

		//Lägger till fiende i vectorn.
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

	for (int i = 0; i <= rombVector.size(); i++){}

	if (!player->hasFocus())
		player->setFocus();
	//grabKeyboard();
	//update();
}

void Game::addSceneItems()
{
	scene.addItem(player);
	scene.addItem(course);
	scene.addItem(player->hud);
	scene.addItem(player->hud->iteum);
	course->addLinesToScene(scene);
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
