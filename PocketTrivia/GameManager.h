#pragma once

#include <allegro.h>
#include "MainMenu.h"
#define CONFIG_FILE "PocketTrivia.cfg"

/*
	This function initializes allegro and sets up sound and keyboard.
	Parameters: no params
	Returns: 0 if everything is setup successfully else error code
*/
//extern int init(void);

class GameManager {
private:
	int gameState;
	void bufferToScreen(BITMAP* buffer);
	void showLoadingScreen(BITMAP* buffer);
	void renderFrameToScreen(BITMAP* buffer);
	MainMenu* mainMenu;
	BITMAP* loadScreen; 

public:
	GameManager();
	int init(void);
	void exit(void); 
	void runGameLoop(void);

};