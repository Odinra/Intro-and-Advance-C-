/*Christopher King
Section 1031
Create a program that shows how sorting algorithms function.
CK - 05/09/12 11:50 Start Program
CK - 05/09/12 12:30ish End Program
*/

#include <iostream>

using namespace std;
//prototypes
void bubbleSort(int iarray[], int size);
void selectionSort(int iarray[], int size);

int main()
{
	//arrays
	int iarray1[8] = { 7, 5, 10, 3, 5, 4, 6, 1};
	int iarray2[8] = { 7, 5, 10, 3, 5, 4, 6, 1};
	//display list for array1
	cout << "Here is the initialized list of 8 nubers for array1:\n\n";
	for (int index = 0; index < 8; index++)
	{
		cout << iarray1[index] << "\t";
	}

	cout << "\n\nArray1 will now be sorted using a bubble sort\n\n";
	//bubble sort call
	bubbleSort(iarray1, 8);
	//array2 numbers displayed
	cout << "\n\nHere is the initialized list of 8 numbers for array2:\n\n";
	for (int index = 0; index < 8; index++)
	{
		cout << iarray2[index] << "\t";
	}
	
	cout << "\n\nArray2 will now be sorted using a selection sort\n\n";
	
	//selectionSort call
	selectionSort(iarray2, 8);

	cout << "\n";
	system("pause");
	return 0;
}
//bubble sort function
void bubbleSort(int iarray[], int size)
{//variables
	int temp;
	bool swap;
	int iPassCount = 1;
	
	//do llop
	do
	{	swap = false;
		for (int index = 0; index < (size - 1); index++)
		{
			if (iarray[index] > iarray[index+1])
			{
				//swaps
				temp = iarray[index];
				iarray[index] = iarray[index +1];
				iarray[index + 1] = temp;
				swap = true;
			}
		}
		
		//display the pass findings and count
		cout << "\nPass #" << iPassCount << ":\n";

		for (int count = 0; count < size; count++)
		{
			cout << iarray[count] << "\t";
		}
		//increment
		iPassCount++;
	} while (swap);
}
//seslection sort function
void selectionSort(int iarray[], int size)
{
	//variables
	int iStartScan, iMinIndex, iMinValue;
	int iPassCount = 1;

	//for loop
	for (iStartScan = 0; iStartScan < (size - 1); iStartScan++)
	{	
		//store the smallest
		iMinIndex = iStartScan;
		iMinValue = iarray[iStartScan];
		for (int index = iStartScan +1; index < size; index++)
		{
			if (iarray[index] < iMinValue)
			{
				//if smallest changed switch
				iMinValue = iarray[index];
				iMinIndex = index;
			}
		}
		
		iarray[iMinIndex] = iarray[iStartScan];
		iarray[iStartScan] = iMinValue;
		
		//display count number and the order after each pass
		cout << "\nPass #" << iPassCount << ":\n";
	
		for (int count = 0; count < size; count++)
		{
			cout << iarray[count] << "\t";
		}

		iPassCount++;
	}

}