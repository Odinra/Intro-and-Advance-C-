/* CK King
Section 1031
Start Time: 07/12/12 21:17 End Time:*/
#include "AbstractSeq.h"
int main()
{
	OddSeq odd;
	CubeSeq cube;

	cout << "The 5th through 100th odd numbers are:\n\n";
	odd.printSeq(4, 99);
	cout << "\n\nThe sum of the 5th through 100th odd numbers is :\n" << odd.sumSeq(4,99);

	cout << "\n\nThe 5th through the 100th Cubes are:\n\n";
	cube.printSeq(4, 99);
	cout << "\n\nThe sum of the 5th though the 100th cubes is:\n\n" << cube.sumSeq(4,99);

	cout << "\n\n";

	system("pause");
	return 0;
}