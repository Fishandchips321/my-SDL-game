#pragma once
#include "block.h"
#include "serviceLocator.h"
class air :public block
{
public:
	air(serviceLocator *SL);
	void draw(int x, int y);
	~air();
};

