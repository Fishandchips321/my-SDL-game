#pragma once
#include <vector>
#include "tile.h"
#include "block.h"
#include "resourceLocator.h"
#include "chunk.h"
#include "worldGen.h"
class worldGrid
{
public:
	worldGrid();
	void update();
	void draw();
	bool loadGridFromText(std::string path);
	bool useDefaultGrid();
	bool placeBlock(int x, int y, int type);
	bool placeBlockEntity(int x, int y, block* blockEntity);
	bool breakBlock(int x, int y);
	bool rightClickBlock(int x, int y);
	bool leftClickBlock(int x, int y);
	void getChunkBlock(int *x, int *y, int *chunkX, int *chunkY);
	std::vector<std::vector<chunk* >> chunkGrid;
	~worldGrid();

	int gridWidth, gridHeight;

private:
	resourceLocator myRL;
	int chunkSize;
};

