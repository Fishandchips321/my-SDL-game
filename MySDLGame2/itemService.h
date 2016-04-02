#pragma once
#include "item.h"
#include <vector>
class itemService
{
public:
	itemService();
	bool registerItme(item* i);
	~itemService();
private:
	std::vector<item* > items;
};

