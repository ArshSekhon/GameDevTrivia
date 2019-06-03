#ifndef QUIZ_H
#define QUIZ_H
#include "Question.h"

  
class Quiz
{
private: 
	Question **chapterWiseQuestionsList;
	int questionCount;
public:
	Quiz(const char** questionsFileName, const char** answersFileName, int chapterCount);

};
 
#endif 
