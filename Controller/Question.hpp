/*_Created_by_K1ngp1n_*/

#pragma once

#include <iostream>
//#include "Answer.hpp"
//
//class Answer;

class Question { // ???
	std::string m_content;
	int m_key;
	public:
	Question(const std::string& content)
		: m_content(content)
		, m_key(-1)
	{}

	virtual ~Question() {}

	inline void ask() {
		std::cout << m_content << std::endl;

		std::cin >> m_key;
	}

	int getAnswer() const {
		return m_key;
	}

};

inline int askQuestion(const std::string& question) {
	std::cout << question << std::endl;
	std::string answer;
	std::cin >> answer;
	std::cout << answer << std::endl;

	int n = 0;

	for (char c: answer) {
		if (c >= '0' && c <= '9') {
			int digit = (c - 48);// '0' = symbol zero
			n = n*10 + digit;
		} else {
			std::cout << "invalid input. Try again" << std::endl;
			return askQuestion(question);
		}
	}
	return n;
}