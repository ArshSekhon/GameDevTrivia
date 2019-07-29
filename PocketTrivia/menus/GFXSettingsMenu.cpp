#include "GFXSettingsMenu.h"
//#include <string> 
// constructor to do the initialization
GFXSettingsMenu::GFXSettingsMenu(GameState* gs, ConfigManager* configManager) {
	this->gameState = gs;
	this->configManager = configManager;

	this->bannerBitmap = load_bitmap("assets/ui-elem/Banner_Sq.bmp", NULL);
	this->gfxResOptions = new const char*[3]{"640x480","960x720","1280x960"};
	this->gfxScreenModeOptions = new const char* [2]{ "Windowed", "Fullscreen" };
	this->resolutionChangeArrows = new BoundingBox[2];;
	this->screenModeChangeArrows = new BoundingBox[2];

	if (SCREEN_H == 960 && SCREEN_W == 1280) {
		this->gfxResolutionMode = GFX_RES_1280_X_960;
	}else if (SCREEN_H == 720 && SCREEN_W == 960) {
		this->gfxResolutionMode = GFX_RES_960_X_720;
	}else if (SCREEN_H == 480 && SCREEN_W == 640) {
		this->gfxResolutionMode = GFX_RES_640_X_480;
	}
}

GFXSettingsMenu::~GFXSettingsMenu() {
	destroy_bitmap(this->bannerBitmap);
	this->bannerBitmap = NULL;
}

int GFXSettingsMenu::showGfxMenu(BITMAP* buffer) {
	gameState->gameScreen = GAME_SCREEN_GFX_SETTINGS;
	// clear BG
	rectfill(buffer, 0, 0, SCREEN_W, SCREEN_H, COLOR_BG);


	// draw graphics on screen for 640x480 mode
	if (SCREEN_W == 640 && SCREEN_H == 480) {
		masked_stretch_blit(bannerBitmap, buffer, 0, 0, bannerBitmap->w, bannerBitmap->h, SCREEN_W*0.1 , SCREEN_H * 0.1, SCREEN_W * 0.8, SCREEN_H * 0.8);
		Utility::textout_centre_magnified(buffer, font, SCREEN_W/2, SCREEN_H * 0.25, 3, "GFX SETTINGS", COLOR_TEXT, -1);
		
		int arrowLeftX = SCREEN_W / 2;
		int arrowRightX = SCREEN_W / 1.25;

		Utility::textout_magnified(buffer, font, SCREEN_W / 5.2, SCREEN_H * 0.45, 1.5, "RESOLUTION", COLOR_TEXT, -1);
		resolutionChangeArrows[0] = Utility::create_arrow_left(buffer, arrowLeftX, SCREEN_H * 0.44, 15, COLOR_TEXT);
		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 1.53, SCREEN_H * 0.45, 1.5, gfxResOptions[gfxResolutionMode], COLOR_TEXT, -1);
		resolutionChangeArrows[1] = Utility::create_arrow_right(buffer, arrowRightX, SCREEN_H * 0.44, 15, COLOR_TEXT);

		Utility::textout_magnified(buffer, font, SCREEN_W / 5.2, SCREEN_H * 0.55, 1.5, "MODE", COLOR_TEXT, -1);
		screenModeChangeArrows[0] = Utility::create_arrow_left(buffer, arrowLeftX, SCREEN_H * 0.54, 15, COLOR_TEXT);
		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 1.53, SCREEN_H * 0.55, 1.5, gfxScreenModeOptions[gfxScreenMode], COLOR_TEXT, -1);
		screenModeChangeArrows[1] = Utility::create_arrow_right(buffer, arrowRightX, SCREEN_H * 0.54, 15, COLOR_TEXT);

		backButton = Utility::textout_centre_magnified(buffer, font, SCREEN_W / 3, SCREEN_H * 0.75, 2, "BACK", COLOR_TEXT, -1);
		applyButton = Utility::textout_centre_magnified(buffer, font, SCREEN_W* 2.0/3, SCREEN_H * 0.75, 2, "APPLY", COLOR_TEXT, -1);
	}
	// draw graphics on screen for 960x720 mode
	else if (SCREEN_W == 960 && SCREEN_H == 720) { 
		masked_stretch_blit(bannerBitmap, buffer, 0, 0, bannerBitmap->w, bannerBitmap->h, (SCREEN_W - bannerBitmap->w) / 2, (SCREEN_H - bannerBitmap->h) / 2, bannerBitmap->w, bannerBitmap->h);


		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.25, 3, "GFX SETTINGS", COLOR_TEXT, -1);




		int arrowLeftX = SCREEN_W / 1.9;
		int arrowRightX = SCREEN_W / 1.4;

		Utility::textout_magnified(buffer, font, SCREEN_W / 3.5, SCREEN_H * 0.45, 1.5, "RESOLUTION", COLOR_TEXT, -1);
		resolutionChangeArrows[0] = Utility::create_arrow_left(buffer, arrowLeftX, SCREEN_H * 0.44, 15, COLOR_TEXT);
		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 1.6, SCREEN_H * 0.45, 1.5, gfxResOptions[gfxResolutionMode], COLOR_TEXT, -1);
		resolutionChangeArrows[1] = Utility::create_arrow_right(buffer, arrowRightX, SCREEN_H * 0.44, 15, COLOR_TEXT);

		Utility::textout_magnified(buffer, font, SCREEN_W / 3.5, SCREEN_H * 0.55, 1.5, "MODE", COLOR_TEXT, -1);
		screenModeChangeArrows[0] = Utility::create_arrow_left(buffer, arrowLeftX, SCREEN_H * 0.54, 15, COLOR_TEXT);
		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 1.6, SCREEN_H * 0.55, 1.5, gfxScreenModeOptions[gfxScreenMode], COLOR_TEXT, -1);
		screenModeChangeArrows[1] = Utility::create_arrow_right(buffer, arrowRightX, SCREEN_H * 0.54, 15, COLOR_TEXT);





		backButton = Utility::textout_centre_magnified(buffer, font, SCREEN_W / 3, SCREEN_H * 0.75, 2, "BACK", COLOR_TEXT, -1);
		applyButton = Utility::textout_centre_magnified(buffer, font, SCREEN_W * 2.0 / 3, SCREEN_H * 0.75, 2, "APPLY", COLOR_TEXT, -1);
	}
	// draw graphics on screen for 1280x960 mode
	else  if (SCREEN_W == 1280 && SCREEN_H == 960) {
		masked_stretch_blit(bannerBitmap, buffer, 0, 0, bannerBitmap->w, bannerBitmap->h, (SCREEN_W - bannerBitmap->w) / 2, (SCREEN_H - bannerBitmap->h) / 2, bannerBitmap->w, bannerBitmap->h);

		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.35, 3, "GFX SETTINGS", COLOR_TEXT, -1);





		int arrowLeftX = SCREEN_W / 2;
		int arrowRightX = SCREEN_W / 1.5;

		Utility::textout_magnified(buffer, font, SCREEN_W / 3, SCREEN_H * 0.45, 1.5, "RESOLUTION", COLOR_TEXT, -1);
		resolutionChangeArrows[0] = Utility::create_arrow_left(buffer, arrowLeftX, SCREEN_H * 0.44, 15, COLOR_TEXT);
		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 1.7, SCREEN_H * 0.45, 1.5, gfxResOptions[gfxResolutionMode], COLOR_TEXT, -1);
		resolutionChangeArrows[1] = Utility::create_arrow_right(buffer, arrowRightX, SCREEN_H * 0.44, 15, COLOR_TEXT);

		Utility::textout_magnified(buffer, font, SCREEN_W / 3, SCREEN_H * 0.55, 1.5, "MODE", COLOR_TEXT, -1);
		screenModeChangeArrows[0] = Utility::create_arrow_left(buffer, arrowLeftX, SCREEN_H * 0.54, 15, COLOR_TEXT);
		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 1.7, SCREEN_H * 0.55, 1.5, gfxScreenModeOptions[gfxScreenMode], COLOR_TEXT, -1);
		screenModeChangeArrows[1] = Utility::create_arrow_right(buffer, arrowRightX, SCREEN_H * 0.54, 15, COLOR_TEXT);





		backButton = Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2.5, SCREEN_H * 0.69, 2, "BACK", COLOR_TEXT, -1);
		applyButton = Utility::textout_centre_magnified(buffer, font, SCREEN_W * 1.8 / 3, SCREEN_H * 0.69, 2, "APPLY", COLOR_TEXT, -1);
	}

	//draw buffer to screen and clear buffer
	blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	clear_bitmap(buffer);



	// handle clicks on the apply Button
	if (Utility::mouseInTheBoundingBox(applyButton)) {
		gameState->mouseHover = 1;

		if ((gameState->pendingMouseClick==1) && !(mouse_b & 1)) {
			// change the gfx settings
			this->changeGfxMode(buffer, this->gfxResolutionMode, this->gfxScreenMode, this->gameState);
			gameState->mouseHover = 0;
			gameState->pendingMouseClick = 0;
			rest(300);
			return 1;
		}
	} 
	// handle clicks on the back button
	else if (Utility::mouseInTheBoundingBox(backButton)) {
		gameState->mouseHover = 1;
		if ((gameState->pendingMouseClick==1) && !(mouse_b & 1)) {
			gameState->gameScreen = GAME_SCREEN_SETTINGS;
			gameState->mouseHover = 0;
			gameState->pendingMouseClick = 0;
			rest(300);
			return 1;
		}
	}
	
	// handle clicks on the arrows for the resolution
	else if (Utility::mouseInTheBoundingBox(resolutionChangeArrows[0]) || Utility::mouseInTheBoundingBox(resolutionChangeArrows[1])) {
		gameState->mouseHover = 1;
		if ((gameState->pendingMouseClick==1) && !(mouse_b & 1)) {
			if (Utility::mouseInTheBoundingBox(resolutionChangeArrows[0])) {
				if (--gfxResolutionMode < 0)
					gfxResolutionMode = 2;
			}else if (Utility::mouseInTheBoundingBox(resolutionChangeArrows[1])) {
				if (++gfxResolutionMode > 2)
					gfxResolutionMode = 0;
			}
			gameState->pendingMouseClick = 0;
			rest(200);
		}
	}
	// handle clicks on the arrows for the screen mode
	else if (Utility::mouseInTheBoundingBox(screenModeChangeArrows[0]) || Utility::mouseInTheBoundingBox(screenModeChangeArrows[1])) {
		gameState->mouseHover = 1;
		if ((gameState->pendingMouseClick==1) && !(mouse_b & 1)) {
			if (Utility::mouseInTheBoundingBox(screenModeChangeArrows[0])) {
				if (--gfxScreenMode < 0)
					gfxScreenMode = 1;
			}
			else if (Utility::mouseInTheBoundingBox(screenModeChangeArrows[1])) {
				if (++gfxScreenMode > 1)
					gfxScreenMode = 0;
			}
			gameState->pendingMouseClick = 0;
			rest(200);
		}
	}
	else {
		gameState->mouseHover = 0;
	}

	return 0;
}

// this function changes the gfx settings and immediately saves the settings to the config file
void GFXSettingsMenu::changeGfxMode(BITMAP* buffer, int gfxRes , int screenMode, GameState* gameState) {

	int card = (screenMode == GFX_MODE_WINDOWED) ? GFX_AUTODETECT_WINDOWED : GFX_AUTODETECT_FULLSCREEN;
	int resX = (gfxRes == GFX_RES_1280_X_960) ? 1280 : (gfxRes == GFX_RES_960_X_720) ? 960 : 640;
	int resY = (gfxRes == GFX_RES_1280_X_960) ? 960 : (gfxRes == GFX_RES_960_X_720) ? 720 : 480;

	gameState->resolution_x = resX;
	gameState->resolution_y = resY;
	gameState->fullscreen = (screenMode == GFX_MODE_FULLSCREEN);
	gameState->gfxSettingsUpdated = 1;

	configManager->save_config(CONFIG_FILENAME, gameState);
	set_gfx_mode(card, resX, resY, 0, 0);

}