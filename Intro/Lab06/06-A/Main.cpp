/* Christopher King
Section 1023
A program that calculates an item's retail price
02/28/12 19:03 - 19:12 Started and finished Main 
and dCalculateRetail functions

02/28/12 19:20 - 19:28 added (and tested) input validation*/
#include <iostream>
#include <iomanip>
using namespace std;

//prototype
double dCalculateRetail(double, double);

int main()
{
	double dWhole, dMark, dPrice;

	//prompts
	cout << "Please enter the WholeSale Cost:\n";
	cin >> dWhole;
	
	//input validation
	while (dWhole < 0)
	{
		cout << "Invalid input. Cost can not be a negative number.\n"
			<< "Please enter the WholeSale Cost:\n";
		cin >> dWhole;
	}
	
	//prompts
	cout << "Please enter the Markup Percentage (in decimal form):\n";
	cin >> dMark;
	
	//input validation
	while (dMark < 0)
	{
		cout << "Invalid input. Markup Percentage can not be a negative number"
			<< ".\nPlease enter the Markup Percentage (in decimal form):\n";
		cin >> dMark;
	}

	//function call
	dPrice = dCalculateRetail(dWhole, dMark);
	
	//display price
	cout << fixed << setprecision(2);
	cout << "The Retail price is:\n\t\t\t$" << dPrice << endl;
	system("pause");
	return 0;
}

//function definition
double dCalculateRetail(double dWhole, double dMark)
{
	//local scoped price
	double dPrice;

	//calculations
	dPrice = dWhole + (dWhole * dMark);

	//return the price
	return dPrice;
}