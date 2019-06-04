#pragma once
#include "Constants.h"
#include "entities/Quiz.h"
#include "Utility.h"
#include "SoundManager.h"

#include <allegro.h>

class GameQuestionScreen
{
public:
	GameQuestionScreen(GameState* gameState, SoundManager* soundManager);
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

