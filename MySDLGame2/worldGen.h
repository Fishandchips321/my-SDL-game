#pragma once
// this class will be used by the worldGrid class to generate new chunks
//it will return the generated chunks from the x and y coordinated passed into it
#include "resources.h"
#include "chunk.h"
class worldGen
{
public:
	worldGen(int seed);
	chunk generateChunk(int x, int y);
	~worldGen();
private:
	int genSeed;
};