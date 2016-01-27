#pragma once
#include <SDL.h>
#include "resourceLocator.h"
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

	const int blockWidth = 20, blockHeight = 20;
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

protected:
	resourceLocator myRL;
	bool loadSurface(std::string path);
	material blockMaterial;
	
private:
	SDL_Surface* surface;
	bool randomUpdates;
};

