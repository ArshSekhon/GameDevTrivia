#ifndef QUIZ_H
#define QUIZ_H
#include "..//Constants.h"

/**
 * @brief Used to store data for a particular question in Quiz
 * 
 */
struct QuizQuestion {
	/**
	 * @brief Array to hold the text for the question itself.
	 * 
	 */
	char questionText[2000];
	/**
	 * @brief Array to hold the text for all the options for the question.
	 */
	char options[4][1000];
	/**
	 * @brief Index of the option that is correct answer to the question.
	 */
	int correctAnswerIndex;
};

 
/**
 * @brief Quiz class that takes in files for question and answer files as input and creates a quiz with NUMBER_OF_QUESTIONS_PER_GAME random
 * questions
 * 
 */
class Quiz
{
private:
	int chapterCount;
	int* questionsCount;
	QuizQuestion** chapterWiseQuestionsList;
	int quizQuestionList[NUMBER_OF_QUESTIONS_PER_GAME][2];
	int questionAlreadyInQuizQuestionList(int chapterIndex, int questionIndex, int questionListIndex);
public:
	/**
	 * @brief This constructor allows creation of a new quiz by taking in the names of files containing the questions and answers. 
	 * It would automatically read those files and create a quiz consisting of random NUMBER_OF_QUESTIONS_PER_GAME (see Constants.h) questions 
	 *
	 * @param questionsFileNames Pointer to array containing names of the files containing the questions that would be 
	 * used to prepare the quiz. (Important! The question and corresponding answer files should have same position in the arrays)
	 * @param answersFileNames Pointer to array containing names of the files containing the answers that would be used to prepare the quiz. 
	 * (Important! The question and corresponding answer files should have same position in the arrays)
	 * @param count Number of files being used.
	 *  
	 */
	Quiz(const char** questionsFileNames, const char** answersFileNames, int count);
	
	/**
	 * @brief This function allows getting the text for a particular question
	 * @param quizQuestionListIndex Index of the question.
	 * @returns A pointer to the question text string
	 * 
	 */
	char* getQuestionText(int quizQuestionListIndex);
	
	/**
	 * @brief This function allows getting the text for a give option for a particular question.
	 *
	 * @param quizQuestionListIndex Index of the question.
	 * @param optionIndex Index of the option you wish to get the text for.
	 *
	 * @returns A pointer to the option text string
	 * 
	 */
	char* getQuestionOption(int quizQuestionListIndex, int optionIndex);
	
	/**
	 * @brief Returns the index of option that is correct answer for a particular question.
	 * 
	 * @param quizQuestionListIndex Index of the question.
	 * 
	 * @returns Index of option that is correct answer. 
	 */	
	int getQuestionAnswerIndex(int quizQuestionListIndex);
	
	/**
	 * @brief Returns pointer to the text of the correct option for a particular question
	 *
	 * @param quizQuestionListIndex Index of the question.
	 * 
	 * @returns Pointer to the text of the correct option. 
	 */	
	char* getQuestionAnswer(int quizQuestionListIndex);
	
	/**
	 * @brief Provides a means to check if a particular option is correct answer for a question.
	 *
	 * @param quizQuestionListIndex Index of the question.
	 * @param chosenOption Index of the option you wish to check if is the correct answer. 
	 *
	 * @returns Boolean that tells if the passed index belonged to correct answer or not
	 * 
	 */
	int checkQuestionAnswer(int quizQuestionListIndex, int chosenOption);

};

#endif 
