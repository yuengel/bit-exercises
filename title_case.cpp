/*
Oscar Yuengel
Gets a string from the user and converts it into Title Case. String must consist of ASCII.
*/

#include <iostream>
#include <string>
#include <iterator>
#include <cctype>
using namespace std;

int main()
{
	cout << "Enter an ASCII string. This program will convert the string into title case\n"
	     << "(e.g. \"the lord of the rings\" will return \"The Lord of the Rings\").\n";

	string str;

	getline(cin, str, '\n');

	bool firstWord = true, firstLetter = true;

	for (string::iterator it = str.begin(), itEnd = str.end(); it != itEnd; it++)
	{
		// Reset new word flag
		if (isspace(*it))
			firstLetter = true;
		// Capitalize the first word no matter what
		else if (firstWord)
		{
			*it = toupper(*it);
			firstWord = false;
			firstLetter = false;
		}
		else if (firstLetter)
		{
			unsigned int index = distance(str.begin(), it);
			unsigned int wordEnd = str.find(' ', index);
			// Capitalize the last word no matter what (i.e. no more spaces were found)
			if (wordEnd == string::npos)
				*it = toupper(*it);
			else
			{
				string tmp = str.substr(index, wordEnd - index);
				// Convert substring to lowercase for comparison
				for (string::iterator itTmp = tmp.begin(), itTmpEnd = tmp.end();
					 itTmp != itTmpEnd; itTmp++)
					*itTmp = tolower(*itTmp);
				// Ensure word is not meant to remain lowercase
				if (tmp != "the" && tmp != "and" && tmp != "but" && tmp != "of")
					*it = toupper(*it);
			}

			firstLetter = false;
		}
	}

	cout << str;

	return 0;
}