#pragma once
#include <lua.hpp>
#include <iostream>
#include <vector>
class scriptService
{
public:
	scriptService();
	lua_State* getScript(int script);
	lua_State* loadScript(std::string path);
	~scriptService();

	enum commonScripts
	{
		none,
		follow
	};

private:
	std::vector<lua_State* > states;
	std::string scripts[10];
};

