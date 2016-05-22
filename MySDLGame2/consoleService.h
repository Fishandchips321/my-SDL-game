#pragma once
#include <iostream>
#include <stdio.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include "UIConsole.h"
#include "UIService.h"
#include <sstream>
class consoleService
{
public:
	consoleService();
	static void info(std::string text);
	static void warn(std::string text);
	static void error(std::string text);
	static bool UIGeneric(std::string text);
	static bool UIInfo(std::string text);
	static bool UIWarn(std::string text);
	static bool UIError(std::string text);
	~consoleService();
};

