#pragma once
#include "item.h"

class itemStack
{
public:
	itemStack();
	void setItem(item* NItem);
	item* getItem();
	void setAmount(int amount);
	void addAmount(int amount);
	void removeAmount(int amount);
	int getAmount();
	void setMetadata(int meta);
	int getMetadata();
	~itemStack();

private:
	item* SItem;
	int amount;
	int metadata;
};

