#include "itemStackEnt.h"


itemStackEnt::itemStackEnt()
{
	entityTexture = entStack.SItem->iTexture;
	entityRect = { 0, 0, 20, 20 };
	pickupTimer = 60;
}

void itemStackEnt::update()
{
	if (pickupTimer != 0)
		pickupTimer -= 1;

	entityRect.x += xVel;
	entityRect.y += yVel;
}

itemStackEnt::~itemStackEnt()
{
}
