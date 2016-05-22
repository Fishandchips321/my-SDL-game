#pragma once
#include <vector>
#include "container.h"
class UIService
{
public:
	UIService();
	static void update();
	static void eventUpdate();
	static void draw();
	static bool registerContainer(container* newCont);
	~UIService();

	static std::vector<container* > containers;
};

