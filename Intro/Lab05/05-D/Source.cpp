/*Christopher King
section 1023
A program that works as a math tutor for a child*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int main()
{
	//declare variables
	int iRand1, iRand2, iInput, iCorrect, iMenu;
	unsigned seed;

	//seed the generator with the time function
	seed = time(0);
	srand(seed);

	//Do loop so the player can play multiple times
	do
	{

		//generate the random numbers between 10 and 40
		iRand1 = 11 + rand() % 40;
		iRand2 = 11 + rand() % 40;

		//Menu prompt
		cout << "Please make a selection from the list below\n"
			<< "1. Addition \n2. Subtraction \n3. Multiplication \n4. Quit\n";
		cin >> iMenu;

		//menu validation
		while (iMenu < 1 || iMenu > 5)
		{
			cout << "Invalid selection. Please enter a number between 1 and 4\n";
			cin >> iMenu;
		}

		//Addition problem
		if (iMenu == 1)
		{
			cout << setw(4) << iRand1 << endl
				<< "+" << setw(3) << iRand2 << endl
				<< "____" << endl;
			cin >> iInput;

			//test for correctness		
			if (iInput == (iRand1 + iRand2))
			{
				cout << "Congratulations! You're answer is correct\n";
			}
			else
			{
				cout << "Oops! the correct anser is " << iRand1 + iRand2 << endl;
			}
		}

		//Subtraction Problem
		if (iMenu == 2)
		{
			//make sure the answer is not negative
			if (iRand1 > iRand2)
			{
				cout << setw(4) << iRand1 << endl
					<< "-" << setw(3) << iRand2 << endl
					<< "____" << endl;
				cin >> iInput;

				//test for correctness	
				if (iInput == (iRand1 - iRand2))
				{
					cout << "Congratulations! You're answer is correct\n";
				}
				else
				{
					cout << "Oops! the correct anser is " << iRand1 - iRand2 << endl;
				}
			}
			else
			{
				cout << setw(4) << iRand2 << endl
					<< "-" << setw(3) << iRand1 << endl
					<< "____" << endl;
				cin >> iInput;

				//test for correctness
				if (iInput == (iRand2 - iRand1))
				{
					cout << "Congratulations! You're answer is correct\n";
				}
				else
				{
					cout << "Oops! the correct anser is " << iRand2 - iRand1 << endl;
				}
			}
		}

		//Multiplication Problem
		if (iMenu == 3)
		{
			cout << setw(4) << iRand1 << endl
				<< "x" << setw(3) << iRand2 << endl
				<< "____" << endl;
			cin >> iInput;

			//test for correctness
			if (iInput == (iRand1 * iRand2))
			{
				cout << "Congratulations! You're answer is correct\n";
			}
			else
			{
				cout << "Oops! the correct anser is " << iRand1 * iRand2 << endl;
			}
		}

		//Redo loop while while exit is not selected
	} while (iMenu != 4);
	system("pause");
	return 0;
}