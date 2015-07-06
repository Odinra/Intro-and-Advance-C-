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

	int random = rand() % 10 + 1;
	int num;
	for(int i = 0; i < random; i++)
	{
		num = rand()%100 + 1;
		list.add(num);
		cout << num << "\t";
	}

	ReliableLinkedList list2(list);

	double guess;

	cout << "\nPlease guess a number between 1 and 100 to see if it appears on the \ncopy constructered linked list2\n";
	cin >> guess;

	if (list2.isMember(guess))
		cout << "\nNice Guess! That number was in the List2!\n";
	else
		cout << "\nDang! that number doesnt exist in the List2\n";
	system("pause");
	return 0;
}