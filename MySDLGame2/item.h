#pragma once
#include "resources.h"
#include "imageService.h"
class item
{
public:
	item();
	virtual bool onRightClick();
	virtual bool onLeftClick();
	virtual bool onDrop();
	virtual int getMetadata(int metadata);
	virtual bool onPlace(int x, int y);
	~item();

	double weight;
	SDL_Texture* iTexture;
protected:
	//resourceLocator myRL;
};

