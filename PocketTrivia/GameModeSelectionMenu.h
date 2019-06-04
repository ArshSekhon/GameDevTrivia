#pragma once

#include "Constants.h"

#include "Utility.h"
#include "entities/Quiz.h"
#include <allegro.h>

#define CHAPTER_COUNT 22

class GameModeSelectionMenu
{
public:
	GameModeSelectionMenu(GameState* gameState);
	Quiz* showGameModeMenu(BITMAP* buffer);

private:
	GameState* gameState;
	BITMAP* bannerBitmap;
	BoundingBox exitToMainMenuButton;
	BoundingBox playButton; 
	Quiz* prepareQuizFromSelection(char* chapterSelection);
	const char* chapterQuestionsList[CHAPTER_COUNT] = { 
		"questions/Chapter-1-Questions.txt",
		"questions/Chapter-2-Questions.txt",
		"questions/Chapter-3-Questions.txt",
		"questions/Chapter-4-Questions.txt",
		"questions/Chapter-5-Questions.txt",
		"questions/Chapter-6-Questions.txt",
		"questions/Chapter-7-Questions.txt",
		"questions/Chapter-8-Questions.txt",
		"questions/Chapter-9-Questions.txt",
		"questions/Chapter-10-Questions.txt",
		"questions/Chapter-11-Questions.txt",
		"questions/Chapter-12-Questions.txt",
		"questions/Chapter-13-Questions.txt",
		"questions/Chapter-14-Questions.txt",
		"questions/Chapter-15-Questions.txt",
		"questions/Chapter-16-Questions.txt",
		"questions/Chapter-17-Questions.txt",
		"questions/Chapter-18-Questions.txt",
		"questions/Chapter-19-Questions.txt",
		"questions/Chapter-20-Questions.txt",
		"questions/Chapter-21-Questions.txt",
		"questions/Chapter-22-Questions.txt" 
	};

	const char* chapterAnswersList[CHAPTER_COUNT] = { 
		"questions/Chapter-1-Answers.txt",
		"questions/Chapter-2-Answers.txt",
		"questions/Chapter-3-Answers.txt",
		"questions/Chapter-4-Answers.txt",
		"questions/Chapter-5-Answers.txt",
		"questions/Chapter-6-Answers.txt",
		"questions/Chapter-7-Answers.txt",
		"questions/Chapter-8-Answers.txt",
		"questions/Chapter-9-Answers.txt",
		"questions/Chapter-10-Answers.txt",
		"questions/Chapter-11-Answers.txt",
		"questions/Chapter-12-Answers.txt",
		"questions/Chapter-13-Answers.txt",
		"questions/Chapter-14-Answers.txt",
		"questions/Chapter-15-Answers.txt",
		"questions/Chapter-16-Answers.txt",
		"questions/Chapter-17-Answers.txt",
		"questions/Chapter-18-Answers.txt",
		"questions/Chapter-19-Answers.txt",
		"questions/Chapter-20-Answers.txt",
		"questions/Chapter-21-Answers.txt",
		"questions/Chapter-22-Answers.txt" 
	};

};

