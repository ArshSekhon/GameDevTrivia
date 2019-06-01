#include "MainMenu.h"
#include "Constants.h" 

#include <allegro.h>

MainMenu::MainMenu() { 
	this->gameState = GAME_STATE_MAIN_MENU;
	this->gameTitle = load_bitmap("assets/main-menu/GameTitleBanner.bmp", NULL);
	this->bannerBitmap = load_bitmap("assets/ui-elem/Banner_Sq.bmp", NULL);
	this->buttonsBitmap = load_bitmap("assets/main-menu/MainMenuButtons.bmp", NULL);
}

int MainMenu::showMainMenu(BITMAP* buffer) { 
	rectfill(buffer, 0, 0, SCREEN_W, SCREEN_H, COLOR_BG);
	//draw buffer to screen and clear buffer

	if (SCREEN_W <= 640 || SCREEN_H <= 480) {
		masked_stretch_blit(gameTitle, buffer, 0, 0, gameTitle->w, gameTitle->h, SCREEN_W * 0.1, 20 , SCREEN_W * 0.8, ((gameTitle->h*1.0)/ gameTitle->w) * SCREEN_W * 0.8);
		masked_stretch_blit(bannerBitmap, buffer, 0, 0, bannerBitmap->w, bannerBitmap->h, SCREEN_W * 0.1, SCREEN_H * 0.3, SCREEN_W * 0.8, ((bannerBitmap->h * 1.0) / bannerBitmap->w) * SCREEN_W * 0.6);
	}
	else {
		masked_stretch_blit(gameTitle, buffer, 0, 0, gameTitle->w, gameTitle->h, (SCREEN_W - gameTitle->w) / 2, SCREEN_H*0.05, gameTitle->w, gameTitle->h);
		masked_stretch_blit(bannerBitmap, buffer, 0, 0, bannerBitmap->w, bannerBitmap->h, (SCREEN_W - bannerBitmap->w) / 2, SCREEN_H * 0.4, bannerBitmap->w, bannerBitmap->h);
	}

	//draw buffer to screen and clear buffer
	blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	clear_bitmap(buffer);  
	 
	return this->gameState;
}
