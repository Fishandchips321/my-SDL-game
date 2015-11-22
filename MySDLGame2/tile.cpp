#include "tile.h"
#include <iostream>

tile::tile(serviceLocator* SL)
	:mySL(SL)
{
	boundingRect = { 0, 0, 0, 0 };
	surface = mySL->myImageService.loadImageReturn("assets/Textures/missing texture.png");
}

void tile::update()
{
}

void tile::draw(int x, int y)
{
	SDL_Rect drawRect;

	drawRect.x = x + mySL->globalRenderer.xOffset;
	drawRect.y = y + mySL->globalRenderer.yOffset;
	drawRect.w = mySL->tileWidth;
	drawRect.h = mySL->tileHeight;

	if (drawRect.x + drawRect.w >= 0 && drawRect.x < mySL->globalRenderer.screenWidth)
	{
		if (drawRect.y + drawRect.h >= 0 && drawRect.y < mySL->globalRenderer.screenHeight)
		{
			mySL->globalRenderer.drawSurface(surface, drawRect);
		}
	}
}

bool tile::loadSurface(std::string path)
{
	surface = mySL->myImageService.loadImageReturn(path);
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