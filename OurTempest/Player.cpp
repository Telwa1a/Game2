#include "Player.h"
#include "ourtempest.h"

//#include <QDebug>
Player::Player()
{

setRect(200, 350, 100, 100);

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
	//qDebug() << "Player knows that you pressed a key";

	if (e->key() == Qt::Key_A)
	{
		setPos(x() - 10, y());
	}

	else if (e->key() == Qt::Key_D)
	{
		setPos(x() + 10, y());
	}

	else if (e->key() == Qt::Key_W)
	{
		setPos(x(), y() - 10);
	}

	else if (e->key() == Qt::Key_S)
	{
		setPos(x(), y() + 10);
	}
}

Player::~Player()
{

}
