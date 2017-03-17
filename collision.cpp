/*
Oscar Yuengel
Given two axis-aligned bounding boxes, determines the area of their overlapping region.
*/

#include <iostream>
#include <string>
#include <vector>

#include "helpers.h"

using std::cout;
using std::cin;
using std::vector;
using std::string;

class AABB // axis-aligned bounding box
{
public:
	double getX();
	double getY();
	double getWidth();
	double getHeight();

	void setX(double x);
	void setY(double y);
	void setWidth(double width);
	void setHeight(double height);

	AABB();
	AABB(double x, double y, double width, double height);

private:
	double x_;
	double y_;
	double width_;
	double height_;
};

double calculateIntersection(AABB a, AABB b);

int main ()
{
	cout << "This program calculates the overlapping area of two rectangles.\n"
		 << "On one line, you will enter four numbers representing\n"
		 << "the top left x-coordinate, top left y-coordinate, width, and height,\n"
		 << "respectively, of each rectangle.\n\n";

	string str;
	vector<string> firstBox, secondBox;
	bool correctInput = false;

	do
	{
		cout << "Enter the first line.\n";

		getline(cin, str, '\n');

		firstBox = my::tokenize(str, " ");

		if (firstBox.size() != 4)
		{
			cout << "The input must contain four numbers.\n";
			continue;
		}
		for (auto it = firstBox.begin(), itEnd = firstBox.end(); it != itEnd; it++)
		{
			if ((*it).find_first_not_of("1234567890.") != string::npos)
			{
				cout << "The input must only contain numerals, spaces, and the decimal character.\n"; 
				correctInput = false;
				break;
			}
			correctInput = true;
		}

	} while (!correctInput);

	correctInput = false;

	do
	{
		cout << "Enter the second line.\n";

		getline(cin, str, '\n');

		secondBox = my::tokenize(str, " ");

		if (secondBox.size() != 4)
		{
			cout << "The input must contain four numbers.\n";
			continue;
		}
		for (auto it = secondBox.begin(), itEnd = secondBox.end(); it != itEnd; it++)
		{
			if ((*it).find_first_not_of("1234567890.") != string::npos)
			{
				cout << "The input must only contain numerals, spaces, and the decimal character.\n"; 
				correctInput = false;
				break;
			}
			correctInput = true;
		}

	} while (!correctInput);

	AABB a(my::stod(firstBox[0]),
		   my::stod(firstBox[1]),
		   my::stod(firstBox[2]),
		   my::stod(firstBox[3]));
	AABB b(my::stod(secondBox[0]),
		   my::stod(secondBox[1]),
		   my::stod(secondBox[2]),
		   my::stod(secondBox[3]));

	cout << calculateIntersection(a, b);

	return 0;
}

double AABB::getX() { return x_; }
double AABB::getY() { return y_; }
double AABB::getWidth() { return width_; }
double AABB::getHeight() { return height_; }

void AABB::setX(double x) { x_ = x; }
void AABB::setY(double y) { y_ = y; }
void AABB::setWidth(double width) { width_ = width; }
void AABB::setHeight(double height) { height_ = height; }

AABB::AABB() : 
	x_(0.0), y_(0.0), width_(0.0), height_(0.0)
	{
	}

AABB::AABB(double x, double y, double width, double height) :
	x_(x), y_(y), width_(width), height_(height)
	{
	}

double calculateIntersection(AABB a, AABB b)
{
	AABB shared;

	// Determine leftmost shared x coordinate
	if (a.getX() <= b.getX() && b.getX() < (a.getX() + a.getWidth())) // b.x within a's width
		shared.setX(b.getX());
	else if (b.getX() <= a.getX() && a.getX() < (b.getX() + b.getWidth())) // a.x within b's width
		shared.setX(a.getX());
	else // neither
		return 0;

	// Determine topmost shared y coordinate
	if (a.getY() <= b.getY() && b.getY() < (a.getY() + a.getHeight())) // b.y within a's height
		shared.setY(b.getY());
	else if (b.getY() <= a.getY() && a.getY() < (b.getY() + b.getHeight())) // a.y within b's height
		shared.setY(a.getY());
	else // neither
		return 0;

	// Determine width of shared AABB
	if (a.getX() + a.getWidth() < b.getX() + b.getWidth())
		shared.setWidth(a.getX() + a.getWidth() - shared.getX());
	else
		shared.setWidth(b.getX() + b.getWidth()- shared.getX());
	// Determine height
	if (a.getY() + a.getHeight() < b.getY() + b.getHeight())
		shared.setHeight(a.getY() + a.getHeight() - shared.getY());
	else
		shared.setHeight(b.getY() + b.getHeight() - shared.getY());

	// Return area
	return shared.getWidth() * shared.getHeight();
}