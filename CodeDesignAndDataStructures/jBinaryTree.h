#pragma once

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

	jBinaryTree()
	{
		root = nullptr;
	}
	~jBinaryTree()
	{
		// TODO implement later
	}

	void insert(const J &value)
	{
		if(root == nullptr)
		{
			root = value;
		}
		else // TODO while loop?
	}

private:
	std::vector<vertex *> vertices;
	vertex *root;
};