#ifndef GAMEOBJ_H
#define GAMEOBJ_H

#pragma once
#include <QGraphicsItem>
#include <QtWidgets/QApplication>
#include <QGraphicsRectItem>

class GameObj : public QGraphicsRectItem
{
	protected:

		struct Vector2
		{
			float x;
			float y;
		};
		Vector2 position;
		Vector2 size;

		template <typename T>
		T Lerp(T& val1, T& val2, float u)
		{
			return (1 - u) * val1 + u * val2;
		}

	public:

		GameObj();
		GameObj(const float xpos, const float ypos, const float width, const float height);
		GameObj(const Vector2 _pos, const Vector2 _size);
		~GameObj();
		void setObjPos(float posx, float posy);
};

#endif //GAMEOBJ_H

