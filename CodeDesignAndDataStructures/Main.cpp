#include <iostream>
#include "jVector.h"

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
	
	return 0;
}