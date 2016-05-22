#pragma once
#include <sstream>
#include "resources.h"
#include <iostream>
class SDLFileHandler
{
public:
	SDLFileHandler(std::string path, std::string mode);
	bool writeString(std::string text);
	bool writeString(std::stringstream text);
	bool writeInt(int integer);
	~SDLFileHandler();

	SDL_RWops* file;
};

