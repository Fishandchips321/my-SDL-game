#include "entity.h"


entity::entity(serviceLocator *SL)
	:mySL(SL)
{
	entitySurface = mySL->myImageService.loadImageReturn("assets/Textures/missing texture.png");
	entityRect = { 0, 0, entitySurface->w, entitySurface->h };
}

void entity::update()
{}

void entity::eventUpdate(SDL_Event nextEvent)
{}

void entity::draw()
{
	SDL_Rect drawRect;
	drawRect.x = entityRect.x + mySL->globalRenderer.xOffset;
	drawRect.x = entityRect.x + mySL->globalRenderer.yOffset;
	drawRect.w = entityRect.w;
	drawRect.h = entityRect.h;

	mySL->globalRenderer.drawScaledSurface(entitySurface, drawRect);
}

void entity::onCollide(entity* collider)
{}

void entity::onCollide(block* collider)
{}

bool entity::damage(int amount, entity* damager)
{
	return false;
}

bool entity::push(int x, int y)
{
	return false;
}

entity::~entity()
{
}
