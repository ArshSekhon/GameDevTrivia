#pragma once 
#include "../Constants.h"
#include <allegro.h>

class MainMenu
{
public:
	MainMenu(GameState* gs);
	int showMainMenu(BITMAP* buffer);
private:
	GameState* gameState;
	BITMAP* gameTitle;
	BITMAP* bannerBitmap;
	BITMAP* buttonsBitmap;
	BoundingBox startButton;
	BoundingBox settingsButton;
	BoundingBox creditsButton;
	BoundingBox exitButton;
	
};

