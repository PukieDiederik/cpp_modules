#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

// Returns a::iterator.end when it is not found
template<typename T>
typename T::iterator easyfind(T& a, int to_find)
{
	for (auto i = a.begin(); i != a.end(); ++i)
	{
		if (*i == to_find)
			return i;
	}
	return i;
}

#endif
