#include "render.h"
#include "SDL.h"
#include "SDL_image.h"
#include <stdio.h>
#include <iostream>

int render::xOffset, render::yOffset;
SDL_Window* render::window = nullptr;
SDL_Surface* render::screenSurface = nullptr;
SDL_Renderer* render::renderer = nullptr;
int render::screenWidth = 640;
int render::screenHeight = 480;

render::render()
{
}

bool render::init()
{
	xOffset = 0;
	yOffset = 0;
	//create the window
	window = SDL_CreateWindow("Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
	if (window == NULL) // if the window wasn't created
	{
		std::cout << "[ERROR]: An error occured in render. SDL error " << SDL_GetError() << std::endl;
		return false;
	}

	// get the screen's surface
	//screenSurface = SDL_GetWindowSurface(window);
	//if (screenSurface == NULL) // if the surface wasn't gotten
	//{
	//	std::cout << "[ERROR]: an error occured while trying to get the window surface. SDL error " << SDL_GetError() << std::endl;
	//	return false;
	//}

	//initialize the renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
		return false;
	}
	else
	{
		//Initialize renderer color
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xff);
	}

	std::cout << "[INFO]: The renderer was successfully initialised" << std::endl;
	return true;

}

bool render::drawScreen()
{
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xff);
	SDL_RenderPresent(renderer);

	//if (SDL_UpdateWindowSurface(window) != 0) // draw the surface to the window
	//{
	//	std::cout << "[ERROR]: the window wasn't updated SDL_Error: " << SDL_GetError() << std::endl;
	//	return false;
	//}

	//SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x00, 0x00, 0x00)); // clear the screen surface
	SDL_RenderClear(renderer);
	return true;
}

void render::eventUpdate()
{
	if (resources::currentEvent->type == SDL_WINDOWEVENT && resources::currentEvent->window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
	{
		screenWidth = resources::currentEvent->window.data1;
		screenHeight = resources::currentEvent->window.data2;

		screenSurface = SDL_GetWindowSurface(window);
		if (screenSurface == NULL) // if the surface wasn't gotten
		{
			std::cout << "[ERROR]: an error occured while trying to get the window surface. SDL error " << SDL_GetError() << std::endl;
		}
	}
}

//bool render::drawSurface(SDL_Surface* surface, SDL_Rect rect)
//{
//	if (SDL_BlitSurface(surface, NULL, screenSurface, &rect) != 0)// draw the surface directly to the screen surface
//	{
//		std::cout << "[ERROR]: the surface couldn't be blitted SDL_Error: " << SDL_GetError() << std::endl;
//		
//		return false;
//	}
//
//	if (surface == NULL)
//	{
//		std::cout << "[ERROR]: the surface passed was NULL" << std::endl;
//		return false;
//	}
//	return true;
//}
//
//bool render::drawScaledSurface(SDL_Surface* surface, SDL_Rect rect)
//{
//	if (SDL_BlitScaled(surface, NULL, screenSurface, &rect))// draw the surface to the screen to the size of the rectangle
//	{
//		std::cout << "[ERROR]: the surface couldn't be scale-blitted" << std::endl;
//		return false;
//	}
//
//	if (surface == NULL)
//	{
//		std::cout << "[ERROR]: the surface passed was NULL" << std::endl;
//		return false;
//	}
//	return true;
//}
//
//bool render::drawScaledViewportSurface(SDL_Surface* surface, SDL_Rect strechRect, SDL_Rect viewport)
//{
//	SDL_BlitScaled(surface, &viewport, screenSurface, &strechRect); // draw a section of the surface to the screen to the size of the rectangle
//	return true;
//}
//
//bool render::drawViewportSurface(SDL_Surface* surface, SDL_Rect viewport, SDL_Rect rect)
//{
//	SDL_BlitSurface(surface, &viewport, screenSurface, &rect); // draw a section of the surface directly to the screen surface
//	return true;
//}

bool render::drawSquare(SDL_Rect rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	SDL_SetRenderDrawColor(renderer, r, g, b, a);

	if (SDL_RenderFillRect(renderer, &rect) != 0)
	{
		std::cout << "[ERROR]: Problem filling rectangle " << rect.x << " " << rect.y << " " << rect.w << " " << rect.h << ". SDL Error: " << SDL_GetError() << std::endl;
		return false;
	}
	return true;
}

bool render::drawTexture(SDL_Texture* texture, SDL_Rect* rect, SDL_Rect* viewport)
{
	if (texture == nullptr)
		return false;
	if (SDL_RenderCopy(renderer, texture, viewport, rect) != 0)
	{
		std::cout << "[ERROR]: Problem rendering texture " << texture << ". SDL Error: " << SDL_GetError() << std::endl;
		return false;
	}
	return true;
}

render::~render()
{
	// destroy the window and NULL the pointer
	SDL_DestroyWindow(window);
	window = NULL;
}
