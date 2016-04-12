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
		GameObj(const float xpos, const float ypos, const float width, const float height);
		~GameObj();

	protected:
		float xPos;
		float yPos;
		struct Vector2;
};

#endif // GAMEOBJ_H

