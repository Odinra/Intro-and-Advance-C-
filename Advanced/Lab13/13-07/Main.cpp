/*CK King
Section 1031
Time Started 06/08/12 1508 time ended 06/08/12 1612*/
#include "FILES.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string filename;
	//prompt
	cout << "Please enter the file name including file extensions:\n";
	cin >> filename;

	FILES file(filename);

	file.encrypt();

	cout << "Your file has been encrypted!";
	system("pause");
	return 0;
}