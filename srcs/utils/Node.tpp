template <class T>
bool	operator==(const ft::Node<T>& lhs, const ft::Node<T>& rhs)
{
	return lhs.value == rhs.value && lhs.is_nil == rhs.is_nil;
}

template <class T>
bool	operator!=(const ft::Node<T>& lhs, const ft::Node<T>& rhs)
{
	return !(lhs == rhs);
}

template <class T>
bool	operator<(const ft::Node<T>& lhs, const ft::Node<T>& rhs)
{
	return lhs.value < rhs.value && lhs.is_nil == rhs.is_nil;
}

template <class T>
bool	operator>(const ft::Node<T>& lhs, const ft::Node<T>& rhs)
{
	return lhs.value > rhs.value && lhs.is_nil == rhs.is_nil;
}
	
template <class T>
bool	operator<=(const ft::Node<T>& lhs, const ft::Node<T>& rhs)
{
	return !(lhs.value < rhs.value);
}

template <class T>
bool	operator>=(const ft::Node<T>& lhs, const ft::Node<T>& rhs)
{
	return !(lhs.value > rhs.value);
}
