#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "resourceLocator.h"

class tile
{
public:
	tile();
	virtual void update();
	virtual void draw(int x, int y);
	void setID(int ID);
	~tile();

	SDL_Rect boundingRect; // the part of the IMAGE that entities can't move over/through
	bool bounding;
	int tileID;

protected:
	resourceLocator myRL;
	bool loadSurface(std::string path);
private:
	SDL_Surface* surface;
};