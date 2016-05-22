#include "UIConsole.h"


UIConsole::UIConsole()
{
	con.w = 250;
	con.h = 60;
	con.x = render::screenWidth - con.w;
	con.y = 0;

	drawRect.x = con.x;
	//drawRect.h = con.h / 5;
}

void UIConsole::update()
{

}

void UIConsole::draw()
{
	render::drawSquare(con, 0, 0, 0, 0xaa);

	for (size_t x = 0; x < lines.size(); x++)
	{
		int w, h;
		SDL_QueryTexture(lines[x], NULL, NULL, &w, &h);
		drawRect.w = w;
		drawRect.h = h;
		drawRect.y = (con.h / 5) * (int)x;
		render::drawTexture(lines[x], &drawRect);
	}
}

bool UIConsole::write(std::string text)
{
	SDL_Texture* textTexture;
	SDL_Color colour = { 0xff, 0xff, 0xff, 0xff };
	textTexture = imageService::loadText(text, colour, imageService::UIfont, 10);
	if (textTexture == nullptr)
		return false;

	int w, h;
	SDL_QueryTexture(textTexture, NULL, NULL, &w, &h);

	lines.push_back(textTexture);

	if (lines.size() > 4)
	{
		lines.erase(lines.begin());
	}
	return true;
}

UIConsole::~UIConsole()
{
}
