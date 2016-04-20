#include "Player.h"
#include "MovingGameObj.h"
#include "Bullet.h"
#include "Game.h"

#include <QDebug>

Player::Player() : MovingGameObj()
{
	hud = new HUD();
	//scene()->addItem(hud);
	//QGraphicsScene * scenus = scene();
	//scenus->addItem(hud);
	//_health(4, 0, 999);

	//gra
	//QKeyEvent::isAutoRepeat = false;
	updateTimer = new QTimer(this);
	connect(updateTimer, SIGNAL(timeout()), this, SLOT(playerUpdate()));
	//setCacheMode(QGraphicsItem::DeviceCoordinateCache);
	//updateTimer->setTimerType(Qt::PreciseTimer);
	//timer->start(_gameUpdateInterval * 1000); //ms
	//updateTimer->start(1000 / 60); //ms

	/*QTimer * timerKeyPress = new QTimer();
	connect(timerKeyPress, SIGNAL(timeout()), this, SLOT(keyPressEvent()));
	timerKeyPress->start(15);

	QTimer * timerKeyRelease = new QTimer();
	connect(timerKeyRelease, SIGNAL(timeout()), this, SLOT(keyReleaseEvent()));
	timerKeyRelease->start(15);*/

	//Set position
	position.x = 400;
	position.y = 400;

	//Set values for player variables
	velocity.x = 5;
	velocity.y = 5;
	velocityMax.x = 10;
	velocityMax.y = 10;
	direction.x = 0;
	direction.y = 0; //Go downwards
	size.x = 50;
	size.y = 50;
	//qDebug() << pos();
	//qDebug() << scenePos();

	//setRect(250, 350, 100, 100);
	//TODO: make enemy in the shape of a romb
	setRect(0, 0, size.x, size.y);
	setPos(position.x, position.y);

	// Gör att fienden inte "driftar åt sidan utan förblir stationär när den skalas upp
	//setPos(250, 350);

	_score = 0;
	//_health = 4;
	
}

//TODO::Paint player just for fun
/*void Player::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0)
{
	/*QPainter *paintingPlayer;
	setBrush()
	
}
*/

void Player::mousePressEvent(QMouseEvent *e)
{
	//grabMouse();
	//hasFocus();
}

void Player::mouseReleaseEvent(QMouseEvent *e)
{
	//hasFocus();
}

void Player::keyPressEvent(QKeyEvent * e)
{
	if (controlsAllowed)
	{
		//if (!hasFocus())
			//grabKeyboard();

		pressedKeys += ((QKeyEvent*)e)->key();

		//isKeyPressed = true;

		if (!updateTimer->isActive())
			updateTimer->start(1000 / 60);
		//if (updateTimer->)
		//keys[e->key()] = true; 
		//QGraphicsRectItem::keyPressEvent(e);

		//qDebug() << "Player knows that you pressed a key";
		//direction.x = 0;
		//direction.y = 0;

		//if (e->key() == Qt::Key_A)
		if (pressedKeys.contains(Qt::Key_A) && leftAllowed)
		{
			direction.x = -1;
		}

		//if (e->key() == Qt::Key_D)
		if (pressedKeys.contains(Qt::Key_D) && rightAllowed)
		{
			direction.x = 1;
		}

		//if (e->key() == Qt::Key_W)
		if (pressedKeys.contains(Qt::Key_W) && upwardsAllowed)
		{
			direction.y = -1;
		}

		//if (e->key() == Qt::Key_S)
		if (pressedKeys.contains(Qt::Key_S) && downwardsAllowed)
		{
			direction.y = 1;
		}

		//if (e->key() == Qt::Key_Space)
		if (pressedKeys.contains(Qt::Key_Space) && bulletAllowed)
		{
			//Skapar en bullet
			//Bullet bullet;
			Bullet * bullet = new Bullet();
			//bullet->setPos(x(), y());
			bullet->setObjPos(x(), y());
			//bulletArray.push_back(bullet);
			//qDebug() << "Player knows you want to kill";
			//bullet->setPos(x(), y() + 10);
			scene()->addItem(bullet);
			bulletAllowed = false;
		}
	}
}

void Player::keyReleaseEvent(QKeyEvent * e)
{
	//if (!hasFocus())
		//grabKeyboard();

	pressedKeys -= ((QKeyEvent*)e)->key();

	//isKeyPressed = false;
	//keys[e->key()] = false; 
	//QGraphicsRectItem::keyReleaseEvent(e);

	if (!pressedKeys.contains(Qt::Key_S) && !pressedKeys.contains(Qt::Key_W))
	{
		direction.y = 0;
	}

	if (!pressedKeys.contains(Qt::Key_A) && !pressedKeys.contains(Qt::Key_D))
	{
		direction.x = 0;
	}

	if (!pressedKeys.contains(Qt::Key_Space))
	{
		bulletAllowed = true;
	}

	//if (updateTimer->isActive())
		//updateTimer->stop();
}

/*void Player::timerEvent(QTimerEvent *)
{
	//if (keys[Qt::Key_Up])
	if (keys[Qt::Key_W])
		direction.y = -1;

	if (keys[Qt::Key_S])
		direction.y = 1;

	if (keys[Qt::Key_A])
		direction.x = -1;

	if (keys[Qt::Key_D])
		direction.x = 1;

	if (keys[Qt::Key_Space])
	{
		//Skapar en bullet
		Bullet * bullet = new Bullet();
		//qDebug() << "Player knows you want to kill";
		bullet->setPos(x(), y() + 10);
		scene()->addItem(bullet);
	}

	//updateVelocity();
	//setPos(position.x, position.y); 
}*/

Player::~Player()
{
}

/*void Player::playerUpdate(QKeyEvent * e)
{
	if (isKeyPressed)
	{
		direction.x = 0;
		direction.y = 0;

		if (e->key() == Qt::Key_A)
		{
			direction.x = -1;
		}

		else if (e->key() == Qt::Key_D)
		{
			direction.x = 1;
		}

		if (e->key() == Qt::Key_W)
		{
			direction.y = -1;
		}

		else if (e->key() == Qt::Key_S)
		{
			direction.y = 1;
		}

		if (e->key() == Qt::Key_Space)
		{
			//Skapar en bullet
			Bullet * bullet = new Bullet();
			//qDebug() << "Player knows you want to kill";
			bullet->setPos(x(), y() + 10);
			//scene()->addItem(bullet);
		}

		updateVelocity();
		setPos(position.x, position.y);
	}
}*/

/*void Player::subractALife()
{
	int newHealth = _health - 1;
	if (_health == 0);
		//Print "GAME OVER"
}
*/
void Player::playerUpdate()
{
	updateVelocity();

	setPos(position.x, position.y);

	QList <QGraphicsItem*> allItems = scene()->items();
	for (int i = 0; i < scene()->items().length(); i++)
	{
		if (typeid(*(allItems[i])) == typeid(Bullet))
		{
			Bullet *getBullet;

			if (getBullet = dynamic_cast<Bullet*>(allItems[i]))
			{
				if (getBullet->removeBullet)
				{
					_score = _score + getBullet->getAddedScore();
					hud->getPlayerScore(_score);
				}
			}
		}
	}

	//Kollision mellen E=Enemy och P=Player
	QList <QGraphicsItem *> colliding_Items = collidingItems();
	for (int i = 0, n = colliding_Items.size(); i < n; i++)
	{
		Enemy * getEnemy;

		if (getEnemy = dynamic_cast<Enemy*>(colliding_Items[i]))
		{
			colliding_Items[i]->setZValue(1);
			colliding_Items[i]->setAcceptDrops(true);
			getSubtractedHealth();
			break;
		
			//removeEnemy = true;
			//colliding_Items[i]->removeEnemy = true;
		}
	

		/*if (getRombEnemy = dynamic_cast<Enemy*>(collisionbetweenEandP[i]))
		{
		if (getRombEnemy->removeEnemy)
		{
		_health = _health + getRombEnemy->getSubtractedHealth();
		hud->getPlayerHealth(_health);

		getRombEnemy->removeEnemy = true;

		}
		}*/
	}
	
}

void Player::getSubtractedHealth()
{
	shallEnemyGo = true;
	removeEnemy = false;

	if (_health > 0 && _health < 99)
	{
		_health = _health - 1;
		hud->getPlayerHealth(_health);
		if (_health == 0)
		{
			hud->textItemGAMEOVER->setPos(10,200);
		}
	}

}

//int Player::_health(int n, int lower, int upper)
//{
//	return std::max(lower, std::min(n, upper));
//}

int Player::getHealth()
{
	return _health;
}

void Player::setControls(bool enabled)
{
	if (enabled == true)
		controlsAllowed = true;

	if (enabled == false)
		controlsAllowed = false;
}