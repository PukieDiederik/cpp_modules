// Constructors/Destructors
template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() { }

template <typename T>
MutantStack<T>::MutantStack(MutantStack<T>& copy) : std::stack<T>(copy) { }

template <typename T>
MutantStack<T>::~MutantStack() { }

// Operators
template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& copy)
{
	std::stack<T>::operator=(copy);
	return *this;
}

//Iterators
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() { return this->c.begin(); }

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const { return this->c.begin(); }

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() { return this->c.end(); }

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const { return this->c.end(); }


// Reverse operators
template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin() { return this->c.rbegin(); }

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend() { return this->c.rend(); }

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const { return this->c.rbegin(); }

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const { return this->c.rend(); }

// Explicit const operators
template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cbegin() const { return this->c.cbegin(); }

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cend() const { return this->c.cend(); }

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crbegin() const { return this->c.crbegin(); }

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crend() const { return this->c.crend(); }

//	const_iterator cbegin();
//	const_reverse_iterator crbegin() const;
//	const_iterator cend();
//	const_reverse_iterator crend() const;