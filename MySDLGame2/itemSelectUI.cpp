#include "itemSelectUI.h"


itemSelectUI::itemSelectUI()
{
	selectRect.w = 30 * 5;
	selectRect.h = 30;
	selectRect.x = (render::screenWidth / 2) - (selectRect.w / 2);
	selectRect.y = render::screenHeight - selectRect.h - 30;

	for (int x = 0; x < 5; x++)
	{
		widgets[x] = new itemSelectWidget(selectRect.x + (x * 30), selectRect.y);
	}
	selectedItem = 0;
	select(selectedItem);
}

void itemSelectUI::update()
{
	if (inventoryService::inventories.size() > 0)
	{
		for (int x = 0; x < 5; x++)
		{
			if (inventoryService::inventories[0]->itemStacks.size() - 1 >= x)
			{
				widgets[x]->item = inventoryService::inventories[0]->itemStacks[x];
			}
		}
	}
}

void itemSelectUI::eventUpdate()
{
	if (resources::currentEvent->type == SDL_MOUSEWHEEL)
	{
		selectedItem -= resources::currentEvent->wheel.y;
		if (selectedItem > 4)
		{
			selectedItem = 0;
		}

		if (selectedItem < 0)
		{
			selectedItem = 4;
		}

		select(selectedItem);
	}
}

void itemSelectUI::draw()
{	
	for (int x = 0; x < 5; x++)
	{
		widgets[x]->draw();
	}
}

void itemSelectUI::select(int item)
{
	for (int x = 0; x < 5; x++)
	{
		widgets[x]->selected = false;
	}

	widgets[item]->selected = true;
}


itemSelectUI::~itemSelectUI()
{
}
