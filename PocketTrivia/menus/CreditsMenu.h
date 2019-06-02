#pragma once
#include "../Constants.h"
#include "../Utility.h"
#include <allegro.h>
class CreditsMenu
{
private:
	BITMAP* bannerBitmap;
	GameState* gameState;
	BITMAP* tempScreenBmp;
	char* credits;
	FONT* bigFont;
	BoundingBox backButton;
public:
	CreditsMenu(GameState* gameState);
	void showCreditsScreen(BITMAP* buffer);
};

