#include "chunk.h"
#include "blockService.h"
#include "tileService.h"
#include <exception>


chunk::chunk(serviceLocator* SL, int x, int y)
	:mySL(SL)
{
	//set the absolute position of the chunk
	if (mySL == NULL)
	{
		std::cout << "[ERROR]: Service Locator is NULL in chunk" << std::endl;
		SDL_Delay(5000);
	}

	if (x < 0 || x > 1000 || y < 0 || y > 1000)
	{
		std::cout << "[ERROR]: Incorrect positioning data" << std::endl;
	}
	int posX = chunkSize * mySL->tileWidth, posY = chunkSize * mySL->tileHeight;

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
	//initChunks();
}

//void chunk::initChunks()
//{
//	for (int x = 0; x < chunkSize; x++)
//	{
//		std::vector<int> tileX;
//		std::vector<int> blockX;
//		for (int y = 0; y < chunkSize; y++)
//		{
//			tileX.push_back(0);
//			blockX.push_back(0);
//		}
//		tiles.push_back(tileX);
//		blocks.push_back(blockX);
//	}
//}

void chunk::draw()
{

	if (mySL == NULL)
	{
		std::cout << "[ERROR]: chunk " << chunkRect.x / 200 << " " << chunkRect.y / 200 << " has a NULL service locator. Stopping..." << std::endl;
		SDL_Delay(5000);
		exit(1);
	}

	//i = x, j = y
	for (int i = 0; i < chunkSize; i++)
	{
		for (int j = 0; j < chunkSize; j++)
		{
			if (tiles[i][j] != NULL)
			{
				//tiles[i][j]->draw(chunkRect.x + (i * mySL->tileWidth), chunkRect.y + (j * mySL->tileHeight)); //draws the tile
				mySL->myTileService->tiles[tiles[i][j]]->draw(chunkRect.x + (i * mySL->tileWidth), chunkRect.y + (j * mySL->tileHeight));
			}
			else
			{
				std::cout << "[ERROR]: Chunk " << chunkRect.x / 200 << " " << chunkRect.y / 200 << " has a null tile at " << i << " " << j << std::endl;
				if (mySL != NULL)
				{
					tiles[i][j] = mySL->myTileService->grass;
				}
				else
				{
					std::cout << "[ERROR]: chunk " << chunkRect.x / 200 << " " << chunkRect.y / 200 << " has a NULL service locator. Stopping..." << std::endl;
					SDL_Delay(2000);
					exit(1);
				}

			}


			if (blocks[i][j] != NULL)
			{
				//blocks[i][j]->draw(chunkRect.x + (i * mySL->tileWidth), chunkRect.y + (j * mySL->tileHeight));//draws the block
				mySL->myBlockService->blocks[blocks[i][j]]->draw(chunkRect.x + (i * mySL->tileWidth), chunkRect.y + (j * mySL->tileHeight));
			}

			//std::cout << "drawn " << i << " " << j << std::endl;
		}
	}
}

bool chunk::placeBlock(int x, int y, int type)
{
	if (blocks[x][y] == 0)//if there isn't a block where the player wants to place one
	{
		blocks[x][y] = type; //get a refrence to the specified block type
		changed = true;
		return true;
	}
	else
	{
		return false;
	}
}

bool chunk::breakBlock(int x, int y)
{
	if (blocks[x][y] != 0)//if there isn't a block where the break request points to (which shouldn't happen mind)
	{
		blocks[x][y] = mySL->myBlockService->air;
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
	if (blocks[x][y] != NULL)
	{
		//return blocks[x][y]->onLeftClick();
		return mySL->myBlockService->blocks[blocks[x][y]]->onLeftClick();
	}
	return false;
}

bool chunk::rightClickBlock(int x, int y)
{
	if (blocks[x][y] != NULL)
	{
		//return blocks[x][y]->onRightClick();
		return mySL->myBlockService->blocks[blocks[x][y]]->onRightClick();
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

bool chunk::loadBlock(int newBlock, int x, int y)
{
	blocks[x][y] = newBlock;
	if (blocks[x][y] == newBlock)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool chunk::loadTile(int newTile, int x, int y)
{

	if (newTile == NULL)
	{
		return false;
	}

	tiles[x][y] = newTile;
	if (tiles[x][y] == newTile)
	{
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
