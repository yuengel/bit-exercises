/*
Oscar Yuengel
Given an array of hotel rooms, returns whether a group can be booked in consecutive rooms.
*/

#include <iostream>
#include <string>
#include <iterator>
#include <cctype>
#include <sstream> // stoi() fix for MinGW
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

		// Ensure exactly two non-zero integers have been entered
		string strFloors, strRooms;
		bool floorsFull = false, roomsFull = false, tooManyInts = false;
		
		for (string::iterator it = str.begin(), itEnd = str.end(); it != itEnd; it++)
		{
			if (isdigit(*it))
			{
				if (!floorsFull)
					strFloors += *it;
				else if (!roomsFull)
					strRooms += *it;
				else
				{
					cout << "Invalid input.\n"; // has too many integers
					tooManyInts = true;
					break;
				}
			}
			else 
			{
				if (!strFloors.empty())
					floorsFull = true;
				if (!strRooms.empty())
					roomsFull = true;
			}
		}
		// End-of-string case
		if (!strRooms.empty())
			roomsFull = true;

		if (tooManyInts)
			continue;

		if (!floorsFull || !roomsFull)
			cout << "Invalid input.\n"; // has too few integers
		else
			{
				// stoi() workaround
				stringstream ss;
				ss.str(strFloors);
				ss >> floors;
				ss.clear();
				ss.str(strRooms);
				ss >> rooms;
				ss.clear();

				if (floors == 0 || rooms == 0)
					cout << "Invalid input.\n"; // both integers must be positive
				else
					correctInput = true; // loop exit
			}			

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