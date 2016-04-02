#include "player.h"


player::player()
{
	//setup player dimensions for collision detection
	entityRect.w = 30;
	entityRect.h = 60;
	//center the player rect
	entityRect.x = (render::screenWidth / 2) - (entityRect.w / 2);
	entityRect.y = (render::screenHeight / 2) - (entityRect.h / 2);
	//register the player inventory and get the pointer for it
	playerInvIndex = inventoryService::registerInventory();
	playerInv = inventoryService::getPointer(playerInvIndex);

	for (int x = 0; x < 5; x++)
	{
		itemStack s;
		s.SItem = nullptr;
		//to be removed - for testing
		if (x == 0)
		{
			testBlockItem *t = new testBlockItem;
			s.SItem = t;
		}

		playerInv->itemStacks.push_back(s);
	}

	viewport = { 18, 652, 29, 51 }; //x, y, w, h

	entityTexture = imageService::loadTexture("assets/Textures/SaraFullSheet.png");

	speed = 1;
}

void player::draw()
{
	render::drawTexture(entityTexture, &entityRect, &viewport);

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
	render::xOffset -= xVel;
	render::yOffset -= yVel;
	//stop the player from going off the screen
	if (render::xOffset > 0)
	{
		render::xOffset = 0;
	}

	if (render::yOffset > 0)
	{
		render::yOffset = 0;
	}
	//update the place timer
	if (placeTimer > 0)
		placeTimer -= 1;
	//if the right mouse button is down, place a block
	if (SDL_GetMouseState(&mPos.x, &mPos.y) & SDL_BUTTON_RMASK && placeTimer == 0)
	{
		bool action = false;
		if (world::rightClickBlock(mPos.x, mPos.y))
			action = true;
		if (playerInv->itemStacks[selectedItem].SItem != nullptr)
		{
			if (playerInv->itemStacks[selectedItem].SItem->onRightClick() && !action)
				action = true;

			if (playerInv->itemStacks[selectedItem].SItem->onPlace(mPos.x, mPos.y) && !action)
				action = true;
		}

		placeTimer = placeTimerStart;
	}
	//if the left mouse button is down, break the block
	if (SDL_GetMouseState(&mPos.x, &mPos.y) & SDL_BUTTON_LMASK)
	{
		if (!world::breakBlock(mPos.x, mPos.y))
		{
			world::leftClickBlock(mPos.x, mPos.y);
		}
	}
}

void player::eventUpdate()
{
	if (resources::currentEvent->type == SDL_MOUSEWHEEL)
	{
		selectedItem += resources::currentEvent->wheel.y;
		if (selectedItem > 4)
		{
			selectedItem = 0;
		}

		if (selectedItem < 0)
		{
			selectedItem = 4;
		}
	}
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

player::~player()
{
}
