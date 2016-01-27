#pragma once
#include "resourceLocator.h"
#include "block.h"
class entity
{
public:
	entity();
	virtual void update();
	virtual void eventUpdate(SDL_Event nextEvent);
	virtual void draw();
	virtual void onCollide(entity* collider);
	virtual void onCollide(block* collider);
	virtual bool damage(int amount, entity* damager);
	virtual bool push(int x, int y);

	SDL_Rect entityRect;
	SDL_Surface* entitySurface;
	~entity();

protected:
	resourceLocator myRL;
};

