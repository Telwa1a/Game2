#include "HUD.h"

HUD::HUD() : GameObj(0, 0, 400, 400)
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

	iteum = new QGraphicsTextItem();
	iteum->setPlainText(QString("Score: ") + QString::number(_score));
	iteum->setDefaultTextColor(Qt::darkMagenta);
	iteum->setFont(QFont("Courier", 20));
	iteum->setPos(-130, -200);
	//setTextInteractionFlags(Qt::TextEditorInteraction);

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
	iteum->setPlainText(QString("Score: ") + QString::number(_score));
}