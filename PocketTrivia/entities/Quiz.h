#ifndef QUIZ_H
#define QUIZ_H
#include "Question.h"

#include <vector>
#include <string>
  
class Quiz
{
private: 
	std::vector<Question> questionsVector;
public:
	Quiz(const char* questionsFileName, const char* answersFileName);

};
 
#endif 
