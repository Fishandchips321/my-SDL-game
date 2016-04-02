#pragma once
#include "resources.h"
#include "block.h"
#include "inventory.h"
class entity
{
public:
	entity();
	virtual void update();
	virtual void eventUpdate();
	virtual void draw();
	virtual void onCollide(entity* collider);
	virtual void onCollide(block* collider);
	virtual bool damage(int amount, entity* damager);
	virtual bool push(int x, int y);

	SDL_Rect entityRect;
	SDL_Texture* entityTexture;
	inventory* entInv;
	int xVel, yVel;
	int speed;
	~entity();
};

