#include "testBlockItem.h"


testBlockItem::testBlockItem()
{
	iTexture = imageService::loadTexture("assets/Textures/test block.png");
}

bool testBlockItem::onPlace(int x, int y)
{
	return world::placeBlock(x, y, blockService::test);
}

testBlockItem::~testBlockItem()
{
}
