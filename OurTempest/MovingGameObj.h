#ifndef MOVINGGAMEOBJ_H
#define MOVINGGAMEOBJ_H

#pragma once
#include "GameObj.h"

class MovingGameObj : public GameObj
{
	public:
		MovingGameObj();

		MovingGameObj(const float xdirection, const float ydirection);
		MovingGameObj(const float xdirection, const float ydirection, const float xvelocity, const float yvelocity);
		MovingGameObj(const float xdirection, const float ydirection, const float xvelocity, const float yvelocity, const float xvelocityMax, const float yvelocityMax);
		MovingGameObj(const float xdirection, const float ydirection, const float xvelocity, const float yvelocity, const float xvelocityMax, const float yvelocityMax,
			const float xposition, const float yposition);
		MovingGameObj(const float xdirection, const float ydirection, const float xvelocity, const float yvelocity, const float xvelocityMax, const float yvelocityMax,
			const float xposition, const float yposition, const float xsize, const float ysize);

		MovingGameObj(const Vector2 _direction);
		MovingGameObj(const Vector2 _direction, const Vector2 _velocity);
		MovingGameObj(const Vector2 _direction, const Vector2 _velocity, const Vector2 _maxVelocity);
		MovingGameObj(const Vector2 _direction, const Vector2 _velocity, const Vector2 _maxVelocity, const Vector2 _position);
		MovingGameObj(const Vector2 _direction, const Vector2 _velocity, const Vector2 _maxVelocity, const Vector2 _position, const Vector2 _size);

		~MovingGameObj();

	protected:
		Vector2 direction;
		Vector2 velocity;
		Vector2 velocityMax;
		void updateVelocity();
		float scale;
};

#endif //MOVINGGAMEOBJ_H

