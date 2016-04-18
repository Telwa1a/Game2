#ifndef COURSE_H
#define COURSE_H

#include <QGraphicsItem>
#include <LLCR.h>
#include "Player.h"

class Course// : public QGraphicsRectItem, public QObject
{
	public:
		Course();
		Course(int numberOfLLCRs);
		~Course();
		
		/*QRectF boundingRect() const Q_DECL_OVERRIDE;
		QPainterPath shape() const Q_DECL_OVERRIDE;
		void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;*/
		
	private:
		std::vector<LLCR> llcrVector;
		bool lerpBackToCurrentLine = true;
		void setCourceLLCRs();
		float centerX;
		float centerY;

	private slots:
		void lerpBackPlayerToLine(Player &player);
};

#endif // COURSE_H
