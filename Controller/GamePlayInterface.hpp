/*_Created_by_K1ngp1n_*/

#pragma once
#include <iostream>
#include "../Interfaces/BattleField.hpp"


class Question;
class Answer;

class GamePlayInterface {
	Question* m_question;
	Answer* m_answer;
	public:
	GamePlayInterface();
	~GamePlayInterface();

	void start();
};



