/**************
* Oscar Yuengel
*
* Given a string representing a valid Roman numeral, calculates its value.
*************************************************************************/

#include <iostream>
#include <string>
#include <iterator>

using std::cout;
using std::cin;
using std::endl;
using std::string;

const unsigned int VALUE_OF_M = 1000;
const unsigned int VALUE_OF_D = 500;
const unsigned int VALUE_OF_C = 100;
const unsigned int VALUE_OF_L = 50;
const unsigned int VALUE_OF_X = 10;
const unsigned int VALUE_OF_V = 5;
const unsigned int VALUE_OF_I = 1;

// Calculates the integer value of a given Roman numeral string. Returns -1 if string is invalid.
int romanNumeral(string str);

int main() {

	cout << "Enter a valid Roman numeral and this program will calculate its value.\n";

	string str;
	getline(cin, str, '\n');
	int numeral = romanNumeral(str);

	while (numeral == -1) {
		cout << "You must enter a valid Roman numeral.\n";
		getline(cin, str, '\n');
		numeral = romanNumeral(str);
	}

	cout << numeral << endl;

	return 0;
}

int romanNumeral(string str) {
	if (str.find_first_not_of("MDCLXVI") != string::npos)
		return -1;

	unsigned int numeral = 0;
	unsigned int maximum = VALUE_OF_M;

	for (auto it = str.begin(), itEnd = str.end(); it != itEnd; ++it) {
		switch (*it) {
			case 'M':
				if (maximum < VALUE_OF_M)
					return -1;
				
				numeral += VALUE_OF_M;
			break;

			case 'D':
				if (maximum < VALUE_OF_D)
					return -1;

				// String already has a lone D
				if (numeral % VALUE_OF_M == VALUE_OF_D)
					return -1;
				
				numeral += VALUE_OF_D;
				maximum = VALUE_OF_D;
			break;

			case 'C': {
				auto itTmp = next(it);

				if (itTmp != itEnd && *itTmp == 'M') {  // case CM
					if (maximum < VALUE_OF_M)
						return -1;

					numeral += (VALUE_OF_M - VALUE_OF_C);
					maximum = VALUE_OF_L;
					++it;
					break;
				}
				
				if (itTmp != itEnd && *itTmp == 'D') {  // case CD
					if (maximum < VALUE_OF_M)
						return -1;

					numeral += (VALUE_OF_D - VALUE_OF_C);
					maximum = VALUE_OF_L;
					++it;
					break;
				}

				if (maximum < VALUE_OF_C)
					return -1;

				// String already has three lone Cs
				if (numeral % VALUE_OF_D == 3 * VALUE_OF_C)
					return -1;

				numeral += VALUE_OF_C;
				maximum = VALUE_OF_C;
			} break;

			case 'L':
				if (maximum < VALUE_OF_L)
					return -1;

				// String already has a lone L
				if (numeral % VALUE_OF_C == VALUE_OF_L)
					return -1;
				
				numeral += VALUE_OF_L;
				maximum = VALUE_OF_L;
			break;

			case 'X': {
				auto itTmp = next(it);

				if (itTmp != itEnd && *itTmp == 'C') {  // case XC
					if (maximum < VALUE_OF_C)
						return -1;

					numeral += (VALUE_OF_C - VALUE_OF_X);
					maximum = VALUE_OF_V;
					++it;
					break;
				}
				
				if (itTmp != itEnd && *itTmp == 'L') {  // case XL
					if (maximum < VALUE_OF_C)
						return -1;

					numeral += (VALUE_OF_L - VALUE_OF_X);
					maximum = VALUE_OF_V;
					++it;
					break;
				}

				if (maximum < VALUE_OF_X)
					return -1;

				// String already has three lone Xs
				if (numeral % VALUE_OF_L == 3 * VALUE_OF_X)
					return -1;

				numeral += VALUE_OF_X;
				maximum = VALUE_OF_X;
			} break;

			case 'V':
				if (maximum < VALUE_OF_V)
					return -1;

				// String already has a lone V
				if (numeral % VALUE_OF_X == VALUE_OF_V)
					return -1;
				
				numeral += VALUE_OF_V;
				maximum = VALUE_OF_V;
			break;

			case 'I': {
				auto itTmp = next(it);

				if (itTmp != itEnd && *itTmp == 'X') {  // case IX
					if (maximum < VALUE_OF_X)
						return -1;

					numeral += (VALUE_OF_X - VALUE_OF_I);
					maximum = 0;
					++it;
					break;
				}
				
				if (itTmp != itEnd && *itTmp == 'V') {  // case IV
					if (maximum < VALUE_OF_X)
						return -1;

					numeral += (VALUE_OF_V - VALUE_OF_I);
					maximum = 0;
					++it;
					break;
				}

				if (maximum < VALUE_OF_I)
					return -1;

				// String already has three lone Is
				if (numeral % VALUE_OF_V == 3 * VALUE_OF_I)
					return -1;

				numeral += VALUE_OF_I;
				maximum = VALUE_OF_I;
			} break;
		}
	}

	return numeral;
}