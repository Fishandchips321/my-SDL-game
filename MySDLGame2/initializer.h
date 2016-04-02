#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <SDL_ttf.h>
#include <SDL_net.h>
#include <SDL_mixer.h>
#include <lua.hpp>
#include "resources.h"
#include "counter.h"
#include "air.h"
#include "testBlock.h"
#include "block.h"
#include "player.h"
#include "grassTile.h"
#include "blockService.h"
#include "tileService.h"
#include "entityService.h"
#include "itemSelectUI.h"
#include "itemSelectWidget.h"
#include "UIService.h"


using namespace std;

class initializer
{
public:
	initializer();
	bool initAll();
	~initializer();
	bool loadAllFonts();
	/*bool loadUI();
	bool loadBlueUI();
	bool loadRedUI();
	bool loadGreenUI();
	bool loadYellowUI();
	bool loadGreyUI();*/
	bool initRender();
	bool initPlayer();
	bool initBlocks();
	bool initTiles();
	bool initSDL();
	bool initUI();
private:
};

