/*
Oscar Yuengel
Determines the degrees of separation between two individuals.
*/

#include <iostream>
#include <iterator>
#include <cstdlib>
#include "helpers.h" // <string>, <vector>, <limits>
using namespace std;

// Searches the matrix recursively for a connection between toSearch and toFind.
// Returns true if found, and the number of recursions is returned as degrees.
bool findConnection (vector<bool> matrix[], unsigned int size,
					 unsigned int toSearch, unsigned int toFind, int& degrees);

void printMatrix(vector<bool> matrix[], const unsigned int size);

int main()
{
	cout << "This program determines the degrees of separation between two individuals.\n\n"
		 << "First, enter the number of individuals to compare.\n";

	unsigned int matrixSize;
	
	cin >> matrixSize;
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	while (matrixSize < 2 || matrixSize > 100)
	{
		cout << "Please constrain your input to 2-100 individuals.\n";
		cin >> matrixSize;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	cout << "Next, enter the connections of each individual. The resulting matrix will look\n"
		 << "like this, given 3 individuals:\n"
		 << "[0, 1, 0]\n"
		 << "[1, 0, 1]\n"
		 << "[0, 1, 0]\n"
		 << "Each line represents an individual, and each number represents a connection\n"
		 << "to another individual. A 1 indicates they have a connection.\n"
		 << "A 0 indicates they do not.\n\n";

	vector<bool> population[matrixSize];
	
	for (unsigned int i = 0; i < matrixSize; i++)
	{
		bool correctInput;
		string str;
		vector<string> v;

		// Get matrix from user
		do
		{
			cout << "#" << i << ": ";
			correctInput = true;

			getline(cin, str, '\n');

			v = my::tokenize(str, " ");

			if (v.size() != matrixSize)
			{
				cout << "Incorrect number of entries. Try again.\n";
				correctInput = false;
				continue;
			}

			for (vector<string>::iterator it = v.begin(), itEnd = v.end(); it != itEnd; it++)
			{
				if ((*it).size() != 1)
				{
					cout << "Each entry should be separated by a space. Try again.\n";
					correctInput = false;
					break;
				}

				if ((*it).find_first_not_of("01") != string::npos)
				{
					cout << "Only 0 or 1 may be entered. Try again.\n";
					correctInput = false;
					break;
				}
			}

		} while (!correctInput);

		// Populate matrix
		for (vector<string>::iterator it = v.begin(), itEnd = v.end(); it != itEnd; it++)
		{
			if (*it == "1")
				population[i].push_back(true);
			else
				population[i].push_back(false);
		}
	}

	// An individual cannot have a connection with 'itself'
	for (unsigned int i = 0; i < matrixSize; i++)
		population[i].at(i) = 0;

	// Ensure matrix is symmetric; exit if not
	for (unsigned int i = 0; i < matrixSize; i++)
	{
		for (unsigned int j = 0; j < matrixSize; j++)
		{
			if (population[i].at(j) != population[j].at(i))
			{
				cout << "Okay, so I didn't explain this before, and I'm sorry for that, but\n"
					 << "the matrix you enter has to be symmetric. That means if you enter\n"
					 << "a 1 in the [0, 1] position, you also have to enter a 1 in the [1, 0] position.\n"
					 << "Think of it this way: If person A knows person B,\n"
					 << "person B must also know person A. It's that simple.\n"
					 << "Unfortunately you'll have to restart the program to correct this.\n";

					 exit(0);
			}
		}
	}
	
	unsigned int first, second;
	cout << "Finally, enter the first individual you want to compare.\n";

	cin >> first;

	while (first < 0 || first >= matrixSize)
	{
		cout << "Ensure your input is an integer from 0 to population-1.\n";
		cin >> first;
	}

	cout << "And the second individual.\n";

	cin >> second;

	while (second < 0 || second >= matrixSize)
	{
		cout << "Ensure your input is an integer from 0 to population-1.\n";
		cin >> second;
	}

	vector<bool> tmp[matrixSize];

	// Preserve original matrix
	for (unsigned int i = 0; i < matrixSize; i++)
	{
		for (unsigned int j = 0; j < matrixSize; j++)
			tmp[i].push_back(population[i].at(j));
	}

	int degrees = 0;
	bool found = findConnection(tmp, matrixSize, first, second, degrees);

	if (!found)
		cout << "-1\n";
	else
		cout << degrees << endl;

	return 0;
}

bool findConnection (vector<bool> matrix[], unsigned int size,
					 unsigned int toSearch, unsigned int toFind, int& degrees)
{
	degrees++;

	if (matrix[toSearch].at(toFind))
		return true;

	for (vector<bool>::iterator it = matrix[toSearch].begin(), itEnd = matrix[toSearch].end();
		 it != itEnd; it++)
	{
		if (*it)
		{
			// Set this entry and its symmetric entry to false to prevent infinite recursion
			*it = false;
			unsigned int curr = distance(matrix[toSearch].begin(), it);
			matrix[curr].at(toSearch) = false;

			bool found = findConnection(matrix, size, curr, toFind, degrees);

			if (found)
				return true;
		}
	}
	
	return false;
}

void printMatrix(vector<bool> matrix[], const unsigned int size)
{
	for (unsigned int i = 0; i < size; i++)
	{
		for (unsigned int j = 0; j < size; j++)
			cout << matrix[i].at(j) << " ";

		cout << endl;
	}
	cout << endl;
}