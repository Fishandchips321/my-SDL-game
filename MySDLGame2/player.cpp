#include "player.h"


player::player()
{
	//setup player dimensions for collision detection
	entityRect.w = 20;
	entityRect.h = 40;
	//center the player rect
	entityRect.x = (myRL.globalRenderer->screenWidth / 2) - (entityRect.w / 2);
	entityRect.y = (myRL.globalRenderer->screenHeight / 2) - (entityRect.h / 2);
	//register the player inventory and get the pointer for it
	playerInvIndex = myRL.myInventoryService->registerInventory();
	playerInv = myRL.myInventoryService->getPointer(playerInvIndex);

	viewport = { 18, 652, 29, 51 }; //x, y, w, h

	entitySurface = myRL.myImageService->loadImageReturn("assets/Textures/SaraFullSheet.png");
}

void player::draw()
{
	myRL.globalRenderer->drawViewportSurface(entitySurface, viewport, entityRect);

	animate();
}

void player::animate()
{
	animateCounter++;

	if (animateCounter == animateCounterStart)
	{
		viewport.x += 64; //64 is the amount of pixels between the frames of the animation
		if (viewport.x == 530) //530 is the x coordinate of the last frame of the animation
		{
			viewport.x = 18; //18 is the x coordinate for the beginning of the animation
		}
		animateCounter = 0;
	}
}

void player::update()
{
	move(); //get x and y vel
	//change the global render offsets
	myRL.globalRenderer->xOffset -= xVel;
	myRL.globalRenderer->yOffset -= yVel;
	//stop the player from going off the screen
	if (myRL.globalRenderer->xOffset > 0)
	{
		myRL.globalRenderer->xOffset = 0;
	}

	if (myRL.globalRenderer->yOffset > 0)
	{
		myRL.globalRenderer->yOffset = 0;
	}
	//update the place timer
	if (placeTimer > 0)
		placeTimer -= 1;
	//if the right mouse button is down, place a block
	if (SDL_GetMouseState(&mPos.x, &mPos.y) & SDL_BUTTON_RMASK && placeTimer == 0)
	{
		if (!myRL.myWorld->placeBlock(mPos.x, mPos.y, 1))
		{
			myRL.myWorld->rightClickBlock(mPos.x, mPos.y);
		}
		placeTimer = placeTimerStart;
	}
	//if the left mouse button is down, break the block
	if (SDL_GetMouseState(&mPos.x, &mPos.y) & SDL_BUTTON_LMASK)
	{
		if (!myRL.myWorld->breakBlock(mPos.x, mPos.y))
		{
			myRL.myWorld->leftClickBlock(mPos.x, mPos.y);
		}
	}
}

void player::eventUpdate(SDL_Event nextEvent)
{
	if (nextEvent.type == SDL_MOUSEWHEEL)
	{
		selectedItem += nextEvent.wheel.y;
		if (selectedItem >= 9)
		{
			selectedItem = 0;
		}
	}
}

void player::tickBreak()
{

}

void player::placeBlock()
{

}

void player::move()
{
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

	//up
	if (currentKeyStates[SDL_SCANCODE_W])
	{
		yVel = speed * -1;
	}

	//down
	if (currentKeyStates[SDL_SCANCODE_S])
	{
		yVel = speed;
	}

	//up and down
	if (currentKeyStates[SDL_SCANCODE_W] && currentKeyStates[SDL_SCANCODE_S])
	{
		yVel = 0;
	}

	//no vertical movement
	if (!currentKeyStates[SDL_SCANCODE_W] && !currentKeyStates[SDL_SCANCODE_S])
	{
		yVel = 0;
	}


	//left
	if (currentKeyStates[SDL_SCANCODE_A])
	{
		xVel = speed * -1;
	}

	//right
	if (currentKeyStates[SDL_SCANCODE_D])
	{
		xVel = speed;
	}

	//left and right
	if (currentKeyStates[SDL_SCANCODE_A] && currentKeyStates[SDL_SCANCODE_D])
	{
		xVel = 0;
	}

	//no horisontal movement
	if (!currentKeyStates[SDL_SCANCODE_A] && !currentKeyStates[SDL_SCANCODE_D])
	{
		xVel = 0;
	}
}

inventory* player::getInvPointer()
{
	return playerInv;
}

player::~player()
{
}
