#pragma once

template <typename J>

class jList
{
	struct node
	{
		J data;						// data for the element stored
		node *prev;					// pointer to the previous node
		node *next;					// pointer to the next node
	};

	node *head;						// pointer to the head of the linked list
	node *tail;						// pointers to the tail of the linked list

public:
	jList()							// initializes head and tail to null
	{
		head = nullptr;
		tail = nullptr;
	}
	~jList()						// delete all nodes
	{
		while(head !=nullptr)
		{
			node *oldHead = head;			// creates a new node just to point to the head
			head = oldHead->next;			// head becomes whatever the old head was			
			if (head != nullptr)				// if head isn't null, sets the new head's previous pointer to null
			{
				head->prev = nullptr;
			}
			else
			{
				tail = nullptr;
			}
			delete oldHead;					// delete the data of the old head
		}
	}

	void pushFront(const J& val)	// adds element to front (i.e. head)
	{
		node *newNumber = new node();	// creates a new node for the number being added
		newNumber->data = val;			// sets the data of the new node to equal the given value
		newNumber->prev = nullptr;		// sets the previous pointer to null, as this number will be the new head
		newNumber->next = head;			// sets the next pointer to the OLD head, PRIOR to setting this number as the new head
		
		if(head != nullptr)
		{
			head->prev = newNumber;
		}
		
		head = newNumber;				// sets the head to be the new number
		
		if(tail == nullptr)				// if this is the first number added (ie tail is still null), this number is also the tail
		{
			tail = newNumber;
		}
	}
	void removeFront()				// removes element from head
	{
		node *oldHead = head;			// creates a new node just to point to the head
		head = oldHead->next;			// head becomes whatever the old head was			
		if(head != nullptr)				// if head isn't null, sets the new head's previous pointer to null
		{
			head->prev = nullptr;
		}
		else
		{
			tail = nullptr;
		}
		delete oldHead;					// delete the data of the old head
	}
	void pushBack(const J& val)		// adds element to back (i.e. tail)
	{
		node *newNumber = new node();	// creates a new node for the number being added
		newNumber->data = val;			// sets the data of the new node to equal the given value
		newNumber->prev = tail;			// sets the previous pointer to the OLD tail, PRIOR to setting this number as the new tail
		newNumber->next = nullptr;		// sets the next pointer to null, as this number will be the new tail
		
		tail = newNumber;				// sets the tail to be the new number
		
		if (head == nullptr)			// if this is the first number added (ie head is still null), this number is also the head
		{
			head = newNumber;
		}
	}
	void removeBack()				// removes element from tail
	{
		node *oldTail = tail;			// creates a new node just to point to the head
		head = oldTail->prev;			// head becomes whatever the old head was			
		if (tail != nullptr)			// if head isn't null, sets the new head's previous pointer to null
		{
			tail->next = nullptr;
		}
		else
		{
			head = nullptr;
		}
		delete oldTail;					// delete the data of the old head
	}

	J& front()						// returns the element at the head
	{
		return head->data;
	}
	J& back()						// returns the element at the tail
	{
		return tail->data;
	}

	jList(const jList &other)		// copy-constructor
	{
		// used Terry's code, because none of my implementations worked and his makes sense to me
		node *otherNode = other.tail;
		while(otherNode != nullptr)
		{
			pushFront(otherNode->data);
			otherNode = otherNode->prev;
		}
	}
	jList &operator=(const jList &other)	// copy-assignment
	{
		node *otherNode = other.tail;
		while (otherNode != nullptr)
		{
			pushFront(otherNode->data);
			otherNode = otherNode->prev;
		}
		delete otherNode;
		return *this;
	}

	const J &front() const			// returns the element at the head (const)
	{
		return head->data;
	}
	const J &back() const			// returns the element at the tail (tail)
	{
		return tail->data;
	}

	void remove(const J &val)		// removes all nodes equal to the given value
	{
		node *search = head;
		// while we're working on a valid node (non-null)
		while(search != nullptr)
		{
			node *next = search->next;

			// do some things
			if (search->data == val)
			{
				node *searchPrev = search->prev;
				node *searchNext = search->next;

				// if searchPrev is null, then we know that this node is at the head
				// so rather than updating searchPrev, we need to update head
				if(searchPrev == nullptr)
				{
					head = searchNext;
					head->prev = nullptr;
				}
				else
				{
					searchPrev->next = searchNext;
				}

				if (searchNext == nullptr)
				{
					tail = searchPrev;
					tail->next = nullptr;
				}
				else
				{
					searchNext->prev = searchPrev;
				}

				// if searchNext is null, then we know that this node is at the TAIL
				// so rather than updating searchNExt, we need to update TAIL

				delete search;
			}

			search = next;
		}
	}

	bool empty() const
	{
		if(head == nullptr && tail == nullptr)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	void clear()
	{
		while(head != nullptr)
		{
			removeFront();
		}
	}

	void resize(size_t newSize)
	{
		// TODO
	}
};