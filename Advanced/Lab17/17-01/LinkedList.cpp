#include "LinkedList.h"



LinkedList::~LinkedList(void)
{
}

void LinkedList::add(double x)
{
	if(head == NULL)
		head = new ListNode(x);
	else
	{
		ListNode *nodePtr = head;
		while (nodePtr->next != NULL)
			nodePtr = nodePtr->next;

		nodePtr->next = new ListNode(x);
	}
}
bool LinkedList::isMember(double x)
{
	ListNode *nodePtr = head;
	while (nodePtr != NULL)
	{
		if ( nodePtr->value == x)
		{
			return true;
		}
		else
		{
			nodePtr = nodePtr->next;
		}
	}
	return false;
}