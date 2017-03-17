/*
Oscar Yuengel
Gets a string from the user and returns the first location, if any, of the word "cat" as an ordinal.
Max string size is 200 words.
*/

#include <iostream>
#include <iterator>
#include <cctype>
#include <sstream> // to_string() fix for MinGW

#include "helpers.h" 

using std::cout;
using std::cin;
using std::string;
using std::vector;

// Returns the ordinal corresponding to the given integer (e.g. ordinal(1) returns "1st").

string ordinal (unsigned int num);

int main()
{
	cout << "Enter a string of space-separated words that may contain the word \"cat.\"\n"
	     << "This program will find the location of \"cat\" if it exists. Max 200 words.\n";

	string str;

	getline(cin, str, '\n');
	// No string entered
	if (str.empty()) 
	{
		cout << "There is no box.\n";
		return 0;
	}

	vector<string> box = my::tokenize(str, " ");
	// Too many words
	if (box.size() > 200)
	{
		cout << "The box is too large.\n";
		return 0;
	}

	bool found = false;

	for (auto it = box.begin(), itEnd = box.end(); it != itEnd; it++)
	{
		// Convert string to lowercase for comparison
		string tmp = *it;

		for (auto itTmp = tmp.begin(), itTmpEnd = tmp.end(); itTmp != itTmpEnd; itTmp++)
			*itTmp = tolower(*itTmp);
		// Find first instance of "cat"
		if (tmp == "cat")
		{
			cout << "The cat is the " << ordinal(distance(box.begin(), it) + 1)
				 << " item in the box.\n";
			found = true;
			break;
		}
	}

	if (!found)
		cout << "There's no cat.\n";

	return 0;
}

string ordinal (unsigned int num)
{
	// to_string() workaround
	std::stringstream ss;
	ss << num;
	string s = ss.str();

	if ((num / 10) % 10 == 1)
		s += "th";
	else if (num % 10 == 1)
		s += "st";
	else if (num % 10 == 2)
		s += "nd";
	else if (num % 10 == 3)
		s += "rd";
	else
		s += "th"; 

	return s;
}