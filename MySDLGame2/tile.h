#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "render.h"
#include "imageService.h"
#include "resources.h"

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
	bool loadTexture(std::string path);
private:
	SDL_Texture* texture;
};