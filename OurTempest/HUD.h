#ifndef HUD_H
#define HUD_H

#pragma once

#include <QGraphicsTextItem>
#include <QFont>

class HUD : public QGraphicsTextItem
{
	public:
		HUD();
		~HUD();

		void increase();
		int getScore();
	private:
		int _score;
};

#endif //HUD_H

