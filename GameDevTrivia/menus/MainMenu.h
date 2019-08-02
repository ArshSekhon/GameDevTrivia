#pragma once 
#include "../Constants.h"
#include <allegro.h>

/**
 * @brief This class contains function related to diplaying the Main Menu and handling the events for it.
 * 
 */
class MainMenu
{
public:

	/**
	 * @brief Construct a new MainMenu object that would be used to create the Main menu
	 * 
	 * @param gs Pointer to the game state struct that is shared by the entire game 
	 */
	MainMenu(GameState* gs);

	/**
	 * @brief Draws main menu on to the buffer passed as an arguement 
	 * and also handles mouse click events for the same.
	 * 
	 * @param buffer Screen buffer or other buffer where the main menu screen has to be drawn.
	 */
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

