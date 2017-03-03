/*
Oscar Yuengel
Implementation file for helper functions.
*/

#include "helpers.h" // includes <vector> and <string>

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