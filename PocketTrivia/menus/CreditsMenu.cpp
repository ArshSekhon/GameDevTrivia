#include "CreditsMenu.h"

DIALOG creditsDialog = { d_textbox_proc, 0, 0,  0,  0,  0,  0, 0, 0, 0,   0, NULL, NULL, NULL };

CreditsMenu::CreditsMenu(GameState* gameState) {
	this->gameState = gameState;
	this->bannerBitmap = load_bitmap("assets/ui-elem/Banner_Sq.bmp", NULL);

	this->bigFont = (FONT*)load_datafile("assets/bigfont.dat")[0].dat;

	this->credits = (char*)"Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book.\n It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.";
}

void CreditsMenu::showCreditsScreen(BITMAP* buffer) {

	// clear BG
	rectfill(buffer, 0, 0, SCREEN_W, SCREEN_H, COLOR_BG);

	


	if (SCREEN_W == 640 && SCREEN_H == 480) {
		masked_stretch_blit(bannerBitmap, buffer, 0, 0, bannerBitmap->w, bannerBitmap->h, SCREEN_W * 0.1, SCREEN_H * 0.1, SCREEN_W * 0.8, SCREEN_H * 0.8);

		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.25, 3, "CREDITS", COLOR_TEXT, -1);
		Utility::draw_wrapping_text(buffer, font, &creditsDialog, this->credits, SCREEN_W*0.2, SCREEN_H * 0.32, SCREEN_W*0.6, SCREEN_H*0.4, 10);
		backButton = Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.78, 1.5, "BACK", COLOR_TEXT, -1);
	}
	else if (SCREEN_W == 960 && SCREEN_H == 720) {
		masked_stretch_blit(bannerBitmap, buffer, 0, 0, bannerBitmap->w, bannerBitmap->h, (SCREEN_W - bannerBitmap->w) / 2, (SCREEN_H - bannerBitmap->h) / 2, bannerBitmap->w, bannerBitmap->h);

		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.27, 3, "CREDITS", COLOR_TEXT, -1);
		Utility::draw_wrapping_text(buffer, font, &creditsDialog, this->credits, SCREEN_W * 0.22, SCREEN_H * 0.32, SCREEN_W * 0.56, SCREEN_H * 0.37, 10);
		backButton = Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.74, 1.5, "BACK", COLOR_TEXT, -1);
	}
	else  if (SCREEN_W == 1280 && SCREEN_H == 960) {
		masked_stretch_blit(bannerBitmap, buffer, 0, 0, bannerBitmap->w, bannerBitmap->h, (SCREEN_W - bannerBitmap->w) / 2, (SCREEN_H - bannerBitmap->h) / 2, bannerBitmap->w, bannerBitmap->h);

		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.33, 3, "CREDITS", COLOR_TEXT, -1);
		Utility::draw_wrapping_text(buffer, font, &creditsDialog, this->credits, SCREEN_W * 0.3, SCREEN_H * 0.37, SCREEN_W * 0.4, SCREEN_H * 0.27, 10);
		backButton = Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.68, 1.5, "BACK", COLOR_TEXT, -1);
	}


	if (Utility::inTheBoundingBox(backButton)) {
		gameState->mouseHover = 1;
		if (mouse_b & 1) {
			gameState->gameScreen = GAME_SCREEN_MAIN_MENU;
			gameState->mouseHover = 0;
			rest(300);
			return;
		}
	}
	else {
		gameState->mouseHover = 0;
	}

	//draw buffer to screen and clear buffer
	blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	clear_bitmap(buffer);

}