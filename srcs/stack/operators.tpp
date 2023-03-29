template <class T, class Cont>
ft::stack<T, Cont>& ft::stack<T, Cont>::operator=(const stack& other)
{
	this->c = other.c;
	return *this;
}

template <class T, class Container>
bool operator==(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
{
	return lhs.c == rhs.c;
}

template <class T, class Container>
bool operator!=(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
{
	return lhs.c != rhs.c;
}

template <class T, class Container>
bool operator<(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
{
	return lhs.c < rhs.c;
}

template <class T, class Container>
bool operator<=(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
{
	return lhs.c <= rhs.c;
}

template <class T, class Container>
bool operator>(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
{
	return lhs.c > rhs.c;
}

template <class T, class Container>
bool operator>=(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
{
	return lhs.c >= rhs.c;
}
