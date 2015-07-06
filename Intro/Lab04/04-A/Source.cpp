/*Christopher King
Section 1023
A Program that computes and dislays bank fees*/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double dBase, dEach, dChecks, dTotal;
	dBase = 10;

	//prompt the user for the number of checks used
	cout << "How many checks did you write this month?\n";
	cin >> dChecks;

	//perform a check to see how many checks were written
	if (dChecks < 0)
	{
		cout << "You entered an incorrect number";
		exit(0);
	}
	else if (dChecks < 20 && dChecks >= 0)
	{
		dEach = .10;
	}
	else if (dChecks < 40)
	{
		dEach = .08;
	}
	else if (dChecks < 60)
	{
		dEach = .06;
	}
	else
	{
		dEach = .04;
	}

	//perform calculation
	dTotal = dBase + (dEach * dChecks);

	//display the bank fee
	cout << fixed << setprecision(2);
	cout << "Your bank fee for the month is: \n\t" << dTotal << endl;

	system("pause");
	return 0;
}