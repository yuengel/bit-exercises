/*
Oscar Yuengel
Gets a string from the user and returns the first location, if any, of the word "cat" as an ordinal.
Max string size is 200 words.
*/

#include <iostream>
#include <string>
#include <iterator>
#include <cctype>
#include <sstream> // to_string() fix for MinGW
using namespace std;

// Counts the number of words in a given string.
unsigned int countWords(string str);
// Returns the ordinal corresponding to the given integer (e.g. ordinal(1) returns "1st").
string ordinal (unsigned int num);

int main() {

	cout << "Enter a string of space-separated words that may contain the word \"cat.\"\n"
	     << "This program will find the location of \"cat\" if it exists. Max 200 words.\n";

	string box;

	getline(cin, box, '\n');

	if (box.empty()) 
	{
		cout << "There is no box.\n";
		return 0;
	}
	
	if (countWords(box) > 200)
	{
		cout << "The box is too large.\n";
		return 0;
	}

	unsigned int pos = 0;
	bool stillLooking = true;

	// Check that "cat" exists as a whole word
	while (stillLooking)
	{
		unsigned int cat = box.find("cat", pos);

		if (cat == string::npos)
		{
			cout << "There's no cat.\n";
			stillLooking = false;
			return 0;
		}
		else if ((cat == 0 || box[cat - 1] == ' ') && (cat + 3 == box.size() || box[cat + 3] == ' '))
		{
			pos = cat;
			stillLooking = false;
		}
		else
			pos = cat + 4;
	}

	unsigned int location = countWords(box.substr(0, pos)) + 1;

	cout << "The cat is the " << ordinal(location) << " item in the box.\n";

	return 0;
}
	
unsigned int countWords(string str) 
{
	unsigned int words = 0;
	bool ready = true;

	for (string::iterator it = str.begin(), itEnd = str.end(); it != itEnd; it++)
	{	
		if (ready == true && isalnum(*it))
		{
			++words;
			ready = false;
		}

		if (ready == false && *it == ' ')
			ready = true;
	}	

	return words;
}

string ordinal (unsigned int num)
{
	// to_string() workaround
	stringstream ss;
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