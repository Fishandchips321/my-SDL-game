#pragma once
#include <SDL.h>
#include "worldService.h"
#include "inventory.h"
#include "inventoryDisplay.h"
#include "entity.h"
class player : public entity
{
	friend playerService;
public:
	player(serviceLocator* SL);
	void update(); //called once a frame
	void eventUpdate(SDL_Event nextEvent); //can be called multiple times a frame
	void draw();
	~player();

	int playerInvIndex;
private:
	void move(); //checks which keys are being pressed and sets the x and y velocity
	void updateKeys();
	void animate(); //changes the section of the texture to be drawn
	void tickBreak(); //ticks the block break timer and breaks the block when breakCounter reaches breakCounterEnd
	void placeBlock(); //places a block
	inventory* getInvPointer(); //allows playerService to get the inventory pointer
	//inventory
	inventory* playerInv;
	int selectedItem;
	//movement
	SDL_Point mPos;
	SDL_Rect viewport;
	int xVel, yVel;
	const int speed = 1;
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

