template <class T, class Cont>
bool		ft::stack<T, Cont>::empty() const
{
	return this->_cont.empty();
}

template <class T, class Cont>
typename ft::stack<T, Cont>::size_type	ft::stack<T, Cont>::size() const
{
	return this->_cont.size();
}
