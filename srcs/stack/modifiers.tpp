template <class T, class Cont>
void	ft::stack<T, Cont>::push(const value_type &value)
{
	this->_cont.push_back(value);
}

template <class T, class Cont>
void	ft::stack<T, Cont>::pop()
{
	this->_cont.pop_back();
}
