template <class T, class Cont>
typename ft::stack<T, Cont>::reference	ft::stack<T, Cont>::top()
{
	return this->c.back();
}

template <class T, class Cont>
typename ft::stack<T, Cont>::const_reference	ft::stack<T, Cont>::top() const
{
	return this->c.back();
}
