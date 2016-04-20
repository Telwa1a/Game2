#include "HUD.h"

HUD::HUD() : GameObj(200, 200, 450, 150)
{
	//Skriver ut text.
	//scoar = new QLCDNumber();
	//scoar->setDigitCount(1);
	//scoar->setGeometry(200, 200, 200, 200);
	//scoar->display(QString("Score: ") + QString::number(_score));
	
	/*labelina = new QLabel(0);
	labelina->setText(QString("Score: ") + QString::number(_score));
	labelina->setFont(QFont("Courier", 20));
	labelina->setAlignment(Qt::AlignTop | Qt::AlignLeft);
	labelina->setGeometry(200, 200, 200, 200);
	labelina->repaint();*/

	/*setPlainText(QString("Score: ") + QString::number(_score));
	setDefaultTextColor(Qt::darkMagenta);
	setFont(QFont("Courier", 20));
	setPos(-130, -200);*/

	//scoreText = new QTextEdit();
	//scoreText->setText(QString("Score: ") + QString::number(_score));
	//scoreText->setTextColor(Qt::darkMagenta);
	//scoreText->setFont(QFont("Courier", 20));
	//scoreText->setGeometry(100, 100, 20, 10);

	/*setPlainText(QString("Score: ") + QString::number(_score));
	setDefaultTextColor(Qt::darkMagenta);
	setFont(QFont("Courier", 20));
	setPos(-130, -200);
	setTextInteractionFlags(Qt::TextEditorInteraction);*/

	//TODO: Fixa roligare fonts..
	textItemScore = new QGraphicsTextItem();
	textItemScore->setPlainText(QString("Score: ") + QString::number(_score));
	textItemScore->setDefaultTextColor(Qt::darkMagenta);
	textItemScore->setFont(QFont("Courier", 20));
	textItemScore->setPos(400, 450);
	//setTextInteractionFlags(Qt::TextEditorInteraction);

	//TODO: Fixa roligare fonts..
	textItemHealth = new QGraphicsTextItem();
	textItemHealth->setPlainText(QString("Health: ") + QString::number(_health));
	textItemHealth->setDefaultTextColor(Qt::black);
	textItemHealth->setFont(QFont("Courier", 20));
	textItemHealth->setPos(550, 450);

	//TODO: Fixa roligare fonts..
	textItemGAMEOVER = new QGraphicsTextItem();
	textItemGAMEOVER->setPlainText(QString("GAMEOVER"));
	textItemGAMEOVER->setDefaultTextColor(Qt::red);
	textItemGAMEOVER->setFont(QFont("Courier", 100));
	textItemGAMEOVER->setPos(-1000, -1000);

	updateTimer = new QTimer();
	connect(updateTimer, SIGNAL(timeout()), this, SLOT(updateHUD()));
	updateTimer->start(1000/60);
	//scene().ui
}

HUD::~HUD()
{
}

void HUD::getPlayerScore(int score)
{
	_score = score;
	//iteum->setPlainText(QString("Score: ") + QString::number(_score));
}

void HUD::getPlayerHealth(int health)
{
	_health = health;
}

void HUD::updateHUD()
{
	//if (_score >= 1)
	//setPlainText(QString("Score: ") + QString::number(_score));
	//update();
	//scoreText->setText(QString("Score: ") + QString::number(_score));
	//scoreText->repaint();
	//scoar->display(QString("Score: ") + QString::number(_score));
	//labelina->repaint();
	//iteum->update();
	textItemScore->setPlainText(QString("Score: ") + QString::number(_score));
	textItemHealth->setPlainText(QString("Health: ") + QString::number(_health));
	textItemGAMEOVER->setPlainText(QString("GAMEOVER"));
}