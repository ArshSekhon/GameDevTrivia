#ifndef QUIZ_H
#define QUIZ_H
#include "..//Constants.h"


struct QuizQuestion {
	char questionText[2000];
	char options[4][1000];
	int correctAnswerIndex;
};

class Quiz
{
private:
	int chapterCount;
	int* questionsCount;
	QuizQuestion** chapterWiseQuestionsList;
	int quizQuestionList[NUMBER_OF_QUESTIONS_PER_GAME][2];
	int questionAlreadyInQuizQuestionList(int chapterIndex, int questionIndex, int questionListIndex);
public:
	Quiz(const char** questionsFileName, const char** answersFileName, int chapterCount);
	char* getQuestionText(int quizQuestionListIndex);
	char* getQuestionOption(int quizQuestionListIndex, int optionIndex);
	int getQuestionAnswerIndex(int quizQuestionListIndex);
	char* getQuestionAnswer(int quizQuestionListIndex);
	int checkQuestionAnswer(int quizQuestionListIndex, int chosenOption);

};

#endif 
