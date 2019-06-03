#include "Question.h"

Question::Question(char* questionText, char** questionOptions, int correctAnswerIndex) {
	this->questionText = questionText;
	this->questionOptions = questionOptions;
	this->correctAnswerIndex = correctAnswerIndex;
}
char* Question::getQuestionText() {
	return this->questionText;
}
void  Question::setQuestionText(char* text) {
	this->questionText = text;
}
char** Question::getQuestionOptions() {
	return this->questionOptions;
}
void  Question::setQuestionText(char** options) {
	this->questionOptions = options;
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
	return this->questionOptions[this->correctAnswerIndex];
}