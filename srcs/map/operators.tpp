template <class Key, class T, class Compare, class Allocator>
ft::map<Key, T, Compare, Allocator>	&ft::map<Key, T, Compare, Allocator>::operator=(const map<Key, T, Compare, Allocator> &other)
{
	if (*this == other) { return *this; }
	clear();
	insert(other.begin(), other.end());
	return *this;
}

template <class Key, class T, class Compare, class Allocator>
T&	ft::map<Key, T, Compare, Allocator>::operator[](const key_type& key)
{
	return (insert(ft::make_pair(key, mapped_type())).first)->second;
}

template <class Key, class T, class Compare, class Allocator>
bool	operator==(const ft::map<Key, T, Compare, Allocator>& x, const ft::map<Key, T, Compare, Allocator>& y)
{
	typename ft::map<Key, T, Compare, Allocator>::const_iterator	it_x = x.begin();
	typename ft::map<Key, T, Compare, Allocator>::const_iterator	ite_x = x.end();
	typename ft::map<Key, T, Compare, Allocator>::const_iterator	it_y = y.begin();
	typename ft::map<Key, T, Compare, Allocator>::const_iterator	ite_y = y.end();

	if (x.size() != y.size()) { return false; }

	for (; it_x != ite_x; it_x++, it_y++) { if (*it_x != *it_y) { return false; } }

	return true;
}

template <class Key, class T, class Compare, class Allocator>
bool	operator!=(const ft::map<Key, T, Compare, Allocator>& x, const ft::map<Key, T, Compare, Allocator>& y)
{
	return !(x == y);
}

template <class Key, class T, class Compare, class Allocator>
bool	operator<(const ft::map<Key, T, Compare, Allocator>& x, const ft::map<Key, T, Compare, Allocator>& y)
{
	typename ft::map<Key, T, Compare, Allocator>::const_iterator	it_x = x.begin();
	typename ft::map<Key, T, Compare, Allocator>::const_iterator	ite_x = x.end();
	typename ft::map<Key, T, Compare, Allocator>::const_iterator	it_y = y.begin();
	typename ft::map<Key, T, Compare, Allocator>::const_iterator	ite_y = y.end();

	return ft::lexicographical_compare(it_x, ite_x, it_y, ite_y);
}

template <class Key, class T, class Compare, class Allocator>
bool	operator>(const ft::map<Key, T, Compare, Allocator>& x, const ft::map<Key, T, Compare, Allocator>& y)
{
	return y < x;
}

template <class Key, class T, class Compare, class Allocator>
bool	operator<=(const ft::map<Key, T, Compare, Allocator>& x, const ft::map<Key, T, Compare, Allocator>& y)
{
	return !(x > y);
}

template <class Key, class T, class Compare, class Allocator>
bool	operator>=(const ft::map<Key, T, Compare, Allocator>& x, const ft::map<Key, T, Compare, Allocator>& y)
{
	return !(x < y);
}

template <class Key, class T, class Compare, class Allocator>
void	swap(ft::map<Key, T, Compare, Allocator>& x, ft::map<Key, T, Compare, Allocator>& y)
{
	x.swap(y);
}
