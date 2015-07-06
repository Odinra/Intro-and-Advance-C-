#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>

using namespace std;

class LinkedList
{
protected:
	struct ListNode
	{
		double value;
		ListNode *next;
		ListNode(double Value1, ListNode *next1 = NULL)
		{
			value = Value1;
			next = next1;
		}
	};
	
public:
	ListNode *head;
	LinkedList(void) { head = NULL; };
	void add(double x);
	bool isMember(double x);
	~LinkedList(void);
};

#endif