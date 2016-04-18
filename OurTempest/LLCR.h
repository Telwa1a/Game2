#ifndef LLCR_H
#define LLCR_H

#pragma once

#include "GameObj.h"
#include "Player.h"

class LLCR// : public GameObj//LLCR stands for "Level Line Collision Rectangle"
{
	public:
		LLCR();
		~LLCR();

		std::vector<float> allowedDirections[4];

	private:
		float centerX;
		float centerY;
		bool isTriggerEnabled;
		void whenTriggerEnabled(Player &player);
};

#endif //LLCR_H

