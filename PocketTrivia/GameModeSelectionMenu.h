#pragma once

#include "Constants.h"

#include "Utility.h"
#include <allegro.h>

class GameModeSelectionMenu
{
public:
	GameModeSelectionMenu(GameState* gameState);
	void showGameModeMenu(BITMAP* buffer);

private:
	GameState* gameState;
	BITMAP* bannerBitmap;
	BoundingBox exitToMainMenuButton;
	BoundingBox playButton;

};

