#include "testBlock.h"


testBlock::testBlock()
{
	loadTexture("assets/Textures/test block.png");
}

bool testBlock::save(std::string path, int x, int y)
{
	return true;
}

testBlock::~testBlock()
{
}
