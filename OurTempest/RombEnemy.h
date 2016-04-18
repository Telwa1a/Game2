#ifndef ROMBENEMY_H
#define ROMBENEMY_H

#pragma once
#include "Enemy.h"

class RombEnemy : public Enemy
{
	public:
		RombEnemy();
		~RombEnemy();
		void isRombEnemyActive();
};

#endif //ROMBENEMY_H

