/*
Oscar Yuengel
Determines whether a cat will run out of food.
*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	cout << "This program determines whether or not your cat will run out of fish,\n"
		 << "and on which day it will do so (zero-indexed).\n\n";

	int fish;
	do
	{
		cout << "How many fish does your cat start with?\n";
		cin >> fish;

	} while (fish < 0);

	int days;
	do
	{
		cout << "Okay, how many days does your cat plan to eat fish?\n";
		cin >> days;
		
	} while (days < 0);

	int fishOnDay[days];
	for (int i = 0; i < days; i++)
	{
		do
		{
			cout << "How many fish does your cat plan to eat on day " << i << "?\n";
			cin >> fishOnDay[i];

		} while (fishOnDay[i] < 0);
	}

	int fishLeft = fish;
	for (int i = 0; i < days; i++)
	{
		fishLeft -= fishOnDay[i];

		if (fishLeft < 0)
		{
			cout << i << endl; // the day the cat will run out of food
			break;
		}
	}

	if (fishLeft >= 0)
		cout << "Happy cat!\n";

	return 0;
}