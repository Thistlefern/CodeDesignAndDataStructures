#include <iostream>
#include "jVector.h"
#include "jList.h"
#include "hashing.h"

int main()
{
	// ********** Testing vector functions **********
	/*jVector<int> original;
	original.add_element_to_end(4);
	original.add_element_to_end(5);
	original.add_element_to_end(6);

	jVector<int> copy = original;
	copy.remove_last_element();
	copy.remove_last_element();

	std::cout << original.size() << std::endl;
	std::cout << copy.size() << std::endl;*/

	// ********** Testing list functions **********
	//jList<int> list;
	//list.pushFront(12);		// head = 12, tail = 12
	//list.pushFront(3);		// head = 3, tail = 12
	//list.pushBack(7);		// head = 3, tail = 7

	//std::cout << "First list head: " << list.front() << std::endl;		// prints head, should be 3
	//std::cout << "First list tail: " << list.back() << std::endl;		// print tail, should be 7

	//jList<int>copyList(list);	// copy-constructs firts list (makes NEW list, and copies data without linking the lists)
	//std::cout << "Second list is copy-constructed" << std::endl;
	//
	//std::cout << "Second list head: " << copyList.front() << std::endl;	// prints head of new list, should be 3

	//list.pushFront(17);		// changes head of FIRST list to 17
	//std::cout << "First list has new value pushed to front, to make sure that second list isn't linked just copied" << std::endl;

	//std::cout << "First list head: " << list.front() << std::endl;		// prints head of first list, should be 17
	//std::cout << "Second list head: " << copyList.front() << std::endl;	// prints head of second list, should be 3

	//copyList = list;		// copy-assigns data from first list into second list
	//std::cout << "Second list is copy-assigned, to check copy-assignment function" << std::endl;

	//std::cout << "Second list head: " << copyList.front();				// prints head of second list, should be 17
	
	// ********** Testing remove function **********

	/*jList<int> list;
	list.pushFront(14);
	list.pushFront(16);
	list.pushFront(15);
	list.pushFront(18);
	list.pushFront(12);
	list.pushFront(15);
	list.pushFront(13);
	list.pushFront(12);

	std::cout << "List head: " << list.front() << std::endl;
	std::cout << "List tail: " << list.back() << std::endl;*/
	
	//list.remove(15);														// removing 15, a value that appears in the middle of the list
	//std::cout << "All nodes with value of 15 are removed" << std::endl;
	//std::cout << "List head: " << list.front() << std::endl;
	//std::cout << "List tail: " << list.back() << std::endl;

	//list.remove(14);
	//std::cout << "All nodes with value of 14 are removed" << std::endl;		// removing 14, to make sure the tail is removed
	//std::cout << "List head: " << list.front() << std::endl;
	//std::cout << "List tail: " << list.back() << std::endl;

	//list.remove(12);
	//std::cout << "All nodes with value of 12 are removed" << std::endl;		// removing 12, to make sure the head is removed
	//std::cout << "List head: " << list.front() << std::endl;
	//std::cout << "List tail: " << list.back() << std::endl;

	//list.remove(23);
	//std::cout << "All nodes with value of 23 are removed" << std::endl;		// removing 23, to make sure there are no errors with "removing" a value that doesn't exist
	//std::cout << "List head: " << list.front() << std::endl;
	//std::cout << "List tail: " << list.back() << std::endl;

	//list.remove(16);
	//std::cout << "All nodes with value of 16 are removed" << std::endl;
	//std::cout << "List head: " << list.front() << std::endl;
	//std::cout << "List tail: " << list.back() << std::endl;

	hash("Josie");
	hash("Thistle");
	hash("gay");
	hash("josie");
	hash("Josie");

	return 0;
}