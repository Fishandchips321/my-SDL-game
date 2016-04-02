#pragma once
#include "entity.h"
#include "itemStack.h"
class itemStackEnt : public entity
{
public:
	itemStackEnt();
	void update();
	~itemStackEnt();

	itemStack entStack;
	int pickupTimer;
};

