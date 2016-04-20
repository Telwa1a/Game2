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

bool LLCR::hasPlayerCollidedPreviously(Player *player)
{
	//if (hasBeenCollidedWith)

	return false;
}

void LLCR::setCurrentLLCR(Player *player)
{
	attachedPlayer = player;
}

//LLCR::col

/*void LLCR::whenTriggerEnabled(Player &player)
{
}*/
