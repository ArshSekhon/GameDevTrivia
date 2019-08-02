#pragma once
#include "Constants.h"
#include "entities/Quiz.h"
#include "Utility.h"
#include "SoundManager.h"

#include <allegro.h>

/**
 * @brief This class contains function related to diplaying a question screen for the quiz, handles event for the same and also shows the 
 * result for these questions after user select their answer. This visually the most important screen and constitutes major part of the game.
 * 
 */
class GameQuestionScreen
{
public:
	/**
	 * @brief Construct a new Game Question Screen object used to display a questions screen
	 * 
	 * @param gameState  Pointer to the game state struct that is shared by the entire game.
	 * @param soundManager Pointer to soundManager object that is used to play sounds.
	 */
	GameQuestionScreen(GameState* gameState, SoundManager* soundManager);

	/**
	 * @brief Function draws a question screen for the quiz to the buffer , handles event for the same and also shows the 
	 * result for these questions after user select their answer and finally displays the results at the end of the game. 
	 * This is the most important screen and constitutes major part of the game.
	 * 
	 * @param buffer Pointer to the buffer where the question screen has to be drawn upon.
	 * @param quiz Pointer to the quiz object that contains the questions to be used in Quiz.
	 * 
	 */
	void showQuestionScreen(BITMAP* buffer, Quiz* quiz);
private:
	SoundManager* soundManager;
	BITMAP* questionBannerBitmap;
	BITMAP* answerBannerBitmap;
	BITMAP* bannerBitmap;
	GameState* gameState;
	BoundingBox* optionsBoundingBoxes;
	BoundingBox nextQuestionButton;
	BoundingBox exitToMainMenuButton;
	DIALOG_PLAYER* questionScreenPlayer;

	int showingCorrectAnswerBanner;
	int showingWrongAnswerBanner;
	int showingResultsBanner;

	void showCorrectAnswerBanner(BITMAP* buffer, Quiz* quiz);
	void showWrongAnswerBanner(BITMAP* buffer, Quiz* quiz);
	void showQuestion(BITMAP* buffer, Quiz* quiz);
	void showResultsBanner(BITMAP* buffer);


    void printScore(BITMAP* bmp, FONT* font, int x, int y, double multiplier, int score, int color, int bg);
	void printScoreCentred(BITMAP* bmp, FONT* font, int x, int y, double multiplier, int score, int color, int bg);
	void printQuestionNumber(BITMAP* bmp, FONT* font, int x, int y, double multiplier, int questionNo, int color, int bg);
	FONT* bigFont;
	 
};

