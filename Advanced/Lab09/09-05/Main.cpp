/* Christopher King
Section 1031
Create a Snow Conditions Report
CK 05/08/12 - 12:55-01:42 Started Program
CK 05/10/12 - 11:00ish - 11:37 Finished product
*/
#include <iostream>
#include <string>
#include "Slopes.h"

using namespace std;

//sort prototype
Slopes bubbleSort(Slopes slReport);

//main
int main()
{
	//variables
	int iStartDate;
	Slopes slReport;

	//prompt
	cout << "Please enter the Month:\n";
	cin >> slReport.sMonth;
	//prompt
	cout << "Please enter the Starting Date:\n";
	cin >> iStartDate;
	slReport.setDates(iStartDate);

	//looped prompt
	for (int index = 0; index < 7 ; index++)
	{
		cout << "Please enter the inches of snow in the base on date :\t" 
			<< slReport.iDate[index] << endl;
		cin >> slReport.dBase[index];
	}

	//output before sort
	cout << "Show Report: \t" << slReport.sMonth << " " << slReport.iDate[0] 
		<< " - " << slReport.iDate[6] << endl;
	//sort
	slReport = bubbleSort(slReport);
	//ouput after sort
	cout << "Date\tBase\n";

	//output loop
	for (int index = 0; index < 7; index++)
	{
		cout << slReport.iDate[index] << "\t" << slReport.dBase[index] << endl;
	}

	system("pause");
	
	return 0;
}
//sort function
Slopes bubbleSort(Slopes slReport)
{
	//temp variables
	double dTemp;
	int iTemp;

	//swap test
	bool bSwap;
	
	//dowhile loop
	do//set swap to false
	{	bSwap = false;
	//run though the different indexes
	for (int index = 0; index < 6; index++)
	{
		//check if swap needed
		if (slReport.dBase[index] > slReport.dBase[index+1])
		{
			//swap data
			dTemp = slReport.dBase[index];
			iTemp = slReport.iDate[index];
			slReport.dBase[index] = slReport.dBase[index+1];
			slReport.iDate[index] = slReport.iDate[index+1];
			slReport.dBase[index+1] = dTemp;
			slReport.iDate[index+1] = iTemp;

			//if swap occured set to true
			bSwap = true;
		}
	}//if swap is true 
	} while (bSwap);

	return slReport;
}