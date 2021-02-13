#pragma once

#include <vector>

template <typename J>

class jBinaryTree
{
public:

	struct vertex
	{
		J data;			// data stored in this vortex
		vertex *left;	// left connection
		vertex *right;	// right connection

		bool hasLeft() const
		{
			if (this->left != nullptr)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		bool hasRight() const
		{
			if (this->right != nullptr)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		vertex()
		{
			left = nullptr;
			right = nullptr;
		}
	};

	vertex *root;

	jBinaryTree()
	{
		root = nullptr;
	}
	~jBinaryTree()
	{
		while(root != nullptr)
		{
			vertex *current = root;
			if(current->left != nullptr)
			{
				current = current->left;
			}
			else if(current->right !=nullptr)
			{
				current = current->right;
			}
			else
			{
				current = nullptr;
			}
		}
	}

	void insert(const J &value)
	{
		_insertRecursive(root, value);
	}
	bool search(const J &value)
	{
		return _searching(root, value);
	}
	void remove(const J &value)
	{
	//	vertex *parent = root;
	//	if(parent->left != nullptr)
	//	{
	//		vertex *current = root->left;
	//	}
	//	// TODO ELSE
	//	
	//	while(current != nullptr)
	//	{
	//		if (current->data == value)
	//		{
	//			if(current->left == nullptr && current->right == nullptr)
	//			{
	//				current = nullptr;
	//			}
	//			else if(current->left != nullptr && current->right != nullptr)
	//			{
	//				// deleting node with two children
	//			}
	//			else
	//			{

	//			}
	//		}
	//		else if (current->data > value)
	//		{
	//			current = current->left;
	//		}
	//		else
	//		{
	//			current = current->right;
	//		}
	//	}
	}

private:
	std::vector<vertex *> vertices;
	void _insertRecursive(vertex *&current, const J &value)
	{
		if (current == nullptr)
		{
			current = new vertex();
			current->data = value;
			vertices.push_back(current);
		}
		else if (value < current->data)
		{
			_insertRecursive(current->left, value);
		}
		else if(value > current->data)
		{
			_insertRecursive(current->right, value);
		}
	}

	bool _searching(vertex *&current, const J &value)
	{
		if(current == nullptr)
		{
			return false;
		}
		else if(current->data == value)
		{
			vertex &found = *current;
			return true;
		}
		else if(current->data > value)
		{
			_searching(current->left, value);
		}
		else
		{
			_searching(current->right, value);
		}
	}
};