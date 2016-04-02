#include "imageService.h"
#include <iostream>

std::vector<TTF_Font* > imageService::loadedFonts;

imageService::imageService()
{
}


SDL_Texture* imageService::loadTexture(std::string path)
{
	SDL_Texture* loadTexture(std::string path);
	{
		//The final texture
		SDL_Texture* newTexture = NULL;

		//Load image at specified path
		SDL_Surface* loadedSurface = IMG_Load(path.c_str());
		if (loadedSurface == NULL)
		{
			std::cout << "[ERROR]: Unable to load image " << path << "! SDL_image Error: " << IMG_GetError() << std::endl;
		}
		else
		{
			//Create texture from surface pixels
			newTexture = SDL_CreateTextureFromSurface(render::renderer, loadedSurface);
			if (newTexture == NULL)
			{
				std::cout << "[ERROR]: Unable to create texture from " << path << "!SDL Error : " << SDL_GetError() << std::endl;
			}

			//Get rid of old loaded surface
			SDL_FreeSurface(loadedSurface);
		}
		std::cout << "[INFO]: The image \"" << path << "\" was loaded and made into a texture" << std::endl;
		return newTexture;
	}
}

SDL_Surface* imageService::loadText(std::string text, SDL_Color colour, int font)
{
	SDL_Surface* textSurface;
	textSurface = TTF_RenderText_Solid(loadedFonts[font], text.c_str(), colour);
	if (textSurface == NULL)
	{
		std::cout << "[ERROR]: couldn't make text surface\"" << text << "\" with font " << font << ". SDL_Error: " << SDL_GetError() << std::endl;
		return false;
	}

	SDL_ConvertSurface(textSurface, render::screenSurface->format, NULL);//optimise the surface

	return textSurface;
}

bool imageService::loadFont(std::string path, int size)
{
	loadedFonts.push_back(TTF_OpenFont(path.c_str(), size));
	if (loadedFonts.back() == NULL)
	{
		std::cout << "[ERROR]: Couldn't load font \"" << path << "\". SDL_ERROR: " << SDL_GetError() << std::endl;
		return false;
	}
	return true;
}

void imageService::getTextSize(int *w, int *h, int font, std::string text)
{
	TTF_SizeText(loadedFonts[font], text.c_str(), w, h);
}


	imageService::~imageService()
{
}
