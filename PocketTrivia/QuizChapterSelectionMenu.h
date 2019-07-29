#pragma once

#include "Constants.h"

#include "Utility.h"
#include "entities/Quiz.h"
#include <allegro.h>

#define CHAPTER_COUNT 22

/**
 * @brief This class contains function related to diplaying the Chapter Seleection screen that allows selecting what chapter the quiz should be based on, 
 * handling the events for the same.
 * 
 */
class QuizChapterSelectionMenu
{
public:
	/**
	 * 
	 * @brief Construct a new QuizChapterSelectionMenu object that would be used to show an screen that allows selecting chapters which 
	 * the quiz should be based.
	 * 
	 * @param gameState Pointer to the game state struct that is shared by the entire game 
	 *  
	 */
	QuizChapterSelectionMenu(GameState* gameState);
	/**
	 * @brief Draws game chapter selection screen on to the buffer passed as an arguement 
	 * and also handles mouse click events for the same.
	 * 
	 * @param buffer Screen buffer or other buffer where the game chapter screen screen has to be drawn.
	 * @return Pointer to quiz object created from user's selection of chapters
	 */
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

