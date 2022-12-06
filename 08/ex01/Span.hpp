#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span {
private:
	std::vector<int> m_nums;
	int m_size;
	int m_amount_added;

	// Constructors/Destructors
	Span(); // default constructor
public:
	// Constructors/Destructors
	Span(const Span& copy); // copy constructor
	Span(int n);

	~Span(); // destructor

	// Operators
	Span& operator=(const Span& copy); //copy-assignment

	// Functions
	int shortestSpan() const;
	int longestSpan() const;
	void addNumber(int n);

	template<typename T>
	void addNumbers(const typename T::iterator& begin, const typename T::iterator& end)
	{
		for (typename T::iterator i = begin; i != end; i++)
			addNumber(*i);
	}
};

#endif
