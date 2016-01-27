#pragma once
#include "resourceLocator.h"
#include <vector>
#include "block.h"
class blockService
{
public:
	blockService();
	void update();
	int registerBlock(block* newBlock);
	bool registerForUpdates(block* newBlock); //for animated textures
	~blockService();

	std::vector<block* > blocks;

	enum blockType// <- for testing purposes. to be removed after inventory is fully implemented
	{
		air,
		test,
		wood,
		stone,
		workbench
	};

private:
	std::vector<block* > updates;
	//int updatesSize
	//int blocksSize;
	resourceLocator* myRL;
};

