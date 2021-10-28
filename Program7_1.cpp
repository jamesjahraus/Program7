/*
Triangle Classification

Programmer: James Jahraus

Course: CSC160-141 Computer Science I C++ Fall 2021

Submission Date: 2021-10-27

a. Define an enumeration type triangleType that has the values scalene,
isosceles, equilateral, and noTriangle.

b. Write a function triangleShape that takes as parameters three numbers,
each of which represents the length of a side of the triangle. The function
should return the shape of the triangle. (Note: In a triangle, the sum of the
lengths of any two sides is greater than the length of the third side.)

c. Write a program that prompts the user to input the length of the sides
of a triangle and outputs the shape of the triangle.
*/

// import libraries
#include <iostream>
#include <algorithm>

// use standard namespace
using namespace std;

// enums
enum triangleType {
	scalene, isosceles, equilateral, noTriangle
};

// function prototypes
triangleType triangleShape(double sideLengths[], int size);

int main()
{
	// initialize inputs array
	const int SIZE = 3;
    double sideInputs[SIZE];
	triangleType t;

	// explain program
	cout << "This program classifies a triangle based on the side lenghts input." << endl;

	// input side lenghts
    for (int i = 0; i < SIZE; i++)
    {
		cout << "Input the value for side " << i + 1 << " :" << endl;
		cin >> sideInputs[i];
    }

	// determine triangle shape
	t = triangleShape(sideInputs, SIZE);

	// output results
	switch (t)
	{
	case scalene:
		cout << "The triangle shape is scalene." << endl;
		break;
	case isosceles:
		cout << "The triangle shape is isosceles." << endl;
		break;
	case equilateral:
		cout << "The triangle shape is equilateral." << endl;
		break;
	case noTriangle:
		cout << "This is not a triangle sorry!" << endl;
	default:
		cout << "Unknown errror occured!" << endl;
	}
}


// returns triangle classification scalene, isosceles, equilateral, or noTriangle
triangleType triangleShape(double sideLengths[], int size)
{
	// In a triangle, the sum of the lengths of any two sides is greater than the length of the third side.
	if ((sideLengths[0] + sideLengths[1]) > sideLengths[2])
	{
		if (sideLengths[0] == sideLengths[1] && sideLengths[0] == sideLengths[2])
		{
			return equilateral;
		}
		else if (sideLengths[0] != sideLengths[1] && sideLengths[0] != sideLengths[2] && sideLengths[1] != sideLengths[2])
		{
			return scalene;
		}
		else if (sideLengths[0] == sideLengths[1] || sideLengths[0] == sideLengths[2] || sideLengths[1] == sideLengths[2])
		{
			return isosceles;
		}
	}
	else {
		return noTriangle;
	}
}