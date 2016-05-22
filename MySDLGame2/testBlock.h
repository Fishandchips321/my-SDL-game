#pragma once
#include "block.h"
class testBlock : public block
{
public:
	testBlock();
	bool save(std::string path, int x, int y);
	~testBlock();

private:
};

