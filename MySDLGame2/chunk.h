#pragma once
#include "resources.h"
#include "tile.h"
#include "block.h"
#include "entity.h"
#include "blockService.h"
#include "tileService.h"
#include <vector>
class chunk
{
public:
	chunk( int x, int y);
	void draw();
	bool placeBlock(int x, int y, int type);
	bool placeBlock(int x, int y, block* nBlock);
	bool breakBlock(int x, int y);
	bool leftClickBlock(int x, int y);
	bool rightClickBlock(int x, int y);
	bool loadTile(int tile, int x, int y, int metadata = 0);
	bool loadBlock(int block, int x, int y, int metadata = 0);
	bool clearEntities();
	bool registerEntiy(entity* ent);
	~chunk();

	const int chunkSize = 10;

	//holds the absolute position of the chunk (not the camera position)
	SDL_Rect chunkRect; // this isn't modified by the screen offset and must be done by classes using it

	std::vector<entity* > entities;
	bool changed; //to determine whether the chunk should be saved

	struct blockStack
	{
		block* tBlock;
		int metadata;
	};

	struct tileStack
	{
		tile* tTile;
		int metadata;
	};
private:
	tileStack tiles[10][10];
	blockStack blocks[10][10];
};

