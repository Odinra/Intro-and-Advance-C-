/*CK King
Section 1031
Start Time: 05/30/12 1548 End Time: 
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{	//setprecision
	cout << fixed << setprecision(2);

	//get arrays
	char cPayee[101], cDate[11], cThousand[15], cHundred[15], cTen[15], 
		cOne[15], cAmt[65], cITOA[10];
	//initialize
	for (int index = 0; index < 65; index++)
	{
		cAmt[index] = '\0';
	}
	//initialize
	for (int index = 0; index < 15; index++)
	{
		cThousand[index] = '\0';
		cHundred[index] = '\0';
		cTen[index] = '\0';
		cOne[index] = '\0';
	}
	double dAmt;
	//prompts
	cout << "Please enter the Payee:\n";
	cin.getline(cPayee, 101);
	cout << "Please enter the date in the MM/DD/YYYY format:\n";
	cin >> cDate;
	cout << "Please enter the check amount.\n\t"
		"Be advised no checks larger than 10000 dollars, "
		"and no negative amounts\n";
	cin >> dAmt;
		//set the amounts
	while (dAmt > 10000 || dAmt < 0)
	{
		cout << "ERROR: Invalid entry!\n";
		cout << "Please enter the check amount.\n\t"
			"Be advised no checks larger than 10000 dollars, "
			"and no negative amounts\n";
		cin >> dAmt;
	}
	//set the amounts
	if (dAmt == 10000)
	{
		strcpy_s(cThousand, "Ten Thousand\0");
		for (int index = 0; index < 15; index++)
		{
			cHundred[index] = '\0';
			cTen[index] = '\0';
			cOne[index] = '\0';
		}
	}
	else if (dAmt < 10000 && dAmt >= 1000)
	{
		/*strcat_s(cConvert, */_itoa_s(dAmt * 100, cITOA, 10);
	}
	else if (dAmt < 1000 && dAmt >= 100)
	{
		
		/*strcat_s(cConvert, */_itoa_s(dAmt * 100, cITOA, 10);
	}
	else if (dAmt < 100 && dAmt >= 10)
	{
		
		/*strcat_s(cConvert, */_itoa_s(dAmt * 100, cITOA, 10);
	}
	else if (dAmt < 10 && dAmt >=1)
	{
	
		/*strcat_s(cConvert, */_itoa_s(dAmt * 100, cITOA, 10);
	}

	//set the strings
	if ( dAmt > 1000 && dAmt < 10000)
	{
	if (cITOA[0] == '9')
		strcat_s(cThousand, "Nine Thousand ");
	if (cITOA[0] == '8')
		strcat_s(cThousand, "Eight Thousand ");
	if (cITOA[0] == '7')
		strcat_s(cThousand, "Seven Thousand ");
	if (cITOA[0] == '6')
		strcat_s(cThousand, "Six Thousand ");
	if (cITOA[0] == '5')
		strcat_s(cThousand, "Five Thousand ");
	if (cITOA[0] == '4')
		strcat_s(cThousand, "Four Thousand ");
	if (cITOA[0] == '3')
		strcat_s(cThousand, "Three Thousand ");
	if (cITOA[0] == '2')
		strcat_s(cThousand, "Two Thousand ");
	if (cITOA[0] == '1')
		strcat_s(cThousand, "One Thousand ");
	if (cITOA[0] == '0')
		strcat_s(cThousand, '\0');

	if (cITOA[1] == '9')
		strcat_s(cHundred, "Nine Hundred ");
	if (cITOA[1] == '8')
		strcat_s(cHundred, "Eight Hundred ");
	if (cITOA[1] == '7')
		strcat_s(cHundred, "Seven Hundred ");
	if (cITOA[1] == '6')
		strcat_s(cHundred, "Six Hundred ");
	if (cITOA[1] == '5')
		strcat_s(cHundred, "Five Hundred ");
	if (cITOA[1] == '4')
		strcat_s(cHundred, "Four Hundred ");
	if (cITOA[1] == '3')
		strcat_s(cHundred, "Three Hundred ");
	if (cITOA[1] == '2')
		strcat_s(cHundred, "Two Hundred ");
	if (cITOA[1] == '1')
		strcat_s(cHundred, "One Hundred ");
	if (cITOA[1] == '0')
		strcat_s(cHundred, '\0');

	if (cITOA[2] == '9')
		strcat_s(cTen, "Ninety ");
	if (cITOA[2] == '8')
		strcat_s(cTen, "Eighty ");
	if (cITOA[2] == '7')
		strcat_s(cTen, "Seventy ");
	if (cITOA[2] == '6')
		strcat_s(cTen, "Sixty ");
	if (cITOA[2] == '5')
		strcat_s(cTen, "Fifty ");
	if (cITOA[2] == '4')
		strcat_s(cTen, "Fourty ");
	if (cITOA[2] == '3')
		strcat_s(cTen, "Thirty ");
	if (cITOA[2] == '2')
		strcat_s(cTen, "Twenty ");
	if (cITOA[2] == '1')
		strcat_s(cTen, "Ten ");
	if (cITOA[2] == '0')
		strcat_s(cTen, '\0');

	if (cITOA[3] == '9')
		strcat_s(cOne, "Nine ");
	if (cITOA[3] == '8')
		strcat_s(cOne, "Eight ");
	if (cITOA[3] == '7')
		strcat_s(cOne, "Seven ");
	if (cITOA[3] == '6')
		strcat_s(cOne, "Six ");
	if (cITOA[3] == '5')
		strcat_s(cOne, "Five ");
	if (cITOA[3] == '4')
		strcat_s(cOne, "Four ");
	if (cITOA[3] == '3')
		strcat_s(cOne, "Three ");
	if (cITOA[3] == '2')
		strcat_s(cOne, "Two ");
	if (cITOA[3] == '1')
		strcat_s(cOne, "One ");
	if (cITOA[3] == '0')
		strcat_s(cOne, '\0');
	}
	else if ((dAmt < 1000 && dAmt >= 100))
	{
	if (cITOA[0] == '9')
		strcat_s(cHundred, "Nine Hundred ");
	if (cITOA[0] == '8')
		strcat_s(cHundred, "Eight Hundred ");
	if (cITOA[0] == '7')
		strcat_s(cHundred, "Seven Hundred ");
	if (cITOA[0] == '6')
		strcat_s(cHundred, "Six Hundred ");
	if (cITOA[0] == '5')
		strcat_s(cHundred, "Five Hundred ");
	if (cITOA[0] == '4')
		strcat_s(cHundred, "Four Hundred ");
	if (cITOA[0] == '3')
		strcat_s(cHundred, "Three Hundred ");
	if (cITOA[0] == '2')
		strcat_s(cHundred, "Two Hundred ");
	if (cITOA[0] == '1')
		strcat_s(cHundred, "One Hundred ");
	if (cITOA[0] == '0')
		strcat_s(cHundred, '\0');

	if (cITOA[1] == '9')
		strcat_s(cTen, "Ninety ");
	if (cITOA[1] == '8')
		strcat_s(cTen, "Eighty ");
	if (cITOA[1] == '7')
		strcat_s(cTen, "Seventy ");
	if (cITOA[1] == '6')
		strcat_s(cTen, "Sixty ");
	if (cITOA[1] == '5')
		strcat_s(cTen, "Fifty ");
	if (cITOA[1] == '4')
		strcat_s(cTen, "Fourty ");
	if (cITOA[1] == '3')
		strcat_s(cTen, "Thirty ");
	if (cITOA[1] == '2')
		strcat_s(cTen, "Twenty ");
	if (cITOA[1] == '1')
		strcat_s(cTen, "Ten ");
	if (cITOA[1] == '0')
		strcat_s(cTen, '\0');

	if (cITOA[2] == '9')
		strcat_s(cOne, "Nine ");
	if (cITOA[2] == '8')
		strcat_s(cOne, "Eight ");
	if (cITOA[2] == '7')
		strcat_s(cOne, "Seven ");
	if (cITOA[2] == '6')
		strcat_s(cOne, "Six ");
	if (cITOA[2] == '5')
		strcat_s(cOne, "Five ");
	if (cITOA[2] == '4')
		strcat_s(cOne, "Four ");
	if (cITOA[2] == '3')
		strcat_s(cOne, "Three ");
	if (cITOA[2] == '2')
		strcat_s(cOne, "Two ");
	if (cITOA[2] == '1')
		strcat_s(cOne, "One ");
	if (cITOA[2] == '0')
		strcat_s(cOne, '\0');
	}
	else if (dAmt < 100 && dAmt >= 10)
	{
			
	if (cITOA[0] == '9')
		strcat_s(cTen, "Ninety ");
	if (cITOA[0] == '8')
		strcat_s(cTen, "Eighty ");
	if (cITOA[0] == '7')
		strcat_s(cTen, "Seventy ");
	if (cITOA[0] == '6')
		strcat_s(cTen, "Sixty ");
	if (cITOA[0] == '5')
		strcat_s(cTen, "Fifty ");
	if (cITOA[0] == '4')
		strcat_s(cTen, "Fourty ");
	if (cITOA[0] == '3')
		strcat_s(cTen, "Thirty ");
	if (cITOA[0] == '2')
		strcat_s(cTen, "Twenty ");
	if (cITOA[0] == '1')
		strcat_s(cTen, "Ten ");
	if (cITOA[0] == '0')
		strcat_s(cTen, '\0');

	if (cITOA[1] == '9')
		strcat_s(cOne, "Nine ");
	if (cITOA[1] == '8')
		strcat_s(cOne, "Eight ");
	if (cITOA[1] == '7')
		strcat_s(cOne, "Seven ");
	if (cITOA[1] == '6')
		strcat_s(cOne, "Six ");
	if (cITOA[1] == '5')
		strcat_s(cOne, "Five ");
	if (cITOA[1] == '4')
		strcat_s(cOne, "Four ");
	if (cITOA[1] == '3')
		strcat_s(cOne, "Three ");
	if (cITOA[1] == '2')
		strcat_s(cOne, "Two ");
	if (cITOA[1] == '1')
		strcat_s(cOne, "One ");
	if (cITOA[1] == '0')
		strcat_s(cOne, '\0');
	}
		else if (dAmt < 10 && dAmt >=1)
		{
	if (cITOA[0] == '9')
		strcat_s(cOne, "Nine ");
	if (cITOA[0] == '8')
		strcat_s(cOne, "Eight ");
	if (cITOA[0] == '7')
		strcat_s(cOne, "Seven ");
	if (cITOA[0] == '6')
		strcat_s(cOne, "Six ");
	if (cITOA[0] == '5')
		strcat_s(cOne, "Five ");	
	if (cITOA[0] == '4')
		strcat_s(cOne, "Four ");
	if (cITOA[0] == '3')
		strcat_s(cOne, "Three ");
	if (cITOA[0] == '2')
		strcat_s(cOne, "Two ");
	if (cITOA[0] == '1')
		strcat_s(cOne, "One ");
	if (cITOA[0] == '0')
		strcat_s(cOne, '\0');
	}

	if(cThousand[0] != '\0')
	{
		if (cAmt[0] != '\0')
		{
			strcat_s(cAmt, cThousand);
		}
		else 
		{
			strcpy_s(cAmt, cThousand);
		}
	}
	if (cHundred[0] != '\0')
	{
		if (cAmt[0] != '\0')
		{
			strcat_s(cAmt, cHundred);
		}
		else 
		{
			strcpy_s(cAmt, cHundred);
		}
	}
	if (cTen[0] != '\0')
	{
		if (cAmt[0] != '\0')
		{
			strcat_s(cAmt, cTen);
		}
		else 
		{
			strcpy_s(cAmt, cTen);
		}
	}
	if (cOne[0] != '\0')
	{
		if (cAmt[0] != '\0')
		{
			strcat_s(cAmt, cOne);
		}
		else 
		{
			strcpy_s(cAmt, cOne);
		}
	}
	if (dAmt > 1000 && dAmt < 10000)
	{
	strcat_s(cAmt, "and ");
	strcat_s(cAmt, &cITOA[4]);
	strcat_s(cAmt, &cITOA[5]);
	}
	else if (dAmt < 1000 && dAmt > 100)
	{
	strcat_s(cAmt, "and ");
	strcat_s(cAmt, &cITOA[3]);
	strcat_s(cAmt, &cITOA[4]);
	}
	else if (dAmt < 100 && dAmt > 10)
	{
	strcat_s(cAmt, "and ");
	strcat_s(cAmt, &cITOA[2]);
	strcat_s(cAmt, &cITOA[3]);
	}
	else if (dAmt < 10 && dAmt > 1)
	{
	strcat_s(cAmt, "and ");
	strcat_s(cAmt, &cITOA[1]);
	strcat_s(cAmt, &cITOA[2]);
	}
	else if (dAmt < 1 && dAmt > 0)
	{
	strcat_s(cAmt, "and ");
	strcat_s(cAmt, &cITOA[0]);
	strcat_s(cAmt, &cITOA[1]);
	}
	//clear the screen
	system("cls");
	//display the check
	cout << right << setw(60) << "Date: " << setw(10) << cDate << "\n"
		<< left << setw(22) << "Pay to the Order of: " << setw(28) << cPayee
		<< right << setw(10) << "$" << dAmt << "\n"
		<< cAmt << "\n";

	system("pause");
	return 0;
}