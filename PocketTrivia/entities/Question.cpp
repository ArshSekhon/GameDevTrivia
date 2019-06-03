#include "Question.h"

Question::Question() {

}

Question::Question(char* questionText, char* option1, char* option2, char* option3, char* option4 , int correctAnswerIndex) {
	this->questionText = questionText;
	this->option1 = option1;
	this->option2 = option2;
	this->option3 = option3;
	this->option4 = option4;
	this->correctAnswerIndex = correctAnswerIndex;

}
char* Question::getQuestionText() {
	return this->questionText;
}
void  Question::setQuestionText(char* text) {
	this->questionText = text;
}

char* Question::getQuestionOption(int index) {
	if (index == 0)
		return option1;
	if (index == 1)
		return option2;
	if (index == 2)
		return option3;
	if (index == 3)
		return option4;
}

void  Question::setQuestionOptions(char* option1, char* option2, char* option3, char* option4 ) {
	this->option1 = option1;
	this->option2 = option2;
	this->option3 = option3;
	this->option4 = option4;
} 
void Question::setQuestionAnswer(int correctAnswerIndex) {
	this->correctAnswerIndex = correctAnswerIndex;
}
bool Question::checkQuestionAnswer(int answerIndex) {
	return (this->correctAnswerIndex == answerIndex);
}
int Question::getQuestionAnswerIndex() {
	return this->correctAnswerIndex;
}
char* Question::getQuestionAnswer() {
	return getQuestionOption(correctAnswerIndex);
}