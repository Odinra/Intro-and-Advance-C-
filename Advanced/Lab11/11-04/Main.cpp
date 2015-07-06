/*Christopher King
Section 1031
Started  05/29/12 1317 ended -*/
#include "NumDays.h"
#include <iostream>
using namespace std;

//main
int main()
{
	//variables
	int iHour;
	//promptify
	cout << "Please enter the nunber of Hours Worked:\n";
	cin >> iHour;

	//initialize
	NumDays Day(iHour), Day2(8);

	//show inititalized
	cout << "\nThe Number of Days worked is:\t" << Day.getDays();
	
	//examplifymication
	cout << "\nThe number of Days worked after incrementaion Operator is:\t" << ++Day;
	
	cout << "\nThe Number of days worked after decremention operator is :\t" << Day--;
	cout << "\nThe Number of days worked by employee 1 plus employee 2 is:\t" << Day + Day2;
	cout << "\nThe Number of hours employee 1 worked more than employee 2 is:\t" << Day - Day2 << "\n";
	system("pause");
	return 0;
}