#include "tile.h"
#include <iostream>

tile::tile()
{
	boundingRect = { 0, 0, 0, 0 };
	texture = imageService::loadTexture("assets/Textures/missing texture.png");
}

void tile::update()
{
}

void tile::draw(int x, int y)
{
	SDL_Rect drawRect;

	drawRect.x = x + render::xOffset;
	drawRect.y = y + render::yOffset;
	drawRect.w = resources::tileWidth;
	drawRect.h = resources::tileHeight;

	if (drawRect.x + drawRect.w >= 0 && drawRect.x < render::screenWidth)
	{
		if (drawRect.y + drawRect.h >= 0 && drawRect.y < render::screenHeight)
		{
			render::drawTexture(texture, &drawRect);
		}
	}
}

bool tile::loadTexture(std::string path)
{
	texture = imageService::loadTexture(path);
	if (texture != NULL)
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