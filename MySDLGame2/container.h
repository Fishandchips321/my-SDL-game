#pragma once
#include "render.h"
#include "resources.h"
#include <vector>
class container
{
public:
	container();
	virtual void update();
	virtual void eventUpdate();
	virtual void draw();
	~container();
};

