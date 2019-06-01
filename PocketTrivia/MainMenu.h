#pragma once 
#include <allegro.h>

class MainMenu
{
public:
	MainMenu();
	int showMainMenu(BITMAP* buffer);
private:
	int gameState;
	BITMAP* gameTitle;
	BITMAP* bannerBitmap;
	BITMAP* buttonsBitmap;
};

