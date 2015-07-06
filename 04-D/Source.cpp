/*Christopher King
Section 1023
A Program that computes and dislays a customer's monthly ISP bill*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	//declare variables
	double dPrice, dHours, dDue;
	string sName;
	char cPackage;

	//prompt for and store the data
	cout << "What is your name?\n";
	getline(cin, sName);
	cout << "What package did you purchase? A, B, or C?\n";
	cin >> cPackage;
	cout << "How many hours did you use?\n";
	cin >> dHours;

	//validate the data
	if (!(cPackage == 'A' || cPackage == 'B' || cPackage == 'C'
		|| cPackage == 'a' || cPackage == 'b' || cPackage == 'c')
		|| dHours > 744 || dHours < 0)
	{
		cout << "You have entered invalid data.\n";
		exit(0);
	}

	//test to see wich package they purchased
	if (cPackage == 'A' || cPackage == 'a')
	{
		//test to see if they pay the base price,or more
		if (dHours > 10)
		{
			dDue = (dHours - 10) * 2 + 9.95;
		}
		else
			dDue = 9.95;
	}
	else if (cPackage == 'B' || cPackage == 'b')
	{
		//test to see if they pay the base price, or more
		if (dHours > 20)
		{
			dDue = (dHours - 20) * 1 + 14.95;
		}
		else
			dDue = 9.95;
	}
	else
	{
		dDue = 19.95;
	}

	//open the file
	ofstream ofBill;
	ofBill.open("bill.txt");

	//store the data
	ofBill << sName << "\nPackage Purchased: " << cPackage << "\nHours Used: "
		<< dHours << "\nTotal Amount Due: " << dDue << endl;

	//close the file
	ofBill.close();
	system("pause");
	return 0;
}