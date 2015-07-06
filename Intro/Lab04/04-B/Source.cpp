/*Christopher King
Section 1023
A Program that does geometry for the user*/
#include <iostream>
using namespace std;

int main()
{
	//declare variables
	double dBase, dHeight, dRadius, dResult;
	const double dPI = 3.14159;
	int iChoice;

	//prompt for and and store the menu option
	cout << "Geometry Calculator\n\n\t1. Calculate the Area of a Circle\n\t"
		<< "2. Calculate the Area of a Rectangle\n\t3. Calculate the Area of a"
		<< " Triangle\n\t4. Quit\n\nEnter your choice (1-4):\n";
	cin >> iChoice;

	//test the data to see which if statement to execute
	if (iChoice < 1 || iChoice > 4)
	{
		cout << "Error incorrect number\n";
		exit(0);
	}
	else if (iChoice == 1)
	{
		//prompt for and store the data
		cout << "Please enter the radius of the circle\n";
		cin >> dRadius;
		//validate the data
		if (dRadius < 0)
		{
			cout << "Error incorrect number\n";
			exit(0);
		}
		//do the calculation
		dResult = dPI * (dRadius * dRadius);
	}
	else if (iChoice == 2)
	{
		//prompt for and store the data
		cout << "Please enter the length\n";
		cin >> dBase;
		cout << "Please enter the width\n";
		cin >> dHeight;
		//validate the data
		if (dBase < 0 || dHeight < 0)
		{
			cout << "Error incorrect number\n";
			exit(0);
		}
		//do the calculation
		dResult = dBase * dHeight;
	}
	else if (iChoice == 3)
	{
		//prompt for and store the data
		cout << "Please enter the base length\n";
		cin >> dBase;
		cout << "Please enter the height\n";
		cin >> dHeight;
		//validate the data
		if (dBase < 0 || dHeight < 0)
		{
			cout << "Error incorrect number\n";
			exit(0);
		}
		//do the calculation
		dResult = (dBase / 2) * dHeight;
	}
	else
		exit(0);

	//display the answer
	cout << "The answer is:\t" << dResult << endl;
	system("pause");
	return 0;
}