#pragma once
#include "..//Constants.h"
#include "..//Utility.h"
#include <allegro.h>

/**
 * @brief This class contains function related to diplaying the Settings Menu and handling the events for it.
 * 
 */
class SettingsMenu
{
private:
	BITMAP* bannerBitmap;
	GameState* gameState;
	BoundingBox soundSettingButton;
	BoundingBox gfxSettingButton;
	BoundingBox backButton;

public:
	/**
	 * @brief Construct a new SettingsMenu object that would be used to display the Settings menu
	 * 
	 * @param gs Pointer to the game state struct that is shared by the entire game 
	 */
	SettingsMenu(GameState* gs);
	/**
	 * @brief Destroy the SettingsMenu struct and performs the required clean-up.
	 * 
	 */
	~SettingsMenu();
	
	/**
	 * @brief Draws Settings menu on to the buffer passed as an arguement 
	 * and also handles mouse click events for the same.
	 * 
	 * @param buffer Screen buffer or other buffer where the Settings screen has to be drawn.
	 */
	void showSettingsMenu(BITMAP* buffer);
};

