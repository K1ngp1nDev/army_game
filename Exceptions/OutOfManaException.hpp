/*_Created_by_K1ngp1n_*/

#pragma once

#include <iostream>

class OutOfManaException {
	public:
	std::string text;
	OutOfManaException(const std::string& text) : text(text) {}
	~OutOfManaException() {}

};