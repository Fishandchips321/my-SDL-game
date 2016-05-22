#include "blockService.h"

std::vector<block* > blockService::blocks;
std::vector<block* > blockService::updates;

blockService::blockService()
{
}

void blockService::update()
{
	for (int i = 0; i < int(updates.size()); i++)
	{
		updates[i]->update();
	}
}

int blockService::registerBlock(block* newBlock)
{
	blocks.push_back(newBlock);
	newBlock->setID(int(blocks.size() - 1));
	return int(blocks.size());
}

bool blockService::registerForUpdates(block* newBlock)
{
	if (newBlock != NULL)
	{
		updates.push_back(newBlock);
		return true;
	}
	else
	{
		return false;
	}
}

blockService::~blockService()
{
}