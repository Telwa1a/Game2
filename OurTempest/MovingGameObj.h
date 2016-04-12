#ifndef MOVINGGAMEOBJ_H
#define MOVINGGAMEOBJ_H

#pragma once
#include "GameObj.h"

class MovingGameObj : public GameObj
{
	public:
		MovingGameObj();
		MovingGameObj(const float xdirection, const float ydirection);
		MovingGameObj(const float xdirection, const float ydirection, const float xSetVelocity, const float ySetVelocity);
		~MovingGameObj();

	protected:
		float xDirection;
		float yDirection;
		float xVelocity;
		float yVelocity;
		float xSetVelocity;
		float ySetVelocity;
};

#endif //MOVINGGAMEOBJ_H

