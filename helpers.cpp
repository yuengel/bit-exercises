/*
Oscar Yuengel
Implementation file for helper functions.
*/

#include "helpers.h" // <vector>, <string>

namespace my {

	std::vector<std::string> tokenize(const std::string str, const std::string delims)
	{
		std::vector<std::string> v;
		std::string tmp;
		int prev = 0;
		size_t location = str.find_first_of(delims, prev);
		
		while (location != std::string::npos)
		{
			tmp = str.substr(prev, location - prev);
			// ensure token exists
			if (!tmp.empty())
				v.push_back(tmp);

			prev = location + 1;
			location = str.find_first_of(delims, prev);
		}
		// last token
		tmp = str.substr(prev);

		if (!tmp.empty())
			v.push_back(tmp);

		return v;
	}

	int stoi(const std::string str)
	{
		// Invalid characters
		if (str.find_first_not_of("-1234567890 ") != std::string::npos)
			throw std::invalid_argument("str must contain a valid integer.\n");

		std::stringstream ss;
		long long int llNum;
		
		ss.str(str);
		ss >> llNum >> std::ws; // captures trailing whitespace
		// More than one integer entered
		if (!ss.eof())
			throw std::invalid_argument("str must contain a single valid integer.\n");

		if (llNum > std::numeric_limits<int>::max() ||
			llNum < std::numeric_limits<int>::min())
			throw std::out_of_range("str must contain an integer within int range.\n");

		int num = llNum;

		return num;
	}
}