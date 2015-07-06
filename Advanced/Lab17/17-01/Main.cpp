/*CK King
Section 1031
Started 07/25/12*/

#include "LinkedList.h"
#include <cstdlib>
#include <ctime>

int main()
{
	LinkedList list;

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

	double guess;

	cout << "\nPlease guess a number between 1 and 100 to see if it appearedn on the link list\n";
	cin >> guess;

	if (list.isMember(guess))
		cout << "\nNice Guess! That number was in the List!\n";
	else
		cout << "\nDang! that number doesnt exist in the List\n";

	//cout << "The Numbers in the list are:\n";

	//while (list.head != NULL)
	//{
	//	cout << *list->head << "\t";
	//}


	system("pause");
	return 0;
}