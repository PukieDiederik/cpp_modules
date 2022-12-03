#include "Span.hpp"
#include <algorithm>
#include <stdexcept>

// Constructors/Destructors
Span::Span(int n) : m_size(n), m_amount_added(0)
{
	if (m_size < 2)
		throw std::runtime_error("Invalid size");
	m_nums = new int[m_size];
}

Span::Span(const Span& copy) // copy constructor
{
	*this = copy;
}

Span::~Span() // destructor
{
	delete[] m_nums;
}

// Operators
Span& Span::operator=(const Span& copy) //copy-assignment
{
	delete[] m_nums;
	m_size = copy.m_size;
	m_amount_added = copy.m_amount_added;
	m_nums = new int[m_size];
	std::copy(copy.m_nums, copy.m_nums + copy.m_amount_added, m_nums);
	return *this;
}

// Functions
int Span::shortestSpan() const
{
	if (m_amount_added < 2)
		throw std::runtime_error("Not enough numbers");
	int *n = new int[m_amount_added];
	std::copy(m_nums, m_nums + m_amount_added, n);
	std::sort(n, n + m_amount_added);
	int shortest = std::abs(n[0] - n[1]);
	for (int i = 1; i < m_amount_added - 1; ++i)
	{
		if (std::abs(n[i] - n[i + 1]) < shortest)
			shortest = std::abs(n[i] - n[i + 1]);
	}
	delete[] n;
	return shortest;
}

// smallest and biggest number should make the biggest span
int Span::longestSpan() const
{
	if (m_amount_added < 2)
		throw std::runtime_error("Not enough numbers");
	return *std::max_element(m_nums, m_nums + m_amount_added)
		 - *std::min_element(m_nums, m_nums + m_amount_added);
}
void Span::addNumber(int n)
{
	if (m_amount_added >= m_size)
		throw std::runtime_error("Too many numbers added");
	m_nums[m_amount_added] = n;
	++m_amount_added;
}