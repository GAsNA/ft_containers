template <class T, class Cont>
void	ft::stack<T, Cont>::push(const value_type &value)
{
	this->c.push_back(value);
}

template <class T, class Cont>
void	ft::stack<T, Cont>::pop()
{
	this->c.pop_back();
}
