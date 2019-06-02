#include "SettingsMenu.h"

SettingsMenu::SettingsMenu(GameState* gameState) {
	this->bannerBitmap = load_bitmap("assets/ui-elem/Banner_Sq.bmp", NULL);
	this->gameState = gameState;
}
SettingsMenu::~SettingsMenu() {
	destroy_bitmap(this->bannerBitmap);
}

void SettingsMenu::showSettingsMenu(BITMAP* buffer) {

	// clear BG
	rectfill(buffer, 0, 0, SCREEN_W, SCREEN_H, COLOR_BG);


	if (SCREEN_W == 640 && SCREEN_H == 480) {
		masked_stretch_blit(bannerBitmap, buffer, 0, 0, bannerBitmap->w, bannerBitmap->h, SCREEN_W * 0.1, SCREEN_H * 0.1, SCREEN_W * 0.8, SCREEN_H * 0.8);
		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.35, 3, "SETTINGS", COLOR_TEXT, -1);
		gfxSettingButton = Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.50, 2, "GRAPHICS SETTINGS", COLOR_TEXT, -1);
		soundSettingButton = Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.59, 2, "SOUND SETTINGS", COLOR_TEXT, -1);
		backButton = Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.68, 2, "BACK", COLOR_TEXT, -1);
		 

	}
	else if (SCREEN_W == 960 && SCREEN_H == 720) {
		masked_stretch_blit(bannerBitmap, buffer, 0, 0, bannerBitmap->w, bannerBitmap->h, (SCREEN_W - bannerBitmap->w) / 2, (SCREEN_H - bannerBitmap->h) / 2, bannerBitmap->w, bannerBitmap->h);


		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.35, 3, "SETTINGS", COLOR_TEXT, -1);
		gfxSettingButton = Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.49, 2, "GRAPHICS SETTINGS", COLOR_TEXT, -1);
		soundSettingButton = Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.56, 2, "SOUND SETTINGS", COLOR_TEXT, -1);
		backButton = Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.63, 2, "BACK", COLOR_TEXT, -1);


		 




	}
	else  if (SCREEN_W == 1280 && SCREEN_H == 960) {
		masked_stretch_blit(bannerBitmap, buffer, 0, 0, bannerBitmap->w, bannerBitmap->h, (SCREEN_W - bannerBitmap->w) / 2, (SCREEN_H - bannerBitmap->h) / 2, bannerBitmap->w, bannerBitmap->h);

		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.35, 3, "SETTINGS", COLOR_TEXT, -1);
		gfxSettingButton = Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.47, 2, "GRAPHICS SETTINGS", COLOR_TEXT, -1);
		soundSettingButton = Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.55, 2, "SOUND SETTINGS", COLOR_TEXT, -1);
		backButton = Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.63, 2, "BACK", COLOR_TEXT, -1);

		 
	}


	if (Utility::inTheBoundingBox(gfxSettingButton)) {
		gameState->mouseHover = 1;

		if (mouse_b & 1) {
			gameState->gameScreen = GAME_SCREEN_GFX_SETTINGS;
			rest(300); 
		}
	}
	else if (Utility::inTheBoundingBox(soundSettingButton)) {
		gameState->mouseHover = 1;
		if (mouse_b & 1) {
			gameState->gameScreen = GAME_SCREEN_SOUND_SETTINGS;
			rest(300);
		}
	}
	else if (Utility::inTheBoundingBox(backButton)) {
		gameState->mouseHover = 1;
		if (mouse_b & 1) {
			gameState->gameScreen = GAME_SCREEN_MAIN_MENU;
			rest(300);
		}
	}
	else {
		gameState->mouseHover = 0;
	}




	//draw buffer to screen and clear buffer
	blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	clear_bitmap(buffer);

}