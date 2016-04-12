#ifndef GAMEOBJ_H
#define GAMEOBJ_H

#pragma once
#include <QGraphicsItem>
#include <QtWidgets/QApplication>
#include <QGraphicsRectItem>

class GameObj : public QGraphicsRectItem
{
	public:
		GameObj();
		~GameObj();
};

#endif // GAMEOBJ_H

