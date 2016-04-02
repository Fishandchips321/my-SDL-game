#pragma once
#include "entity.h"
#include "worldGrid.h"
#include "resources.h"

//todo
//write functions to check collisions
//entity-entity
//entity-block

class entityService
{
public:
	entityService();
	static void update();
	static void eventUpdate();
	static void draw();
	static bool registerEntity(entity* newEnt);
	~entityService();

	//called by chunk
	static bool detectCollision(entity* entity1, entity* entity2);
	static bool detectCollision(entity* ent, int x, int y);

	static std::vector<entity* > entities;
};

