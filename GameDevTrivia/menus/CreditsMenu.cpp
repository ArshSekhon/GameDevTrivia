#include "CreditsMenu.h"

DIALOG creditsDialog = { d_textbox_proc, 0, 0,  0,  0,  0,  0, 0, 0, 0,   0, NULL, NULL, NULL };

DIALOG_PLAYER* creditsPlayer;
// constructor to do the initializations
CreditsMenu::CreditsMenu(GameState* gameState) {
	this->gameState = gameState;
	this->bannerBitmap = load_bitmap("assets/ui-elem/Banner_Sq.bmp", NULL);

	this->bigFont = (FONT*)load_datafile("assets/bigfont.dat")[0].dat;

	this->credits = (char*)"Questions for the quizes are obtained from the back exercises of the book Game Programming All in One by Jonathan S. Harbour.\n\n\nThe UI elements were derived from https://opengameart.org/content/fantasy-ui-elements-by-ravenmore \n\nBackground music was obtained from: http://www.partnersinrhyme.com/midi/index.shtml \n\nSound FX were obtained from: http://www.wavsource.com/sfx/sfx.htm";
}

void CreditsMenu::showCreditsScreen(BITMAP* buffer) {

	// clear BG
	rectfill(buffer, 0, 0, SCREEN_W, SCREEN_H, COLOR_BG);

	

	// draw graphics on screen for 640x480 mode
	if (SCREEN_W == 640 && SCREEN_H == 480) {
		masked_stretch_blit(bannerBitmap, buffer, 0, 0, bannerBitmap->w, bannerBitmap->h, SCREEN_W * 0.1, SCREEN_H * 0.1, SCREEN_W * 0.8, SCREEN_H * 0.8);

		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.25, 3, "CREDITS", COLOR_TEXT, -1);
		creditsPlayer=Utility::draw_wrapping_text(buffer, font, &creditsDialog, this->credits, SCREEN_W*0.2, SCREEN_H * 0.32, SCREEN_W*0.6, SCREEN_H*0.4, 10);
		backButton = Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.78, 1.5, "BACK", COLOR_TEXT, -1);
	}
	// draw graphics on screen for 960x720 mode
	else if (SCREEN_W == 960 && SCREEN_H == 720) {
		masked_stretch_blit(bannerBitmap, buffer, 0, 0, bannerBitmap->w, bannerBitmap->h, (SCREEN_W - bannerBitmap->w) / 2, (SCREEN_H - bannerBitmap->h) / 2, bannerBitmap->w, bannerBitmap->h);

		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.27, 3, "CREDITS", COLOR_TEXT, -1);
		creditsPlayer=Utility::draw_wrapping_text(buffer, font, &creditsDialog, this->credits, SCREEN_W * 0.22, SCREEN_H * 0.32, SCREEN_W * 0.56, SCREEN_H * 0.37, 10);
		backButton = Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.74, 1.5, "BACK", COLOR_TEXT, -1);
	}
	// draw graphics on screen for 1280x960 mode
	else  if (SCREEN_W == 1280 && SCREEN_H == 960) {
		masked_stretch_blit(bannerBitmap, buffer, 0, 0, bannerBitmap->w, bannerBitmap->h, (SCREEN_W - bannerBitmap->w) / 2, (SCREEN_H - bannerBitmap->h) / 2, bannerBitmap->w, bannerBitmap->h);

		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.33, 3, "CREDITS", COLOR_TEXT, -1);
		creditsPlayer=Utility::draw_wrapping_text(buffer, font, &creditsDialog, this->credits, SCREEN_W * 0.3, SCREEN_H * 0.37, SCREEN_W * 0.4, SCREEN_H * 0.27, 10);
		backButton = Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.68, 1.5, "BACK", COLOR_TEXT, -1);
	}

	// handle mouse clicks for the backbutton
	if (Utility::mouseInTheBoundingBox(backButton)) {
		gameState->mouseHover = 1;
		//if mouse is clicked on the back button
		if ((gameState->pendingMouseClick==1) && !(mouse_b & 1)) {
			gameState->gameScreen = GAME_SCREEN_MAIN_MENU;
			gameState->mouseHover = 0;
			if (creditsPlayer) {

				shutdown_dialog(creditsPlayer);
				creditsPlayer = NULL;
			}
			gameState->pendingMouseClick = 0;
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