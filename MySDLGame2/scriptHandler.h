#pragma once
#include "scriptService.h"
#include <SDL.h>
class scriptHandler
{
public:
	scriptHandler();
	bool registerFunction(void* func);
	bool setScript(int script);
	bool setScript(std::string path);
	bool registerInt(int I);
	bool registerBool(bool B);
	bool registerRect(SDL_Rect rect);
	bool runScript();
	~scriptHandler();

	lua_State* state;
};

