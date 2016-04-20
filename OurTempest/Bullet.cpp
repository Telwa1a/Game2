#include "Bullet.h"
#include "Game.h"
#include <QTimer>
#include <QDebug>

Bullet::Bullet() : MovingGameObj()
{	
	//Set position
	position.x = 0;
	position.y = 0;

	//Set values for player variables
	velocity.x = 5;
	velocity.y = 5;
	velocityMax.x = 10;
	velocityMax.y = 10;
	direction.x = 0;
	direction.y = -1; //Go downwards
	size.x = 10;
	size.y = 30;
	//qDebug() << pos();
	//qDebug() << scenePos();

	//setRect(250, 350, 100, 100);
	//TODO: make enemy in the shape of a romb
	setRect(0, 0, size.x, size.y);
	setPos(position.x, position.y);

	//connect
	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(move()));
	timer->start(1000/60);
}

Bullet::~Bullet()
{
	//MovingGameObj::~MovingGameObj();
}

void Bullet::move()
{
	if (!removeBullet && !shallBulletGo)
	{
		updateVelocity();
		setPos(position.x, position.y);
		//setPos(x(), y() - 10);

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

			//QGraphicsScene *scene;
		}
	}

	if (position.x > scene()->width() || position.y > scene()->height() || position.x < 0 || position.y < 0)
	{
  		scoreToAdd = 0;
		removeBullet = true;
	}

	/*if (pos().y() + rect().height() < -600)
	{
 		scene()->removeItem(this);
		delete this;
		//qDebug() << "Bullet deleted.";
		return;
	}*/

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

			//deleta fiende och bullet från heapen.
			delete colliding_Items[i];
			//delete this;
			QObject::deleteLater();
			return;
		}
	}

 	scene()->removeItem(this);
	//delete this;
	QObject::deleteLater();
}

int Bullet::getAddedScore()
{
	shallBulletGo = true;
	removeBullet = false;
	return scoreToAdd;
}