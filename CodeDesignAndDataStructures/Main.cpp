#include <iostream>
#include "jVector.h"
#include "jList.h"

int main()
{
	/*jVector<int> original;
	original.add_element_to_end(4);
	original.add_element_to_end(5);
	original.add_element_to_end(6);

	jVector<int> copy = original;
	copy.remove_last_element();
	copy.remove_last_element();

	std::cout << original.size() << std::endl;
	std::cout << copy.size() << std::endl;*/

	jList<int> list;
	list.pushFront(12);		// head = 12, tail = 12
	list.pushFront(3);		// head = 3, tail = 12
	list.pushBack(7);		// head = 3, tail = 7

	std::cout << "First list head:" << list.front() << std::endl;		// prints head, should be 3
	std::cout << "First list tail:" << list.back() << std::endl;		// print tail, should be 7

	jList<int>copyList(list);	// copy-constructs firts list (makes NEW list, and copies data without linking the lists)
	std::cout << "Second list is copy-constructed" << std::endl;
	
	std::cout << "Second list head:" << copyList.front() << std::endl;	// prints head of new list, should be 3

	list.pushFront(17);		// changes head of FIRST list to 17
	std::cout << "First list has new value pushed to front, to make sure that second list isn't linked just copied" << std::endl;

	std::cout << "First list head:" << list.front() << std::endl;		// prints head of first list, should be 17
	std::cout << "Second list head:" << copyList.front() << std::endl;	// prints head of second list, should be 3

	copyList = list;		// copy-assigns data from first list into second list
	std::cout << "Second list is copy-assigned, to check copy-assignment function" << std::endl;

	std::cout << "Second list head:" << copyList.front();				// prints head of second list, should be 17
	
	return 0;
}