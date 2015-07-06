/*Christopher King
Section 1031
Create a Program to validate a charge account number
CK - 05/08/12 12:32 PM Started program
CK - 05/08/12 12:53 PM Ended Program
*/
#include <iostream>
using namespace std;
//search function prototype
bool searchList(int iAccount[], int iSize, int iEntered);

int main()
{
	//variables
	bool bValid = false;
	const int ISIZE = 18;
	int iAccount[ISIZE] = {5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 
		8080152, 4562555, 5552012, 5050552, 7825877, 1250255, 1005231, 6545231,
		3852085, 7576651, 7881200, 4581002};
	int iEntered;
	
	//prompt
	cout << "Please enter a charge account number:\n";
	cin >> iEntered;

	//function call
	bValid = searchList(iAccount, ISIZE, iEntered);

	//check
	if (bValid)
	{
		cout << "Your account Number is Valid!\n";
	}
	else 
	{
		cout << "Your account Number is InValid!\n";
	}
	system("pause");
	return 0;
}
//function
bool searchList(int iAccount[], int iSize, int iEntered)
{//check to see if number exists
	for(int iIndex = 0; iIndex < iSize; iIndex++)
	{
		if (iAccount[iIndex] == iEntered)
		{
			return true;
		}
	}

	return false;
}