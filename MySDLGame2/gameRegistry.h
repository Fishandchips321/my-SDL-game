#pragma once
#include "item.h"
#include "entity.h"
#include "block.h"
#include <SDL_mixer.h>
#include <SDL.h>
#include <utility>
#include <vector>
class gameRegistry
{
public:
	gameRegistry();
	int registerItem(item* NItem, std::string name);
	int registerEntity(entity* NEntity, std::string name);
	int registerBlock(block* NBlock, std::string name);

	item* getItem(int ID);
	entity* getEntity(int ID);
	block* getBlock(int ID);
	~gameRegistry();

private:
	std::vector<std::pair <item*, std::string> > items;
	std::vector<std::pair <entity*, std::string> > entities;
	std::vector<std::pair <block*, std::string> > blocks;
};

