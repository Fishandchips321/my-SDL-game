#include "serviceLocator.h"


serviceLocator::serviceLocator()
{
}

serviceLocator::~serviceLocator()
{
	delete myPlayerService;
	delete myWorldService;
	delete myBlockService;
	delete myInventoryService;
	delete myUI;
}
