#pragma once
#include "container.h"
#include "entityService.h"
#include "itemSelectWidget.h"
#include "inventoryService.h"
class itemSelectUI : public container
{
public:
	itemSelectUI();
	void update();
	void eventUpdate();
	void draw();
	~itemSelectUI();

private:
	int selectedItem;
	void select(int item);
	SDL_Rect selectRect;
	itemSelectWidget* widgets[5];
};

