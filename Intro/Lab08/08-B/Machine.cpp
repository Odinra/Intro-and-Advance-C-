/*Christopher King
Section 1023
Machine source file to contain object information*/
#include "Machine.h"
#include <iostream>
#include <string>
using namespace std;

//display function
void Machine::display()
{
	//for loop to display all drink types
	for (int index = 0; index < 5; index++)
	{
		cout << index + 1 << ":\t\t" << dDrink[index].sName << "\t\t" 
			<< dDrink[index].dPrice << "\t\t" << dDrink[index].iNumber << "\n";
	}
}

//constructor to automate drink names, price, and quantity
Machine::Machine()
{
	dDrink[0].sName = "Cola     ";
	dDrink[0].dPrice = .75;
	dDrink[0].iNumber = 20;
		
	dDrink[1].sName = "Root Beer";
	dDrink[1].dPrice = .75;
	dDrink[1].iNumber = 20;
	
	dDrink[2].sName = "Orange Soda";
	dDrink[2].dPrice = .75;
	dDrink[2].iNumber = 20;

	dDrink[3].sName = "Grape Soda";
	dDrink[3].dPrice = .75;
	dDrink[3].iNumber = 20;
	
	dDrink[4].sName = "Bottled water";
	dDrink[4].dPrice = 1.00;
	dDrink[4].iNumber = 20;

	//set the money collected to 0
	dCollected = 0;
}

//buydrink public function
double Machine::buyDrink(int iChoice)
{
	//variables
	char cTest;
	double dMoney, dChange;
	//money input function
	dMoney = inputMoney(iChoice);

	//prompt
	cout << "Do you still wish to make the purchase? (y/n)\n";
	cin >> cTest;

	//validation
	while (cTest != 'y' && cTest != 'Y' && cTest != 'n' && cTest != 'N')
	{
		cout << "ERROR! Invalid data entry!";
		cout << "Do you still wish to make the purchase? (y/n)\n";
		cin >> cTest;
	}

	//if they dont want to continue return their money
	if (cTest == 'n' || cTest == 'N')
	{
		return dMoney;
	}

	//display if sold out
	if (dDrink[iChoice].iNumber <= 0)
	{
		cout << "Unfortunately your drink selection is SOLD OUT!\n";

		return dMoney;
	}


	else
	{
		//decrement
		dDrink[iChoice].iNumber--;
		//calculate change
		dChange = dMoney - dDrink[iChoice].dPrice;

		//give soday
		cout << "Here is your " << dDrink[iChoice].sName << "!\n";
		//update collected
		dCollected += dDrink[iChoice].dPrice;

		//return the change
		return dChange;
	}


}

//inputMoney function
double Machine::inputMoney(int iChoice)
{
	//variable
	double dMoney, dAdd = 0;
	//prompt
	cout << "GIVE ME ALL YOUR MONNIES:\n";
	cin >> dMoney;

	//validator
	while (dMoney < 0)
	{
		cout << "I WILL NOT ACCEPT NEGATIVE MONIES!\n";
		cout << "GIVE ME ALL YOUR MONNIES:\n";
		cin >> dMoney;
	}

	//test to see if enough money is given
	while (dMoney < dDrink[iChoice].dPrice)
	{
		cout << "NOT ENOUGH MONIES!\n";
		cout << "GIVE ME ALL YOUR MONNIES:\n";
		cin >> dAdd;

		//validator
		while (dAdd < 0)
		{
			cout << "I WILL NOT ACCEPT NEGATIVE MONIES!\n";
			cout << "GIVE ME ALL YOUR MONNIES:\n";
			cin >> dAdd;
		}

		dMoney += dAdd;
	}
	
	//return money deposited
	return dMoney;
}

//display the report after destructor is called
void Machine::dailyReport()
{
	for (int index = 0; index < 5; index++)
	{
		cout << index + 1 << ":\t\t" << dDrink[index].sName << "\t\t" 
			<< dDrink[index].dPrice << "\t\t" << dDrink[index].iNumber << "\n";
	}

	cout << "Total money collected:\n\t\t\t$" << dCollected << endl;
}