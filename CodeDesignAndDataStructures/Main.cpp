#include <iostream>
#include "jVector.h"
#include "jList.h"

int main()
{
	jVector<int> original;
	original.add_element_to_end(4);
	original.add_element_to_end(5);
	original.add_element_to_end(6);

	jVector<int> copy = original;
	copy.remove_last_element();
	copy.remove_last_element();

	std::cout << original.size() << std::endl;
	std::cout << copy.size() << std::endl;

	jList<int> list;
	list.pushFront(12);
	list.pushFront(3);
	list.pushBack(7);

	std::cout << list.front() << std::endl;
	std::cout << list.back() << std::endl;
	
	return 0;
}