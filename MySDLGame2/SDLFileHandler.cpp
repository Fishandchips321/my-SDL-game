#include "SDLFileHandler.h"


SDLFileHandler::SDLFileHandler(std::string path, std::string mode)
{
	SDL_RWFromFile(path.c_str(), mode.c_str());
}

bool SDLFileHandler::writeString(std::string text)
{
	size_t len = SDL_strlen(text.c_str());
	if (SDL_RWwrite(file, &text, sizeof(text), len) != len)
	{
		std::cout << "[ERROR]: text couldn't be written" << std::endl;
		return false;
	}
	return true;
}

bool SDLFileHandler::writeString(std::stringstream text)
{
	std::string sText = text.str();
	size_t len = SDL_strlen(sText.c_str());
	if (SDL_RWwrite(file, &sText, sizeof(text), len) != len)
	{
		std::cout << "[ERROR]: text couldn't be written" << std::endl;
		return false;
	}
	return true;
}

bool SDLFileHandler::writeInt(int integer)
{
	std::string text;
	text = integer;
	size_t len = SDL_strlen(text.c_str());
	if (SDL_RWwrite(file, &text, sizeof(text), len) != len)
	{
		std::cout << "[ERROR]: text couldn't be written" << std::endl;
		return false;
	}
	return true;
}

SDLFileHandler::~SDLFileHandler()
{
	SDL_RWclose(file);
	delete file;
}
