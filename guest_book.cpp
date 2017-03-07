/*
Oscar Yuengel
Given an array of hotel rooms, returns whether a group can be booked in consecutive rooms.
*/

#include <iostream>
#include <string>
#include <iterator>
#include <cctype>
#include <sstream> // stoi() fix for MinGW
#include "helpers.h"
using namespace std;

int main()
{
	cout << "This program determines whether a group can book hotel rooms contiguously.\n\n";

	string str;
	unsigned int floors = 0, rooms = 0;
	bool correctInput = false;

	// Prompt user for hotel size; reprompts in case of improper input
	do {

	 	cout << "Enter two integers representing the number of floors\n"
	 		 << "and number of rooms per floor:\n";

		getline(cin, str, '\n');

		// Ensure only integers have been entered
		bool hasOnlyIntegers = true;
		
		for (string::iterator it = str.begin(), itEnd = str.end(); it != itEnd; it++)
		{
			if (!isspace(*it) && !isdigit(*it))
			{
				cout << "Invalid input.\n"; // has invalid characters
				hasOnlyIntegers = false;
				break;
			}
		}

		if (!hasOnlyIntegers)
			continue;

		vector<string> v = tokenize(str, " ");

		if (v.size() != 2)
		{
			cout << "Invalid input.\n"; // incorrect number of integers
			continue;
		}

		// stoi() workaround
		stringstream ss;
		ss.str(v[0]);
		ss >> floors;
		ss.clear();
		ss.str(v[1]);
		ss >> rooms;
		ss.clear();

		if (floors == 0 || rooms == 0)
			cout << "Invalid input.\n"; // both integers must be positive
		else
			correctInput = true; // loop exit

	} while (!correctInput);

	// Populate hotel
	bool hotel[floors][rooms];

	cout << "Enter the hotel's occupancy line by line.\n"
		 << "1 indicates a room is full, and 0 indicates a room is empty.\n";

	for (unsigned int i = 0; i < floors; i++)
	{
		do 
		{
			cout << "Floor " << i + 1 << ": ";

			getline(cin, str, '\n');

			if (str.length() != rooms)
			{
				correctInput = false;
				cout << "Invalid input.\n"; // wrong number of rooms
				continue;
			}

			for (string::iterator it = str.begin(), itEnd = str.end(); it != itEnd; it++)
			{
				if (*it != '1' && *it != '0')
				{
					correctInput = false;
					cout << "Invalid input.\n"; // char other than 0 or 1 entered
					break;
				} 
				if (*it == '1')
				{
					correctInput = true;
					hotel[i][distance(str.begin(), it)] = true;
				}
				else
				{
					correctInput = true;
					hotel[i][distance(str.begin(), it)] = false;
				}
			}

		} while (!correctInput);
	}

	// Prompts user for group size; assumes positive integer input
	unsigned int groupSize = 0;

	do
	{
		cout << "Enter the number of rooms the group requires.\n";

		cin >> groupSize;

		if (groupSize == 0)
			cout << "Invalid input.\n"; // integer must be nonzero

	} while (groupSize <= 0);

	// Impossible to fit group on single floor
	if (groupSize > rooms)
	{
		cout << "0\n";
		return 0;
	}

	// Scan hotel for groupSize contiguous block of rooms
	for (unsigned int i = 0; i < floors; i++)
	{
		unsigned int emptyRooms = 0;

		for (unsigned int j = 0; j < rooms; j++)
		{
			if (!hotel[i][j])
			{
				emptyRooms++;

				if (emptyRooms == groupSize)
				{
					cout << "1\n"; // no block found
					return 0;
				}
			}
			else
				emptyRooms = 0;
		}
	}

	cout << "0\n"; // no block found
	return 0;
}