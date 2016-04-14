#include "Player.h"
#include "MovingGameObj.h"
#include "Bullet.h"

//#include <QDebug>
Player::Player() : MovingGameObj()
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
	direction.y = 0; //Go downwards
	size.x = 100;
	size.y = 100;
	//qDebug() << pos();
	//qDebug() << scenePos();

	//setRect(250, 350, 100, 100);
	//TODO: make enemy in the shape of a romb
	setRect(position.x, position.y, size.x, size.y);

	// Gör att fienden inte "driftar åt sidan utan förblir stationär när den skalas upp
	//setPos(250, 350);
}

//TODO::Paint player just for fun
/*void Player::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0)
{
	/*QPainter *paintingPlayer;
	setBrush()
	
}
*/

void Player::keyPressEvent(QKeyEvent * e)
{
	isKeyPressed = true;
	//keys[e->key()] = true; 
	//QGraphicsRectItem::keyPressEvent(e);

	//qDebug() << "Player knows that you pressed a key";
	/*direction.x = 0;
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
	setPos(position.x, position.y);*/
}

void Player::keyReleaseEvent(QKeyEvent * e)
{
	isKeyPressed = false;
	//keys[e->key()] = false; 
	//QGraphicsRectItem::keyReleaseEvent(e);

	//direction.x = 0;
	//direction.y = 0;
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
		//scene()->addItem(bullet);
	}

	//updateVelocity();
	//setPos(position.x, position.y); 
}*/

Player::~Player()
{

}
