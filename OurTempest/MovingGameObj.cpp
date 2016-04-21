#include "MovingGameObj.h"

MovingGameObj::MovingGameObj() : GameObj()
{
	direction.x = 0;
	direction.y = 0;
	velocity.x = 0;
	velocity.y = 0;
	velocityMax.x = 0;
	velocityMax.y = 0;
}

MovingGameObj::MovingGameObj(const float xdirection, const float ydirection)
	: GameObj(0, 0, 0, 0)
{
	direction.x = xdirection;
	direction.y = ydirection;
	velocity.x = 0;
	velocity.y = 0;
	velocityMax.x = 0;
	velocityMax.y = 0;
}

MovingGameObj::MovingGameObj(const float xdirection, const float ydirection, const float xvelocity, const float yvelocity)
	: GameObj(0, 0, 0, 0)
{
	direction.x = xdirection;
	direction.y = ydirection;
	velocity.x = xvelocity;
	velocity.y = yvelocity;
	velocityMax.x = 0;
	velocityMax.y = 0;
}

MovingGameObj::MovingGameObj(const float xdirection, const float ydirection, const float xvelocity, const float yvelocity, const float xvelocityMax, const float yvelocityMax)
	: GameObj(0, 0, 0, 0)
{
	direction.x = xdirection;
	direction.y = ydirection;
	velocity.x = xvelocity;
	velocity.y = yvelocity;
	velocityMax.x = xvelocityMax;
	velocityMax.y = yvelocityMax;
}

MovingGameObj::MovingGameObj(const float xdirection, const float ydirection, const float xvelocity, const float yvelocity, const float xvelocityMax, const float yvelocityMax,
	const float xposition, const float yposition) : GameObj(xposition, yposition, 0, 0)
{
	direction.x = xdirection;
	direction.y = ydirection;
	velocity.x = xvelocity;
	velocity.y = yvelocity;
	velocityMax.x = xvelocityMax;
	velocityMax.y = yvelocityMax;
}

MovingGameObj::MovingGameObj(const float xdirection, const float ydirection, const float xvelocity, const float yvelocity, const float xvelocityMax, const float yvelocityMax,
	const float xposition, const float yposition, const float xsize, const float ysize) : GameObj(xposition, yposition, xsize, ysize)
{
	direction.x = xdirection;
	direction.y = ydirection;
	velocity.x = xvelocity;
	velocity.y = yvelocity;
	velocityMax.x = xvelocityMax;
	velocityMax.y = yvelocityMax;
}

MovingGameObj::MovingGameObj(const Vector2 _direction)
	: GameObj(0, 0, 0, 0)
{
	direction.x = _direction.x;
	direction.y = _direction.y;
	velocity.x = 0;
	velocity.y = 0;
	velocityMax.x = 0;
	velocityMax.y = 0;
}

MovingGameObj::MovingGameObj(const Vector2 _direction, const Vector2 _velocity)
	: GameObj(0, 0, 0, 0)
{
	direction.x = _direction.x;
	direction.y = _direction.y;
	velocity.x = _velocity.x;
	velocity.y = _velocity.y;
	velocityMax.x = 0;
	velocityMax.y = 0;
}

MovingGameObj::MovingGameObj(const Vector2 _direction, const Vector2 _velocity, const Vector2 _maxVelocity)
	: GameObj(0, 0, 0, 0)
{
	direction.x = _direction.x;
	direction.y = _direction.y;
	velocity.x = _velocity.x;
	velocity.y = _velocity.y;
	velocityMax.x = _maxVelocity.x;
	velocityMax.y = _maxVelocity.y;
}

MovingGameObj::MovingGameObj(const Vector2 _direction, const Vector2 _velocity, const Vector2 _maxVelocity, const Vector2 _position)
	: GameObj(_position.x, _position.y, 0, 0)
{
	direction.x = _direction.x;
	direction.y = _direction.y;
	velocity.x = _velocity.x;
	velocity.y = _velocity.y;
	velocityMax.x = _maxVelocity.x;
	velocityMax.y = _maxVelocity.y;
}

MovingGameObj::MovingGameObj(const Vector2 _direction, const Vector2 _velocity, const Vector2 _maxVelocity, const Vector2 _position, const Vector2 _size)
	: GameObj(_position.x, _position.y, _size.x, _size.y)
{
	direction.x = _direction.x;
	direction.y = _direction.y;
	velocity.x = _velocity.x;
	velocity.y = _velocity.y;
	velocityMax.x = _maxVelocity.x;
	velocityMax.y = _maxVelocity.y;
}

MovingGameObj::~MovingGameObj()
{
}

void MovingGameObj::updateVelocity()
{
	if (velocity.x > velocityMax.x)
		velocity.x = velocityMax.x;

	if (velocity.y > velocityMax.y)
		velocity.y = velocityMax.y;

	position.x += (velocity.x * direction.x);
	position.y += (velocity.y * direction.y);
}

void MovingGameObj::stopMovement()
{
	direction.x = 0;
	direction.y = 0;
}

void MovingGameObj::setDirection(float x, float y)
{
	direction.x = x;
	direction.y = y;
}

void MovingGameObj::setVelocity(float x, float y)
{
	velocity.x = x;
	velocity.y = y;

	if (velocity.x > velocityMax.x)
		velocityMax.x = velocity.x;
}