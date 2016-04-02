#include "item.h"


item::item()
{
	iTexture = imageService::loadTexture("assets/Textures/missing texture.png");
}

bool item::onDrop()
{
	return false;
}

bool item::onLeftClick()
{
	return false;
}

bool item::onRightClick()
{
	return false;
}

int item::getMetadata(int metadata)
{
	return 0;
}

bool item::onPlace(int x, int y)
{
	return false;
}


item::~item()
{
}
