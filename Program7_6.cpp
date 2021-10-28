/*
Number Game

Programmer: James Jahraus

Course: CSC160-141 Computer Science I C++ Fall 2021

Submission Date: 2021-10-27

Write a program that uses a random number generator to generate a two digit
positive integer and allows the user to perform one or more of the
following operations:

a. Double the number.

b. Reverse the digits of the number.

c. Raise the number to the power of 2, 3, or 4.

d. Sum the digits of the number.

e. If the number is a two-digit number, then raise the first digit to the
power of the second digit.

f. If the number is a three-digit number and the last digit is less than or
equal to 4, then raise the first two digits to the power of the last digit.

After performing an operation if the number is less than 10, add 10 to the
number. Also, after each operation determine if the number is prime.

Each successive operation should be performed on the number generated
by the last operation. Your program should not contain any global variables
and each of these operations must be implemented by a separate function.

Also, your program should be menu driven.
*/

// import io library
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <random>

// use standard namespace
using namespace std;

// choose function
enum chooseFunction {
	doubleN, reverseN, powerN, sumDs, twoDs, threeDs, invalidFunction
};

// function prototypes
bool primeCheck(int n);
int doubleNumber(int n); // a. Double the number.
int reverseNumber(int n); // b. Reverse the digits of the number.
int powerNumber(int n); // c. Raise the number to the power of 2, 3, or 4.
int sumDigits(int i); // d. Sum the digits of the number.
int twoDigit(int n); // e. If the number is a two-digit number, then raise the first digit to the power of the second digit.
int threeDigit(int n); // f. If the number is a three - digit number and the last digit is less than or equal to 4, then raise the first two digits to the power of the last digit.
void displayChoices();
chooseFunction getFun(char choice);
int runFun(chooseFunction, int n);


int main()
{
	// declair variables
	int n;
	char selection = '0';
	chooseFunction cf;
	
	// Generate a random number between 1 and 99

	// Get system time
	int seed = time(0);

	// Seed random number gen
	srand(seed);
	n = 1 + rand() % 99;

	// explain program
	cout << "Enter # to stop the program." << endl;
	cout << "This program performs operations on this number:" << endl;
	cout << n << endl;

	// main game loop
	while (selection != '#')
	{
		// input a choice
		displayChoices();
		cin >> selection;

		// get the function and run it
		cf = getFun(selection);

		// validate input
		if (cf == invalidFunction)
		{
			cout << "Please choose a valid operation, enter # to stop the program." << endl;
		}
		else
		{
			// run the correct function
			n = runFun(cf, n);
		}

		// Output current state: 
		cout << "The number is now: " << n << endl;

		//After performing an operation if the number is less than 10, add 10 to the number.
		if (n < 10)
		{
			cout << n << " is too small I will add 10!" << endl;
			n = n + 10;
		}

		//Check Prime
		if (primeCheck(n))
		{
			cout << n << " is a prime number!" << endl;
		}
		else
		{
			cout << n << " is not prime number!" << endl;
		}
		cout << endl;
	}
}

// Shows the user possible functions to call on the number
void displayChoices()
{
	cout << endl;
	cout << "D: double the number" << endl;
	cout << "R: reverse the number" << endl;
	cout << "P: raise the number to the power of 2, 3 or 4" << endl;
	cout << "S: sum all the digits" << endl;
	cout << "T: two digit surprize - warning only use on two digit numbers!" << endl;
	cout << "C: three digit surprize - warning only use on three digit numbers! Buggy need to fix this one!" << endl;
	cout << "Choose an opperation." << endl;
}

// returns correct function id: doubleN, reverseN, powerN, sumDs, twoDs, threeDs, invalidFunction
chooseFunction getFun(char choice)
{
	switch (choice)
	{
	case 'D':
		return doubleN;
	case 'R':
		return reverseN;
	case 'P':
		return powerN;
	case 'S':
		return sumDs;
	case 'T':
		return twoDs;
	case 'C':
		return threeDs;
	default:
		return invalidFunction;
	}
}

// runs the correct function and returns int answer
// function id : doubleN, reverseN, powerN, sumDs, twoDs, threeDs, invalidFunction
int runFun(chooseFunction fn, int n)
{
	// declair the answer var
	int ans = 0;

	switch (fn)
	{
	case doubleN:
		ans = doubleNumber(n);
		break;
	case reverseN:
		ans = reverseNumber(n);
		break;
	case powerN:
		ans = powerNumber(n);
		break;
	case sumDs:
		ans = sumDigits(n);
		break;
	case twoDs:
		ans = twoDigit(n);
		break;
	case threeDs:
		ans = threeDigit(n);
	// return 0 if there is some problem
	default:
		cout << "Critical error, enter # to stop the program!" << endl;
		return 0;
	}
	return ans;
}

// An even number is prime if it is 2. An odd integer
// is prime if it is not divisible by any odd integer
// less than or equal to the square root of the number.
bool primeCheck(int n)
{
	// less than 2 is not prime
	if (n < 2)
	{
		return false;
	}
	// 2 is prime
	else if (n == 2)
	{
		return true;
	}
	// remaining even are not prime
	else if ((n % 2) == 0)
	{
		return false;
	}
	// An odd integer is prime if it is not divisible by any odd integer less than or equal to the square root of the number.
	else
	{
		for (int i = 2; i <= sqrt(n); i++)
			if (n % i == 0)
				return false;
		return true;
	}
}

// double the number
int doubleNumber(int n)
{
	int d;
	d = n * 2;
	return d;
}

// reverse the order of the number
int reverseNumber(int n)
{
	// remove any possible negative numbers
	int pn = abs(n);

	// simple string converstion
	string s = to_string(pn);

	// reverse string using algorithm library
	reverse(s.begin(), s.end());

	// return the reversed string as an int
	return stoi(s);
}

// Raise the number to the power of 2, 3, or 4.
int powerNumber(int n)
{
	int max = 4;
	int min = 2;
	int p = rand() % (max - min + 1) + min;

	// tell user what power was chosen
	cout << "random power is: " << p << endl;

	double ans;
	ans = pow(n, p);
	return (int)ans;
}

// sum all the digits in the number
int sumDigits(int i)
{
	int mod;
	int sum = 0;
	// iterate through the integer using mod stop at zero
	while (i != 0)
	{
		mod = i % 10;
		sum = sum + mod;
		i = i / 10;
	}
	return sum;
}

// raise the first digit to the power of the second digit
// only input two digit numbers
int twoDigit(int n)
{
	// remove any possible negative numbers
	int pn = abs(n);

	// simple string converstion
	string s = to_string(pn);

	// convert to chars
	char ch1 = (s[0] - '0');
	char ch2 = (s[1] - '0');

	// convert to ints
	int x = (int)ch1;
	int y = (int)ch2;

	// find the ans x^y and return it
	return (int)pow(x,y);
}

// f. If the number is a three - digit number and the last digit is less than or equal to 4, then raise the first two digits to the power of the last digit.
// only input three digit numbers
int threeDigit(int n)
{
	// remove any possible negative numbers
	int pn = abs(n);

	// simple string converstion
	string s = to_string(pn);

	// convert to chars
	char ch1 = (s[0] - '0');
	char ch2 = (s[1] - '0');
	char ch3 = (s[2] - '0');

	// convert to ints
	int x = (int)ch1;
	int y = (int)ch2;
	int z = (int)ch3;

	// assemble first two digits back to an int
	int xy = (x * 10) + y;

	// if last digit is less than or equal to 4
	if (z <= 4)
	{
		// raise the first two digits to the power of the last digit
		return (int)pow(xy, z);
	}
	else {
		return n;
	}
}