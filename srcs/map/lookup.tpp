template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::size_type	ft::map<Key, T, Compare, Allocator>::count(const key_type &key) const
{
	return this->_tree.count(ft::make_pair(key, mapped_type()));
}

template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::iterator	ft::map<Key, T, Compare, Allocator>::find(const key_type &key)
{
	return this->_tree.find(ft::make_pair(key, mapped_type()));
}

template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::const_iterator	ft::map<Key, T, Compare, Allocator>::find(const key_type &key) const
{
	return this->_tree.find(ft::make_pair(key, mapped_type()));
}

template <class Key, class T, class Compare, class Allocator>
ft::pair<typename ft::map<Key, T, Compare, Allocator>::iterator, typename ft::map<Key, T, Compare, Allocator>::iterator>	ft::map<Key, T, Compare, Allocator>::equal_range(const key_type& key)
{
	return ft::make_pair(lower_bound(key), upper_bound(key));
}

template <class Key, class T, class Compare, class Allocator>
ft::pair<typename ft::map<Key, T, Compare, Allocator>::const_iterator, typename ft::map<Key, T, Compare, Allocator>::const_iterator>	ft::map<Key, T, Compare, Allocator>::equal_range(const key_type& key) const
{
	return ft::make_pair(lower_bound(key), upper_bound(key));
}

template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::iterator	ft::map<Key, T, Compare, Allocator>::lower_bound(const key_type& key)
{
	return this->_tree.lower_bound(ft::make_pair(key, mapped_type()));
}

template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::const_iterator	ft::map<Key, T, Compare, Allocator>::lower_bound(const key_type& key) const
{
	return this->_tree.lower_bound(ft::make_pair(key, mapped_type()));
}

template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::iterator	ft::map<Key, T, Compare, Allocator>::upper_bound(const key_type& key)
{
	return this->_tree.upper_bound(ft::make_pair(key, mapped_type()));
}

template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::const_iterator	ft::map<Key, T, Compare, Allocator>::upper_bound(const key_type& key) const
{
	return this->_tree.upper_bound(ft::make_pair(key, mapped_type()));
}
