#pragma region TODO and notes
//TODO
//* = don't have to complete

//VERY IMPORTANT!!!
//setup main to use the game class.

//encorperate a lighting surface layer which will have the light drawn onto it. it will be slightly transparent depending on the light level
//setup renderer functions for the Texture type*

//setup GUI for inventory - an inventory menu
//use widget as a base class
//create a UI container
//use function pointers with buttons for callback*

//use scripting to create AI packages
//use lua scripts to create items?

//complete the terrain generation class
//research how to randomly generate terrain :P

//the entity controller will register each entity to one or more chunks (if it is across a chunk boundary)
//the controller will deal with collisions with other entities and blocks using a vector of structs
	//the structs will have an entity pointer and 4 chunk pointers
//the controller will handle pushing of other entities and damaging
	//when a mob comes into collision with another mob, it calls a function of the colliding entity with a pointer to the other entity (for damaging etc.)

//worldGrid file loading/creating
//when the player creates a new world create an empty file
//the world grid will find NULL references to tiles and blocks so it will randomly generate them
//when a chunk unloads the world grid will check if it has been changed (the flag has been implemented already)
//if it has been changed, the changes are saved and the chunk object is deleted
//if it hasn't been changed, the chunk object is just deleted

//every time a chunk is loaded or generated check to see if mobs should spawn
//spawnable entities will be registered with a mob spawning class

//figure out how the game will access the blocks, items etc objects
//terrain gen will add blocks to chunks based on the seed and registered terrain types
//	e.g. ground, ore etc.
//items will be spawned by blocks/mobs and created through crafting
//entities will be spawned using an entity service
//a spawn service will determine when and where to spawn mobs e.g. sheep raiders etc.
#pragma endregion

#include <iostream>
#include <SDL.h>
#include "game.h"

using namespace std;

int main(int argc, char* argv[])
{
	
	SDL_Quit();

	return 0;
}