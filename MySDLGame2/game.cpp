#include "game.h"
#include <iostream>

game::game()
{
}

bool game::init()
{
	myGameState = gameStates::play;
	bool success = world::useTestingWorld();

	if (success == false)
	{
		std::cout << "[ERROR]: test world couldn't be created. stopping..." << std::endl;
		SDL_Delay(2000);
		return false;
	}
	return true;
}

bool game::startGameLoop()
{
	bool quit = false;
	std::cout << "[INFO]: Entering the game loop" << std::endl;

	counter capTimer;

	counter fpsTimer;
	fpsTimer.start();
	int countedFrames = 0;

	while (!quit && myGameState != gameStates::end)
	{

		capTimer.start();
		SDL_Event e;
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}

			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)
			{
				myGameState = gameStates::end;
			}

			if (e.type >= SDL_USEREVENT)
			{
				std::cout << "user event detected" << std::endl;
			}

			resources::currentEvent = &e;
			eventUpdate();
		}

		//Calculate and correct fps
		float avgFPS = countedFrames / (fpsTimer.getTicks() / 1000.f);
		if (avgFPS > 2000000)
		{
			avgFPS = 0;
		}

		//output the agerage fps to the console
		//cout << (int)avgFPS << endl;

		//update then draw the game
		update();
		draw();

		//"frame capping"
		int frameTicks = capTimer.getTicks();
		if (frameTicks < screenTicksPerFrame)
		{
			SDL_Delay(screenTicksPerFrame - frameTicks);
		}

		++countedFrames;
	}

	return true;
}

void game::eventUpdate()
{
	switch (myGameState)
	{
	case gameStates::play:
		break;
	case gameStates::splash:
		break;
	case gameStates::end:
		break;
	case gameStates::over:
		break;
	case gameStates::paused:
		break;
	}
	render::eventUpdate();
	entityService::eventUpdate();
	UIService::eventUpdate();
}

void game::update()
{
	switch (myGameState)
	{
	case gameStates::play:
		entityService::update();
		UIService::update();
		break;
	case gameStates::splash:
		break;
	case gameStates::end:
		break;
	case gameStates::over:
		break;
	case gameStates::paused:
		UIService::update();
		break;
	}
	render::update();
}

void game::draw()
{
	switch (myGameState)
	{
	case gameStates::play:
		world::draw();
		entityService::draw();
		UIService::draw();
		break;
	case gameStates::splash:
		break;
	case gameStates::end:
		break;
	case gameStates::over:
		break;
	case gameStates::paused:
		world::draw();
		entityService::draw();
		UIService::draw();
		break;
	}

	render::drawScreen(); //no touchey
}

game::~game()
{
}
