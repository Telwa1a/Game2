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
	//rombEnemy = new RombEnemy();
	//scene.addItem(rombEnemy);

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

	//Initierar score
	//hud = new HUD();
	//scene.addItem(hud);
	scene.addItem(player->hud);
	scene.addItem(player->hud->textItemScore);
	scene.addItem(player->hud->textItemHealth);


	//TODO: gör en koll som kollar om fienden är nedanför viewn. om detta är sant så subtrahera ett liv.
	/*if (rombEnemy->y() < 300)
	{
		//int newHealth = player->hud->_health - 1;

		/*if (newHealth == 0);
		{
			//Print "GAME OVER"
		}
		//subractALife();
		
	}*/


	
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
	

	bgMusic = new QMediaPlayer;
	bgMusic->setMedia(QMediaContent(QUrl("qrc:/Mega Man 3 (NES) Music - Select Screen.mp3")));



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
		_rombVector.push_back(rombEnemy);
	}
}

void Game::updateGame()
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
