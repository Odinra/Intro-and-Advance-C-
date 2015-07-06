/*CK King
Section 1031
Time Started 06/08/12 1612 time ended 06/08/12 1613*/
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

	file.decrypt();

	cout << "Your file has been decrypted!";
	system("pause");
	return 0;
}