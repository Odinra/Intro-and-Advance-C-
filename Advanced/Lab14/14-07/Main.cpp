/*CK King
Section 1031
Start Time 06/12/12 1349 End Time*/
#include <iostream>
#include <string>
using namespace std;
//prototypical
char * reverseIt(char * string);
int main()
{
	//initialize a string for testimification
	char blah[] = "John Jacob JingleHiemer Schmidt, his name is my name too!"
		" Whenever we go out, the people always shout \"John Jacob "
		"JingleHeimer Schmidt\"";
	//display the forwards string
	cout << blah << "\n\n";
	cout << "Now reversIt will reverse It\n\n";
	//call the reverse it function
	reverseIt(blah);
	//show the reversed string
	cout << "The reversed string is:\n\n";
	cout << blah << "\n";
	system("pause");
	return 0;
}
//function
char * reverseIt(char * cstring)
{
	//static variables
	static int iFirst = 0, iLast = strlen(cstring) - 1;
	//temo characters
	char cTemp = 'a', cTemp2;
	//base case
	if (iFirst >= iLast)
	{
		return cstring;
	}
	//character swapimification magic
	cTemp = cstring[iLast];
	cTemp2 = cstring[iFirst];
	cstring[iLast] = cTemp2;
	cstring[iFirst] = cTemp;
	//incrementation and decrementation so that
	iFirst++;
	iLast--;

	//recursion
	return reverseIt(cstring);
}