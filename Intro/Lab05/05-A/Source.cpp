/*Christopher King
Section 1023
A program to display th ASCII values from 32 to 127*/
#include <iostream>
using namespace std;

int main()
{
	//Create the ascii character to be displayed
	char cAscii = 32;

	//create the loop that displays the 6 rows
	for (int iCount = 0; iCount < 6; iCount++)
	{
		//Create the 16 columns per row
		for (int iColumn = 0; iColumn < 16; iColumn++)
		{
			//display and increment the characters		
			cout << cAscii++ << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}