/*_Created_by_K1ngp1n_*/

#pragma once

#include <iostream>

class UnitIsDeadException {
	public:
	std::string text;
	UnitIsDeadException(const std::string& text) : text(text) {}
	~UnitIsDeadException() {}
};



