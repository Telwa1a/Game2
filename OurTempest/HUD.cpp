#include "HUD.h"

HUD::HUD()
{
	_score = 0;

	//Skriver ut text.
	setPlainText(QString("Score: ") + QString::number(_score));
	setDefaultTextColor(Qt::darkMagenta);
	setFont(QFont("Courier", 20));
	setPos(-130, -200);
}

HUD::~HUD()
{
}


void Score::increase()
{
	_score++;
	setPlainText(QString("Score: ") + QString::number(_score));
}

int Score::getScore()
{
	return _score;
}