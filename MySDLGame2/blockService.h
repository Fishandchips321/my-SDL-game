#pragma once
#include <vector>
#include "block.h"
class blockService
{
public:
	blockService();
	static void update();
	static int registerBlock(block* newBlock);
	static bool registerForUpdates(block* newBlock); //for animated textures
	~blockService();

	static std::vector<block* > blocks;

	enum blockType// <- for testing purposes. to be removed after inventory is fully implemented
	{
		air,
		test
	};

private:
	static std::vector<block* > updates;
};

