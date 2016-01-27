#pragma once
#include "serviceLocator.h"
#include "counter.h"
class game
{
public:
	game(serviceLocator *SL);
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

	serviceLocator *mySL;
	const int FPS = 60;
	const int screenTicksPerFrame = 1000 / FPS;
	gameStates myGameState;

	void update();
	void eventUpdate();
	void draw();
};

