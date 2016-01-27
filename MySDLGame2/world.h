#pragma once
#include "worldGrid.h"
class world
{
public:
	world();
	bool useTestingWorld();
	bool newWorld(std::string name);
	bool loadWorld(std::string name);
	bool saveWorld();
	bool registerGrid(worldGrid* newGrid);
	void update();
	void draw();
	void eventUpdate();
	bool placeBlock(int x, int y, int type);
	bool placeBlockEntity(int x, int y, block* blockEntity);
	bool breakBlock(int x, int y);
	bool rightClickBlock(int x, int y);
	bool leftClickBlock(int x, int y);
	~world();

	std::vector<worldGrid* > grids;
	int currentGrid = -1;
	std::string worldName;
private:
	
};

