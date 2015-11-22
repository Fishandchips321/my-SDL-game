#include "itemStack.h"


itemStack::itemStack()
{
}

void itemStack::setItem(item* NItem)
{
	SItem = NItem;
}

item* itemStack::getItem()
{
	return SItem;
}

void itemStack::setAmount(int amount)
{
	itemStack::amount = amount;
}

void itemStack::addAmount(int amount)
{
	itemStack::amount += amount;
}

void itemStack::removeAmount(int amount)
{
	itemStack::amount -= amount;
}

int itemStack::getAmount()
{
	return amount;
}

void itemStack::setMetadata(int meta)
{
	metadata = meta;
}

int itemStack::getMetadata()
{
	return metadata;
}

itemStack::~itemStack()
{
}
