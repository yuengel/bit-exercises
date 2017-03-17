/*
Oscar Yuengel
Prints a string, one word per line, encircled by a frame.
*/

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <cstdlib>

#include "helpers.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

const int PADDING = 4;
const char FRAME_CHAR = '#';
const int MAX_WORD_LENGTH = 76; // cmd size (80) - PADDING

int main()
{
	cout << "Enter a string.\n";

	string str;

	getline(cin, str, '\n');

	vector<string> v = my::tokenize(str, " ");
	unsigned int longest = 0;

	for (auto it = v.begin(), itEnd = v.end(); it != itEnd; it++)
	{
		unsigned int size = (*it).size();

		if (size > MAX_WORD_LENGTH)
		{
			cout << "Whoops, you entered a really long word!\n"
				 << "Better just end the program now\n"
				 << "rather than stretch the command prompt to fit it on one line.\n";

			exit(0);
		}

		if (size > longest)
			longest = size;
	}

	cout << longest << endl;

	longest += PADDING;

	for (unsigned int i = 0; i < longest; i++)
		cout << FRAME_CHAR;

	cout << endl;

	for (auto it = v.begin(), itEnd = v.end(); it != itEnd; it++)
	{
		// Print left frame and word
		cout << FRAME_CHAR << " " << *it;
		// Print right spaces as necessary
		unsigned int spacesLeft = longest - ((*it).size() + PADDING);
		while (spacesLeft > 0)
			{
				cout << " ";
				spacesLeft--;
			}
		// Print right frame
		cout << " " << FRAME_CHAR << " \n";
	}

	for (unsigned int i = 0; i < longest; i++)
		cout << FRAME_CHAR;

	return 0;
}