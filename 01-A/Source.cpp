// A simple program that Calculates the funds earned during a fundraiser
#include <iostream>
using namespace std;

int main()
{
	// dbars = number of bars sold, dpriceEach = Price of each bar, dtotal = total $ earned
	double dbars, dpriceEach, dtotal;

	// Get the number of Candy Bars sold from the user.
	cout << "How many Candy Bars were sold?" << endl;
	cin >> dbars;

	// Get the Price Per Bar
	cout << "How much was each Candy bar sold for?" << endl;
	cin >> dpriceEach;

	// Calcutale the total earned.
	dtotal = dbars * dpriceEach;

	// Display the total amount earned
	cout << "The total amount earned is $" << dtotal << endl;
	return 0;
}