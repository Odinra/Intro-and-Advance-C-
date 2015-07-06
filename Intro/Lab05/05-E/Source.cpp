/*Christopher King
section 1023
A program that calculates the balance of a savings account*/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//declare and initialize variables
	double dStart, dBalanceTotal, dInterest, dMonthDep, dInterestTotal = 0,
		dMonthInterest, dMonthWith, dDepTotal = 0, dWithTotal = 0,
		dMonthStart;

	//prompt for starting balance and interest rate
	cout << "What is your starting balance?\n";
	cin >> dStart;
	cout << "What is your annual percentage rate in decimal form?\n";
	cin >> dInterest;

	//set the balance total = to the start
	dBalanceTotal = dStart;
	dMonthStart = dStart;

	//loop for deposits, withdrawals, and interest each month
	for (int iMonth = 1; iMonth < 4; iMonth++)
	{

		//prompt for deposit	
		cout << "How much was deposited during month " << iMonth << endl;
		cin >> dMonthDep;

		//input validation
		while (dMonthDep < 0)
		{
			cout << "Invalid entry, Please enter a positive number\n";
			cin >> dMonthDep;
		}

		//accumulate
		dBalanceTotal += dMonthDep;
		dDepTotal += dMonthDep;

		//prompt for withdrawals
		cout << "How much was withdrawn during month " << iMonth << endl;
		cin >> dMonthWith;

		//Validation
		while (dMonthWith < 0 || dMonthWith > dBalanceTotal)
		{
			cout << "Invalid entry, Please enter a positive number\n"
				"and a number less than the account balance of $"
				<< dBalanceTotal << endl;
			cin >> dMonthWith;
		}

		//accumulator
		dBalanceTotal -= dMonthWith;
		dWithTotal += dMonthWith;

		//interest calculations
		dMonthInterest = (dInterest / 12) *((dMonthStart + dBalanceTotal) / 2);


		//accumulator
		dBalanceTotal += dMonthInterest;
		dInterestTotal += dMonthInterest;

		//set the next month's starting point
		dMonthStart = dBalanceTotal;
	}

	//Display the results
	cout << fixed << setprecision(2);
	cout << "Starting balance: \n\t\t\t" << dStart << endl
		<< "Total Deposits: \n\t\t\t" << dDepTotal << endl
		<< "Total Withdrawals: \n\t\t\t" << dWithTotal << endl
		<< "Total Interest earned: \n\t\t\t" << dInterestTotal << endl
		<< "Final Balance: \n\t\t\t" << dBalanceTotal << endl;

	system("pause");
	return 0;
}