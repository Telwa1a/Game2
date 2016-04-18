#include "Course.h"
#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>

Course::Course()
{
	LLCR initialLLCR;
	llcrVector.push_back(initialLLCR);
}

Course::Course(int numberOfLLCRs)
{
	LLCR initialLLCR;
	for (int i = 0; i < numberOfLLCRs; i++)
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

//TODO: få "banan" att skrivas ut här ifrån. de rätta kordinaterna för plusssymbolen finns i ourtempest.cpp
/*void Course::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	

}*/
