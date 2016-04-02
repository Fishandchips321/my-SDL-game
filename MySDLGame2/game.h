#pragma once
#include "resources.h"
#include "counter.h"
#include "world.h"
#include "render.h"
#include "entityService.h"
#include "UIService.h"
class game
{
public:
	game();
	bool startGameLoop();
	bool init();
	~game();
private:

	enum class gameStates
	{
		splash,
		play,
		paused,
		over,
		end
	};

	const int FPS = 60;
	const int screenTicksPerFrame = 1000 / FPS;
	gameStates myGameState;

	void update();
	void eventUpdate();
	void draw();
};

