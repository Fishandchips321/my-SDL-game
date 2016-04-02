#pragma once
#include <SDL.h>

class resources
{
public:
	resources();
	~resources();

	static const int tileWidth = 40;
	static const int tileHeight = 40;
	static SDL_Event* currentEvent;

	enum eventTypes
	{
		playerSelectItem
	};

};