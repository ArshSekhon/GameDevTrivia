#pragma once
#include "../Constants.h"
#include "../Utility.h"
#include <allegro.h>

/**
 * @brief This class contains function related to diplaying then Credits screen and handling the events for it. 
 * 
 */
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
	/**
	 * @brief Construct a new Credits Menu object.
	 * 
	 * @param gameState Pointer to the game state struct that is shared by the entire game.
	 */
	CreditsMenu(GameState* gameState);
	/**
	 * @brief This function draws credits menu on to the buffer passed as an arguement and also handles mouse clicks for the credits menu screen.
	 * 
	 * @param buffer Screen buffer or other buffer where the Credits screen has to be drawn.
	 */
	void showCreditsScreen(BITMAP* buffer);
};

