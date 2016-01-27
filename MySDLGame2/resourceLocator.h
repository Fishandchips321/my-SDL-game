#pragma once
#include <memory>
#include "render.h"
#include "gridService.h"
#include "imageService.h"
#include "blockService.h"
#include "world.h"
#include "playerService.h"
#include "inventoryService.h"
#include "tileService.h"

class resourceLocator
{
public:
	resourceLocator();
	~resourceLocator();

	static render* globalRenderer;//
	static imageService* myImageService;//
	static blockService* myBlockService;//
	static world* myWorld;//
	static playerService* myPlayerService;//
	static inventoryService* myInventoryService;//
	static tileService* myTileService;//
	static SDL_Event* currentEvent;//

	const int tileWidth = 20;
	const int tileHeight = 20;

};