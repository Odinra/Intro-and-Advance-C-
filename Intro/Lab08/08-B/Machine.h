/*Christopher King
Section 1023
Machine header file to contain object information*/
#ifndef MACHINE_H
#define MACHINE_H

#include <string>

using namespace std;

//structure for the drinks
struct Drink
{
	string sName;
	double dPrice;
	int iNumber;
};

//class for the machine
class Machine
{
	//private variables
	double dCollected;
	Drink dDrink[5];
	//private functions
	double inputMoney(int iChoice);
	void dailyReport();
public:	
	//constructor
	Machine::Machine();
	// deconstructor
	Machine::~Machine()
	{
		dailyReport();
	}
	//public functions
	void display();
	double buyDrink(int iChoice);

};
#endif