#include <cstring>
#include <stdexcept>
#include <string>

template <typename T>
Array<T>::Array() :m_arr(NULL), m_size(0) { }
template <typename T>
Array<T>::Array(unsigned int n) :m_arr(new T[n]()), m_size(n) { }
template <typename T>
Array<T>::Array(Array<T>& copy) :m_arr(NULL)
{
	*this = copy;
}

template <typename T>
Array<T>::~Array()
{
	if (m_arr)
		delete[] m_arr;
}

// Operators
template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& copy)
{
	if (m_arr)
		delete[] m_arr;
	m_size = copy.m_size;
	m_arr = new T[m_size]();
	std::memcpy(m_arr, copy.m_arr, sizeof(T) * m_size);
	return *this;
}
template <typename T>
T& Array<T>::operator[](int n) {
	if (n < 0 || static_cast<unsigned int>(n) >= m_size)
		throw (std::range_error("out of range"));
	return m_arr[n];
}

// Functions
template <typename T>
unsigned int Array<T>::size() const
{
	return m_size;
}