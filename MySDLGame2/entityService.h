#pragma once
#include "entity.h"
#include "chunk.h"
#include "block.h"
#include "worldGrid.h"
#include "serviceLocator.h"
#include "vector"

//todo
//write functions to check collisions
//entity-entity
//entity-block

class entityService
{
public:
	entityService(serviceLocator* SL);
	void update();
	void draw();
	bool registerEntity(entity* newEnt);
	bool registerGrid(worldGrid* currentGrid);
	~entityService();

private:
	bool detectCollision(entity* entity1, entity* entity2);
	bool detectCollision(entity* ent, block* blk);
	serviceLocator* mySL;
	std::vector<entity* > entities;
	worldGrid* grid;
};

