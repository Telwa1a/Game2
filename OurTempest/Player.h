#ifndef PLAYER_H
#define PLAYER_H

#include "Aircraft.h"
#include <QGraphicsItem>
#include <QKeyEvent>

class Player : public Aircraft //,QGraphicsItem
{
	//Q_OBJECT
public:
	Player();
	~Player();


	//void paint (QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0);
	//void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;

	void keyPressEvent(QKeyEvent *e);

private:
	//Player *_player1;
};

#endif // PLAYER_H