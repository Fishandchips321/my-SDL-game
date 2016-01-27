#include "resourceLocator.h"

render* resourceLocator::globalRenderer;
imageService* resourceLocator::myImageService;
blockService* resourceLocator::myBlockService;
world* resourceLocator::myWorld;
playerService* resourceLocator::myPlayerService;
inventoryService* resourceLocator::myInventoryService;
tileService* resourceLocator::myTileService;
UI* resourceLocator::myUI;
SDL_Event* resourceLocator::currentEvent;

resourceLocator::resourceLocator()
{
}


resourceLocator::~resourceLocator()
{
}
