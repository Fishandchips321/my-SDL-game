#include "scriptService.h"


scriptService::scriptService()
{
}

lua_State* scriptService::getScript(int script)
{
	lua_State* state = luaL_newstate();

	int err = luaL_loadfile(state, scripts[script].c_str());

	if (err != 0)
	{
		std::cout << "[ERROR]: there was a problem loading file \"" << scripts[script].c_str() << "\" ";

		if (err == LUA_ERRSYNTAX)
			std::cout << "there was a syntax error" << std::endl;

		if (err == LUA_ERRMEM)
			std::cout << "there was a memory allocation error" << std::endl;

		if (err == LUA_ERRFILE)
			std::cout << "the file couldn't be opened/read" << std::endl;

		delete state;

		return NULL;
	}

	states.push_back(state);

	return state;
}

lua_State* scriptService::loadScript(std::string path)
{
	lua_State* state = luaL_newstate();

	int err = luaL_loadfile(state, path.c_str());

	if (err != 0)
	{
		std::cout << "[ERROR]: there was a problem loading file \"" << path.c_str() << "\" ";

		if (err == LUA_ERRSYNTAX)
			std::cout << "there was a syntax error" << std::endl;

		if (err == LUA_ERRMEM)
			std::cout << "there was a memory allocation error" << std::endl;

		if (err == LUA_ERRFILE)
			std::cout << "the file couldn't be opened/read" << std::endl;

		delete state;

		return NULL;
	}

	states.push_back(state);

	return state;
}

scriptService::~scriptService()
{
	for (int i = 0; i < int(states.size()); i++)
	{
		delete states[i];
	}
}
