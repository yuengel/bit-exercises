/**************
* Oscar Yuengel
*
* Given a string representing an algebraic sum of integers,
* parses it and finds its value.
* Accepts only + and - as operators.
***********************************/

#include <iostream>
#include <string>
#include <iterator>
#include <sstream>  // stoi() fix for MinGW

using std::cout;
using std::cin;
using std::string;
using std::stringstream;

int main() {

	cout << "This program determines the sum of an algebraic expression of integers.\n\n"
		 << "Enter a string representing such an expression.\n"
		 << "The program assumes a valid expression consisting only of (0,9), +, -, and SPACE.\n"
		 << "Please use care.\n";

	string str, tmpString = "";
	int sum = 0, tmp = 0;
	bool add = true;
	getline(cin, str, '\n');

	for (auto it = str.begin(), itEnd = str.end(); it != itEnd; it++) {
		switch (*it) {
			case '+': {
				if (!tmpString.empty()) {
					// stoi() workaround
					stringstream ss;
					ss.str(tmpString);
					ss >> tmp;
					ss.clear();

					tmpString = "";

					if (add)
						sum += tmp;
					else
						sum -= tmp;
				}

				add = true;
			} break;

			case '-': {
				if (!tmpString.empty())
				{
					// stoi() workaround
					stringstream ss;
					ss.str(tmpString);
					ss >> tmp;
					ss.clear();

					tmpString = "";

					if (add)
						sum += tmp;
					else
						sum -= tmp;
				}

				add = false;
			} break;

			case ' ': {
				if (!tmpString.empty())
				{
					// stoi() workaround
					stringstream ss;
					ss.str(tmpString);
					ss >> tmp;
					ss.clear();

					tmpString = "";

					if (add)
						sum += tmp;
					else
						sum -= tmp;
				}
			} break;

			// Executes in case of numeral
			default: {
				tmpString += *it;
			} break;
		}
	}

	if (!tmpString.empty()) {
		// stoi() workaround
		stringstream ss;
		ss.str(tmpString);
		ss >> tmp;
		ss.clear();

		tmpString = "";

		if (add)
			sum += tmp;
		else
			sum -= tmp;
	}

	cout << sum;

	return 0;
}