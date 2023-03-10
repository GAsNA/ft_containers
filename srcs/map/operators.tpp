template <class Key, class T, class Compare, class Allocator>
ft::map<Key, T, Compare, Allocator>	&ft::map<Key, T, Compare, Allocator>::operator=(map const &other)
{
	if (this == &other) { clear(); insert(other.begin(), other.end()); }
	return *this;
}

template <class Key, class T, class Compare, class Allocator>
T&	ft::map<Key, T, Compare, Allocator>::operator[](const Key& key)
{
	return (insert(ft::make_pair(key, mapped_type())).first)->second;
}
