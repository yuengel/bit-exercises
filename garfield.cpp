/**************
* Oscar Yuengel
*
* Given Garfield's initial hunger level
* and the hunger-reducing and happiness-increasing levels of a group of food items,
* returns Garfield's maximum happiness after eating all the items.
* Maximum number of food items is 30.
************************************/

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <iterator>
#include <limits>

#include "helpers.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::tuple;

const int UNDERFED_PENALTY = 10;
const int OVERFED_PENALTY = 20;

int main() {

	cout << "Garfield is hungry. How hungry would you say he is?\n"
		 << "Enter an integer.\n";

	string str;
	getline(cin, str, '\n');
	int hunger = my::stoi(str);

	cout << "Jon goes to the store to buy Garfield some food.\n"
		 << "How many items of food does he buy?\n";

	getline(cin, str, '\n');
	unsigned int numItems = my::stoi(str);

	while (numItems < 1 || numItems > 30) {
		cout << "That's not right. Garfield probably needs between 1 and 30 items of food.\n"
			 << "Try that again.\n";

		getline(cin, str, '\n');
		numItems = my::stoi(str);
	}

	vector<tuple<int, int>> foods;

	cout << "Each item of food makes Garfield a little less hungry and a little more happy.\n"
		 << "Enter two numbers for each item representing\n"
		 << "how much Garfield's hunger is reduced\n"
		 << "and how much happier Garfield becomes after eating it.\n";

	while (foods.size() < numItems) {
		getline(cin, str, '\n');
		vector<string> v = my::tokenize(str, " ,");
		int itemHunger = my::stoi(v.at(0));
		int itemHappiness = my::stoi(v.at(1));
		tuple<int, int> food = std::make_tuple(itemHunger, itemHappiness);
		foods.push_back(food);
	}
	
	int happiness = 0; 
	int maximumHappiness = std::numeric_limits<int>::min();
	int modifiedHappiness;

	for (auto it = foods.begin(), itEnd = foods.end(); it != itEnd; it++) {
		hunger -= std::get<0>(*it);
		happiness += std::get<1>(*it);
		modifiedHappiness = happiness;

		if (hunger > 0)
			modifiedHappiness = modifiedHappiness - (UNDERFED_PENALTY * hunger);
		else
			modifiedHappiness = modifiedHappiness + (OVERFED_PENALTY * hunger);

		if (modifiedHappiness > maximumHappiness)
			maximumHappiness = modifiedHappiness;
	}

	cout << maximumHappiness << endl;

	return 0;
}