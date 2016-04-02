#pragma once
#include <SDL.h>
#include "render.h"
#include "imageService.h"
#include "inventory.h"
#include "resources.h"
class block
{
public:
	block();
	virtual void update();
	virtual void draw(int x, int y);
	void setID(int ID);
	~block();

	virtual bool onLeftClick();
	virtual bool onRightClick();
	virtual bool onCollision();
	virtual bool onMouseHover();
	virtual bool onBreak();
	virtual bool onPlace();

	SDL_Rect drawRect;
	bool solid;
	int blockID;

	struct material
	{
		//serviceLocator::materialTypes type;
		//serviceLocator::toolTypes effectiveTool;
		int harvestLevel;
		int baseHarvestTime;
	};

	inventory* blockInv;

protected:
	bool loadTexture(std::string path);
	material blockMaterial;
	
private:
	SDL_Texture* texture;
	bool randomUpdates;
};

