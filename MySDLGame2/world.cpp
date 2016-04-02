#include "world.h"

std::vector<worldGrid* > world::grids;
int world::currentGrid;
std::string world::worldName;

world::world()
{
}

void world::eventUpdate()
{

}

void world::update()
{
	
}

void world::draw()
{
	grids[currentGrid]->draw();
}

bool world::useTestingWorld()
{
	worldGrid* testGrid = new worldGrid();
	grids.push_back(testGrid);
	currentGrid = (int)grids.size() - 1;
	return grids[currentGrid]->useDefaultGrid();
}

bool world::newWorld(std::string name)
{
	return false;
}

bool world::loadWorld(std::string name)
{
	return false;
}

bool world::saveWorld()
{
	return false;
}

bool world::placeBlock(int x, int y, int type)
{
	return grids[currentGrid]->placeBlock(x, y, type);
}

bool world::placeBlockEntity(int x, int y, block* blockEntity)
{
	return grids[currentGrid]->placeBlockEntity(x, y, blockEntity);
}

bool world::breakBlock(int x, int y)
{
	return grids[currentGrid]->breakBlock(x, y);
}

bool world::rightClickBlock(int x, int y)
{
	return grids[currentGrid]->rightClickBlock(x, y);
}

bool world::leftClickBlock(int x, int y)
{
	return grids[currentGrid]->leftClickBlock(x, y);
}

world::~world()
{
	for (size_t i = 0; i < grids.size(); i++)
	{
		delete grids[i];
		grids[i] = NULL;
	}
}
