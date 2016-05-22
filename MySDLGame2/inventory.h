#pragma once
#include <vector>
#include "itemStack.h"

class inventory
{
public:
	inventory();
	//adding items
	//used for picking up items. may change
	bool addItem(item* NItem, int amount); //adds the item to the first avalable slot in the inventory
	//used for moving itemStacks between inventories
	bool addItemStack(itemStack NStack);
	//removing items
	itemStack removeStack(item* NItem); //removes the itemstack from the array and returns it
	itemStack removeHalfStack(item* NItem);//halves the amount in the itemstack and returns a new itemstack with half the amount in it. new itemstack gets higher amount for odd amounts
	itemStack removeAmount(item* NItem, int amount); //removes a specific amount from a slot
	~inventory();
	
	std::vector<itemStack> itemStacks;
	double maxWeight;
	double currentWeight;
};

