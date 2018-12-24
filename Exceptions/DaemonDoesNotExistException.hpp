/*_Created_by_K1ngp1n_*/

#pragma once

#include <iostream>
class DaemonDoesNotExistException {
	public:
	std::string text;
	DaemonDoesNotExistException(const std::string& text) : text(text) {}
	~DaemonDoesNotExistException() {}

};