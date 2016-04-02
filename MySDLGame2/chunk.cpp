#include "chunk.h"


chunk::chunk(int x, int y)
{
	//set the absolute position of the chunk

	if (x < 0 || x > 1000 || y < 0 || y > 1000)
	{
		std::cout << "[ERROR]: Incorrect positioning data" << std::endl;
	}
	int posX = chunkSize * resources::tileWidth, posY = chunkSize * resources::tileHeight;

	if (posX < 0 || posY < 0)
	{
		std::cout << "[ERROR]: Chunk not setup properly; incorrect position data" << std::endl;
	}
	else
	{
		chunkRect.x = x * posX;
		chunkRect.y = y * posY;
		chunkRect.w = chunkSize;
		chunkRect.h = chunkSize;
		changed = false;
	}
}

void chunk::draw()
{
	//i = x, j = y
	for (int i = 0; i < chunkSize; i++)
	{
		for (int j = 0; j < chunkSize; j++)
		{
			if (tiles[i][j].tTile != NULL)
			{
				tiles[i][j].tTile->draw(chunkRect.x + (i * resources::tileWidth), chunkRect.y + (j * resources::tileHeight));
			}

			if (blocks[i][j].tBlock != NULL)
			{
				blocks[i][j].tBlock->draw(chunkRect.x + (i * resources::tileWidth), chunkRect.y + (j * resources::tileHeight));
			}

		}
	}
}

bool chunk::placeBlock(int x, int y, int type)
{
	if (blocks[x][y].tBlock == blockService::blocks[blockService::air])//if there isn't a block where the player wants to place one
	{
		blocks[x][y].tBlock = blockService::blocks[type]; //get a pointer to the specified block type
		changed = true;
		return true;
	}
	else
	{
		return false;
	}
}

bool chunk::placeBlock(int x, int y, block* nBlock)
{
	if (blocks[x][y].tBlock == blockService::blocks[blockService::air])//if there isn't a block where the player wants to place one
	{
		blocks[x][y].tBlock = nBlock; //the pointer of the supplied block
		changed = true;
		return true;
	}
	return false;
}

bool chunk::breakBlock(int x, int y)
{
	if (blocks[x][y].tBlock != blockService::blocks[blockService::air])//if there isn't a block where the break request points to (which shouldn't happen mind)
	{
		blocks[x][y].tBlock = blockService::blocks[blockService::air];
		changed = true;
		return true;
	}
	else
	{
		return false;
	}

	return false;
}

bool chunk::leftClickBlock(int x, int y)
{
	if (blocks[x][y].tBlock != NULL)
	{
		//return blocks[x][y]->onLeftClick();
		return blocks[x][y].tBlock->onLeftClick();
	}
	return false;
}

bool chunk::rightClickBlock(int x, int y)
{
	if (blocks[x][y].tBlock != NULL)
	{
		//return blocks[x][y]->onRightClick();
		return blocks[x][y].tBlock->onRightClick();
	}
	return false;
}

bool chunk::clearEntities()
{
	entities.clear();
	if (int(entities.size()) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool chunk::registerEntiy(entity* ent)
{
	entities.push_back(ent);
	if (entities.back() == ent)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool chunk::loadBlock(int newBlock, int x, int y, int metadata)
{
	blocks[x][y].tBlock = blockService::blocks[newBlock];
	if (blocks[x][y].tBlock == blockService::blocks[newBlock])
	{
		blocks[x][y].metadata = metadata;
		return true;
	}
	else
	{
		return false;
	}
}

bool chunk::loadTile(int newTile, int x, int y, int metadata)
{
	tiles[x][y].tTile = tileService::tiles[newTile];
	if (tiles[x][y].tTile == tileService::tiles[newTile])
	{
		tiles[x][y].metadata = metadata;
		return true;
	}
	else
	{
		return false;
	}
}

chunk::~chunk()
{
}
