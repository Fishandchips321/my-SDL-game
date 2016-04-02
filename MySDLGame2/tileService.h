#pragma once
#include "tile.h"
#include <vector>
class tileService
{
public:
	tileService();
	static void update();
	static int registerTile(tile* newTile);
	static bool registerForUpdtaes(tile* newTile);// for animation updates
	~tileService();

	static std::vector<tile* > tiles;

	enum tileTypes
	{
		none,
		grass
	};

private:
	static std::vector<tile* > updates;
};

