#include <iostream>
#include "jVector.h"
#include "jList.h"
#include "hashing.h"
#include "jBinaryTree.h"

int main()
{
	/*jList<int> list;

	list.pushBack(1);
	list.pushBack(2);

	jList<int> secondList;

	secondList.pushFront(10);
	secondList.pushFront(9);
	secondList.pushFront(8);

	std::cout << secondList.front() << std::endl;
	std::cout << secondList.back() << std::endl;

	secondList = list;

	std::cout << secondList.front() << std::endl;
	std::cout << secondList.back() << std::endl;*/

	/*jBinaryTree<int> tree;
	tree.insert(10);
	tree.insert(20);
	tree.insert(8);
	tree.insert(14);
	tree.insert(9);
	tree.insert(11);
	tree.insert(15);
	tree.insert(21);

	std::cout << tree.root << std::endl;
	std::cout << tree.root->data << std::endl;

	tree.remove(10, tree.root);

	std::cout << tree.root << std::endl;
	std::cout << tree.root->data << std::endl;*/

	//jList<int> numbers;
	//numbers.pushBack(1);
	//numbers.pushBack(2);
	//numbers.pushBack(3);

	//// assigning to an existing but empty list
	//jList<int> otherNumbers;
	//otherNumbers = numbers;

	//std::cout << numbers.back() << std::endl; // should be 3
	//std::cout << otherNumbers.back() << std::endl; // should be 3

	//otherNumbers.removeBack(); // drop 3 from the copied list

	//std::cout << numbers.back() << std::endl;
	//std::cout << otherNumbers.back() << std::endl;

	//auto it = numbers.begin();
	//++it;
	//++it;
	//bool isPastTheEnd = it == numbers.end(); // this should be true
	//std::cout << isPastTheEnd;

	jBinaryTree<int> tree;
	tree.insert(4);
	tree.insert(2);
	tree.insert(6);
	tree.insert(1);
	tree.insert(5);
	tree.insert(8);
	tree.insert(9);

	jBinaryTree<int>::vertex *nullVertex = nullptr;
	jBinaryTree<int>::vertex *temp = nullptr;

	tree.search(8, temp);
	tree.remove(temp);

	tree.search(6, temp);

	return 0;
}
