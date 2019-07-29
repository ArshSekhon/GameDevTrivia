#include "GameQuestionScreen.h"


DIALOG gameQuestionDialog = { d_textbox_proc, 0, 0,  0,  0,  0,  0, 0, 0, 0,   0, NULL, NULL, NULL };
GameQuestionScreen::GameQuestionScreen(GameState* gameState, SoundManager* soundManager) {
	this->gameState = gameState;
	this->optionsBoundingBoxes = new BoundingBox[4];
	this->soundManager = soundManager;
	this->questionBannerBitmap = load_bitmap("assets/ui-elem/question-banner.bmp", NULL);
	this->answerBannerBitmap = load_bitmap("assets/ui-elem/option-banner.bmp", NULL);
	this->bannerBitmap = load_bitmap("assets/ui-elem/Banner_Sq.bmp", NULL);
	this->bigFont = (FONT*)load_datafile("assets/bigfont.dat")[0].dat;
}


void GameQuestionScreen::showQuestionScreen(BITMAP* buffer, Quiz* quiz) {
	
	// clear BG
	rectfill(buffer, 0, 0, SCREEN_W, SCREEN_H, COLOR_BG);
	
	if (showingCorrectAnswerBanner) {
		showCorrectAnswerBanner(buffer, quiz);
	}
	else if (showingWrongAnswerBanner) {
		showWrongAnswerBanner(buffer, quiz);
	}
	else if (showingResultsBanner) {
		showResultsBanner(buffer);
	}
	else{
		showQuestion(buffer, quiz);
	}

	//draw buffer to screen and clear buffer
	blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	clear_bitmap(buffer);

	if (Utility::inTheBoundingBox(optionsBoundingBoxes[0]) && !(showingCorrectAnswerBanner || showingWrongAnswerBanner || showingResultsBanner)) {
		gameState->mouseHover = 1;
		if ((gameState->pendingMouseClick==1) && !(mouse_b & 1)) {
			//OPTION 1 Selected
			if (quiz->checkQuestionAnswer(gameState->currentQuestion,0)){
				this->showingCorrectAnswerBanner = 1;
				gameState->currentScore++;
				soundManager->playSound(SOUND_CHEERING, 1000); 
			}
			else{
				this->showingWrongAnswerBanner = 1;
				soundManager->playSound(SOUND_BUZZER, 1000);
			}

			if (questionScreenPlayer) {
				shutdown_dialog(questionScreenPlayer);
				questionScreenPlayer = NULL;
			}
			gameState->pendingMouseClick = 0;
			rest(200);
		}
	}
	else if (Utility::inTheBoundingBox(optionsBoundingBoxes[1]) && !(showingCorrectAnswerBanner || showingWrongAnswerBanner || showingResultsBanner)) {
		gameState->mouseHover = 1;
		if ((gameState->pendingMouseClick==1) && !(mouse_b & 1)) {
			//OPTION 2 Selected
			if (quiz->checkQuestionAnswer(gameState->currentQuestion,1)){
				this->showingCorrectAnswerBanner = 1;
				gameState->currentScore++;
				soundManager->playSound(SOUND_CHEERING, 1000); 
			}
			else {
				this->showingWrongAnswerBanner = 1;
				soundManager->playSound(SOUND_BUZZER, 1000);
			}
			if (questionScreenPlayer) {
				shutdown_dialog(questionScreenPlayer);
				questionScreenPlayer = NULL;
			}
			gameState->pendingMouseClick = 0;
			rest(200);
		}
	}
	else if (Utility::inTheBoundingBox(optionsBoundingBoxes[2]) && !(showingCorrectAnswerBanner || showingWrongAnswerBanner || showingResultsBanner)) {
		gameState->mouseHover = 1;
		if ((gameState->pendingMouseClick==1) && !(mouse_b & 1)) {
			//OPTION 3 Selected
			if (quiz->checkQuestionAnswer(gameState->currentQuestion,2)){
				this->showingCorrectAnswerBanner = 1;
				gameState->currentScore++;
				soundManager->playSound(SOUND_CHEERING, 1000); 
			}
			else {
				this->showingWrongAnswerBanner = 1;
				soundManager->playSound(SOUND_BUZZER, 1000);
			}
			if (questionScreenPlayer) {
				shutdown_dialog(questionScreenPlayer);
				questionScreenPlayer = NULL;
			}
			gameState->pendingMouseClick = 0;
			rest(200);
		}
	}
	else if (Utility::inTheBoundingBox(optionsBoundingBoxes[3]) && !(showingCorrectAnswerBanner || showingWrongAnswerBanner || showingResultsBanner)) {
		gameState->mouseHover = 1;
		if ((gameState->pendingMouseClick==1) && !(mouse_b & 1)) {
			//OPTION 4 Selected
			if (quiz->checkQuestionAnswer(gameState->currentQuestion, 3)){
				this->showingCorrectAnswerBanner = 1;
				gameState->currentScore++;
				soundManager->playSound(SOUND_CHEERING, 1000);
			}
			else {
				this->showingWrongAnswerBanner = 1;
				soundManager->playSound(SOUND_BUZZER, 1000);
			}
			if (questionScreenPlayer) {
				shutdown_dialog(questionScreenPlayer);
				questionScreenPlayer = NULL;
			}
			gameState->pendingMouseClick = 0;
			rest(200);
		}
	}
	else if (Utility::inTheBoundingBox(exitToMainMenuButton) && showingResultsBanner && !(showingCorrectAnswerBanner || showingWrongAnswerBanner)) {
		gameState->mouseHover = 1;
		if ((gameState->pendingMouseClick==1) && !(mouse_b & 1)) {
			//OPTION 4 Selected
			gameState->gameScreen = GAME_SCREEN_MAIN_MENU;
			gameState->currentScore = 0;
			gameState->currentQuestion = 0;
			this->showingResultsBanner = 0;
			if (questionScreenPlayer) {
				shutdown_dialog(questionScreenPlayer);
				questionScreenPlayer = NULL;
			}
			gameState->pendingMouseClick = 0;
			rest(200);
		}
	}

	else if (Utility::inTheBoundingBox(nextQuestionButton) && !showingResultsBanner && (showingCorrectAnswerBanner || showingWrongAnswerBanner)) {
		gameState->mouseHover = 1;
		if ((gameState->pendingMouseClick==1) && !(mouse_b & 1)) {
			this->showingCorrectAnswerBanner = 0;
			this->showingWrongAnswerBanner = 0;

			if (gameState->currentQuestion + 1 == NUMBER_OF_QUESTIONS_PER_GAME) {
				showingResultsBanner = 1;
			}
			else {
				gameState->currentQuestion++;
			}

			if (questionScreenPlayer) {
				shutdown_dialog(questionScreenPlayer);
				questionScreenPlayer = NULL;
			}
			gameState->pendingMouseClick = 0;
			rest(200);
		}
	}
	else {
		gameState->mouseHover = 0;
	}

}

void GameQuestionScreen::showCorrectAnswerBanner(BITMAP* buffer, Quiz* quiz) {

	if (SCREEN_W == 640 && SCREEN_H == 480) {
		masked_stretch_blit(bannerBitmap, buffer, 0, 0, bannerBitmap->w, bannerBitmap->h, SCREEN_W * 0.1, SCREEN_H * 0.1, SCREEN_W * 0.8, SCREEN_H * 0.8);
		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.5, 3, "CORRECT ANSWER!!!", COLOR_TEXT, -1);

		nextQuestionButton = Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.75, 2, "NEXT", COLOR_TEXT, -1);
	}
	else if (SCREEN_W == 960 && SCREEN_H == 720) {
		masked_stretch_blit(bannerBitmap, buffer, 0, 0, bannerBitmap->w, bannerBitmap->h, (SCREEN_W - bannerBitmap->w) / 2, (SCREEN_H - bannerBitmap->h) / 2, bannerBitmap->w, bannerBitmap->h);
		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.5, 3, "CORRECT ANSWER!!!", COLOR_TEXT, -1);



		nextQuestionButton = Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.75, 2, "NEXT", COLOR_TEXT, -1);
	}
	else  if (SCREEN_W == 1280 && SCREEN_H == 960) {
		masked_stretch_blit(bannerBitmap, buffer, 0, 0, bannerBitmap->w, bannerBitmap->h, (SCREEN_W - bannerBitmap->w) / 2, (SCREEN_H - bannerBitmap->h) / 2, bannerBitmap->w, bannerBitmap->h);
		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.5, 3, "CORRECT ANSWER!!!", COLOR_TEXT, -1);

		nextQuestionButton = Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.69, 2, "NEXT", COLOR_TEXT, -1);
	}
}
void GameQuestionScreen::showWrongAnswerBanner(BITMAP* buffer, Quiz* quiz) {

	if (SCREEN_W == 640 && SCREEN_H == 480) {
		masked_stretch_blit(bannerBitmap, buffer, 0, 0, bannerBitmap->w, bannerBitmap->h, SCREEN_W * 0.1, SCREEN_H * 0.1, SCREEN_W * 0.8, SCREEN_H * 0.8);
		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.25, 3, "WRONG ANSWER", COLOR_TEXT, -1);

		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.37, 2, "QUESTION", COLOR_TEXT, -1);
		questionScreenPlayer = Utility::draw_wrapping_text(buffer, font, &gameQuestionDialog, quiz->getQuestionText(gameState->currentQuestion), SCREEN_W * 0.2, SCREEN_H * 0.42, SCREEN_W * 0.6, SCREEN_H * 0.1, COLOR_TEXT);
		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H / 1.7, 2, "CORRECT ANSWER:", COLOR_TEXT, -1);
		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H / 1.5, 1.3, quiz->getQuestionAnswer(gameState->currentQuestion), COLOR_TEXT, -1);


		nextQuestionButton = Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.75, 2, "NEXT", COLOR_TEXT, -1);
	}
	else if (SCREEN_W == 960 && SCREEN_H == 720) {
		masked_stretch_blit(bannerBitmap, buffer, 0, 0, bannerBitmap->w, bannerBitmap->h, (SCREEN_W - bannerBitmap->w) / 2, (SCREEN_H - bannerBitmap->h) / 2, bannerBitmap->w, bannerBitmap->h);
		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.25, 3, "WRONG ANSWER", COLOR_TEXT, -1);


		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.37, 2, "QUESTION", COLOR_TEXT, -1);
		questionScreenPlayer = Utility::draw_wrapping_text(buffer, font, &gameQuestionDialog, quiz->getQuestionText(gameState->currentQuestion), SCREEN_W * 0.25, SCREEN_H * 0.4, SCREEN_W * 0.5, SCREEN_H * 0.1, COLOR_TEXT);
		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H / 1.7, 2, "CORRECT ANSWER:", COLOR_TEXT, -1);
		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H / 1.6, 1.5, quiz->getQuestionAnswer(gameState->currentQuestion), COLOR_TEXT, -1);

		nextQuestionButton = Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.75, 2, "NEXT", COLOR_TEXT, -1);
	}
	else  if (SCREEN_W == 1280 && SCREEN_H == 960) {
		masked_stretch_blit(bannerBitmap, buffer, 0, 0, bannerBitmap->w, bannerBitmap->h, (SCREEN_W - bannerBitmap->w) / 2, (SCREEN_H - bannerBitmap->h) / 2, bannerBitmap->w, bannerBitmap->h);
		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.35, 3, "WRONG ANSWER", COLOR_TEXT, -1);

		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.42, 2, "QUESTION", COLOR_TEXT, -1);
		questionScreenPlayer = Utility::draw_wrapping_text(buffer, font, &gameQuestionDialog, quiz->getQuestionText(gameState->currentQuestion), SCREEN_W * 0.3, SCREEN_H * 0.45, SCREEN_W * 0.4, SCREEN_H * 0.1, COLOR_TEXT);
		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H / 1.7, 2, "CORRECT ANSWER:", COLOR_TEXT, -1);
		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H/1.6, 1.5, quiz->getQuestionAnswer(gameState->currentQuestion), COLOR_TEXT, -1);
		nextQuestionButton = Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.69, 2, "NEXT", COLOR_TEXT, -1);
	}



}



void GameQuestionScreen::showResultsBanner(BITMAP* buffer) {

	char* message = (char*)"";
	if (gameState->currentScore > 8) {
		message = (char*) "You did an amazing job!";
	}else if (gameState->currentScore > 6) {
		message = (char*) "You passed!";
	}
	else {
		message = (char*) "You need to study harder!";
	}


	if (SCREEN_W == 640 && SCREEN_H == 480) {
		masked_stretch_blit(bannerBitmap, buffer, 0, 0, bannerBitmap->w, bannerBitmap->h, SCREEN_W * 0.1, SCREEN_H * 0.1, SCREEN_W * 0.8, SCREEN_H * 0.8);
		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.25, 3, "RESULTS", COLOR_TEXT, -1);

		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.55, 1.5, message, COLOR_TEXT, -1);
		printScoreCentred(buffer, font, SCREEN_W*0.5, SCREEN_H * 0.4, 2, gameState->currentScore, COLOR_HUD_TEXT, -1);
		exitToMainMenuButton = Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.75, 2, "EXIT TO MAIN MENU", COLOR_TEXT, -1);
	}
	else if (SCREEN_W == 960 && SCREEN_H == 720) {
		masked_stretch_blit(bannerBitmap, buffer, 0, 0, bannerBitmap->w, bannerBitmap->h, (SCREEN_W - bannerBitmap->w) / 2, (SCREEN_H - bannerBitmap->h) / 2, bannerBitmap->w, bannerBitmap->h);
		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.25, 3, "RESULTS", COLOR_TEXT, -1);

		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.55, 1.5, message, COLOR_TEXT, -1);
		printScoreCentred(buffer, font, SCREEN_W * 0.5, SCREEN_H * 0.4, 2, gameState->currentScore, COLOR_HUD_TEXT, -1);
		exitToMainMenuButton = Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.75, 2, "EXIT TO MAIN MENU", COLOR_TEXT, -1);
	}
	else  if (SCREEN_W == 1280 && SCREEN_H == 960) {
		masked_stretch_blit(bannerBitmap, buffer, 0, 0, bannerBitmap->w, bannerBitmap->h, (SCREEN_W - bannerBitmap->w) / 2, (SCREEN_H - bannerBitmap->h) / 2, bannerBitmap->w, bannerBitmap->h);
		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.35, 3, "RESULTS", COLOR_TEXT, -1);

		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.55, 1.5, message, COLOR_TEXT, -1);
		printScoreCentred(buffer, font, SCREEN_W * 0.5, SCREEN_H * 0.47, 2, gameState->currentScore, COLOR_HUD_TEXT, -1);
		exitToMainMenuButton = Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.69, 2, "EXIT TO MAIN MENU", COLOR_TEXT, -1);
	}


}



void GameQuestionScreen::showQuestion(BITMAP* buffer, Quiz* quiz) {
	if (SCREEN_W == 640 && SCREEN_H == 480) {
		masked_stretch_blit(questionBannerBitmap, buffer, 0, 0, questionBannerBitmap->w, questionBannerBitmap->h, SCREEN_W * 0.1, SCREEN_H * 0.07, SCREEN_W * 0.8, SCREEN_H * 0.45);

		float width_scale = 1.0 / 2.5;
		float height_scale = 1.0 / 2.5;

		optionsBoundingBoxes[0].x = optionsBoundingBoxes[1].x = optionsBoundingBoxes[2].x = optionsBoundingBoxes[3].x = (SCREEN_W - answerBannerBitmap->w * width_scale) / 2;

		optionsBoundingBoxes[0].y = (SCREEN_H - answerBannerBitmap->h) * 0.705;
		optionsBoundingBoxes[1].y = (SCREEN_H - answerBannerBitmap->h) * 0.835;
		optionsBoundingBoxes[2].y = (SCREEN_H - answerBannerBitmap->h) * 0.965;
		optionsBoundingBoxes[3].y = (SCREEN_H - answerBannerBitmap->h) * 1.095;

		optionsBoundingBoxes[0].w = optionsBoundingBoxes[1].w = optionsBoundingBoxes[2].w = optionsBoundingBoxes[3].w = answerBannerBitmap->w * width_scale;
		optionsBoundingBoxes[0].h = optionsBoundingBoxes[1].h = optionsBoundingBoxes[2].h = optionsBoundingBoxes[3].h = answerBannerBitmap->h * height_scale;

		Utility::draw_button(buffer, answerBannerBitmap, optionsBoundingBoxes[0]);
		Utility::draw_button(buffer, answerBannerBitmap, optionsBoundingBoxes[1]);
		Utility::draw_button(buffer, answerBannerBitmap, optionsBoundingBoxes[2]);
		Utility::draw_button(buffer, answerBannerBitmap, optionsBoundingBoxes[3]);



		// print info header
		printScore(buffer, font, SCREEN_W * 0.38, SCREEN_H * 0.15, 1.3, gameState->currentScore, COLOR_HUD_TEXT, -1);
		printQuestionNumber(buffer, font, SCREEN_W * 0.83, SCREEN_H * 0.15, 1.3, gameState->currentQuestion + 1, COLOR_HUD_TEXT, -1);
		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.22, 2.5, "QUESTION", COLOR_TEXT, -1);
		// display question text box
		questionScreenPlayer = Utility::draw_wrapping_text(buffer, bigFont, &gameQuestionDialog,quiz->getQuestionText(gameState->currentQuestion), SCREEN_W * 0.13, SCREEN_H * 0.28, SCREEN_W * 0.74, SCREEN_H * 0.2, COLOR_TEXT);

		//print options
		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, optionsBoundingBoxes[0].y + optionsBoundingBoxes[0].h / 2, 1, quiz->getQuestionOption(gameState->currentQuestion,0), COLOR_TEXT, -1);
		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, optionsBoundingBoxes[1].y + optionsBoundingBoxes[1].h / 2, 1, quiz->getQuestionOption(gameState->currentQuestion,1), COLOR_TEXT, -1);
		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, optionsBoundingBoxes[2].y + optionsBoundingBoxes[2].h / 2, 1, quiz->getQuestionOption(gameState->currentQuestion, 2), COLOR_TEXT, -1);
		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, optionsBoundingBoxes[3].y + optionsBoundingBoxes[0].h / 2, 1, quiz->getQuestionOption(gameState->currentQuestion, 3), COLOR_TEXT, -1);
	}
	else if (SCREEN_W == 960 && SCREEN_H == 720) {
		masked_stretch_blit(questionBannerBitmap, buffer, 0, 0, questionBannerBitmap->w, questionBannerBitmap->h, (SCREEN_W - questionBannerBitmap->w / 1.3) / 2, (SCREEN_H - questionBannerBitmap->h / 1.3) * 0.15, questionBannerBitmap->w / 1.3, questionBannerBitmap->h / 1.3);
		float width_scale = 1.0 / 1.5;
		float height_scale = 1.0 / 1.4;

		optionsBoundingBoxes[0].x = optionsBoundingBoxes[1].x = optionsBoundingBoxes[2].x = optionsBoundingBoxes[3].x = (SCREEN_W - answerBannerBitmap->w * width_scale) / 2;

		optionsBoundingBoxes[0].y = (SCREEN_H - answerBannerBitmap->h) * 0.585;
		optionsBoundingBoxes[1].y = (SCREEN_H - answerBannerBitmap->h) * 0.715;
		optionsBoundingBoxes[2].y = (SCREEN_H - answerBannerBitmap->h) * 0.845;
		optionsBoundingBoxes[3].y = (SCREEN_H - answerBannerBitmap->h) * 0.975;

		optionsBoundingBoxes[0].w = optionsBoundingBoxes[1].w = optionsBoundingBoxes[2].w = optionsBoundingBoxes[3].w = answerBannerBitmap->w * width_scale;
		optionsBoundingBoxes[0].h = optionsBoundingBoxes[1].h = optionsBoundingBoxes[2].h = optionsBoundingBoxes[3].h = answerBannerBitmap->h * height_scale;

		Utility::draw_button(buffer, answerBannerBitmap, optionsBoundingBoxes[0]);
		Utility::draw_button(buffer, answerBannerBitmap, optionsBoundingBoxes[1]);
		Utility::draw_button(buffer, answerBannerBitmap, optionsBoundingBoxes[2]);
		Utility::draw_button(buffer, answerBannerBitmap, optionsBoundingBoxes[3]);



		// print info header
		printScore(buffer, font, SCREEN_W * 0.3, SCREEN_H * 0.18, 2, gameState->currentScore, COLOR_HUD_TEXT, -1);
		printQuestionNumber(buffer, font, SCREEN_W * 0.9, SCREEN_H * 0.18, 2, gameState->currentQuestion + 1, COLOR_HUD_TEXT, -1);
		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.17, 3, "QUESTION", COLOR_TEXT, -1);

		questionScreenPlayer = Utility::draw_wrapping_text(buffer, bigFont, &gameQuestionDialog, quiz->getQuestionText(gameState->currentQuestion), SCREEN_W * 0.09, SCREEN_H * 0.22, SCREEN_W * 0.82, SCREEN_H * 0.2, COLOR_TEXT);

		//print options
		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, optionsBoundingBoxes[0].y + optionsBoundingBoxes[0].h / 2, 1.5, quiz->getQuestionOption(gameState->currentQuestion, 0), COLOR_TEXT, -1);
		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, optionsBoundingBoxes[1].y + optionsBoundingBoxes[1].h / 2, 1.5, quiz->getQuestionOption(gameState->currentQuestion, 1), COLOR_TEXT, -1);
		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, optionsBoundingBoxes[2].y + optionsBoundingBoxes[2].h / 2, 1.5, quiz->getQuestionOption(gameState->currentQuestion, 2), COLOR_TEXT, -1);
		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, optionsBoundingBoxes[3].y + optionsBoundingBoxes[0].h / 2, 1.5, quiz->getQuestionOption(gameState->currentQuestion, 3), COLOR_TEXT, -1);
	}
	else  if (SCREEN_W == 1280 && SCREEN_H == 960) {
		masked_stretch_blit(questionBannerBitmap, buffer, 0, 0, questionBannerBitmap->w, questionBannerBitmap->h, (SCREEN_W - questionBannerBitmap->w) / 2, (SCREEN_H - questionBannerBitmap->h) * 0.1, questionBannerBitmap->w, questionBannerBitmap->h);
		float width_scale = 1.0 / 1.2;

		optionsBoundingBoxes[0].x = optionsBoundingBoxes[1].x = optionsBoundingBoxes[2].x = optionsBoundingBoxes[3].x = (SCREEN_W - answerBannerBitmap->w * width_scale) / 2;

		optionsBoundingBoxes[0].y = (SCREEN_H - answerBannerBitmap->h) * 0.515;
		optionsBoundingBoxes[1].y = (SCREEN_H - answerBannerBitmap->h) * 0.655;
		optionsBoundingBoxes[2].y = (SCREEN_H - answerBannerBitmap->h) * 0.795;
		optionsBoundingBoxes[3].y = (SCREEN_H - answerBannerBitmap->h) * 0.935;

		optionsBoundingBoxes[0].w = optionsBoundingBoxes[1].w = optionsBoundingBoxes[2].w = optionsBoundingBoxes[3].w = answerBannerBitmap->w * width_scale;
		optionsBoundingBoxes[0].h = optionsBoundingBoxes[1].h = optionsBoundingBoxes[2].h = optionsBoundingBoxes[3].h = answerBannerBitmap->h;

		Utility::draw_button(buffer, answerBannerBitmap, optionsBoundingBoxes[0]);
		Utility::draw_button(buffer, answerBannerBitmap, optionsBoundingBoxes[1]);
		Utility::draw_button(buffer, answerBannerBitmap, optionsBoundingBoxes[2]);
		Utility::draw_button(buffer, answerBannerBitmap, optionsBoundingBoxes[3]);

		// print info header
		printScore(buffer, font, SCREEN_W*0.28, SCREEN_H*0.12, 2, gameState->currentScore, COLOR_HUD_TEXT, -1);
		printQuestionNumber(buffer, font, SCREEN_W * 0.88, SCREEN_H * 0.12, 2, gameState->currentQuestion+1, COLOR_HUD_TEXT, -1);
		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.16, 3, "QUESTION", COLOR_TEXT, -1);

		// display question text box
		questionScreenPlayer= Utility::draw_wrapping_text(buffer, bigFont, &gameQuestionDialog, quiz->getQuestionText(gameState->currentQuestion), SCREEN_W * 0.09, SCREEN_H * 0.2, SCREEN_W * 0.82, SCREEN_H * 0.2, COLOR_TEXT);
		//print options
		Utility::textout_centre_magnified(buffer, font, SCREEN_W/2, optionsBoundingBoxes[0].y + optionsBoundingBoxes[0].h/2, 2, quiz->getQuestionOption(gameState->currentQuestion, 0), COLOR_TEXT, -1);
		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, optionsBoundingBoxes[1].y + optionsBoundingBoxes[1].h / 2, 2, quiz->getQuestionOption(gameState->currentQuestion, 1), COLOR_TEXT, -1);
		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, optionsBoundingBoxes[2].y + optionsBoundingBoxes[2].h / 2, 2, quiz->getQuestionOption(gameState->currentQuestion, 2), COLOR_TEXT, -1);
		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, optionsBoundingBoxes[3].y + optionsBoundingBoxes[0].h / 2, 2, quiz->getQuestionOption(gameState->currentQuestion, 3), COLOR_TEXT, -1);
	}
}




void GameQuestionScreen::printScore(BITMAP* bmp, FONT* font, int x, int y, double multiplier, int score, int color, int bg)
{
	BoundingBox box = {};
	BITMAP* tmp;
	tmp = create_bitmap(text_length(font, "Score: XX/XX"), text_height(font));
	if (!tmp)
		return;
	clear_to_color(tmp, makecol(255, 0, 255)); 

	textprintf_ex(tmp, font, 0, 0, color, bg, "Score: %d/%d", score, NUMBER_OF_QUESTIONS_PER_GAME);

	box.x = x - (int)(tmp->w * multiplier) ;
	box.y = y - (int)(tmp->h * multiplier);
	box.w = (int)(tmp->w * multiplier);
	box.h = (int)(tmp->h * multiplier);

	masked_stretch_blit(tmp, bmp, 0, 0, tmp->w, tmp->h, box.x, box.y, box.w, box.h);
	destroy_bitmap(tmp);

	return;

}


void GameQuestionScreen::printScoreCentred(BITMAP* bmp, FONT* font, int x, int y, double multiplier, int score, int color, int bg)
{
	BoundingBox box = {};
	BITMAP* tmp;
	tmp = create_bitmap(text_length(font, "Score: XX/XX"), text_height(font));
	if (!tmp)
		return;
	clear_to_color(tmp, makecol(255, 0, 255));

	textprintf_ex(tmp, font, 0, 0, color, bg, "Score: %d/%d", score, NUMBER_OF_QUESTIONS_PER_GAME);

	box.x = x - (int)(tmp->w * multiplier);
	box.y = y - (int)(tmp->h * multiplier);
	box.w = (int)(tmp->w * multiplier);
	box.h = (int)(tmp->h * multiplier);

	masked_stretch_blit(tmp, bmp, 0, 0, tmp->w, tmp->h, box.x + box.w/2, box.y + box.h / 2, box.w, box.h);
	destroy_bitmap(tmp);

	return;

}




void GameQuestionScreen::printQuestionNumber(BITMAP* bmp, FONT* font, int x, int y, double multiplier, int questionNo, int color, int bg)
{
	BoundingBox box = {};
	BITMAP* tmp;
	tmp = create_bitmap(text_length(font, "Question# XX/XX"), text_height(font));
	if (!tmp)
		return;
	clear_to_color(tmp, makecol(255, 0, 255));

	textprintf_ex(tmp, font, 0, 0, color, bg, "Question# %d/%d", questionNo, NUMBER_OF_QUESTIONS_PER_GAME);

	box.x = x - (int)(tmp->w * multiplier);
	box.y = y - (int)(tmp->h * multiplier);
	box.w = (int)(tmp->w * multiplier);
	box.h = (int)(tmp->h * multiplier);

	masked_stretch_blit(tmp, bmp, 0, 0, tmp->w, tmp->h, box.x, box.y, box.w, box.h);
	destroy_bitmap(tmp);

	return;

}


