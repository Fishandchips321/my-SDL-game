#pragma once
#include "itemStack.h"
class itemSelectWidget
{
public:
	itemSelectWidget(int x, int y);
	void draw();
	~itemSelectWidget();

	itemStack item;
	bool selected;

private:
	SDL_Texture* WTexture;
	SDL_Rect WRect;
	SDL_Rect IRect;
};

