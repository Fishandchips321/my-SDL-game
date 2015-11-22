#include "world.h"


world::world(serviceLocator* SL)
{
	mySL = SL;
	if (mySL == NULL)
	{
		std::cout << "Service Locator is NULL in World" << std::endl;
		SDL_Delay(5000);
	}
	mainGrid = new worldGrid(mySL);
}

bool world::getNewGrid()
{
	if (mySL == NULL)
	{
		std::cout << "Service Locator is NULL in World" << std::endl;
		SDL_Delay(5000);
	}
	otherGrids.push_back(new worldGrid(mySL));
	return true;
}

bool world::getNewWorldGrid()
{
	mainGrid = new worldGrid(mySL);
	return true;
}

void world::drawCurrentGrid()
{
	if (currentGrid == -1)
	{
		mainGrid->draw();
	}
	else
	{
		otherGrids[currentGrid]->draw();
	}
}

world::~world()
{
}
