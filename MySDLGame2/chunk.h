#pragma once
#include "serviceLocator.h"
#include "tile.h"
#include "block.h"
#include "entity.h"
#include <vector>
class chunk
{
public:
	chunk(serviceLocator* SL, int x, int y);
	void draw();
	bool placeBlock(int x, int y, int type);
	bool breakBlock(int x, int y);
	bool leftClickBlock(int x, int y);
	bool rightClickBlock(int x, int y);
	bool loadTile(int tile, int x, int y);
	bool loadBlock(int block, int x, int y);
	bool clearEntities();
	bool registerEntiy(entity* ent);
	~chunk();

	const int chunkSize = 10;

	//holds the absolute position of the chunk (not the camera position)
	SDL_Rect chunkRect; // this isn't modified by the screen offset and must be done by classes using it

	std::vector<entity* > entities;
	bool changed; //to determine whether the chunk should be saved
private:
	serviceLocator* mySL;

	int tiles[10][10];
	int blocks[10][10];

	//void initChunks();

	//std::vector< std::vector<int>> tiles;
	//std::vector< std::vector<int>> blocks;
};

