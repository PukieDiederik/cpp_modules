#ifndef ARRAY_HPP
#define ARRAY_HPP

template<typename T>

class Array
{
private:
	T* m_arr;
	unsigned int m_size;
public:
	// Constructors/Destructor
	Array();
	Array(unsigned int n);
	Array(Array<T>& copy);

	~Array();

	// Operators
	Array<T>& operator=(const Array<T>& copy);
	T& operator[](int n);

	// Functions
	unsigned int size() const;
};

#include "Array.inl"

#endif
