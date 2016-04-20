#ifndef COURSE_H
#define COURSE_H

#pragma once

#include <QGraphicsItem>
#include "LLCR.h"
#include "Player.h"

class Course : public QGraphicsRectItem//, public QObject
{
	//Q_OBJECT

	public:
		Course();
		Course(int numberOfLines);
		Course(int numberOfLines, int numberOfLLCRs);
		~Course();
		
		void addLinesToScene(QGraphicsScene &scene);
		/*QRectF boundingRect() const Q_DECL_OVERRIDE;
		QPainterPath shape() const Q_DECL_OVERRIDE;
		void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;*/
		
	private:
		std::vector<LLCR*> llcrVector;
		std::vector<QLine> lines;
		bool lerpBackToCurrentLine = true;
		void setCourceLLCRs();
		float centerX;
		float centerY;

	private slots:
		void lerpBackPlayerToLine(Player &player);
};

#endif // COURSE_H
