#include "Span.hpp"
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <iostream>

// Constructors/Destructors
Span::Span(unsigned int n) : m_nums(0), m_size(n), m_amount_added(0)
{
	if (m_size < 2)
		throw std::runtime_error("Invalid size");
}

Span::Span(const Span& copy) // copy constructor
{
	*this = copy;
}

Span::~Span() { }// destructor

// Operators
Span& Span::operator=(const Span& copy) //copy-assignment
{
	m_size = copy.m_size;
	m_amount_added = copy.m_amount_added;
	m_nums = copy.m_nums;
	return *this;
}

// Functions
int Span::shortestSpan() const
{
	if (m_amount_added < 2)
		throw std::runtime_error("Not enough numbers");
	std::vector<int> n(m_nums);
	std::sort(n.begin(), n.end());
	int shortest = std::abs(n[0] - n[1]);
	typedef std::vector<int>::size_type s_t;
	for (s_t i = 1; i < static_cast<s_t>(m_amount_added) - 1; ++i)
	{
		if (std::abs(n[i] - n[i + 1]) < shortest)
			shortest = std::abs(n[i] - n[i + 1]);
	}
	return shortest;
}

// smallest and biggest number should make the biggest span
int Span::longestSpan() const
{
	if (m_amount_added < 2)
		throw std::runtime_error("Not enough numbers");
	return *std::max_element(m_nums.begin(),m_nums.end())
		 - *std::min_element(m_nums.begin(), m_nums.end());
}
void Span::addNumber(int n)
{
	if (m_amount_added >= m_size)
		throw std::runtime_error("Too many numbers added");
	m_nums.push_back(n);
	++m_amount_added;
}