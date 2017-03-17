/*
Oscar Yuengel
Gets a string from the user and converts it into Title Case. String must consist of ASCII.
*/

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

int main()
{
	cout << "Enter an ASCII string. This program will convert the string into title case\n"
	     << "(e.g. \"the lord of the rings\" will return \"The Lord of the Rings\").\n";

	string str;

	getline(cin, str, '\n');

	vector<string> v = my::tokenize(str, " ");

	// Capitalize the first and last words no matter what
	v.front()[0] = toupper(v.front()[0]);
	v.back()[0] = toupper(v.back()[0]);

	str = "";

	for (vector<string>::iterator it = v.begin(), itEnd = v.end(); it != itEnd; it++)
	{
		// Convert string to lowercase for comparison
		string tmp = *it;

		for (string::iterator itTmp = tmp.begin(), itTmpEnd = tmp.end();
			 itTmp != itTmpEnd; itTmp++)
			*itTmp = tolower(*itTmp);
		// Ensure word is not meant to remain lowercase
		if (tmp != "the" && tmp != "and" && tmp != "but" && tmp != "of")
			(*it)[0]= toupper((*it)[0]);
		// Rebuild str
		str = str + *it + " ";
	}
	// Remove trailing space
	str.pop_back();

	cout << str;

	return 0;
}