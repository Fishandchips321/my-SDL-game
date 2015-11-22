#include "worldService.h"


worldService::worldService()
{
}

bool worldService::getNewWorld(serviceLocator* SL)
{
	if (SL == NULL)
	{
		std::cout << "Service Locator is NULL in worldService" << std::endl;
		SDL_Delay(5000);
	}
	world tempWorld(SL);
	worlds.push_back(tempWorld);
	return true;
}

worldService::~worldService()
{
}
