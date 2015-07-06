/*Christopher King
Section 1023
Creat a random number guessing game*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	//initialize and declare variables
	int iNumber, iGuess = 0, iFCount = 0, iDCount = 0, iAccum = 0;
	unsigned uSeed = time(0);
	char cRepeat = 'n';

	//seed the RNG
	srand(uSeed);

	//Do loop to be able to play the game multiple times if wanted (not required)
	do
	{

		//set the random number	
		iNumber = 1 + rand() % 100;

		cout << "I have chosen a random number between 1 and 100\n";

		//For loop that contains the bulk of the game
		for (; iGuess != iNumber; iFCount++)
		{
			//prompt for a guess
			cout << "Please enter a guess between 1 and 100\n";
			cin >> iGuess;

			//Validate input
			while (iGuess < 1 || iGuess > 100)
			{
				cout << "That is an invalid choice,"
					" please enter a number between 1 and 100\n";
				cin >> iGuess;
			}

			// If/Else to tell the player if the guessed to high or low
			if (iGuess > iNumber)
			{
				cout << "Too high. Try again\n";
			}
			else if (iGuess < iNumber)
			{
				cout << "Too Low. Try again\n";
			}
		}

		//clear the screen
		system("cls");

		//display when Victoriuos with the number of attempts needed
		cout << "Congratulations! You figured out my number in " << iFCount;

		//makes sure attempt is in the correct form (plural or not)
		if (iFCount == 1)
		{
			cout << " attempt!\n";
		}
		else
		{
			cout << " attepmts!\n";
		}

		//prompt the user to see if they want to play again
		cout << "Type y or Y to play again\n";
		cin >> cRepeat;

		//accumulate
		iAccum += iFCount;

		//reinitialize
		iFCount = 0;
		iGuess = 0;

		//increment
		iDCount++;

		//if condition is met, replay the game
	} while (cRepeat == 'y' || cRepeat == 'Y');

	//display how many numbers were guessed
	cout << "Congratulations! You guessed " << iDCount;

	//test for plurality
	if (iDCount == 1)
	{
		cout << " number ";
	}
	else
	{
		cout << " numbers ";
	}

	//Display how many total attempts used
	cout << "In " << iAccum;

	//plurality test
	if (iAccum == 1)
	{
		cout << " attempt!\n";
	}
	else
	{
		cout << " attepmts!\n";
	}
	system("pause");
	return 0;
}