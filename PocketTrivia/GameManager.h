#pragma once

#include <allegro.h>
#include "menus/MainMenu.h"
#include "GameIntroScreen.h"
#include "GameModeSelectionMenu.h"


#include "menus/SettingsMenu.h"
#include "menus/GFXSettingsMenu.h"
#include "menus/SoundSettingsMenu.h"
#include "menus/CreditsMenu.h"

#include "GameQuestionScreen.h"

#include "Constants.h"
#define CONFIG_FILE "PocketTrivia.cfg"

/*
	This function initializes allegro and sets up sound and keyboard.
	Parameters: no params
	Returns: 0 if everything is setup successfully else error code
*/
//extern int init(void);

class GameManager {
private:
	GameState* gameState;
	void bufferToScreen(BITMAP* buffer);
	void showLoadingScreen(BITMAP* buffer);
	void renderFrameToScreen(BITMAP* buffer);

	GameIntroScreen* gameIntroScreen;

	MainMenu* mainMenu;
	GFXSettingsMenu* gfxSettingsMenu;
	SoundSettingsMenu* soundSettingsMenu;
	SettingsMenu* settingsMenu;
	CreditsMenu* creditsMenu;
	GameModeSelectionMenu* gameModeSelectionMenu;

	GameQuestionScreen* gameQuestionScreen;

	BITMAP* loadScreen; 
	BITMAP* cursor;
	BITMAP* cursorHand;
	int pointerAsCursor; 
public:
	GameManager(GameState* gamseState);
	int init(void);
	void exit(void); 
	void runGameLoop(void);

};