#pragma once
#include "blockService.h"
#include "entityService.h"
#include "gridService.h"
#include "imageService.h"
#include "itemService.h"
#include "playerService.h"
#include "tileService.h"
#include "worldService.h"
class serviceInterface
{
public:
	serviceInterface();
	~serviceInterface();

	blockService* Sblock;
	entityService* Sentity;
	gridService* Sgrid;
	imageService* Simage;
	itemService* Sitem;
	playerService* Splayer;
	tileService* Stile;
	worldService* Sworld;
};

