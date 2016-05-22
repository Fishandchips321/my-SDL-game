#pragma once
#include "container.h"
#include "imageService.h"
#include "render.h"
#include <vector>
class UIConsole : public container
{
public:
	UIConsole();
	void update();
	void draw();
	bool write(std::string text);
	~UIConsole();
private:
	SDL_Rect con;
	std::vector<SDL_Texture* > lines;
	SDL_Rect drawRect;
};

