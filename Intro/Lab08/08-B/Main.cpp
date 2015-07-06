/* Christopher King
Section 1023
A program to simulate a soft drink machine*/
#include <iostream>
#include <string>
#include "Machine.h"

using namespace std;

int main()
{
	//variables
	int iChoice = 0;
	//object
	Machine mMachine;
	double dChange;

	//menu loop
	do	
	{
		//pause and clear screen
		system("pause");
		system("cls");
		cout <<"Please make a selection from the following menu:\n";
		mMachine.display();
		cout << "6:\t\tExit\n";
		cin >> iChoice;

		//validation
		while (iChoice <= 0 ||  iChoice > 6)
		{
			cout << "ERROR! Invalid selection";
			cout <<"Please make a selection from the following menu:\n";
			mMachine.display();
			cout << "6:\t\tExit\n";
			cin >> iChoice;
		}

		//only go to the buydrink function if requested
		if (iChoice != 6)
		{
			dChange = mMachine.buyDrink(iChoice - 1);
			cout << "Your change is :\n\t\t\t$" << dChange << endl;

		}

	} while( iChoice != 6);
	system("pause");
	//return and deconstructor
	return 0;
}