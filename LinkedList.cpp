// William Kavanagh, CMP201 lab 3, minimal implementation
// Solution by Sam Collier - 2100259

#include "LinkedList.h"
#include <iostream>
#include <sstream>

// default Constructor
template <class T>
LinkedList<T>::LinkedList()
{
	LinkedList::head = nullptr;
}

// Single element constructor set head to new Node(n)
template<class T>
LinkedList<T>::LinkedList(T n)
{
	// TODO: Unassessed.
	// Remember a single-element LL is still circular
	head = new Node<T>(n);
	head->next = head;
	head->prev = head;
}

template<class T>
LinkedList<T>::~LinkedList()
{
	// TODO: Wipe out all nodes
	if(head == nullptr)
	{
		return;
	}
	for(int i=0;i<Size();i++)
	{
		Remove(Get(i)->data);
	}
}

// Insertion, append to LL, update references.
template<class T>
void LinkedList<T>::Insert(T n)
{
	// TODO: Assessed, 1 mark
	//		0.5 marks for forward referencing (i.e. ->next is correct)
	//		0.5 marks for backward referencing (i.e. ->prev is correct)

	if(head==nullptr)
	{
		head=new Node<T>(n);
		head->next=head;
		head->prev=head;
		return;
	}

	Node<T>* newNode = new Node<T>(n);
	newNode->next = head;
	newNode->prev = head->prev;
	head->prev->next = newNode;
	head->prev = newNode;
}

// Removal, delete first element found matching param, update references
template<class T>
void LinkedList<T>::Remove(T n)
{
	//	TODO: Assessed, 2 marks
	//		1 mark for removal of the head
	//			0.5 marks for correct head assignment
	//			0.5 marks for correct reference updating
	//		1 mark for removal from after head
	//			0.5 marks for correct forward referencing (i.e. ->next is correct)
	//			0.5 marks for correct backward referencing (i.e. ->prev is correct)
	if(head == nullptr)
	{
		return;
	}

	if(head->data == n)
	{
		if(Size() == 1)
		{
			delete head;
			head = nullptr;
			return;
		}
		Node<T>* oldHead = head;
		head->prev->next = head->next;
		head->next->prev = head->prev;
		head = head->next;
		delete oldHead;
		return;
	}

	// iterate through linked list until there's a match
	Node<T>* nodeToDelete = head->next;
	while(nodeToDelete->data != n && nodeToDelete != head)
	{
		nodeToDelete = nodeToDelete->next;
	}

	// no matches
	if(nodeToDelete == head)
	{
		return;
	}

	// there was a match so we must remove
	nodeToDelete->prev->next = nodeToDelete->next;
	nodeToDelete->next->prev = nodeToDelete->prev;
	delete nodeToDelete;
}

// Return element at position indexed by param <index>
template<class T>
Node<T>* LinkedList<T>::Get(int index)
{
	// TODO: Unassessed.
	if(head == nullptr)
	{
		return nullptr;
	}
	Node<T>* nodeToReturn = head;
	for(int i=0;i<index; i++)
	{
		nodeToReturn=nodeToReturn->next;
	}
	return nodeToReturn;
}


// Flip the order of all elements in the LL such that head becomes the tail.
template<class T>
void LinkedList<T>::Reverse()
{
	// TODO: Assessed, 2 marks
	//		1 mark for test with ints
	//		1 mark for test with std:strings

	if(head == nullptr)
	{
		return;
	}

	Node<T>* tail = GetTail();

	// swap head's next and prev
	Node<T>* oldPrev = head->prev;
	head->prev = head->next;
	head->next = oldPrev;

	// swap rest of list's next and prev
	Node<T>* currentNode = head->next;
	while(currentNode != head)
	{
		Node<T>* oldPrev = currentNode->prev;
		currentNode->prev = currentNode->next;
		currentNode->next = oldPrev;
		currentNode = currentNode->next;
	}

	// change head to old tail
	head = tail;
}

// return count of elements in LL
template<class T>
int LinkedList<T>::Size()
{
	// TODO: Unassessed
	if(head == nullptr)
		return 0;
	int size = 1;
	Node<T>* counter = head->next;
	for(Node<T>* counter = head->next; counter != head; size++)
	{
		counter = counter->next;
	}
	return size;
}

// Convert all elements into a vector 
template<class T>
std::vector<T> LinkedList<T>::ToVector()
{

	// TODO: Unassessed.
	// Use lecture 3B on vectors for reference on declaring and inserting.
	if(head == nullptr)
	{
		return {};
	}
	std::vector<T> returnVector;
	for(int i=0;i<Size();i++)
	{
		returnVector.push_back(Get(i)->data);
	}
	return returnVector;
}

// Return pointer to the tail 
template<class T>
Node<T>* LinkedList<T>::GetTail()
{
	// TODO: Unassessed.
	// this will be very short (remember we're DOUBLY linked)
	if(head == nullptr)
	{
		return nullptr;
	}
	return head->prev;
}

// A generic toString
template<class T>
std::string LinkedList<T>::ToString()
{
	std::ostringstream oss;  
	Node<T>* t = head;
	while (t)
	{
		oss << t->data;
		// comma if there is more to come.
		if (t->next != head)
		{
			oss << ", ";
		}
		else
		{
			break;	// we're done, leave.
		}
		t = t->next;
	}
	return "[" + oss.str() + "]\n";	// end and newline.
}

