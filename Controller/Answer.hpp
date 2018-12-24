/*_Created_by_K1ngp1n_*/

#pragma once

#include <iostream>
#include "Question.hpp"

class Question;

class Answer { // !!!
	protected:
	public:
	Question* m_question;
	Answer(Question* q) : m_question(q) {}
	virtual ~Answer() {}
	virtual void readInput() = 0;

};


