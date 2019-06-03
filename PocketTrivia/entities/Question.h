#pragma once

class Question
{ 
private:
		char* questionText;
		char** questionOptions;
		int correctAnswerIndex; 
public:
	Question(char* questionText, char** questionOptions, int correctAnswerIndex);
	char* getQuestionText(void);
	void setQuestionText(char*);
	char** getQuestionOptions(void);
	void setQuestionText(char**);
	void setQuestionAnswer(int correctAnswerIndex);
	bool checkQuestionAnswer(int answerIndex);
	int getQuestionAnswerIndex();
	char* getQuestionAnswer();
};

