#include "Bullet.h"
#include "Game.h"
#include <QTimer>

Bullet::Bullet()
{	
	//ritade bullet
	setRect(200, 350, 10, 30);

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
	QList <QGraphicsItem *> colliding_Items = collidingItems();
	for (int i = 0, n = colliding_Items.size(); i < n; i++)
	{
		if (typeid(*(colliding_Items[i])) == typeid(RombEnemy))
		{
			//Ta bort b�de bullet och fiende.
			scene()->removeItem(colliding_Items[i]);
			scene()->removeItem(this);

			//deleta fiende och bullet fr�n heapen.
			delete colliding_Items[i];
			delete this;
			return;

		}
	}

	setPos(x(), y() - 10);
}
