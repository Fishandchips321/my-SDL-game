#include "worldGrid.h"
#include "grassTile.h" // for the useDefaultGrid
#include "tileService.h"
#include <iostream>
#include <fstream>


worldGrid::worldGrid()
{
	
	chunk tempChunk(0, 0);
	chunkSize = tempChunk.chunkSize;
}

void worldGrid::update()
{

}

bool worldGrid::placeBlock(int x, int y, int type)//if false, the player class will try to right click the block
{
	if (x > (gridWidth * 10) * resources::tileWidth || y > (gridHeight * 10) * resources::tileHeight)
	{
		return false;
	}

	int chunkX, chunkY;

	getChunkBlock(&x, &y, &chunkX, &chunkY);


	return chunkGrid[chunkX][chunkY]->placeBlock(x, y, type);
}

bool worldGrid::placeBlockEntity(int x, int y, block* blockEntity)
{
	if (x > (gridWidth * 10) * 20 || y > (gridHeight * 10) * 20)
	{
		return false;
	}

	int chunkX, chunkY;

	getChunkBlock(&x, &y, &chunkX, &chunkY);

	return chunkGrid[chunkX][chunkY]->placeBlock(x, y, blockEntity);
}

bool worldGrid::breakBlock(int x, int y)
{
	if (x > (gridWidth * 10) * 20 || y > (gridHeight * 10) * 20)
	{
		return false;
	}

	int chunkX, chunkY;

	getChunkBlock(&x, &y, &chunkX, &chunkY);

	return chunkGrid[chunkX][chunkY]->breakBlock(x, y);
	//return false;
}

bool worldGrid::leftClickBlock(int x, int y)
{
	if (x > (gridWidth * 10) * 20 || y > (gridHeight * 10) * 20)
	{
		return false;
	}

	int chunkX, chunkY;

	getChunkBlock(&x, &y, &chunkX, &chunkY);

	return chunkGrid[chunkX][chunkY]->leftClickBlock(x, y);
}

bool worldGrid::rightClickBlock(int x, int y)
{

	if (x > (gridWidth * 10) * 20 || y > (gridHeight * 10) * 20)
	{
		return false;
	}

	int chunkX, chunkY;

	getChunkBlock(&x, &y, &chunkX, &chunkY);

	return chunkGrid[chunkX][chunkY]->rightClickBlock(x, y);
}

void worldGrid::getChunkBlock(int *x, int *y, int *chunkX, int *chunkY)
{

	*x -= render::xOffset;
	*y -= render::yOffset;

	*x /= resources::tileWidth;
	*y /= resources::tileHeight;

	*chunkX = *x / chunkSize;
	*chunkY = *y / chunkSize;

	*x -= chunkGrid[*chunkX][*chunkY]->chunkRect.x / resources::tileWidth;
	*y -= chunkGrid[*chunkX][*chunkY]->chunkRect.y / resources::tileHeight;
}


void worldGrid::draw() // if the tile/block is on the screen, draw it
{
	//i = x, j = y
	for (int i = 0; i < int(chunkGrid.size()); i++)
	{
		for (int j = 0; j < int(chunkGrid[i].size()); j++)
		{
			
			if (chunkGrid[i][j] != NULL) //if there is a chunk there, draw it
				chunkGrid[i][j]->draw();
		}
	}
}

bool worldGrid::loadGridFromText(std::string path)
{
	std::ifstream baseGridFile;
	baseGridFile.open(path);
	if (!baseGridFile.is_open())
	{
		std::cout << "[ERROR]: File " << path << " couldn't be opened. Maby it doesn't exist." << std::endl;
		return false;
	}
	else
	{
	std::string sW, sH;
		getline(baseGridFile, sW);
		getline(baseGridFile, sH);

		if (sW == "" || sH == "")
		{
			std::cout << "[ERROR]: File " << path << " width or height is missing. could not load baseGrid." << std::endl;
			return false;
		}
		else
		{
			int w, h;
			w = atoi(sW.c_str());
			h = atoi(sH.c_str());
			return false;
			for (int i = 1; i <= w; i++)
			{
				for (int j = 1; j <= h; j++)
				{
					//insert string loading baseGrid system thing here
				}
			}
		}
	}
}

bool worldGrid::useDefaultGrid() //for testing purposes
{
	const int width = 5;
	const int height = 5;

	//instantiate the 2D vector
	//i = x, j = y
	for (int i = 0; i < height; i++)
	{
		std::vector<chunk* > tempChunks;
		for (int j = 0; j < width; j++)
		{
			chunk* tempChunk = new chunk(i, j);
			tempChunks.push_back(tempChunk);
		}
		chunkGrid.push_back(tempChunks);
	}

	//setup the chunk grid
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			for (int x = 0; x < 10; x++)
			{
				for (int y = 0; y < 10; y++)
				{
					bool success = chunkGrid[i][j]->loadTile(tileService::grass, x, y);

					if (success == false)
					{
						return false;
					}

					success = chunkGrid[i][j]->loadBlock(blockService::air, x, y);

					if (success == false)
					{
						return false;
					}

				}
			}
		}
	}

	gridWidth = width; gridHeight = height;
	return true;
}

worldGrid::~worldGrid()
{
	for (int i = 0; i < int(chunkGrid.size()); i++)
	{
		for (int j = 0; j < int(chunkGrid[i].size()); j++)
		{
			delete chunkGrid[i][j];
		}
	}
}
