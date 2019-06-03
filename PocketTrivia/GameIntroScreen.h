#pragma once
#include "Constants.h"
#include  "ConfigManager.h"

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
	BoundingBox skipIntroButton;
	BoundingBox okButton;
	ConfigManager* configManager;

public:
	GameIntroScreen(GameState* gameState, ConfigManager* configManager);
	void showIntroScreen(BITMAP* buffer);
};

