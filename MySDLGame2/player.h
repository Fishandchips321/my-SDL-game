#pragma once
#include <SDL.h>
#include "inventory.h"
#include "entity.h"
#include "inventoryService.h"
#include "world.h"
#include "testBlockItem.h" //temp
class player : public entity
{
public:
	
	player();
	void update(); //called once a frame
	void eventUpdate(); //can be called multiple times a frame
	void draw();
	~player();

	int playerInvIndex;
private:
	void move(); //checks which keys are being pressed and sets the x and y velocity
	void updateKeys();
	void animate(); //changes the section of the texture to be drawn
	//inventory
	inventory* playerInv;
	int selectedItem;
	//movement
	SDL_Point mPos;
	SDL_Rect viewport;
	//block placement
	const int placeTimerStart = 10;
	int placeTimer = 0;
	//animation
	int animateCounter;
	const int animateCounterStart = 6;
	//block breaking
	int breakCounter;
	int breakCounterEnd;//will be set determining on the block's base break speed and the tool's correct usage break speed/incorrect usage break speed
};

