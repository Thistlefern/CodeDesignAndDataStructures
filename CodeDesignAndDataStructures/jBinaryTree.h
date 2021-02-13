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
	vertex *found;
	vertex *parent;

	jBinaryTree()
	{
		root = nullptr;
		found = nullptr;
		parent = nullptr;
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
	void remove(const J &value, vertex *&start)
	{
		_searching(start, value);	// search for the value

		if(found->left == nullptr && found->right == nullptr)	// if the vertex found has no children...
		{
			vertex *toDelete = found;					// ...mark the vertex for deletion...
			
			if(found == parent->left)					// ...and make sure that the deleted vertex's parent doesn't point to anything where the vertex used to be
			{
				parent->left = nullptr;
			}
			else
			{
				parent->right = nullptr;
			}
			found = nullptr;							// reset found
			parent = root;								// reset parent to the root
			delete toDelete;							// delete the vertex
		}
		else if(found->left != nullptr && found->right != nullptr)	// if the vertex has two children...
		{
			vertex *smallestLargerThan = found->right;
			if(smallestLargerThan->left !=nullptr)
			{
				smallestLargerThan = smallestLargerThan->left;
			}

			found->data = smallestLargerThan->data;

			remove(smallestLargerThan->data, smallestLargerThan);
		}
		else	// if the vertex has one child...
		{
			if(found->left != nullptr)					// ...figure out which side the child is on...
			{
				if(parent->left = found)				// ...and set the parent's pointer appropriately to point to the child
				{
					parent->left = found->left;
				}
				else if(parent->right = found)
				{
					parent->right = found->left;
				}
			}
			else
			{
				if (parent->left = found)
				{
					parent->left = found->right;
				}
				else if (parent->right = found)
				{
					parent->right = found->right;
				}
			}
			
			vertex *toDelete = found;					// mark the vertex for deletion
			found = nullptr;							// reset found
			parent = root;								// reset parent to root
			delete toDelete;							// delete the vertex
		}
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
		if(parent == nullptr)
		{
			parent = root;
		}
	}

	bool _searching(vertex *&toSearch, const J &value)
	{
		if (toSearch == nullptr)
		{
			return false;
		}
		else if (toSearch->data == value)
		{
			found = toSearch;
			return true;
		}
		else if (toSearch->data > value)
		{
			if(toSearch != root)
			{
				parent = toSearch;
			}
			_searching(toSearch->left, value);
		}
		else
		{
			if (toSearch != root)
			{
				parent = toSearch;
			}
			_searching(toSearch->right, value);
		}
	}
};