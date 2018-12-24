/*_Created_by_K1ngp1n_*/

#pragma once

#include "Answer.hpp"

class Answer;

class AnswerByHandFillAll : public Answer{
	public:
	AnswerByHandFillAll(Question *q);
	~AnswerByHandFillAll() override;

	void readInput() override;

};



