#pragma once
#include "Constants.h"
#include  "ConfigManager.h"

#include "Utility.h"
#include <allegro.h>

/**
 * @brief This class contains function related to diplaying the Game Intro screen, handling the events for the screen and
 * managing and appling the Game Intro. 
 * 
 */
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
	/**
	 * 
	 * @brief Construct a new GameIntroScreen object that would be used to show an intro screen when game start.
	 * 
	 * @param gameState Pointer to the game state struct that is shared by the entire game
	 * @param configManager Pointer to the ConfigManager object that would be used to load and save the config related to game intro screen
	 * 
	 */
	GameIntroScreen(GameState* gameState, ConfigManager* configManager);


	/**
	 * @brief Draws game intro screen on to the buffer passed as an arguement 
	 * and also handles mouse click events for the same.
	 * 
	 * @param buffer Screen buffer or other buffer where the game intro screen screen has to be drawn.
	 */
	void showIntroScreen(BITMAP* buffer);
};

