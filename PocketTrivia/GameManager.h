#pragma once

#include <allegro.h>
#include "menus/MainMenu.h"
#include "GameIntroScreen.h"
#include "QuizChapterSelectionMenu.h"
#include  "SoundManager.h"


#include "menus/SettingsMenu.h"
#include "menus/GFXSettingsMenu.h"
#include "menus/SoundSettingsMenu.h"
#include "menus/CreditsMenu.h"

#include "GameQuestionScreen.h"

#include "Constants.h"
#define CONFIG_FILE "PocketTrivia.cfg"

/**
 * @brief It is the spine of the game. This class contains function for initialization of the game and the game loop. 
 * It manages transition between screens, maintains the game state, facilitates communication between different screens and does a lot of 
 * housekeeping stuff.
 * 
 * 
 */

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
	QuizChapterSelectionMenu* quizChapterSelectionMenu;

	GameQuestionScreen* gameQuestionScreen;

	Quiz* quiz;

	SoundManager* soundManager;

	BITMAP* loadScreen; 
	BITMAP* cursor;
	BITMAP* cursorHand;
	int pointerAsCursor; 
public:
	/**
	 * @brief Construct a new Game Manager object
	 * 
	 * @param gamseState Pointer to the struct used for storing game struct
	 */
	GameManager(GameState* gamseState);

	/**
	 * @brief Initializes the game by performing required setup like initializing allegro etc.
	 * 
	 * @return int Zero if initialization is successfull
	 */
	int init(void);
	/**
	 * @brief Exits the game
	 * 
	 */
	void exit(void); 
	/**
	 * @brief Game loop 
	 * 
	 */
	void runGameLoop(void);

};