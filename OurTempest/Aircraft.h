#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include <QtWidgets/QApplication>
#include <QGraphicsRectItem>
//#include "Player.h"

/*BASKLASS till player och enemy. f�r att b�da kommer vara QGRaphicsRectItem*/


class Aircraft : public QGraphicsRectItem
{
		//Q_OBJECT
public:
	Aircraft();
	~Aircraft();

private:

};

#endif // AIRCRAFT_H