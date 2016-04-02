#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "render.h"
class imageService
{
public:
	imageService();
	static SDL_Surface* loadText(std::string text, SDL_Color colour, int font);
	static SDL_Texture* loadTexture(std::string path);
	static bool loadFont(std::string path, int size = 10);
	static void getTextSize(int *w, int *h, int font, std::string text);
	~imageService();

	enum commonFonts
	{
		UIfont,
		UIfont_thin
	};

private:
	static std::vector<TTF_Font* > loadedFonts;
};

