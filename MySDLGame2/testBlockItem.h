#pragma once
#include "item.h"
#include "testBlock.h"
#include "world.h"
class testBlockItem : public item
{
public:
	testBlockItem();
	bool onPlace(int x, int y);
	~testBlockItem();
};

