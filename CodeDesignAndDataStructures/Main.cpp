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

	jBinaryTree<int> tree;
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
	std::cout << tree.root->data << std::endl;

	return 0;
}
