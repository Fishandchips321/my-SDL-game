#include "consoleService.h"


consoleService::consoleService()
{
}

void consoleService::info(std::string text)
{
	std::cout << "[INFO]: " << text << std::endl;
}

void consoleService::warn(std::string text)
{
	std::cout << "[WARN]: " << text << std::endl;
}

void consoleService::error(std::string text)
{
	std::cout << "[ERROR]: " << text << std::endl;
}

bool consoleService::UIGeneric(std::string text)
{
	UIConsole* cons;
	cons = dynamic_cast <UIConsole*> (UIService::containers[1]);
	return cons->write(text);
}

bool consoleService::UIInfo(std::string text)
{
	UIConsole* cons;
	cons = dynamic_cast <UIConsole*> (UIService::containers[1]);
	return cons->write("[INFO]: " + text);
}

bool consoleService::UIWarn(std::string text)
{
	UIConsole* cons;
	cons = dynamic_cast <UIConsole*> (UIService::containers[1]);
	return cons->write("[WARN]: " + text);
}

bool consoleService::UIError(std::string text)
{
	UIConsole* cons;
	cons = dynamic_cast <UIConsole*> (UIService::containers[1]);
	return cons->write("[ERROR]: " + text);
}

consoleService::~consoleService()
{
}
