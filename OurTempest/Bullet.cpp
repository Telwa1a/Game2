#include "Bullet.h"
#include <QTimer>

Bullet::Bullet()
{	
	//ritade bullet
	//setRect(200, 350, 10, 30);

	//connect

	QTimer * timer = new QTimer();
	connect(timer, SIGNAL(timeout()), this, SLOT(move()));

	timer->start(50);
}

Bullet::~Bullet()
{
}


void Bullet::move()
{
	setPos(x(), y() - 10);
}
