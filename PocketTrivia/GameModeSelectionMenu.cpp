#include "GameModeSelectionMenu.h"





char* chapter_listbox_getter(int index, int* list_size)
{
	static char* chapters[] =
	{
	  (char*) "All Chapters",  (char*)"Chapter 1: Demystifying Game Development",  (char*) "Chapter 2: Getting Started with the Allegro Game Library",   (char*)"Chapter 3: Getting Started with the Allegro Game Library", (char*)"Chapter 4: Writing Your First Allegro Game",  (char*)"Chapter 5: Getting Input from the Player",
	  (char*) "Chapter 6: Mastering the AudibleRealm",   (char*)"Chapter 7: Mastering the Audible Realm", (char*)"Chapter 8: Introduction to Sprite Programming",(char*) "Chapter 9: Introduction to Sprite Programming",  (char*)"Chapter 10: Advanced Sprite Programming",(char*)"Chapter 11: Programming the Perfect Game Loop",  (char*)"Chapter 12: Programming Tile-Based Scrolling Backgrounds",  (char*)"Chapter 13: Creating a Game World: Editing Tiles and Levels",  (char*)"Chapter 14: Loading Native Mappy Files",  (char*)"Chapter 15: Vertical Scrolling Arcade Games",  (char*)"Chapter 16: Horizontal Scrolling Platform Games",  (char*)"Chapter 17: The Importance of Game Design",  (char*)"Chapter 18: Using Datafiles to Store Game Resources",  (char*)"Chapter 19: Playing Movies and Cut Scenes",  (char*)"Chapter 20: Introduction to Artificial Intelligence",  (char*)"Chapter 21: Multi-Threading",   (char*)"Chapter 22: Publishing Your Game"
	};

	if (index < 0) {
		//+1 due to the all chapters option
		*list_size = CHAPTER_COUNT+1;
		return NULL;
	}
	else {
		return chapters[index];
	}
}



DIALOG chapterListDialog = { d_list_proc, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, (void*)chapter_listbox_getter, NULL,  NULL };


GameModeSelectionMenu::GameModeSelectionMenu(GameState* gameState) {
	this->gameState = gameState;
	this->gameState->chapter_selection = new char[22]{NULL};
	this->bannerBitmap = load_bitmap("assets/ui-elem/Banner_Sq.bmp", NULL);

}

Quiz* GameModeSelectionMenu::showGameModeMenu(BITMAP* buffer) {

	// clear BG
	rectfill(buffer, 0, 0, SCREEN_W, SCREEN_H, COLOR_BG);



	if (SCREEN_W == 640 && SCREEN_H == 480) {
		masked_stretch_blit(bannerBitmap, buffer, 0, 0, bannerBitmap->w, bannerBitmap->h, SCREEN_W * 0.1, SCREEN_H * 0.1, SCREEN_W * 0.8, SCREEN_H * 0.8);

		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.25, 1.5, "WHERE TO PICK QUESTIONS FROM?", COLOR_TEXT, -1);
		Utility::create_list(buffer, font, &chapterListDialog, chapter_listbox_getter, gameState->chapter_selection, SCREEN_W * 0.2, SCREEN_H * 0.32, SCREEN_W * 0.6, SCREEN_H * 0.4, 10);
		exitToMainMenuButton = Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2.7, SCREEN_H * 0.78, 1.5, "EXIT TO MAIN MENU", COLOR_TEXT, -1);
		playButton = Utility::textout_centre_magnified(buffer, font, SCREEN_W / 1.35, SCREEN_H * 0.78, 1.5, "PLAY!", COLOR_TEXT, -1);
	}
	else if (SCREEN_W == 960 && SCREEN_H == 720) {
		masked_stretch_blit(bannerBitmap, buffer, 0, 0, bannerBitmap->w, bannerBitmap->h, (SCREEN_W - bannerBitmap->w) / 2, (SCREEN_H - bannerBitmap->h) / 2, bannerBitmap->w, bannerBitmap->h);

		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.27, 2, "WHERE TO PICK QUESTIONS FROM?", COLOR_TEXT, -1);
		Utility::create_list(buffer, font, &chapterListDialog, chapter_listbox_getter, gameState->chapter_selection, SCREEN_W * 0.22, SCREEN_H * 0.32, SCREEN_W * 0.56, SCREEN_H * 0.37, 10);
		exitToMainMenuButton = Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2.7, SCREEN_H * 0.74, 1.5, "EXIT TO MAIN MENU", COLOR_TEXT, -1);
		playButton = Utility::textout_centre_magnified(buffer, font, SCREEN_W / 1.44, SCREEN_H * 0.74, 1.5, "PLAY!", COLOR_TEXT, -1);
	}
	else  if (SCREEN_W == 1280 && SCREEN_H == 960) {
		masked_stretch_blit(bannerBitmap, buffer, 0, 0, bannerBitmap->w, bannerBitmap->h, (SCREEN_W - bannerBitmap->w) / 2, (SCREEN_H - bannerBitmap->h) / 2, bannerBitmap->w, bannerBitmap->h);

		Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2, SCREEN_H * 0.33, 2, "WHERE TO PICK QUESTIONS FROM?", COLOR_TEXT, -1);
		Utility::create_list(buffer, font, &chapterListDialog, chapter_listbox_getter, gameState->chapter_selection, SCREEN_W * 0.3, SCREEN_H * 0.37, SCREEN_W * 0.4, SCREEN_H * 0.27, 10);
		exitToMainMenuButton = Utility::textout_centre_magnified(buffer, font, SCREEN_W / 2.5, SCREEN_H * 0.68, 1.5, "EXIT TO MAIN MENU", COLOR_TEXT, -1);
		playButton = Utility::textout_centre_magnified(buffer, font, SCREEN_W / 1.6, SCREEN_H * 0.68, 1.5, "PLAY!", COLOR_TEXT, -1);
	}
	 

	if (Utility::inTheBoundingBox(exitToMainMenuButton)) {
		gameState->mouseHover = 1;
		if ((gameState->pendingMouseClick==1) && !(mouse_b & 1)) {
			gameState->gameScreen = GAME_SCREEN_MAIN_MENU;
			gameState->mouseHover = 0;
			gameState->pendingMouseClick = 0;
			rest(300);
			return NULL;
		}
	}
	else if (Utility::inTheBoundingBox(playButton)) {
		gameState->mouseHover = 1;
		if ((gameState->pendingMouseClick==1) && !(mouse_b & 1)) { 
			gameState->gameScreen = GAME_SCREEN_QUESTION;
			gameState->mouseHover = 0;
			gameState->pendingMouseClick = 0;
			rest(300);
		
			return prepareQuizFromSelection(gameState->chapter_selection);
		}
	}
	else {
		gameState->mouseHover = 0;
	}




	//draw buffer to screen and clear buffer
	blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	clear_bitmap(buffer);
	return NULL;
}
Quiz* GameModeSelectionMenu::prepareQuizFromSelection(char* chapterSelection) {
	//if all chapter mode selected
	if (chapterSelection[0] != NULL)
		return new Quiz(chapterQuestionsList, chapterAnswersList, CHAPTER_COUNT);
	else {
		int noOfChaptersSelected = 0;
		for(int i=0;i<=CHAPTER_COUNT;i++)
			if (chapterSelection[i] != NULL) {
				noOfChaptersSelected++;
			}
		char** chapterQuestionsArray = new char* [noOfChaptersSelected];
		char** chapterAnswersArray = new char* [noOfChaptersSelected];

		int currentIndex = 0;
		for (int i = 1; i <=CHAPTER_COUNT; i++)
			if (chapterSelection[i] != NULL) {
				chapterQuestionsArray[currentIndex] = (char*)chapterQuestionsList[i-1];
				chapterAnswersArray[currentIndex++] = (char*)chapterAnswersList[i-1];
			}

		Quiz* quiz = new Quiz((const char**)chapterQuestionsArray, (const char**)chapterAnswersArray, noOfChaptersSelected);
		return quiz;
		
	}
}