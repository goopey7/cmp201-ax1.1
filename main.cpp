#include <iostream>

#include "LinkedList.h"
#include "LinkedList.cpp"

int main()
{
	// Test 1: Ints and insertion.
	LinkedList<int>* ll = new LinkedList<int>();	// Make an empty linked list for ints
	ll->Insert(5);				// insert when empty.
	std::cout << "expecting [5], got: " << ll->ToString();

	ll->Insert(10);
	ll->Insert(20);
	ll->Insert(10);
	std::cout << "expecting [5, 10, 20, 10], got: " << ll->ToString();

	// Test 2: Removal
	ll->Remove(10);
	std::cout << "expecting [5, 20, 10], got: " << ll->ToString();

	LinkedList<char>* llChar = new LinkedList<char>('x');	// Make a ll<char>: {x}
	llChar->Remove('x');	// test removal from head
	std::cout << "expecting [], got: " << llChar->ToString();

	// Test 3: Reversal
	llChar->Insert('a');	// should be empty, add 'a', 'b', 'c'
	llChar->Insert('b');
	llChar->Insert('c');
	llChar->Reverse();		// reverse in place.
	std::cout << "expecting [c, b, a], got: " << llChar->ToString();
	ll->Reverse();
	std::cout << "expecting [10, 20, 5], got: " << ll->ToString();
	delete ll;
	delete llChar;

	// Test 4: Empty List
	LinkedList<int>* el = new LinkedList<int>();
	el->Remove(4);
	el->Reverse();
	el->Get(2);
	el->Size();
	std::vector<int> empty = el->ToVector();
	std::cout << "EMPTY LIST: " << el->ToString();
	return 0;
}


