#include "Course.h"
#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>

Course::Course()
{
	LLCR initialLLCR;
	llcrVector.push_back(initialLLCR);

	QLine newLine;
	lines.push_back(newLine);

	//Set position
	centerX = 100;
	centerY = 100;

	//Set values for course variables
	//qDebug() << pos();
	//qDebug() << scenePos();

	//setRect(250, 350, 100, 100);
	//TODO: make enemy in the shape of a romb
	setRect(centerX, centerY, 0, 0);
	setPos(centerX, centerY);

	/*scene->addLine(150, 30, 350, 30);
	scene->addLine(150, 400, 350, 400);
	scene->addLine(150, 30, 150, 150);
	scene->addLine(350, 30, 350, 150);
	scene->addLine(10, 150, 150, 150);
	scene->addLine(350, 150, 490, 150);


	scene->addLine(350, 400, 350, 290);
	scene->addLine(150, 400, 150, 290);

	scene->addLine(10, 290, 150, 290);
	scene->addLine(350, 290, 490, 290);

	scene->addLine(490, 150, 490, 290);
	scene->addLine(10, 150, 10, 290);*/
}

Course::Course(int numberOfLines)
{
	LLCR initialLLCR;
	for (int i = 0; i < numberOfLines; i++)
	{
		llcrVector.push_back(initialLLCR);
	}
}

Course::~Course()
{

}

void Course::setCourceLLCRs()
{
	//for (std::vector<LLCR>::iterator itr = llcrVector.begin(); itr != llcrVector.end(); ++itr)
	//{
	//}

	//MUST BE SET MANUALLY
}

void Course::addLinesToScene(QGraphicsScene &scene)
{

}

//TODO: få "banan" att skrivas ut här ifrån. de rätta kordinaterna för plusssymbolen finns i ourtempest.cpp
/*void Course::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	

}*/
