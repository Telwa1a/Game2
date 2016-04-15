#include "Bullet.h"
#include "Game.h"
#include <QTimer>
#include <QDebug>

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
			//Ta bort både bullet och fiende.
			scene()->removeItem(colliding_Items[i]);
			scene()->removeItem(this);

			//deleta fiende och bullet från heapen.
			delete colliding_Items[i];
			delete this;
			return;

		}
	}
	if (pos().y() + rect().height() < -600)
	{
		scene()->removeItem(this);
		delete this;
		//qDebug() << "Bullet deleted.";
		return;
	}
	setPos(x(), y() - 10);
}
