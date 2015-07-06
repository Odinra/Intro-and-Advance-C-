/*CK King
Section 1031
Start Time: 05/30/12 1458 - End Time: 05/30/12 1512
*/
#include <iostream>

using namespace std;

int main()
{	//prompt
	char cFirst[20], cMiddle[20], cLast[40], cFixed[85];
	cout << "What is your First Name?\n";
	cin >> cFirst;
	cout << "What is your Middle Name?\n";
	cin >> cMiddle;
	cout << "What is your Last Name?\n";
	cin >> cLast;
	//copy string
	strcpy_s(cFixed, cLast);
	//string cat
	strcat_s(cFixed, ", ");
	strcat_s(cFixed, cFirst);
	strcat_s(cFixed, " ");
	strcat_s(cFixed, cMiddle);
	//display
	cout << "Your name is:\n\t\t " << cFixed << "\n\n\n";
	system("pause");
	return 0;
}