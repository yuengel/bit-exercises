/**************
* Oscar Yuengel
*
* Given a string from the user,
* prints the string, one word per line, encircled by a frame.
* Max word size is 76 characters.
********************************/

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
const int MAX_WORD_LENGTH = 76;  // necessary to fit into command prompt window

int main() {

	cout << "Enter a string.\n";

	string str;
	unsigned int longestWord = 0;
	getline(cin, str, '\n');
	vector<string> v = my::tokenize(str, " ");
	
	for (auto it = v.begin(), itEnd = v.end(); it != itEnd; ++it) {
		unsigned int size = (*it).size();

		if (size > MAX_WORD_LENGTH) {
			cout << "Whoops, you entered a really long word!\n"
				 << "Better just end the program now\n"
				 << "rather than stretch the command prompt to fit it on one line.\n";

			exit(0);
		}

		if (size > longestWord)
			longestWord = size;
	}

	longestWord += PADDING;

	for (unsigned int i = 0; i < longestWord; i++)
		cout << FRAME_CHAR;

	cout << endl;

	for (auto it = v.begin(), itEnd = v.end(); it != itEnd; ++it) {
		cout << FRAME_CHAR << " " << *it;
		
		unsigned int spacesLeft = longestWord - ((*it).size() + PADDING);

		while (spacesLeft > 0) {
				cout << " ";
				spacesLeft--;
			}
		
		cout << " " << FRAME_CHAR << " \n";
	}

	for (unsigned int i = 0; i < longestWord; i++)
		cout << FRAME_CHAR;

	return 0;
}