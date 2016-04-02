#pragma once
#include "resources.h"
class render
{
public:
	render();
	static bool init();
	static bool drawScreen();
	//static bool drawSurface(SDL_Surface* surface, SDL_Rect rect);
	//static bool drawScaledSurface(SDL_Surface* surface, SDL_Rect rect);
	//static bool drawScaledViewportSurface(SDL_Surface* surface, SDL_Rect stretchRect, SDL_Rect viewport);
	//static bool drawViewportSurface(SDL_Surface* surface, SDL_Rect viewport, SDL_Rect rect);
	static bool drawTexture(SDL_Texture* texture, SDL_Rect* rect, SDL_Rect* viewport = NULL);
	static bool drawSquare(SDL_Rect rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	static void eventUpdate();
	static int screenWidth; //640
	static int screenHeight; //480
	static int xOffset, yOffset;
	static SDL_Window* window;
	static SDL_Surface* screenSurface;
	static SDL_Renderer* renderer;
	~render();
private:

};

