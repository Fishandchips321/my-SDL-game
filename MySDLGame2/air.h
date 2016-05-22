#pragma once
#include "block.h"
class air :public block
{
public:
	air();
	void draw(int x, int y, int metadata);
	~air();
};

