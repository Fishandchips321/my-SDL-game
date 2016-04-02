#include "inventory.h"


inventory::inventory()
{
}

bool inventory::addItem(item*NItem, int amount)
{
	if (NItem->weight + currentWeight <= maxWeight)
	{
		//if it's already in the inventory, increase the amount
		for (size_t i = 0; i < itemStacks.size(); i++)
		{
			if (itemStacks[i].SItem == NItem)
			{
				itemStacks[i].amount += amount;
				return true;
			}
		}
		//if it isn't in the inventory, add it
		itemStack i;
		i.SItem = NItem;
		i.metadata = NItem->getMetadata(0);
		i.amount = amount;
		itemStacks.push_back(i);
		return true;
	}
	else
	{
		return false;
	}
}

bool inventory::addItemStack(itemStack NStack)
{
	if ((NStack.SItem->weight * NStack.amount) + currentWeight <= maxWeight)
	{
		for (size_t i = 0; i < itemStacks.size(); i++)
		{
			if (itemStacks[i].SItem == NStack.SItem)
			{
				itemStacks[i].amount += NStack.amount;
				return true;
			}
		}
		itemStacks.push_back(NStack);
		return true;
	}
	else
	{
		return false;
	}
}

itemStack inventory::removeStack(item*NItem)
{
	for (size_t i = 0; i < itemStacks.size(); i++)
	{
		if (itemStacks[i].SItem == NItem)
		{
			itemStack s;
			s.SItem = itemStacks[i].SItem;
			s.amount = itemStacks[i].amount;
			s.metadata = itemStacks[i].metadata;
			itemStacks.erase(itemStacks.begin() + i);
			return s;

		}
	}
	itemStack s;
	s.SItem = nullptr;
	s.amount = 0;
	s.metadata = 0;
	return s;
}

itemStack inventory::removeHalfStack(item*NItem)
{
	for (size_t i = 0; i < itemStacks.size(); i++)
	{
		if (itemStacks[i].SItem == NItem)
		{
			itemStack s;
			s.SItem = itemStacks[i].SItem;
			s.amount = itemStacks[i].amount - (itemStacks[i].amount / 2);
			s.metadata = itemStacks[i].metadata;

			itemStacks[i].amount /= 2;
			return s;

		}
	}
	itemStack s;
	s.SItem = nullptr;
	s.amount = 0;
	s.metadata = 0;
	return s;
}

itemStack inventory::removeAmount(item*NItem, int amount)
{
	for (size_t i = 0; i < itemStacks.size(); i++)
	{
		if (itemStacks[i].SItem == NItem)
		{
			itemStack s;
			s.SItem = itemStacks[i].SItem;
			s.metadata = itemStacks[i].metadata;
			if (itemStacks[i].amount >= amount)
			{
				s.amount = amount;
			}
			else
			{
				s.amount = itemStacks[i].amount;
				itemStacks.erase(itemStacks.begin() + i);
			}
			return s;

		}
	}
	itemStack s;
	s.SItem = nullptr;
	s.amount = 0;
	s.metadata = 0;
	return s;
}

inventory::~inventory()
{
}
