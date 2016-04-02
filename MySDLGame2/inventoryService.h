#pragma once
#include "inventory.h"
#include <vector>

class inventoryService
{
public:
	inventoryService();
	static int registerInventory();
	static bool registerInventoryAt(int index);
	static inventory* getPointer(int index);
	static bool destroyInventory(int index);
	~inventoryService();

	static std::vector<inventory* > inventories;
};

