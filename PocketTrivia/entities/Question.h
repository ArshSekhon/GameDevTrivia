#pragma once

class Question
{ 
private:
public:
	Question(char* questionText, char* option1, char* option2, char* option3, char* option4, int correctAnswerIndex);
	Question();
	char* getQuestionText(void);
	void setQuestionText(char*);
	//char** getQuestionOptions(void);
	char* getQuestionOption(int index);
	void setQuestionOptions(char* option1, char* option2, char* option3, char* option4);
	//void setQuestionOptions(char** options);
	void setQuestionAnswer(int correctAnswerIndex);
	bool checkQuestionAnswer(int answerIndex);
	int getQuestionAnswerIndex();
	char* getQuestionAnswer();

	char* questionText;
	char* option1;
	char* option2;
	char* option3;
	char* option4;

	int correctAnswerIndex;
};

