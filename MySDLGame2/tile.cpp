#include "tile.h"
#include <iostream>

tile::tile()
{
	boundingRect = { 0, 0, 0, 0 };
	surface = myRL.myImageService->loadImageReturn("assets/Textures/missing texture.png");
}

void tile::update()
{
}

void tile::draw(int x, int y)
{
	SDL_Rect drawRect;

	drawRect.x = x + myRL.globalRenderer->xOffset;
	drawRect.y = y + myRL.globalRenderer->yOffset;
	drawRect.w = myRL.tileWidth;
	drawRect.h = myRL.tileHeight;

	if (drawRect.x + drawRect.w >= 0 && drawRect.x < myRL.globalRenderer->screenWidth)
	{
		if (drawRect.y + drawRect.h >= 0 && drawRect.y < myRL.globalRenderer->screenHeight)
		{
			myRL.globalRenderer->drawSurface(surface, drawRect);
		}
	}
}

bool tile::loadSurface(std::string path)
{
	surface = myRL.myImageService->loadImageReturn(path);
	if (surface != NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void tile::setID(int ID)
{
	tileID = ID;
}

tile::~tile()
{
}