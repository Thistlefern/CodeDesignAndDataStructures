#pragma once

template <typename J>

class jVector
{
	const static size_t GROWTH_FACTOR = 2;

	J* arr;								// pointer to underlying array
	size_t arrSize;						// stores the number of elements currently used
	size_t arrCapacity;					// stores the capacity of the underlying array

public:
	jVector()							// initializes the vector's default values
	{
		arr = new J[1];
		arrSize = 0;
		arrCapacity = 1;
	}
	~jVector()							// destroys the underlying array
	{
		delete[] arr;
	}
	J* data()							// returns a pointer to the underlying array
	{
		arr*;
	}

	void reserve(size_t newCapacity)	// reallocates the underlying array to at least the given capacity
	{
		arrCapacity = newCapacity;
	}
	
	void add_element_to_end(const J& value)		// adds an element to the end of the vector
	{
		if(arrSize >= arrCapacity)								// checks if there is enough space to add another element
		{
			J* newData = new J[arrCapacity * GROWTH_FACTOR];	// if at/over cap, allocates more space
			for(size_t i = 0; i < arrSize; i++)					// copy data over
			{
				newData[i] = arr[i];
			}
			delete[] arr;										// delete existing array
			arr = newData;										// overwrite array with the new data
		}

		arr[arrSize] = value;									// add the new value to the vector
		++arrSize;												// increase the indicator of size, pre-loaded because its faster I guess?
	}

	void remove_last_element()						// destroys and removes the last element of the vector (NOTE: This manually calls the destructor on the removed)
	{
		arr[arrSize - 1].~J();									// destroy last element
		--arrSize;												// reduce array size by one
	}

	J& at(size_t index);				// returns the element at the given index

	size_t size() const;				// returns current number of elements
	size_t capacity() const;			// returns maximum number of elements we can store
};