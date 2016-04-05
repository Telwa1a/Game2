#include "Player.h"

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

//TODO: make Player focusable
/*
void Player::keyPressEvent(QKeyEvent * e)
{
if (e->key() = Qt::Key_A)
{
setPos(x() - 10, y());
}


}

void Player::keyPressEvent(QKeyEvent * e)
{
if (e->key() = Qt::Key_D)
{
setPos(x() + 10, y());
}


}


void Player::keyPressEvent(QKeyEvent * e)
{
if (e->key() = Qt::Key_W)
{
setPos(x(), y()+10);
}


}

void Player::keyPressEvent(QKeyEvent * e)
{
if (e->key() = Qt::Key_S)
{
setPos(x(), y() - 10);
}


}
*/


Player::~Player()
{

}
