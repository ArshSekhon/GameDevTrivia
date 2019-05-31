#include "Question.h"
#include <string>

Question::Question(std::string questionText, std::string* questionOptions, int correctAnswerIndex) {
	this->questionText = questionText;
	this->questionOptions = questionOptions;
	this->correctAnswerIndex = correctAnswerIndex;
}
std::string Question::getQuestionText() {
	return this->questionText;
}
void  Question::setQuestionText(std::string text) {
	this->questionText = text;
}
std::string* Question::getQuestionOptions() {
	return this->questionOptions;
}
void  Question::setQuestionText(std::string* options) {
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
std::string Question::getQuestionAnswer() {
	return this->questionOptions[this->correctAnswerIndex];
}