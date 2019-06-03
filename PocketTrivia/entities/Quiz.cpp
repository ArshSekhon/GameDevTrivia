#include "Quiz.h" 
//#include "../Constants.h"

#include <fstream>
#include <ctime>
//#include <allegro.h>

Quiz::Quiz(const char** questionsFileNames, const char** answersFileNames, int chapterCount) {
	std::ifstream quizQuestionsFile;
	std::string questionText;
	std::ifstream quizAnswersFile;
	chapterWiseQuestionsList = new QuizQuestion * [chapterCount];
	this->chapterCount = chapterCount;
	this->questionsCount = new int[chapterCount];

	for (int chapterIndex = 0; chapterIndex < chapterCount; chapterIndex++) {
		const char* questionFileName = questionsFileNames[chapterIndex];
		const char* answersFileName = answersFileNames[chapterIndex];

		quizQuestionsFile.open(questionFileName, std::ifstream::in);  // open file 


		int count = -1;
		if (!quizQuestionsFile.eof()) {
			char countBuff[10];
			quizQuestionsFile.getline(countBuff, 1000);
			count = atoi(countBuff);
		}
		chapterWiseQuestionsList[chapterIndex] = new QuizQuestion[count];

		this->questionsCount[chapterIndex] = count;

		int questionIndex = 0;

		while (!quizQuestionsFile.eof()) {

			int correctAnswer = -1;
			// read Question
			quizQuestionsFile.getline(chapterWiseQuestionsList[chapterIndex][questionIndex].questionText, 2000);
			// read options;
			quizQuestionsFile.getline(chapterWiseQuestionsList[chapterIndex][questionIndex].options[0], 1000);
			quizQuestionsFile.getline(chapterWiseQuestionsList[chapterIndex][questionIndex].options[1], 1000);
			quizQuestionsFile.getline(chapterWiseQuestionsList[chapterIndex][questionIndex].options[2], 1000);
			quizQuestionsFile.getline(chapterWiseQuestionsList[chapterIndex][questionIndex++].options[3], 1000);

		}

		if (questionIndex != count)
			throw EXCEPTION_READING_QUESTION_FILE;


		quizQuestionsFile.close();
		//READING ANSWERS FILE HERE

		quizAnswersFile.open(answersFileName, std::ifstream::in);  // open file
		char tmpAns[10];
		//reset index for questions
		questionIndex = 0;
		while (!quizAnswersFile.eof()) {
			if (questionIndex >= count)
				throw EXCEPTION_READING_ANSWER_FILE;

			quizAnswersFile.getline(tmpAns, 4);
			if ((tmpAns[0] >= 'A' && tmpAns[0] <= 'D'))
				chapterWiseQuestionsList[chapterIndex][questionIndex++].correctAnswerIndex = (tmpAns[0] - 'A');
			else if (tmpAns[0] >= 'a' && tmpAns[0] <= 'd')
				chapterWiseQuestionsList[chapterIndex][questionIndex++].correctAnswerIndex = (tmpAns[0] - 'a');
			else
				throw EXCEPTION_READING_ANSWER_FILE;

		}

		if (questionIndex != count)
			throw EXCEPTION_READING_ANSWER_FILE;


		quizAnswersFile.close();


	}

	//check if question read in a sufficient
	int totalQuestions = 0;
	for (int i = 0; i < chapterCount; i++)
		totalQuestions += questionsCount[i];
	if (totalQuestions < NUMBER_OF_QUESTIONS_PER_GAME)
		throw - 1;

	//generate random quiz out of the chapters
	for (int i = 0; i < NUMBER_OF_QUESTIONS_PER_GAME; i++) {
		int randChapterIndex = rand() % chapterCount;
		int randQuestionIndex = rand() % questionsCount[randChapterIndex];
		//TODO: make questions distinct
		if (!questionAlreadyInQuizQuestionList(randChapterIndex, randQuestionIndex, i)) {
			quizQuestionList[i][0] = randChapterIndex;
			quizQuestionList[i][1] = randQuestionIndex;
		}
	}

}

char* Quiz::getQuestionText(int quizQuestionListIndex) {
	QuizQuestion* question = &chapterWiseQuestionsList[quizQuestionList[quizQuestionListIndex][0]][quizQuestionList[quizQuestionListIndex][1]];
	return question->questionText;
}
char* Quiz::getOptionText(int quizQuestionListIndex, int optionIndex) {
	QuizQuestion* question = &chapterWiseQuestionsList[quizQuestionList[quizQuestionListIndex][0]][quizQuestionList[quizQuestionListIndex][1]];
	return question->options[optionIndex];
}
int Quiz::getQuestionAnswerIndex(int quizQuestionListIndex) {
	QuizQuestion* question = &chapterWiseQuestionsList[quizQuestionList[quizQuestionListIndex][0]][quizQuestionList[quizQuestionListIndex][1]];
	return question->correctAnswerIndex;
}
char* Quiz::getQuestionAnswer(int quizQuestionListIndex) {
	QuizQuestion* question = &chapterWiseQuestionsList[quizQuestionList[quizQuestionListIndex][0]][quizQuestionList[quizQuestionListIndex][1]];
	return question->options[question->correctAnswerIndex];
}
int Quiz::questionAlreadyInQuizQuestionList(int chapterIndex, int questionIndex, int questionListIndex) {
	for (int i = 0; i < questionListIndex; i++)
		if (quizQuestionList[i][0] == chapterIndex && quizQuestionList[i][0] == questionIndex)
			return 1;
	return 0;
}