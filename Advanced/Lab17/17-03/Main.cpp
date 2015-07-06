/*CK King
Section 1031
Started 07/25/12*/

#include "LinkedList.h"
#include <cstdlib>
#include <ctime>

int main()
{
	ReliableLinkedList list;

	unsigned seed = time(0);
	srand(seed);

	int random = rand() % 100 + 1;
	int num;
	for(int i = 0; i < random; i++)
	{
		num = rand()%100 + 1;
		list.add(num);
	}

	cout << "\nThe List contains the following numbers:\n";
	list.print();
	system("pause");
	return 0;
}