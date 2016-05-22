#pragma once
#include "worldGrid.h"
#include <sstream>
class world
{
public:
	world();
	static bool useTestingWorld();
	static bool newWorld(std::string name);
	static bool loadWorld(std::string name);
	static bool saveWorld();
	static bool registerGrid(worldGrid* newGrid);
	static void update();
	static void draw();
	static void eventUpdate();
	static bool placeBlock(int x, int y, int type);
	static bool placeBlockEntity(int x, int y, block* blockEntity);
	static bool breakBlock(int x, int y);
	static bool rightClickBlock(int x, int y);
	static bool leftClickBlock(int x, int y);
	~world();

	static std::vector<worldGrid* > grids;
	static int currentGrid;
	static std::string worldName;
private:
	
};

