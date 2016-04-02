#include "entityService.h"

std::vector<entity* > entityService::entities;

entityService::entityService()
{
}

void entityService::update()
{
	//if one of the chunks that the entity is inside is on the screen then update the entity
	//clear the entity cache of each loaded chunk (if chunk != NULL)
	//re-register all entities to chunks

	for (size_t i = 0; i < entities.size(); i++)
	{
		entities[i]->update();
	}
}

void entityService::eventUpdate()
{
	for (size_t i = 0; i < entities.size(); i++)
	{
		entities[i]->eventUpdate();
	}
}

void entityService::draw()
{
	//if the entity is on the screen draw it
	for (int i = 0; i < int(entities.size()); i++) //doesn't count the element at value "size"
	{
		if (entities[i]->entityRect.x >= 0 && (entities[i]->entityRect.x + entities[i]->entityRect.w) <= render::screenWidth)
		{
			if (entities[i]->entityRect.y >= 0 && (entities[i]->entityRect.y + entities[i]->entityRect.h) <= render::screenHeight)
			{
				entities[i]->draw();
			}
		}
	}
}

bool entityService::registerEntity(entity* newEnt)
{
	entities.push_back(newEnt);
	if (entities.back() == newEnt)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool entityService::detectCollision(entity* entity1, entity* entity2)
{

	if (entity1->entityRect.x >= entity2->entityRect.x && entity1->entityRect.x <= entity2->entityRect.x + entity2->entityRect.w)
	{
		if (entity1->entityRect.y >= entity2->entityRect.y && entity1->entityRect.y <= entity2->entityRect.y + entity2->entityRect.h)
		{
			return true;
		}
	}

	if (entity2->entityRect.x >= entity1->entityRect.x && entity2->entityRect.x <= entity1->entityRect.x + entity1->entityRect.w)
	{
		if (entity2->entityRect.y >= entity1->entityRect.y && entity2->entityRect.y <= entity1->entityRect.y + entity1->entityRect.h)
		{
			return true;
		}
	}

	return 0;
}

bool entityService::detectCollision(entity* ent, int x, int y)
{
	return 0;
}

entityService::~entityService()
{
	for (int x = 0; x > int(entities.size()); x++)
	{
		delete entities[x];
	}
}
