#pragma once
#include "render.h"
#include "gridService.h"
#include "imageService.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_net.h>
#include <SDL_mixer.h>

class blockService;
class worldService;
class playerService;
class inventoryService;
class tileService;
class UI;
//todo: change all services into void* and have main setup serviceInterface
class serviceLocator
{
public:
	serviceLocator();

	render globalRenderer;
	playerService* myPlayerService;
	imageService myImageService;
	gridService myGridService;
	worldService* myWorldService;
	SDL_Event currentEvent;
	blockService* myBlockService;
	inventoryService* myInventoryService;
	UI* myUI;
	tileService* myTileService;
	~serviceLocator();

#pragma region commonVariablePointers/Constants
	const int tileWidth = 20;
	const int tileHeight = 20;

	SDL_Rect* playerRect;
#pragma endregion

#pragma region enums

#pragma region blockMaterialEnums
	enum materialTypes
	{
		wood,
		stone,
		metal,
		plastic,
		rubber,
		dirt
	};

	enum toolTypes
	{
		pickaxe,
		axe,
		shovel,
		saw
	};
#pragma endregion


#pragma endregion
};