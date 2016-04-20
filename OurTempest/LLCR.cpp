#include "LLCR.h"
#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>

LLCR::LLCR()// : GameObj()
{
	setPos(0, 0);
}

LLCR::~LLCR()
{
}

bool LLCR::hasPlayerCollided(Player *player)
{
	return false;
}

//LLCR::col

/*void LLCR::whenTriggerEnabled(Player &player)
{
}*/
