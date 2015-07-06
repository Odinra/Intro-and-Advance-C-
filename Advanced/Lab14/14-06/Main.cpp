/*CK King
Section 1031
Started: 06/12/12 1332 Ended: 06/12/12 1348*/
#include <iostream>

using namespace std;
//prototype
bool memberTest(int iArray[], int size, int value);
//main
int main()
{
	//pointer to an int for use with dynamic allocation laterr on
	//also other variables
	int * pArray;
	int size;
	int value;
	//prompt
	cout << "How large do you want your array to be?\n";
	cin >> size;
	//allomacation
	pArray = new int[size];

	//initilizationizing
	for (int index = 0; index < size; index++)
	{
		cout << "Please enter value number " << index + 1 << endl;
		cin >> pArray[index];
	}
	//clear screen so they can't "cheat"
	system("cls");
	//promptimification
	cout << "What value do you want to search for?\n";
	cin >> value;

	//test the result
	if(memberTest(pArray, size, value))
	{
		cout << "Your value was found! YAY!\n";
	}
	else
	{
		cout << "Unfortunately your value was not in the array.\n";
	}
	//delete the memory leakage
	delete [] pArray;
	system("pause");
	return 0;
}
//function
bool memberTest(int iArray[], int size, int value)
{
	//index size so that it search from the back forward, since if you just 
	//passed size, it would need to change every recurse
	static int index = size;
	//base cases
	if ( iArray[index] == value)
	{
		return true;
	}
	else if ( size <= 0 )
	{
		return false;
	}
	//recursivimify the functionimification
	return memberTest(iArray, index--, value);

}