/**************
* Oscar Yuengel
*
* Given a string from the user, converts it into Title Case. 
* The words "the", "and", "but", and "of" remain non-capitalized
* unless they are the first or last word in the string.
* String must consist of ASCII.
******************************/

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <cctype>

#include "helpers.h"

using std::cout;
using std::cin;
using std::string;
using std::vector;

int main() {

	cout << "Enter an ASCII string. This program will convert the string into title case\n"
	     << "(e.g. \"the lord of the rings\" will return \"The Lord of the Rings\").\n";

	string str;
	getline(cin, str, '\n');
	vector<string> v = my::tokenize(str, " ");

	// Capitalizes the first and last words no matter what
	v.front()[0] = toupper(v.front()[0]);
	v.back()[0] = toupper(v.back()[0]);

	str = "";

	for (auto it = v.begin(), itEnd = v.end(); it != itEnd; it++) {
		string tmp = *it;

		// Converts string to lowercase for comparison
		for (auto itTmp = tmp.begin(), itTmpEnd = tmp.end(); itTmp != itTmpEnd; itTmp++)
			*itTmp = tolower(*itTmp);

		// Checks word against list of non-capitalized words
		if (tmp != "the" && tmp != "and" && tmp != "but" && tmp != "of")
			(*it)[0]= toupper((*it)[0]);
		
		str = str + *it + " ";
	}

	// Removes trailing space added 
	str.pop_back();
	cout << str;

	return 0;
}