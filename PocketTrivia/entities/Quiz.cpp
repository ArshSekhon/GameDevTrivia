#include "Question.h"
#include "Quiz.h" 
#include "../Constants.h"

#include <string>
#include <fstream>
#include <iostream>
#include <allegro.h>

Quiz::Quiz(const char** questionsFileNames, const char** answersFileNames,int chapterCount) {
	std::ifstream quizQuestionsFile;
	std::string questionText;
	std::ifstream quizAnswersFile;
	chapterWiseQuestionsList = new Question*[chapterCount];

	for (int fileIndex = 0; fileIndex < chapterCount; fileIndex++) {
		const char* questionFileName = questionsFileNames[fileIndex];
		const char* answersFileName = questionsFileNames[fileIndex];

		quizQuestionsFile.open(questionFileName, std::ifstream::in);  // open file 

		// read file till the end


			//IMPORTANT: This approach of reading the file relies on the author of the Questions and Answer files 
			//it assumes the file is properly written.

			//This reading of file can be imporved by introducing a more structured input file for example XML or json
			//for the input file.

			//For the scope of this project a simple txt file would do the job.

		int count;
		if (!quizQuestionsFile.eof()) {
			char countBuff[10];
			quizQuestionsFile.getline(countBuff, 1000);
			count = atoi(countBuff);
		}
		chapterWiseQuestionsList[fileIndex] = new Question[count];

		int questionIndex = 0;

		while (!quizQuestionsFile.eof()) {
			char questionText[2000];
			char option1[1000];
			char option2[1000];
			char option3[1000];
			char option4[1000];

			int correctAnswer = -1;
			// read Question
			quizQuestionsFile.getline(questionText, 2000);
			// read options;
			quizQuestionsFile.getline(option1, 1000);
			quizQuestionsFile.getline(option2, 1000);
			quizQuestionsFile.getline(option3, 1000);
			quizQuestionsFile.getline(option4, 1000);

			chapterWiseQuestionsList[fileIndex][questionIndex++].setQuestionText(questionText);
			chapterWiseQuestionsList[fileIndex][questionIndex++].setQuestionOptions(option1,option2,option3,option4);
		}

		quizQuestionsFile.close();

		/*
		quizAnswersFile.open(answersFileName, std::ifstream::in);  // open file
		std::string line;

		int questionVectorIndex = 0;
		while (!quizAnswersFile.eof()) {
			if (questionVectorIndex == 3)//questionsList.size())
				throw EXCEPTION_READING_ANSWER_FILE;
			std::getline(quizAnswersFile, line);
			if ((line[0] >= 'A' && line[0] <= 'D'))
				//questionsList[questionVectorIndex++].setQuestionAnswer(line[0] - 'A');
				;
			else if (line[0] >= 'a' && line[0] <= 'd')
				//questionsList[questionVectorIndex++].setQuestionAnswer(line[0] - 'a');
				;
			else
				throw EXCEPTION_READING_ANSWER_FILE;
		}

		//if (questionVectorIndex != questionsList.size())
			//throw EXCEPTION_READING_ANSWER_FILE;
			*/
	}

	/*
	quizQuestionsFile.open(questionsFileName, std::ifstream::in);  // open file 
	 
	// read file till the end

	
		//IMPORTANT: This approach of reading the file relies on the author of the Questions and Answer files 
		//it assumes the file is properly written.

		//This reading of file can be imporved by introducing a more structured input file for example XML or json
		//for the input file.

		//For the scope of this project a simple txt file would do the job.

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
		//questionsList.push_back(questionObj);
	} 

	quizQuestionsFile.close();


	quizAnswersFile.open(answersFileName, std::ifstream::in);  // open file
	std::string line;

	int questionVectorIndex = 0;
	while (!quizAnswersFile.eof()) {
		if (questionVectorIndex == 3)//questionsList.size())
			throw EXCEPTION_READING_ANSWER_FILE;
		std::getline(quizAnswersFile, line);
		if ((line[0] >= 'A' && line[0] <= 'D'))
			//questionsList[questionVectorIndex++].setQuestionAnswer(line[0] - 'A');
			;
		else if (line[0] >= 'a' && line[0] <= 'd')
			//questionsList[questionVectorIndex++].setQuestionAnswer(line[0] - 'a');
			;
		else
			throw EXCEPTION_READING_ANSWER_FILE;
	}

	//if (questionVectorIndex != questionsList.size())
		//throw EXCEPTION_READING_ANSWER_FILE;
	*/
}