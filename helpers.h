/*
Oscar Yuengel
Header file for helper functions.
*/

#ifndef HELPERS_H
#define HELPERS_H

#include <string>
#include <vector>

// Tokenizes a string around given delimiters. Returns a vector containing the tokens. 
std::vector<std::string> tokenize(const std::string str, const std::string delims);

#endif