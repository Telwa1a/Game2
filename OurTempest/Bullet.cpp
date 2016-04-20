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
	timer->start(1000/60);
}

Bullet::~Bullet()
{
}


void Bullet::move()
{
	if (!removeBullet && !shallBulletGo)
	{
		setPos(x(), y() - 10);

		QList <QGraphicsItem *> colliding_Items = collidingItems();
		for (int i = 0, n = colliding_Items.size(); i < n; i++)
		{
			Enemy *enemy;

			if (enemy = dynamic_cast<Enemy*>(colliding_Items[i]))
			{
				colliding_Items[i]->setZValue(1); //Enemy is automatically stopped in it's own update
				scoreToAdd = 1;
				removeBullet = true;
			}
		}
	}

	if (pos().y() + rect().height() < -600)
	{
		scene()->removeItem(this);
		delete this;
		//qDebug() << "Bullet deleted.";
		return;
	}

	if (shallBulletGo)
		destroyBullet();
}

void Bullet::destroyBullet()
{
	QList <QGraphicsItem *> colliding_Items = collidingItems();
	for (int i = 0, n = colliding_Items.size(); i < n; i++)
	{
		Enemy *enemy;
		//if (typeid(*(colliding_Items[i])) == typeid(RombEnemy))
		if (enemy = dynamic_cast<Enemy*>(colliding_Items[i]))
		{
			scene()->removeItem(colliding_Items[i]);
			scene()->removeItem(this);

			//deleta fiende och bullet fr�n heapen.
			delete colliding_Items[i];
			delete this;
		}
	}
}

int Bullet::getAddedScore()
{
	shallBulletGo = true;
	removeBullet = false;
	return scoreToAdd;
}