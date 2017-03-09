/*
Oscar Yuengel
Header file for helper functions.
*/

#ifndef HELPERS_H
#define HELPERS_H

#include <string>
#include <vector>
#include <sstream>
#include <limits>
#include <stdexcept>

namespace my {
	// Tokenizes a string around given delimiters. Returns a vector containing the tokens. 
	std::vector<std::string> tokenize(const std::string str, const std::string delims);
	// Converts a string into its corresponding integer. Throws exceptions on invalid inputs.
	int stoi(const std::string str);
	// Converts a string into its corresponding double. Throws exceptions on invalid inputs.
	double stod(const std::string str);
}

#endif