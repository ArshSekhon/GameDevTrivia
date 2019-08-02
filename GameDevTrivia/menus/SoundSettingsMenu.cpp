#include "SoundSettingsMenu.h"

// constructor
SoundSettingsMenu::SoundSettingsMenu(GameState* gs, ConfigManager* configManager) {
	this->gameState = gs;
	this->configManager = configManager;

	this->bannerBitmap = load_bitmap("assets/ui-elem/Banner_Sq.bmp", NULL);
	this->musicVolume = gs->music_volume;
	this->soundVolume = gs->sound_volume;
	this->levels = new const char* [11]{ "0" ,"1","2","3","4","5","6","7","8","9","10"};
	this->soundVolChangeArrows = new BoundingBox[2];;
	this->musicVolChangeArrows = new BoundingBox[2];
}


SoundSettingsMenu::~SoundSettingsMenu() {
	destroy_bitmap(bannerBitmap);
}


void SoundSettingsMenu::showSoundSettingsMenu(BITMAP* buffer) {

	// clear BG
	rectfill(buffer, 0, 0, SCREEN_W, SCREEN_H, COLOR_BG);

	if (this->bannerBitmap == NULL) {
		this->bannerBitmap = load_bitmap("assets/ui-elem/Banner_Sq.bmp", NULL);
	}

	// draw graphics on screen for 640x480 mode
	if (SCREEN_W == 640 && SCREEN_H == 480) {
		masked_stretch_blit(bannerBitmap, buffer, 0, 0, bannerBitmap->w, bannerBitmap->h, SCREEN_W * 0.1, SCREEN_H * 0.1, SCREEN_W * 0.8, SCREEN_H * 0.8);
		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.25, 3, "VOLUME SETTINGS", COLOR_TEXT, -1);

		int arrowLeftX = SCREEN_W / 2;
		int arrowRightX = SCREEN_W / 1.25;

		Utility::textout_magnified(buffer, font, SCREEN_W / 5.2, SCREEN_H * 0.45, 1.5, "SOUND", COLOR_TEXT, -1);
		soundVolChangeArrows[0] = Utility::create_arrow_left(buffer, arrowLeftX, SCREEN_H * 0.44, 15, COLOR_TEXT);

		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 1.53, SCREEN_H * 0.45, 1.5, levels[soundVolume] , COLOR_TEXT, -1);
		soundVolChangeArrows[1] = Utility::create_arrow_right(buffer, arrowRightX, SCREEN_H * 0.44, 15, COLOR_TEXT);

		Utility::textout_magnified(buffer, font, SCREEN_W / 5.2, SCREEN_H * 0.55, 1.5, "MUSIC", COLOR_TEXT, -1);
		musicVolChangeArrows[0] = Utility::create_arrow_left(buffer, arrowLeftX, SCREEN_H * 0.54, 15, COLOR_TEXT);
		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 1.53, SCREEN_H * 0.55, 1.5, levels[musicVolume], COLOR_TEXT, -1);
		musicVolChangeArrows[1] = Utility::create_arrow_right(buffer, arrowRightX, SCREEN_H * 0.54, 15, COLOR_TEXT);

		backButton = Utility::textout_centre_magnified(buffer, font, SCREEN_W / 3, SCREEN_H * 0.75, 2, "BACK", COLOR_TEXT, -1);
		applyButton = Utility::textout_centre_magnified(buffer, font, SCREEN_W * 2.0 / 3, SCREEN_H * 0.75, 2, "APPLY", COLOR_TEXT, -1);
	}
	// draw graphics on screen for 960x720 mode
	else if (SCREEN_W == 960 && SCREEN_H == 720) {
		masked_stretch_blit(bannerBitmap, buffer, 0, 0, bannerBitmap->w, bannerBitmap->h, (SCREEN_W - bannerBitmap->w) / 2, (SCREEN_H - bannerBitmap->h) / 2, bannerBitmap->w, bannerBitmap->h);


		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.25, 3, "VOLUME SETTINGS", COLOR_TEXT, -1);




		int arrowLeftX = SCREEN_W / 1.9;
		int arrowRightX = SCREEN_W / 1.4;

		Utility::textout_magnified(buffer, font, SCREEN_W / 3.5, SCREEN_H * 0.45, 1.5, "SOUND", COLOR_TEXT, -1);
		soundVolChangeArrows[0] = Utility::create_arrow_left(buffer, arrowLeftX, SCREEN_H * 0.44, 15, COLOR_TEXT);
		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 1.6, SCREEN_H * 0.45, 1.5, levels[soundVolume], COLOR_TEXT, -1);
		soundVolChangeArrows[1] = Utility::create_arrow_right(buffer, arrowRightX, SCREEN_H * 0.44, 15, COLOR_TEXT);

		Utility::textout_magnified(buffer, font, SCREEN_W / 3.5, SCREEN_H * 0.55, 1.5, "MUSIC", COLOR_TEXT, -1);
		musicVolChangeArrows[0] = Utility::create_arrow_left(buffer, arrowLeftX, SCREEN_H * 0.54, 15, COLOR_TEXT);
		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 1.6, SCREEN_H * 0.55, 1.5, levels[musicVolume], COLOR_TEXT, -1);
		musicVolChangeArrows[1] = Utility::create_arrow_right(buffer, arrowRightX, SCREEN_H * 0.54, 15, COLOR_TEXT);





		backButton = Utility::textout_centre_magnified(buffer, font, SCREEN_W / 3, SCREEN_H * 0.75, 2, "BACK", COLOR_TEXT, -1);
		applyButton = Utility::textout_centre_magnified(buffer, font, SCREEN_W * 2.0 / 3, SCREEN_H * 0.75, 2, "APPLY", COLOR_TEXT, -1);
	}
	// draw graphics on screen for 1280x960 mode
	else  if (SCREEN_W == 1280 && SCREEN_H == 960) {
		masked_stretch_blit(bannerBitmap, buffer, 0, 0, bannerBitmap->w, bannerBitmap->h, (SCREEN_W - bannerBitmap->w) / 2, (SCREEN_H - bannerBitmap->h) / 2, bannerBitmap->w, bannerBitmap->h);

		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.35, 3, "VOLUME SETTINGS", COLOR_TEXT, -1);





		int arrowLeftX = SCREEN_W / 2;
		int arrowRightX = SCREEN_W / 1.5;

		Utility::textout_magnified(buffer, font, SCREEN_W / 3, SCREEN_H * 0.45, 1.5, "SOUND", COLOR_TEXT, -1);
		soundVolChangeArrows[0] = Utility::create_arrow_left(buffer, arrowLeftX, SCREEN_H * 0.44, 15, COLOR_TEXT);
		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 1.7, SCREEN_H * 0.45, 1.5, levels[soundVolume], COLOR_TEXT, -1);
		soundVolChangeArrows[1] = Utility::create_arrow_right(buffer, arrowRightX, SCREEN_H * 0.44, 15, COLOR_TEXT);

		Utility::textout_magnified(buffer, font, SCREEN_W / 3, SCREEN_H * 0.55, 1.5, "MUSIC", COLOR_TEXT, -1);
		musicVolChangeArrows[0] = Utility::create_arrow_left(buffer, arrowLeftX, SCREEN_H * 0.54, 15, COLOR_TEXT);
		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 1.7, SCREEN_H * 0.55, 1.5, levels[musicVolume], COLOR_TEXT, -1);
		musicVolChangeArrows[1] = Utility::create_arrow_right(buffer, arrowRightX, SCREEN_H * 0.54, 15, COLOR_TEXT);





		backButton = Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2.5, SCREEN_H * 0.69, 2, "BACK", COLOR_TEXT, -1);
		applyButton = Utility::textout_centre_magnified(buffer, font, SCREEN_W * 1.8 / 3, SCREEN_H * 0.69, 2, "APPLY", COLOR_TEXT, -1);
	}
	//draw buffer to screen and clear buffer
	blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	clear_bitmap(buffer);

	// handle clicks on the apply button
	if (Utility::mouseInTheBoundingBox(applyButton)) {
		gameState->mouseHover = 1;

		if ((gameState->pendingMouseClick==1) && !(mouse_b & 1)) {
			this->changeSoundSettings(musicVolume, soundVolume, this->gameState);
			gameState->mouseHover = 0;
			gameState->pendingMouseClick = 0;
			rest(300);
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
		}
	}
	// handle clicks for volume arrows for sound
	else if (Utility::mouseInTheBoundingBox(soundVolChangeArrows[0]) || Utility::mouseInTheBoundingBox(soundVolChangeArrows[1])) {
		gameState->mouseHover = 1;
		if ((gameState->pendingMouseClick==1) && !(mouse_b & 1)) {
			if (Utility::mouseInTheBoundingBox(soundVolChangeArrows[0])) {
				if (soundVolume > 0)
					soundVolume--;
			}
			else if (Utility::mouseInTheBoundingBox(soundVolChangeArrows[1])) {
				if (soundVolume < 10)
					soundVolume++;
			}
			gameState->pendingMouseClick = 0;
			rest(200);
		}
	}
	// handle clicks for volume arrows for music
	else if (Utility::mouseInTheBoundingBox(musicVolChangeArrows[0]) || Utility::mouseInTheBoundingBox(musicVolChangeArrows[1])) {
		gameState->mouseHover = 1;
		if ((gameState->pendingMouseClick==1) && !(mouse_b & 1)) {
			if (Utility::mouseInTheBoundingBox(musicVolChangeArrows[0])) {
				if (musicVolume > 0)
					musicVolume--;
			}
			else if (Utility::mouseInTheBoundingBox(musicVolChangeArrows[1])) {
				if (musicVolume < 10)
					musicVolume++;
			}
			gameState->pendingMouseClick = 0;
			rest(200);
		}
	}
	else {
		gameState->mouseHover = 0;
	}


}
// this function changes the sound settings and immediately saves the settings to the config file

void SoundSettingsMenu::changeSoundSettings(int musicVol, int soundVol, GameState* gameState) {
	gameState->music_volume = musicVol;
	gameState->sound_volume = soundVol;

	set_volume(gameState->sound_volume * 25.5, gameState->music_volume * 25.5);

	configManager->save_config(CONFIG_FILENAME, gameState);
}