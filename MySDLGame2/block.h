#pragma once
#include <SDL.h>
#include "render.h"
#include "imageService.h"
#include "resources.h"
class block
{
public:
	block();
	virtual void update();
	virtual void draw(int x, int y, int metadata);
	void setID(int ID);
	~block();

	virtual bool onLeftClick();
	virtual bool onRightClick();
	virtual bool onCollision();
	virtual bool onMouseHover();
	virtual bool onBreak();
	virtual bool onPlace();
	virtual bool save(std::string path, int x, int y);

	SDL_Rect drawRect;
	bool solid;
	int blockID;

	bool ent;

protected:
	bool loadTexture(std::string path);
	
private:
	SDL_Texture* texture;
	bool randomUpdates;
};

