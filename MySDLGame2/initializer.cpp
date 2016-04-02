#include "initializer.h"


initializer::initializer()
{
}

bool initializer::initAll()
{
	bool success = true;
	//init SDL
	if (initSDL())
	{
		cout << "[INFO]: SDL was initialized successfully" << endl;
	}
	else
	{
		cout << "[ERROR]: SDL wasn't initialised" << endl;
		success = false;
	}
	//init the resource locator
	if (initRender())
	{
		cout << "[INFO]: Resource Locator initialized successfully" << endl;
	}
	else
	{
		cout << "[ERROR]: Resource Locator wasn't initialized correctly" << endl;
	}
	//load the fonts
	if (loadAllFonts())
	{
		cout << "[INFO]: The fonts were loaded" << endl;
	}
	else
	{
		cout << "[ERROR]: The fonts wern't loaded" << endl;
		success = false;
	}
	//initialise the block objects
	if (initBlocks())
	{
		cout << "[INFO]: The blocks were initialized correctly" << endl;
	}
	else
	{
		cout << "[ERROR]: The blocks weren't initialized correctly" << endl;
		success = false;
	}
						
	if (initTiles())
	{
	}
	else
	{
		cout << "[ERROR]: The tiles weren't initialised correctly" << endl;
		success = false;
	}
	
	if (initPlayer())
	{
	}
	else
	{
		cout << "[ERROR]: Player wasn't initialized correctly" << endl;
		success = false;
	}

	if (!initUI())
	{
		cout << "[ERROR]: couldn't initialise the UI" << endl;
		success = false;
	}

	return success;
}

bool initializer::initSDL()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		cout << "[ERROR]: SDL failed to init. SDL_image Error: " << IMG_GetError() << endl;
		return false;
	}
	else
	{
		cout << "[INFO]: SDL initalised." << endl;
		int imgFlags = IMG_INIT_PNG;
		if (!(IMG_Init(imgFlags) & imgFlags))
		{
			cout << "[ERROR]: IMG didn't initialise properly. SDL Error " << SDL_GetError() << endl;
			return false;
		}
		else
		{
			cout << "[INFO]: IMG initialised." << endl;
			//Initialize SDL_ttf
			if (TTF_Init() == -1)
			{
				cout << "[ERROR]: SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << endl;
				return false;
			}
			else
			{
				return true;
			}
		}

	}
}

//bool initializer::loadBlueUI()
//{
//	bool loaded = true;
//
//	const string path = "assets/Textures/UI/Seperate/blue_";
//
//	//check mark box
//	if (!myRL.myImageService->loadImage(path + "boxCheckMark.png"))
//	{
//		loaded = false;
//		cout << "[ERROR]: Failed to load \"blue_boxCheckMark.png\"" << endl;
//	}
//	//cross box
//	if (!myRL.myImageService->loadImage(path + "boxCross.png"))
//	{
//		loaded = false;
//		cout << "[ERROR]: Failed to load \"blue_boxCross.png\"" << endl;
//	}
//	//radio button
//	if (!myRL.myImageService->loadImage(path + "boxTick.png"))
//	{
//		loaded = false;
//		cout << "[ERROR]: Failed to load \"blue_boxTick.png\"" << endl;
//	}
//	//button type 1 up
//	if (!myRL.myImageService->loadImage(path + "button00.png"))
//	{
//		loaded = false;
//		cout << "[ERROR]: Failed to load \"blue_button00.png\"" << endl;
//	}
//	//button type 1 down
//	if (!myRL.myImageService->loadImage(path + "button01.png"))
//	{
//		loaded = false;
//		cout << "[ERROR]: Failed to load \"blue_button01.png\"" << endl;
//	}
//	//button type 2 up
//	if (!myRL.myImageService->loadImage(path + "button02.png"))
//	{
//		loaded = false;
//		cout << "[ERROR]: Failed to load \"blue_button02.png\"" << endl;
//	}
//	//button type 2 down
//	if (!myRL.myImageService->loadImage(path + "button03.png"))
//	{
//		loaded = false;
//		cout << "[ERROR]: Failed to load \"blue_button03.png\"" << endl;
//	}
//	//button type 3 up
//	if (!myRL.myImageService->loadImage(path + "button04.png"))
//	{
//		loaded = false;
//		cout << "[ERROR]: Failed to load \"blue_button04.png\"" << endl;
//	}
//	//button type 3 down
//	if (!myRL.myImageService->loadImage(path + "button05.png"))
//	{
//		loaded = false;
//		cout << "[ERROR]: Failed to load \"blue_button05.png\"" << endl;
//	}
//	//button type 4 up
//	if (!myRL.myImageService->loadImage(path + "button07.png"))
//	{
//		loaded = false;
//		cout << "[ERROR]: Failed to load \"blue_button07.png\"" << endl;
//	}
//	//button type 4 down
//	if (!myRL.myImageService->loadImage(path + "button08.png"))
//	{
//		loaded = false;
//		cout << "[ERROR]: Failed to load \"blue_button08.png\"" << endl;
//	}
//	//button type 5 up
//	if (!myRL.myImageService->loadImage(path + "button09.png"))
//	{
//		loaded = false;
//		cout << "[ERROR]: Failed to load \"blue_button09.png\"" << endl;
//	}
//	//button type 5 down
//	if (!myRL.myImageService->loadImage(path + "button10.png"))
//	{
//		loaded = false;
//		cout << "[ERROR]: Failed to load \"blue_button 10.png\"" << endl;
//	}
//	//button type 6 up
//	if (!myRL.myImageService->loadImage(path + "button11.png"))
//	{
//		loaded = false;
//		cout << "[ERROR]: Failed to load \"blue_button11.png\"" << endl;
//	}
//	//button type 6 down
//	if (!myRL.myImageService->loadImage(path + "button12.png"))
//	{
//		loaded = false;
//		cout << "[ERROR]: Failed to load \"blue_button12.png\"" << endl;
//	}
//	//blue check mark
//	if (!myRL.myImageService->loadImage(path + "checkmark.png"))
//	{
//		loaded = false;
//		cout << "[ERROR]: Failed to load \"blue_checkmark.png\"" << endl;
//	}
//	//blue circle
//	if (!myRL.myImageService->loadImage(path + "circle.png"))
//	{
//		loaded = false;
//		cout << "[ERROR]: Failed to load \"blue_circle.png\"" << endl;
//	}
//	//blue cross
//	if (!myRL.myImageService->loadImage(path + "cross.png"))
//	{
//		loaded = false;
//		cout << "[ERROR]: Failed to load \"blue_cross.png\"" << endl;
//	}
//	//blue panel
//	if (!myRL.myImageService->loadImage(path + "panel.png"))
//	{
//		loaded = false;
//		cout << "[ERROR]: Failed to load \"blue_panel.png\"" << endl;
//	}
//	//blue slider down
//	if (!myRL.myImageService->loadImage(path + "sliderDown.png"))
//	{
//		loaded = false;
//		cout << "[ERROR]: Failed to load \"blue_sliderDown.png\"" << endl;
//	}
//	//blue slider left
//	if (!myRL.myImageService->loadImage(path + "sliderLeft.png"))
//	{
//		loaded = false;
//		cout << "[ERROR]: Failed to load \"blue_sliderLeft.png\"" << endl;
//	}
//	//blue slider right
//	if (!myRL.myImageService->loadImage(path + "sliderRight.png"))
//	{
//		loaded = false;
//		cout << "[ERROR]: Failed to load \"blue_sliderRight.png\"" << endl;
//	}
//	//blue slider up
//	if (!myRL.myImageService->loadImage(path + "sliderUp.png"))
//	{
//		loaded = false;
//		cout << "[ERROR]: Failed to load \"blue_sliderUp.png\"" << endl;
//	}
//	//blue tick (circle mark for radio buttons)
//	return loaded;
//}
//
//bool initializer::loadGreenUI()
//{
//	bool loaded = true;
//
//	return loaded;
//}
//
//bool initializer::loadRedUI()
//{
//	bool loaded = true;
//
//	return loaded;
//}
//
//bool initializer::loadGreyUI()
//{
//	bool loaded = true;
//
//	return loaded;
//}
//
//bool initializer::loadYellowUI()
//{
//	bool loaded = true;
//
//	return loaded;
//}
//
//bool initializer::loadUI()
//{
//	bool loaded = true;
//
//	const string path = "assets/Textures/UI/Seperate/";
//
//	if (!loadBlueUI())
//		loaded = false;
//
//	if (!loadGreenUI())
//		loaded = false;
//
//	if (!loadGreyUI())
//		loaded = false;
//
//	if (!loadRedUI())
//		loaded = false;
//
//	if (!loadYellowUI())
//		loaded = false;
//
//	if (!myRL.myImageService->loadImage(path + "grey_sliderEnd.png"))
//	{
//		cout << "[ERROR]: Failed to load \"grey_sliderEnd.png\"" << endl;
//		loaded = false;
//	}
//
//	if (!myRL.myImageService->loadImage(path + "grey_sliderHorizontal.png"))
//	{
//		cout << "[ERROR]: Failed to load \"grey_sliderVertical.png\"" << endl;
//		loaded = false;
//	}
//
//	if (!myRL.myImageService->loadImage(path + "grey_sliderVertical.png"))
//	{
//		cout << "[ERROR]: Failed to load \"grey_sliderVertical.png\"" << endl;
//		loaded = false;
//	}
//
//	return loaded;
//}

bool initializer::loadAllFonts()
{
	bool loaded = true;
	string path = "assets/Fonts/";

	//UI font (the font that came with the UI pack)
	if (!imageService::loadFont(path + "kenvector_future.ttf", 15))
	{
		cout << "[ERROR]: failed to load font " << path + "kenvector_future.ttf" << endl;
		loaded = false;
	}
	//UI font thin
	if (!imageService::loadFont(path + "kenvector_future_thin.ttf", 10))
	{
		cout << "[ERROR]: failed to load font " << path + "kenvector_future_thin.ttf" << endl;
		loaded = false;
	}

	return loaded;
}

bool initializer::initRender()
{
	if (!render::init())
	{
		cout << "[ERROR]: Renderer wasn't initialised correctly. init returned false" << endl;
		return false;
	}
	return true;
}

bool initializer::initPlayer()
{
	player *mPlayer = new player();
	if (mPlayer == NULL)
	{
		cout << "[ERROR]: The player service couldn't be initialised" << endl;
		return false;
	}

	entityService::registerEntity(mPlayer);
	return true;
}

bool initializer::initBlocks()
{
	blockService::registerBlock(new air());
	blockService::registerBlock(new testBlock());
	return true;
}

bool initializer::initTiles()
{
	tileService::registerTile(new tile());
	tileService::registerTile(new grassTile());
	return true;
}

bool initializer::initUI()
{
	itemSelectUI* item = new itemSelectUI;

	if (UIService::registerContainer(item) == false)
	{
		std::cout << "[ERROR]: couldn't register container" << std::endl;
		return false;
	}
	return true;
}

initializer::~initializer()
{
}
