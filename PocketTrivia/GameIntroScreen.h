#pragma once
#include "Constants.h"
#include "Utility.h"
#include <allegro.h>
class GameIntroScreen
{
private:
	BITMAP* bannerBitmap;
	GameState* gameState;
	BITMAP* tempScreenBmp;
	char* introText;
	FONT* bigFont;

public:
	GameIntroScreen(GameState* gameState);
	void showIntroScreen(BITMAP* buffer);
};

