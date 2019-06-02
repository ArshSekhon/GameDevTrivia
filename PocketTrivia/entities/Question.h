#pragma once
#include <string>

class Question
{ 
private:
		std::string questionText;
		std::string* questionOptions;
		int correctAnswerIndex; 
public:
	Question(std::string questionText, std::string* questionOptions, int correctAnswerIndex);
	std::string getQuestionText(void);
	void setQuestionText(std::string);
	std::string* getQuestionOptions(void);
	void setQuestionText(std::string*);
	void setQuestionAnswer(int correctAnswerIndex);
	bool checkQuestionAnswer(int answerIndex);
	int getQuestionAnswerIndex();
	std::string getQuestionAnswer();
};

