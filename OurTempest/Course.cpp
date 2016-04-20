#include "Course.h"
#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>

Course::Course()
{
	LLCR *initialLLCR;
	initialLLCR = new LLCR();

	llcrVector.push_back(initialLLCR);

	QLine newLine;
	lines.push_back(newLine);

	//Set position
	centerX = 100;
	centerY = 100;

	//isVisible = false;

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
	LLCR *initialLLCR;
	initialLLCR = new LLCR();

	QLine newLine;

	for (int i = 0; i < numberOfLines; i++)
	{
		lines.push_back(newLine);
	}

	llcrVector.push_back(initialLLCR);

	//Set values for course variables
	setRect(centerX, centerY, 0, 0);
	setPos(centerX, centerY);
}

Course::Course(int numberOfLines, int numberOfLLCRs)
{
	LLCR *initialLLCR;
	QLine newLine;

	for (int i = 0; i < numberOfLines; i++)
	{
		lines.push_back(newLine);
	}

	for (int i = 0; i < numberOfLLCRs; i++)
	{
		initialLLCR = new LLCR();
		llcrVector.push_back(initialLLCR);
	}

	//Set values for course variables
	setRect(centerX, centerY, 0, 0);
	setPos(centerX, centerY);

	setCourceLLCRs();
}

Course::~Course()
{

}

void Course::setCourceLLCRs() //MUST BE SET MANUALLY
{
	//NOTE: RECTANGLE THICKNESS IS 50 PIXELS

	//LINES
	//BOTTOM PART
	lines[0].setLine(500, 800, 1100, 800);
	lines[1].setLine(lines[0].x1(), lines[0].y1(), lines[0].x1(), 650);
	lines[2].setLine(lines[0].x2(), lines[0].y1(), lines[0].x2(), 650);

	//TOP PART
	lines[3].setLine(500, 100, 1100, 100);
	lines[4].setLine(lines[3].x1(), lines[3].y1(), lines[3].x1(), 250);
	lines[5].setLine(lines[3].x2(), lines[3].y1(), lines[3].x2(), 250);

	//LEFT PART
	lines[6].setLine(200, lines[1].y2(), 200, lines[4].y2());
	lines[7].setLine(lines[6].x1(), lines[6].y1(), lines[3].x1(), lines[6].y1());
	lines[8].setLine(lines[6].x1(), lines[6].y2(), lines[3].x1(), lines[6].y2());

	//RIGHT PART
	lines[9].setLine(1400, lines[1].y2(), 1400, lines[4].y2());
	lines[10].setLine(lines[9].x1(), lines[9].y1(), lines[3].x2(), lines[9].y1());
	lines[11].setLine(lines[9].x1(), lines[9].y2(), lines[3].x2(), lines[9].y2());

	//LLCR
	//BOTTOM PART INCLUDING UPPER CORNERS
	llcrVector[0]->setRect(0, 0, (lines[0].x2() - lines[0].x1()) - 75, 50);
	llcrVector[0]->setPos(lines[0].x1() + (75/2), lines[0].y1() - 25);

	llcrVector[1]->setRect(0, 0, 50, (lines[1].y2() - lines[1].y1()) + 75);
	llcrVector[1]->setPos(lines[0].x1() - 25, lines[0].y1() - (75 / 2));

	llcrVector[2]->setRect(0, 0, 50, (lines[1].y2() - lines[1].y1()) + 75);
	llcrVector[2]->setPos(lines[0].x2() - 25, lines[0].y1() - (75 / 2));

	llcrVector[3]->setRect(0, 0, 50, 50);
	llcrVector[3]->setPos(lines[0].x1() - 25, lines[0].y1() - 25);

	llcrVector[4]->setRect(0, 0, 50, 50);
	llcrVector[4]->setPos(lines[0].x2() - 25, lines[0].y1() - 25);

	llcrVector[5]->setRect(0, 0, 50, 50);
	llcrVector[5]->setPos(lines[0].x1() - 25, lines[1].y2() - 25);

	llcrVector[6]->setRect(0, 0, 50, 50);
	llcrVector[6]->setPos(lines[0].x2() - 25, lines[1].y2() - 25);

	//TOP PART INCLUDING LOWER CORNERS
	llcrVector[7]->setRect(0, 0, (lines[3].x2() - lines[3].x1()) - 75, 50);
	llcrVector[7]->setPos(lines[3].x1() + (75 / 2), lines[3].y1() - 25);

	llcrVector[8]->setRect(0, 0, 50, (lines[4].y2() - lines[4].y1()) - 75);
	llcrVector[8]->setPos(lines[3].x1() - 25, lines[3].y1() + (75 / 2));

	llcrVector[9]->setRect(0, 0, 50, (lines[4].y2() - lines[4].y1()) - 75);
	llcrVector[9]->setPos(lines[3].x2() - 25, lines[3].y1() + (75 / 2));

	llcrVector[10]->setRect(0, 0, 50, 50);
	llcrVector[10]->setPos(lines[3].x1() - 25, lines[3].y1() - 25);

	llcrVector[11]->setRect(0, 0, 50, 50);
	llcrVector[11]->setPos(lines[3].x2() - 25, lines[3].y1() - 25);

	llcrVector[12]->setRect(0, 0, 50, 50);
	llcrVector[12]->setPos(lines[3].x1() - 25, lines[4].y2() - 25);

	llcrVector[13]->setRect(0, 0, 50, 50);
	llcrVector[13]->setPos(lines[3].x2() - 25, lines[4].y2() - 25);

	//LEFT PART

	llcrVector[14]->setRect(0, 0, 50, (lines[6].y2() - lines[6].y1()) + 75);
	llcrVector[14]->setPos(lines[6].x1() - 25, lines[6].y1() - (75 / 2));

	llcrVector[15]->setRect(0, 0, (lines[7].x2() - lines[7].x1()) - 75, 50);
	llcrVector[15]->setPos(lines[7].x1() + (75 / 2), lines[7].y1() - 25);

	llcrVector[16]->setRect(0, 0, (lines[7].x2() - lines[7].x1()) - 75, 50);
	llcrVector[16]->setPos(lines[7].x1() + (75 / 2), lines[8].y1() - 25);

	llcrVector[17]->setRect(0, 0, 50, 50);
	llcrVector[17]->setPos(lines[7].x1() - 25, lines[7].y1() - 25);

	llcrVector[18]->setRect(0, 0, 50, 50);
	llcrVector[18]->setPos(lines[7].x1() - 25, lines[8].y1() - 25);

	//RIGHT PART

	llcrVector[19]->setRect(0, 0, 50, (lines[9].y2() - lines[9].y1()) + 75);
	llcrVector[19]->setPos(lines[9].x1() - 25, lines[9].y1() - (75 / 2));

	llcrVector[20]->setRect(0, 0, (lines[7].x2() - lines[7].x1()) - 75, 50);
	llcrVector[20]->setPos(lines[10].x2() + (75 / 2), lines[10].y1() - 25);

	llcrVector[21]->setRect(0, 0, (lines[7].x2() - lines[7].x1()) - 75, 50);
	llcrVector[21]->setPos(lines[10].x2() + (75 / 2), lines[11].y1() - 25);

	llcrVector[22]->setRect(0, 0, 50, 50);
	llcrVector[22]->setPos(lines[10].x1() - 25, lines[10].y1() - 25);

	llcrVector[23]->setRect(0, 0, 50, 50);
	llcrVector[23]->setPos(lines[10].x1() - 25, lines[11].y1() - 25);
}

void Course::addLinesToScene(QGraphicsScene &scene)
{
	/*for (std::vector<LLCR>::iterator itr = llcrVector.begin(); itr != llcrVector.end(); ++itr)
	{
		scene.addItem(llcrVector[itr]);
	}

	for (std::vector<QLine>::iterator itr = lines.begin(); itr != lines.end(); ++itr)
	{
	}*/

	for (int i = 0; i < llcrVector.size(); i++)
	{
		//scene.addRect(llcrVector[i]);
		scene.addItem(llcrVector[i]);
	}

	for (int i = 0; i < lines.size(); i++)
	{
		scene.addLine(lines[i]);
	}
}

//TODO: få "banan" att skrivas ut här ifrån. de rätta kordinaterna för plusssymbolen finns i ourtempest.cpp
/*void Course::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	

}*/
