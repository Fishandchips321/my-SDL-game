#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <SDL_ttf.h>
#include <SDL_net.h>
#include <SDL_mixer.h>
#include <lua.hpp>
#include "resourceLocator.h"
#include "counter.h"
#include "air.h"
#include "testBlock.h"
#include "block.h"
#include "toolTip.h"
#include "grassTile.h"

using namespace std;

class initializer
{
public:
	initializer();
	bool initAll();
	~initializer();
	bool initServices();
	bool loadAllTextures();
	bool loadAllFonts();
	bool loadAllSounds();
	bool loadUI();
	bool loadBlueUI();
	bool loadRedUI();
	bool loadGreenUI();
	bool loadYellowUI();
	bool loadGreyUI();
	bool initRL();
	bool initPlayer();
	bool initBlocks();
	bool initTiles();
private:
	resourceLocator myRL;
};

