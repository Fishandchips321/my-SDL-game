#pragma once
#include "itemStack.h"
#include "item.h"

class inventory
{
public:
	inventory();
	//adding items
	//used for picking up items. may change
	virtual bool addItem(item* NItem, int slot); //adds the item to the slot. if the item matches the item already in the slot, the amount is incremented
	virtual bool addItem(item*NItem); //adds the item to the first avalable slot in the inventory
	//used for moving itemStacks between inventories
	virtual bool addItemStack(itemStack* NStack, int slot);// same as above but for a stack of items
	virtual bool addItemStack(itemStack* NStack);//ditto
	//removing items
	virtual itemStack removeStack(int slot); //removes the itemstack from the array and returns it
	virtual itemStack removeHalfStack(int slot);//halves the amount in the itemstack and returns a new itemstack with half the amount in it. new itemstack gets higher amount for odd amounts
	~inventory();

	int lastSlot;

private:

};

