#include "Game.h"
#include "Enemy.h"
#include <QColor>
#include <QTimer>

Game::Game()
{
	//Definiera enum
	state = IngameState;

	//Skapar en scen och sätter storleken
	//QGraphicsScene *scene = new QGraphicsScene();
	scene.setSceneRect(0, 0, 1600, 900); //DEFAULT RESOLUTION IS 1600X900 FOR THIS GAME
	//scene.setSceneRect(0, 0, sceneWidth, sceneHeight);

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
	//view.setFixedSize(sceneWidth, sceneHeight);
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

	//TODO: gör en koll som kollar om fienden är nedanför viewn. om detta är sant så subtrahera ett liv. scrap this shit
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

	if( state == IngameState)
		addSceneItems();
	
	//connect(bgMusic, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
	//bgMusic->setMedia(QMediaContent(QUrl("qrc:/Mega Man 3 (NES) Music - Select Screen.mp3")));
	
	bgMusic = new QMediaPlayer();
	bgMusic->setMedia(QUrl("qrc:/OurTempest/242751_CronPukers.mp3"));
	bgMusic->setVolume(40);
	bgMusic->play();
		
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

	//for (int i = 0; i <= _rombVector.size(); i++){}
	if (state == IngameState)
	{
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
			state = GameOverState;

		}



		if (!player->hasFocus() && !isGameOver)
			player->setFocus();
		//grabKeyboard();
		//update();
	}
	
}

void Game::keyPressEvent(QKeyEvent * e)
{
	if (state == GameOverState)
	{
		//TODO: lägg till någon typ av timeout så att den väntar någon sekund innan den går över till HighScoreState.
		state = HighScoreState;
	}
	if (state == HighScoreState)
	{
		//if (e->key() == Qt::Key_Enter)
		
	}
}

void Game::highScoreVector()
{
	std::vector <highScore>allHighScores(20);

	allHighScores[0].name = "AA";
	allHighScores[0].score = 1;
	allHighScores[1].name = "BB";
	allHighScores[1].score = 2;
	allHighScores[2].name = "CC";
	allHighScores[2].score = 3;
	allHighScores[3].name = "DD";
	allHighScores[3].score = 4;
	allHighScores[4].name = "EE";
	allHighScores[4].score = 5;
	allHighScores[5].name = "FF";
	allHighScores[5].score = 6;
	allHighScores[6].name = "GG";
	allHighScores[6].score = 7;
	allHighScores[7].name = "HH";
	allHighScores[7].score = 8;
	allHighScores[8].name = "II";
	allHighScores[8].score = 9;
	allHighScores[9].name = "JJ";
	allHighScores[9].score = 10;
	allHighScores[10].name = "KK";
	allHighScores[10].score = 11;
	allHighScores[11].name = "LL";
	allHighScores[11].score = 12;
	allHighScores[12].name = "MM";
	allHighScores[12].score = 13;
	allHighScores[13].name = "NN";
	allHighScores[13].score = 14;
	allHighScores[14].name = "OO";
	allHighScores[14].score = 15;
	allHighScores[15].name = "PP";
	allHighScores[15].score = 16;
	allHighScores[16].name = "QQ";
	allHighScores[16].score = 17;
	allHighScores[17].name = "RR";
	allHighScores[17].score = 18;
	allHighScores[18].name = "SS";
	allHighScores[18].score = 19;
	allHighScores[19].name = "TT";
	allHighScores[19].score = 20;


	for (int i = 0; i < allHighScores.size(); i++)
	{
		highScoreList.push_back(allHighScores[i]);
	}

	highScoreList.sort();

	/*
	highScore hS1;
	hS1.name = "FUCKOFF";
	hS1.score = 9001;

	highScore hS2;
	
	*/

	

	//highScoreList.assign("K", 10);//, ("Therese", 20), ("Robin", 30);
	//highScoreList.push_back();
	//highScoreList.assign("Therese", "20");
	//highScoreList.assign("Robin", "30");



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
	scene.addItem(player->hud->textItemInfo);
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

//bool Game::cmpScore(const highScore &A, const highScore &B)
//{
//	return A.score < B.score;
//}

