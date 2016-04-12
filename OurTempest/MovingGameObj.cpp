#include "MovingGameObj.h"

MovingGameObj::MovingGameObj() : GameObj()
{
}

MovingGameObj::MovingGameObj(const float xdirection, const float ydirection)
	: GameObj(0, 0, 0, 0)
{
}

MovingGameObj::~MovingGameObj()
{
}
