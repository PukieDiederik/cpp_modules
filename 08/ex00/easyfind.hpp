#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

// Returns a::iterator.end when it is not found
template<typename T>
typename T::iterator easyfind(T& a, int to_find)
{
	return std::find(a.begin(), a.end(), to_find);
}

#endif
