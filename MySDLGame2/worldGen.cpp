#include "worldGen.h"


worldGen::worldGen(int seed)
	:genSeed(seed)
{
}

chunk worldGen::generateChunk(int x, int y)
{
	chunk newChunk(x, y);
	//gen chunk here
	return newChunk;
}

worldGen::~worldGen()
{
}
