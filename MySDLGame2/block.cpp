#include "block.h"

block::block()
{
	texture = imageService::loadTexture("assets/Textures/missing texture.png");
}

void block::draw(int x, int y)
{
	drawRect.x = x + render::xOffset;
	drawRect.y = y + render::yOffset;
	drawRect.w = resources::tileWidth;
	drawRect.h = resources::tileHeight;

	if (drawRect.x + drawRect.w > 0 && drawRect.x < render::screenWidth)
	{
		if (drawRect.y + drawRect.h > 0 && drawRect.y < render::screenHeight)
		{
			render::drawTexture(texture, &drawRect);
		}
	}
}

void block::update()
{

}

bool block::onLeftClick() //returns false if nothing happened/nothing was done
{
	return false;
}

bool block::onRightClick() //returns false if nothing happened
{
	return false;
}

bool block::onCollision() // returns true if the block is solid
{
	return false;
}

bool block::onMouseHover()
{
	return false;
}

bool block::onPlace() //returns false if the block shouldn't be placed (the block is placed, does a check and then determines whether it can stay)
{
	return true;
}

bool block::onBreak() //returns true to break the block
{
	return true;
}

bool block::loadTexture(std::string path)
{
	texture = imageService::loadTexture(path);
	return true;
}

void block::setID(int ID)
{
	blockID = ID;
}

block::~block()
{
}
