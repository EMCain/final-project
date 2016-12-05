#include "LinkedList.h"
#include <iostream>
using namespace std;



LinkedList::LinkedList()
{
	first = 0;
	last = 0;
	curNode = 0;
	listLen = 0;
}

LinkedList::~LinkedList()
{
  //  delete all nodes
  curNode = first;
	while(curNode){
		Node* newNode = curNode->next_;
		delete curNode;
		curNode = newNode;
	}
}



void LinkedList::AddLinkToBack(void * ptr)
{
	{
		//Creates new node and adds the data to it
		Node* newNode = new Node();
		newNode->data_ = ptr;
		newNode->next_ = 0;

		if (first == 0)
		{
			first = newNode;
			last = newNode;
		}
		else
		{
			//makes the previous node point the new last node

			last->next_ = newNode;

			// Update the last ptr to this new node
			last = newNode;
		}

		listLen++;
	}
}


void* LinkedList::RemoveLinkFromFront()
{
	void* ptr = 0;

	if (first != 0)
	{
		// Store the ptr to the stored
		ptr = first->data_;

		// Store the ptr to the new first
		Node* newFirst = first->next_;

		// Free memory o
		delete first;

		// Update the first ptr to point to the next node
		first = newFirst;

		listLen--;
	}

	return ptr;
}

void* LinkedList::GetFirstNode()
{
	void* dataPtr = 0;

	if (first != 0)
	{
		dataPtr = first->data_;
		curNode = first->next_;
	}

	return dataPtr;
}

void* LinkedList::GetNextNode()
{
	void* dataPtr = 0;

	if (curNode != 0)
	{
		dataPtr = curNode->data_;
		curNode = curNode->next_;
	}

	return dataPtr;
}
long LinkedList::GetListLength()
{
	return listLen;
}
