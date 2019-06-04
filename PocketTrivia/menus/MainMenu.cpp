#include "MainMenu.h"
#include "../Constants.h" 
#include "../Utility.h"
#include <allegro.h>



MainMenu::MainMenu(GameState* gs) { 
	this->gameState = gs;
	this->gameTitle = load_bitmap("assets/main-menu/GameTitleBanner.bmp", NULL);
	this->bannerBitmap = load_bitmap("assets/ui-elem/Banner_Sq.bmp", NULL);
	this->buttonsBitmap = load_bitmap("assets/main-menu/MainMenuButtons.bmp", NULL);

	//TODO: Remove warnings ---> Initialize all the buttons
}

int MainMenu::showMainMenu(BITMAP* buffer) { 
	rectfill(buffer, 0, 0, SCREEN_W, SCREEN_H, COLOR_BG);
	//draw buffer to screen and clear buffer

	const float buttonHeightToBmpHeightRatio = 62.0 / 307;
	const float buttonGapToBmpHeightRatio = 21.0 / 307;

	if (SCREEN_W == 640 && SCREEN_H == 480) {

		masked_stretch_blit(gameTitle, buffer, 0, 0, gameTitle->w, gameTitle->h, SCREEN_W * 0.1, 20 , SCREEN_W * 0.8, ((gameTitle->h*1.0)/ gameTitle->w) * SCREEN_W * 0.8);
		masked_stretch_blit(bannerBitmap, buffer, 0, 0, bannerBitmap->w, bannerBitmap->h, SCREEN_W * 0.1, SCREEN_H * 0.3, SCREEN_W * 0.8, ((bannerBitmap->h * 1.0) / bannerBitmap->w) * SCREEN_W * 0.6);

		float buttonGroupWidth = SCREEN_W * 0.5;
		float buttonGroupHeight = ((buttonsBitmap->h * 1.0) / buttonsBitmap->w) * SCREEN_W * 0.35;

		masked_stretch_blit(buttonsBitmap, buffer, 0, 0, buttonsBitmap->w, buttonsBitmap->h, SCREEN_W * 0.25, SCREEN_H * 0.36, buttonGroupWidth, buttonGroupHeight);


		startButton.x = settingsButton.x  = creditsButton.x = exitButton.x = SCREEN_W * 0.25;
		startButton.w = settingsButton.w = creditsButton.w = exitButton.w = buttonGroupHeight;
		startButton.h = settingsButton.h = creditsButton.h = exitButton.h = buttonGroupHeight * buttonHeightToBmpHeightRatio;
		startButton.y = SCREEN_H * 0.36; 
		settingsButton.y = startButton.y + startButton.h + buttonGapToBmpHeightRatio*(buttonGroupHeight);
		creditsButton.y = startButton.y + 2* settingsButton.h + 2 * buttonGapToBmpHeightRatio * (buttonGroupHeight);
		exitButton.y = startButton.y + 3 * exitButton.h + 3 * buttonGapToBmpHeightRatio * (buttonGroupHeight);
	}
	else if(SCREEN_W == 960 && SCREEN_H == 720) {
		masked_stretch_blit(gameTitle, buffer, 0, 0, gameTitle->w, gameTitle->h, (SCREEN_W - gameTitle->w) / 2, SCREEN_H * 0.05, gameTitle->w, gameTitle->h);
		masked_stretch_blit(bannerBitmap, buffer, 0, 0, bannerBitmap->w, bannerBitmap->h, (SCREEN_W - bannerBitmap->w) / 2, SCREEN_H * 0.35, bannerBitmap->w*0.9, bannerBitmap->h*0.9);
	

		float buttonGroupWidth = buttonsBitmap->w * 0.9;
		float buttonGroupHeight = buttonsBitmap->h * 0.9;

		masked_stretch_blit(buttonsBitmap, buffer, 0, 0, buttonsBitmap->w, buttonsBitmap->h, (SCREEN_W - buttonsBitmap->w) / 2, SCREEN_H * 0.45, buttonGroupWidth, buttonGroupHeight);

		startButton.x = settingsButton.x = creditsButton.x = exitButton.x = (SCREEN_W - buttonsBitmap->w * 0.9) / 2;
		startButton.w = settingsButton.w = creditsButton.w = exitButton.w = buttonsBitmap->w * 0.9;
		startButton.h = settingsButton.h = creditsButton.h = exitButton.h = buttonsBitmap->h * 0.9 * buttonHeightToBmpHeightRatio;
		startButton.y = SCREEN_H * 0.45;
		settingsButton.y = startButton.y + startButton.h + buttonGapToBmpHeightRatio * (buttonGroupHeight);
		creditsButton.y = startButton.y + 2 * settingsButton.h + 2 * buttonGapToBmpHeightRatio * (buttonGroupHeight);
		exitButton.y = startButton.y + 3 * exitButton.h + 3 * buttonGapToBmpHeightRatio * (buttonGroupHeight);
	}
	else  if (SCREEN_W == 1280 && SCREEN_H == 960) {
		masked_stretch_blit(gameTitle, buffer, 0, 0, gameTitle->w, gameTitle->h, (SCREEN_W - gameTitle->w) / 2, SCREEN_H*0.05, gameTitle->w, gameTitle->h);
		masked_stretch_blit(bannerBitmap, buffer, 0, 0, bannerBitmap->w, bannerBitmap->h, (SCREEN_W - bannerBitmap->w) / 2, SCREEN_H * 0.4, bannerBitmap->w, bannerBitmap->h);
		

		float buttonGroupWidth = buttonsBitmap->w;
		float buttonGroupHeight = buttonsBitmap->h ;

		masked_stretch_blit(buttonsBitmap, buffer, 0, 0, buttonsBitmap->w, buttonsBitmap->h, (SCREEN_W - buttonsBitmap->w) / 2, SCREEN_H * 0.5,buttonGroupWidth, buttonGroupHeight);

		startButton.x = settingsButton.x = creditsButton.x = exitButton.x = (SCREEN_W - buttonsBitmap->w ) / 2;
		startButton.w = settingsButton.w = creditsButton.w = exitButton.w = buttonsBitmap->w;
		startButton.h = settingsButton.h = creditsButton.h = exitButton.h = buttonsBitmap->h* buttonHeightToBmpHeightRatio;

		startButton.y = SCREEN_H * 0.5;
		settingsButton.y = startButton.y + startButton.h + buttonGapToBmpHeightRatio * (buttonGroupHeight);
		creditsButton.y = startButton.y + 2 * settingsButton.h + 2 * buttonGapToBmpHeightRatio * (buttonGroupHeight);
		exitButton.y = startButton.y + 3 * exitButton.h + 3 * buttonGapToBmpHeightRatio * (buttonGroupHeight);
	}
	 

	if (Utility::inTheBoundingBox(startButton)) {
		gameState->mouseHover = 1;

		if (mouse_b & 1){
			gameState->gameScreen = GAME_SCREEN_QUIZ_START;
			//reset the score and current question number
			gameState->currentQuestion = 0;
			gameState->currentScore = 0;

			gameState->mouseHover = 0;
			rest(300);
		}
	}
	else if (Utility::inTheBoundingBox(settingsButton)) {
		gameState->mouseHover = 1;

		if (mouse_b & 1){
			gameState->gameScreen = GAME_SCREEN_SETTINGS;
			gameState->mouseHover = 0;
			rest(300);
		}
	}
	else if (Utility::inTheBoundingBox(creditsButton)) {
		gameState->mouseHover = 1;

		if (mouse_b & 1){
			gameState->gameScreen = GAME_SCREEN_CREDITS;
			gameState->mouseHover = 0;
			rest(300);
		}
	}
	else if (Utility::inTheBoundingBox(exitButton)) {
		gameState->mouseHover = 1;
		if (mouse_b & 1)
			gameState->exitGame = 1;
	}
	else {
		gameState->mouseHover = 0;
	}

	//mouse coordinates
	textprintf(buffer, font, 10, 10, -1, "X:%d Y:%d S:%d S:%d C:%d E:%d GS:%d FS:%d", mouse_x, mouse_y, startButton.y, settingsButton.y, creditsButton.y, exitButton.y, gameState->gameScreen, gameState->fullscreen);
	
	//draw buffer to screen and clear buffer
	blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	clear_bitmap(buffer);   

	return this->gameState->gameScreen;
}
