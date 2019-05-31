#include "Question.h"
#include "Quiz.h" 
#include "Constants.h"

#include <string>
#include <fstream>
#include <iostream>
#include <allegro.h>

Quiz::Quiz(const char* questionsFileName, const char* answersFileName) {
	std::ifstream quizQuestionsFile;
	std::ifstream quizAnswersFile;

	quizQuestionsFile.open(questionsFileName, std::ifstream::in);  // open file 
	 
	// read file till the end

	/* 
		IMPORTANT: This approach of reading the file relies on the author of the Questions and Answer files 
		it assumes the file is properly written.

		This reading of file can be imporved by introducing a more structured input file for example XML or json
		for the input file.

		For the scope of this project a simple txt file would do the job.
	*/
	while (!quizQuestionsFile.eof()) {
		std::string questionText;
		std::string questionOptions[4];
		int correctAnswer = -1;

		// read Question
		std::getline(quizQuestionsFile, questionText);
		// read options
		for (int i = 0; i < 4; i++) {
			// if unexpected EOF throw an error
			if (quizQuestionsFile.eof())
				throw EXCEPTION_READING_QUESTION_FILE;

			std::getline(quizQuestionsFile, questionOptions[i]);
		}
		 
		Question questionObj(questionText, questionOptions,correctAnswer);
		questionsVector.push_back(questionObj);
	} 

	quizQuestionsFile.close();


	quizAnswersFile.open(answersFileName, std::ifstream::in);  // open file
	std::string line;

	int questionVectorIndex = 0;
	while (!quizAnswersFile.eof()) {
		if (questionVectorIndex == questionsVector.size())
			throw EXCEPTION_READING_ANSWER_FILE;
		std::getline(quizAnswersFile, line);
		if ((line[0] >= 'A' && line[0] <= 'D'))
			questionsVector[questionVectorIndex++].setQuestionAnswer(line[0] - 'A');
		else if (line[0] >= 'a' && line[0] <= 'd')
			questionsVector[questionVectorIndex++].setQuestionAnswer(line[0] - 'a');
		else
			throw EXCEPTION_READING_ANSWER_FILE;
	}

	if (questionVectorIndex != questionsVector.size())
		throw EXCEPTION_READING_ANSWER_FILE;

}