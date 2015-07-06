/*Christopher King
Section 1023
A simple program that uses loops to calculate a person's pay*/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//initialize the variables
	double dPay = .01, dTotal = 0;
	int iDays;

	//set it to display 2 deicmal places
	cout << fixed << setprecision(2);

	//Prompt the user for how many days they worked
	cout << "How many days did you work this month?\n";
	cin >> iDays;

	//Loop to validate input
	while (iDays > 31 || iDays < 1)
	{
		cout << "Invalid number of days, please enter a number from 1 to 31\n";
		cin >> iDays;
	}

	//loop to multiply the daily pay by 2 for each of days worked
	for (int iCount = 0; iCount < iDays; iCount++)
	{
		//Display the current day's pay
		cout << "Pay for day " << iCount << " is: \n\t\t\t$"
			<< right << setw(11) << dPay << endl;

		//Do the calculation
		dPay *= 2;

		//Add the pay to the accumulator
		dTotal += dPay;
	}

	//Display the Total
	cout << "\nYour Total Pay is: \n\t\t\t$"
		<< right << setw(11) << dTotal << endl;
	system("pause");
	return 0;
}