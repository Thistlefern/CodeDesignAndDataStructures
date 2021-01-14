#pragma once

template <typename J>

class jVector
{
	const static size_t GROWTH_FACTOR = 2;

	J* arr;								// pointer to underlying array
	size_t arrSize;						// stores the number of elements currently used
	size_t arrCapacity;					// stores the capacity of the underlying array

public:
	jVector();							// initializes the vector's default values
	~jVector();							// destroys the underlying array
	
	//J* data()							// returns a pointer to the underlying array
	//{
	//	*arr;
	//}

	jVector(const jVector& vec);			// copy constructs a vectorfrom another vector

	jVector& operator=(const jVector& vec)	// copies the contents of the provided vector into this vector
	{
		J* newArray = new J[vec.arrSize];
		arrSize = vec.arrSize;
		arrCapacity = vec.arrSize;
		for(size_t i = 0; i < arrSize; i++)
		{
			newArray[i] = vec[i];
		}
		return this;
	}

	void reserve(size_t newCapacity);	// reallocates the underlying array to at least the given capacity

	void add_element_to_end(const J& value);		// adds an element to the end of the vector

	void remove_last_element();						// destroys and removes the last element of the vector (NOTE: This manually calls the destructor on the removed)

	J& at(size_t index);							// returns the element at the given index

	size_t size() const;								// returns current number of elements
	size_t capacity() const;							// returns maximum number of elements we can store
};

template <typename J>
jVector<J>::jVector()					// initializes the vector's default values
{
	arr = new J[1];
	arrSize = 0;
	arrCapacity = 1;
}

template <typename J>
jVector<J>::~jVector()					// destroys the underlying array
{
	delete[] arr;
}

template <typename J>
jVector<J>::jVector(const jVector& vec)	// copy constructs a vector from another vector
{
	arr = new J[vec.arrSize];
	arrSize = vec.arrSize;
	arrCapacity = vec.arrSize;
	for (size_t i = 0; i < arrSize; i++)
	{
		arr[i] = vec.arr[i];
	}
}

//template <typename J>
//J& operator=(jVector& vec) const	// copies the contents of the provided vector into this vector
//{
//
//}

template <typename J>
void jVector<J>::reserve(size_t newCapacity)
{
	arrCapacity = newCapacity;
}

template <typename J>
void jVector<J>::add_element_to_end(const J& value)
{
	if (arrSize >= arrCapacity)								// checks if there is enough space to add another element
	{
		arrCapacity *= GROWTH_FACTOR;
		J* newData = new J[arrCapacity * GROWTH_FACTOR];	// if at/over cap, allocates more space
		for (size_t i = 0; i < arrSize; i++)					// copy data over
		{
			newData[i] = arr[i];
		}
		delete[] arr;										// delete existing array
		arr = newData;										// overwrite array with the new data
	}

	arr[arrSize] = value;									// add the new value to the vector
	++arrSize;												// increase the indicator of size, pre-loaded because its faster I guess?
}
template <typename J>
void jVector<J>::remove_last_element()
{
	arr[arrSize - 1].~J();									// destroy last element
	--arrSize;												// reduce array size by one
}

template <typename J>
J& jVector<J>::at(size_t index)								// returns the element at the given index
{
	arr[index];
}

template <typename J>
size_t jVector<J>::size() const								// returns current number of elements
{
	return arrSize;
}

template <typename J>
size_t jVector<J>::capacity() const							// returns maximum number of elements we can store
{
	return arrCapacity;
}