#include "UIService.h"

std::vector<container* > UIService::containers;

UIService::UIService()
{
}

void UIService::update()
{
	for (size_t x = 0; x < containers.size(); x++)
	{
		containers[x]->update();
	}
}

void UIService::eventUpdate()
{
	for (size_t x = 0; x < containers.size(); x++)
	{
		containers[x]->eventUpdate();
	}
}

void UIService::draw()
{
	for (size_t x = 0; x < containers.size(); x++)
	{
		containers[x]->draw();
	}
}

bool UIService::registerContainer(container* newCont)
{
	if (newCont != nullptr)
	{
		containers.push_back(newCont);
		return true;
	}
	return false;
}


UIService::~UIService()
{
	for (size_t x = 0; x < containers.size(); x++)
	{
		delete containers[x];
	}
}
