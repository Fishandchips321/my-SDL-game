#pragma once
#include "tile.h"
#include <vector>
class tileService
{
public:
	tileService();
	void update();
	int registerTile(tile* newTile);
	bool registerForUpdtaes(tile* newTile);// for animation updates
	~tileService();

	std::vector<tile* > tiles;

	enum tileTypes
	{
		none,
		grass
	};

private:
	std::vector<tile* > updates;
};

