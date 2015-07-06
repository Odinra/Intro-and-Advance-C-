#include "LinkedList.h"

ReliableLinkedList::ReliableLinkedList(const ReliableLinkedList& first)
{
	head = copyList(first.head);
}

LinkedList::ListNode *
ReliableLinkedList::copyList(ListNode *aList)
{
	if (aList == NULL)
		return NULL;
	else
	{
		ListNode *tailCopy = copyList(aList->next);
		return new ListNode(aList->value, tailCopy);
	}
}

void ReliableLinkedList::destroyList(ListNode * aList)
{
	if (aList != NULL)
	{
		ListNode *tail = aList->next;
		delete aList;
		destroyList(tail);
	}
}

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

void LinkedList::print()
{
	ListNode *nodePtr = head;
	while (nodePtr)
	{
		cout << nodePtr->value << "\t";
		nodePtr = nodePtr->next;
	}
}