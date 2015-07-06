/*CK King
Section 1031
Start Time: 05/30/12 1514 End Time: 1548
*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
	//initialization for variables and flags
	string sPassword;
	bool bGood = true, bUpper = false, bLower = false, bDigit = false;
	do{ bGood = true, bUpper = false, bLower = false, bDigit = false;
	cout <<"\nPlease enter a Password that meets all of the following criteria:"
		"\n\n\tThe Password must be at least 6 characters long\n"
		"\tThe Password must contain at least one uppercase letter\n"
		"\tThe Password must contain at least one lowercase letter\n"
		"\tThe Password must contain at least one digit\n";
	cin >> sPassword;
	//password
	if (sPassword.length() < 6)
	{
		cout << "ERROR! The Password does not meet the Following Criteria:\n\t"
			"The password is to short, it must be 6 characters!\n";
		bGood = false;
	}
	//password tests
	for (int index = 0; index < sPassword.length(); index++)
	{
		if (isupper(sPassword[index]))
		{
			bUpper = true;
		}
		if (islower(sPassword[index]))
		{
			bLower = true;
		}
		if (isdigit(sPassword[index]))
		{
			bDigit = true;
		}
	}
	//return if errors
	if (!bUpper)
	{
		cout << "ERROR! The Password does not meet the Following Criteria:\n\t"
			"The password does not contain any uppercase letters."
			"\n\t\tIt must contain at least 1 uppercase Letter\n";
		bGood = false;
	}
	//return if errors
	if (!bLower)
	{
		cout << "ERROR! The Password does not meet the Following Criteria:\n\t"
			"The password does not contain any lowercase letters."
			"\n\t\tIt must contain at least 1 lowercase Letter\n";
		bGood = false;
	}
	//return if errors
	if (!bDigit)
	{
		cout << "ERROR! The Password does not meet the Following Criteria:\n\t"
			"The password does not contain any digits."
			"\n\t\tIt must contain at least 1 digit\n";
		bGood = false;
	}
	}while (!bGood);
	system("pause");
	return 0;
}