#pragma once
#include "worldGrid.h"
class world
{
public:
	world(serviceLocator* SL);
	bool getNewGrid();
	bool getNewWorldGrid();
	void drawCurrentGrid();
	~world();

	worldGrid* mainGrid;
	std::vector<worldGrid* > otherGrids;
	int currentGrid = -1;
private:
	serviceLocator* mySL;
	
};

