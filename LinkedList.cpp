// William Kavanagh, CMP201 lab 3, minimal implementation
// Solution by Sam Collier - 2100259

#include "LinkedList.h"
#include <iostream>

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
}

template<class T>
LinkedList<T>::~LinkedList()
{
}

// Insertion, append to LL, update references.
template<class T>
void LinkedList<T>::Insert(T n)
{
	// TODO: Assessed, 1 mark
	//		0.5 marks for forward referencing (i.e. ->next is correct)
	//		0.5 marks for backward referencing (i.e. ->prev is correct)
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
}

// Return element at position indexed by param <index>
template<class T>
Node<T>* LinkedList<T>::Get(int index)
{
	// TODO: Unassessed.
	
	Node<T>* temp;
	return temp;
}


// Flip the order of all elements in the LL such that head becomes the tail.
template<class T>
void LinkedList<T>::Reverse()
{
	// TODO: Assessed, 2 marks
	//		1 mark for test with ints
	//		1 mark for test with std:strings
}

// return count of elements in LL
template<class T>
int LinkedList<T>::Size()
{
	// TODO: Unassessed
}

// Convert all elements into a vector 
template<class T>
std::vector<T> LinkedList<T>::ToVector()
{

	// TODO: Unassessed.
	// Use lecture 3B on vectors for reference on declaring and inserting.
	std::vector<T> returnVector;
	return returnVector;
}

// Return pointer to the tail 
template<class T>
Node<T>* LinkedList<T>::GetTail()
{
	// TODO: Unassessed.
	// this will be very short (remember we're DOUBLY linked)
}

// A generic toString (numeric types typically)
template<class T>
std::string LinkedList<T>::ToString()
{
	std::string returnString = "[";
	Node<T>* t = head;
	while (t)
	{
		returnString += std::to_string(t->data);
		// comma if there is more to come.
		if (t->next != head)
		{
			returnString += ", ";
		}
		else
		{
			break;	// we're done, leave.
		}
		t = t->next;
	}
	return returnString + "]\n";	// end and newline.
}

// specific toString for ll<std::string> 
template <>
std::string LinkedList<std::string>::ToString()
{
	std::string returnString = "[";
	Node<std::string>* t = head;
	while (t)
	{
		returnString += t->data;

		// comma if there is more to come.
		if (t->next != head)
		{
			returnString += ", ";
		}
		else
		{
			break;	// we're done, leave.
		}
		t = t->next;
	}
	return returnString + "]\n";	// end and newline.
}

// specific toString for ll<char> 
template <>
std::string LinkedList<char>::ToString()
{
	std::string returnString = "[";
	Node<char>* t = head;
	while (t)
	{
		returnString += t->data;

		// comma if there is more to come.
		if (t->next != head)
		{
			returnString += ", ";
		}
		else
		{
			break;	// we're done, leave.
		}
		t = t->next;
	}
	return returnString + "]\n";	// end and newline.
}

