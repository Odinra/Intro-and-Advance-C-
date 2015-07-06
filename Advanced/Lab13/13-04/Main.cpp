/*CK King	
Section 1031
Started 06/08/12 1235 Ended 06/08/12 1505 */
#include <iostream>
#include <fstream>
#include <string>
#include "FILES.h"

using namespace std;

int main()
{
	//variables
	string sFileName, sLastLines;

	//prompt
	cout << "What is the filename? including the extenstion?\n";
	cin >> sFileName;

	//class files
	FILES file(sFileName);

	//call lastlines function
	sLastLines = file.LastLines(10);

	//display the last 10 lines
	cout << "The Last 10 lines of the file are:\n\n" << sLastLines;
	system("pause");
	//return error code 0
	return 0;
}