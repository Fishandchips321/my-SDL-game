#include "inventory.h"


inventory::inventory()
{
}

bool inventory::addItem(item* NItem, int slot)
{
	return false;
}

bool inventory::addItem(item*NItem)
{
	return false;
}

bool inventory::addItemStack(itemStack* NStack, int slot)
{
	return false;
}

bool inventory::addItemStack(itemStack* NStack)
{
	return false;
}

itemStack inventory::removeStack(int slot)
{
	itemStack nil;
	return nil;
}

itemStack inventory::removeHalfStack(int slot)
{
	itemStack nil;
	return nil;
}

inventory::~inventory()
{
}
