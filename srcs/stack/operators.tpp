template <class T, class Cont>
ft::stack<T, Cont>& ft::stack<T, Cont>::operator=(const stack& other)
{
	this->_cont = other._cont;
	return *this;
}

template <class T, class Container>
bool operator==(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
{
	return lhs._cont == rhs._cont;
}

template <class T, class Container>
bool operator!=(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
{
	return lhs._cont != rhs._cont;
}

template <class T, class Container>
bool operator<(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
{
	return lhs._cont < rhs._cont;
}

template <class T, class Container>
bool operator<=(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
{
	return lhs._cont <= rhs._cont;
}

template <class T, class Container>
bool operator>(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
{
	return lhs._cont > rhs._cont;
}

template <class T, class Container>
bool operator>=(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
{
	return lhs._cont >= rhs._cont;
}
