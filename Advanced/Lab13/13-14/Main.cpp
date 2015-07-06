/*CK King
Section 1031
Start Time 06/08/12 2106 End Time 06/11/12 */
#include <iostream>
#include "FILES.h"
#include <string>
using namespace std;

char  sName[101];
char sAddress[101];
char sCity_State[101];
char sPhone[101];
double dAccountBalance;
char sLastPayment[101];
char changeCust[101]; 
//prototype
void getinfo(FILES *file);
void displayOne(FILES *file);
void deleteOne(FILES *file);
void changeOne(FILES *file);

int main()
{
	string filename;

	int iMenuChoice;
	//prompt
	cout << "What is the name of the file?";
	cin >> filename;
	FILES file(filename);
	//menu
	do
	{
		//prompt
		cout << "\n\nWhate Would you like to do?\n";
		cout << "1.\tAdd record\n"
			<< "2.\tDisplay a record\n"
			<< "3.\tDelete a record\n"
			<< "4.\tChange a record\n"
			<< "5.\tDisplay all records\n"
			<< "6.\tExit";
		cin >> iMenuChoice;
		//validation
		while (iMenuChoice < 0 || iMenuChoice > 6)
		{
			cout << "invalid choice!, please choose a number between 1 and 6\n";
			cin >> iMenuChoice;
		}
		//do the appropriate action
		switch(iMenuChoice)
		{
		case 1:	
			{
				getinfo(&file);
				break;
			}
		case 2:	
			{
				displayOne(&file);
				break;
			}
		case 3:	
			{
				deleteOne(&file);
				break;
			}
		case 4:	
			{
				changeOne(&file);
				break;
			}
		case 5:	
			{
				file.displayAll();
				break;
			}
		default: break;
		}

	}while (iMenuChoice !=6);
	system("pause");
	return 0;
}
//get info function
void getinfo(FILES *file)
{
	//prompt
	cout << "What is the name?\n";
	cin.ignore();
	cin.getline(sName, 100, '\n');
	cout << "What is the address?\n";
	cin.getline(sAddress, 100, '\n');
	cout << "What is the city, state, and zip?\n";
	cin.getline(sCity_State, 100, '\n');
	cout << "What is the phone number?\n";
	cin.getline(sPhone, 100, '\n');
	cout << "What is the Account Balance?\n";
	cin.ignore();
	cin >> dAccountBalance;
	cout << "What is the date of the Last Payment?\n";
	cin.ignore();
	cin.getline(sLastPayment, 100, '\n');

	file->addCust(sName, sAddress, sCity_State, sPhone, dAccountBalance, sLastPayment); 
}

void displayOne(FILES *file)
{
	//prompt
	cout << "Please enter the name of the customer you wish to display:\n";
		cin.ignore();
	cin.getline(sName, 100, '\n');

	file->displayCust(sName);
}

void deleteOne(FILES *file)
{
	//prompt
	cout << "Please enter the name of the customer you wish to delete:\n";
		cin.ignore();
	cin.getline(sName, 100, '\n');

	file->deleteCust(sName);
}

void changeOne(FILES *file)
{
	//prompt
	cout << "Please enter the name of the customer you wish to change:\n";
	cin.ignore();
	cin.getline(changeCust, 100, '\n');
	//prompt
	cout << "What is the new name?\n";
	cin.getline(sName, 100, '\n');
	cout << "What is the new address?\n";
	cin.getline(sAddress, 100, '\n');
	cout << "What is the new city, state, and zip?\n";
	cin.getline(sCity_State, 100, '\n');
	cout << "What is the new phone number?\n";
	cin.getline(sPhone, 100, '\n');
	cout << "What is the new Account Balance?\n";
	cin.ignore();
	cin >> dAccountBalance;
	cout << "What is the new date of the Last Payment?\n";
	cin.ignore();
	cin.getline(sLastPayment, 100, '\n');

	file->changeCust(changeCust, sName, sAddress, sCity_State, sPhone, dAccountBalance, sLastPayment);
}
