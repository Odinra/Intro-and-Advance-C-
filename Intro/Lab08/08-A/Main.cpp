/* Christopher King
Section 1023
A simple program to record how much food monkeys eat throught the week and use 
that data in functions*/
#include <iostream>

//constant global variables
const int IMONK = 3;
const int IDAY = 7;

using namespace std;

//prototypes
double Average(double dFood[IMONK][IDAY]);
double Least(double dFood[IMONK][IDAY]);
double Most(double dFood[IMONK][IDAY]);

int main()
{
	//variables
	double dAvg, dLowest, dMost;
	//the array
	double dFood[IMONK][IDAY];

	//row for loop
	for (int iRow = 0; iRow < IMONK; iRow++)
	{
		//column for loop
		for (int iColumn = 0; iColumn < IDAY; iColumn++)
		{
			//prompt
			cout << "Please enter the amount of food eaten by monkey " 
				<< iRow + 1 << " on day " << iColumn + 1 << ":\n\t\t";
			cin >> dFood[iRow][iColumn];

			//validation
			while (dFood[iRow][iColumn] < 0)
			{
				cout << "ERROR! Will not Accept Negative Numbers!";
				cout << "Please enter the amount of food eaten by monkey " 
					<< iRow + 1 << " on day " << iColumn + 1 << ":\n\t\t";
				cin >> dFood[iRow][iColumn];
			}
		}
	}

	//function calls
	dAvg = Average(dFood);
	dLowest = Least(dFood);
	dMost = Most(dFood);

	//report
	cout << "The average amount of food eaten by all monkeys is: \n\t\t\t"
		<< dAvg << endl;
	cout << "The least amount of food eaten by any monkey is: \n\t\t\t"
		<< dLowest << endl;
	cout << "The most amount of food eaten by any monkey is: \n\t\t\t"
		<< dMost << endl;
	system("pause");
	return 0;
}

double Average(double dFood[IMONK][IDAY])
{
	//variables
	double dAccum = 0, dCount = 0, dAvg = 0;
	
	//Row loop
	for (int iRow = 0; iRow < IMONK; iRow++)
	{
		//Column Loop
		for (int iColumn = 0; iColumn < IDAY; iColumn++)
		{
			//incrementor
			dCount++;
			//accumulator
			dAccum += dFood[iRow][iColumn];
		}
	}

	//averagerator
	dAvg = dAccum / dCount;

	return dAvg;
}

double Least(double dFood[IMONK][IDAY])
{
	//variable
	double dLeast = dFood[0][0];

	//row loops
	for (int iRow = 0; iRow < IMONK; iRow++)
	{
		//column loop
		for (int iColumn = 0; iColumn < IDAY; iColumn++)
		{
			//find the lowest numbers
			if (dFood[iRow][iColumn] < dLeast)
			{
				dLeast = dFood[iRow][iColumn];
			}
		}
	}

	return dLeast;
}
double Most(double dFood[IMONK][IDAY])
{
	//variable
	double dMost = dFood[0][0];

	//row loops
	for (int iRow = 0; iRow < IMONK; iRow++)
	{
		//column loop
		for (int iColumn = 0; iColumn < IDAY; iColumn++)
		{
			//find the highest number
			if (dFood[iRow][iColumn] > dMost)
			{
				dMost = dFood[iRow][iColumn];
			}
		}
	}

	return dMost;
}