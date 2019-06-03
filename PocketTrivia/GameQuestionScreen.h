#pragma once
#include "Constants.h"
#include "entities/Question.h"
#include "Utility.h"
#include <allegro.h>

class GameQuestionScreen
{
public:
	GameQuestionScreen(GameState* gameState);
	void showQuestionScreen(BITMAP* buffer, Question* question);
private:
	BITMAP* questionBannerBitmap;
	BITMAP* answerBannerBitmap;
	BITMAP* bannerBitmap;
	GameState* gameState;
	BoundingBox* optionsBoundingBoxes;
	BoundingBox nextQuestionButton;
	BoundingBox exitToMainMenuButton;

	int showingCorrectAnswerBanner;
	int showingWrongAnswerBanner;
	int showingResultsBanner;

	void showCorrectAnswerBanner(BITMAP* buffer, Question* question);
	void showWrongAnswerBanner(BITMAP* buffer, Question* question);
	void showQuestion(BITMAP* buffer, Question* question);
	void showResultsBanner(BITMAP* buffer);


    void printScore(BITMAP* bmp, FONT* font, int x, int y, double multiplier, int score, int color, int bg);
	void printScoreCentred(BITMAP* bmp, FONT* font, int x, int y, double multiplier, int score, int color, int bg);
	void printQuestionNumber(BITMAP* bmp, FONT* font, int x, int y, double multiplier, int questionNo, int color, int bg);
	FONT* bigFont;
	 
};

