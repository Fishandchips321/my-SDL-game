#include "entityService.h"


entityService::entityService(serviceLocator* SL)
	:mySL(SL)
{
}

void entityService::update()
{
	//if one of the chunks that the entity is inside is on the screen then update the entity
	//clear the entity cache of each loaded chunk (if chunk != NULL)
	//re-register all entities to chunks

	//this checks collisions between ALL entities. have each chunk have a vector of entities and register each entity to chunks every tick after clearing out the vector
	//needs 2 more for loops to go through all chunks
	//check for collisions
	for (int i = 0; i < int(entities.size()); i++)//go through the list and check that entity with every other entity in the list
	{
		for (int j = i + 1; j < int(entities.size()); j++)//start checking from the entity next in the list. all entities will be checked with each other once
		{
			if (j != i)//don't check collisions with the same entity
			{
				if (detectCollision(entities[i], entities[j]))
				{
					entities[i]->onCollide(entities[j]);
				}
			}	
		}
	}
}

void entityService::draw()
{
	//if the entity is on the screen draw it
	for (int i = 0; i < int(entities.size()); i++) //doesn't count the element at size
	{
		if (entities[i]->entityRect.x >= 0 && (entities[i]->entityRect.x + entities[i]->entityRect.w) <= mySL->globalRenderer.screenWidth)
		{
			if (entities[i]->entityRect.y >= 0 && (entities[i]->entityRect.y + entities[i]->entityRect.h) <= mySL->globalRenderer.screenHeight)
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

bool entityService::registerGrid(worldGrid* currentGrid)
{
	grid = currentGrid;
	if (grid == currentGrid)
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

bool entityService::detectCollision(entity* ent, block* blk)
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
