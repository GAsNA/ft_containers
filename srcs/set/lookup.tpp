template <class Key, class Compare, class Allocator>
typename ft::set<Key, Compare, Allocator>::size_type	ft::set<Key, Compare, Allocator>::count(const key_type &key) const
{
	return this->_tree.count(ft::make_pair(key, value_type()));
}

template <class Key, class Compare, class Allocator>
typename ft::set<Key, Compare, Allocator>::iterator	ft::set<Key, Compare, Allocator>::find(const key_type &key)
{
	return this->_tree.find(ft::make_pair(key, value_type()));
}

template <class Key, class Compare, class Allocator>
typename ft::set<Key, Compare, Allocator>::const_iterator	ft::set<Key, Compare, Allocator>::find(const key_type &key) const
{
	return this->_tree.find(ft::make_pair(key, value_type()));
}

template <class Key, class Compare, class Allocator>
ft::pair<typename ft::set<Key, Compare, Allocator>::iterator, typename ft::set<Key, Compare, Allocator>::iterator>	ft::set<Key, Compare, Allocator>::equal_range(const key_type& key)
{
	return ft::make_pair(lower_bound(key), upper_bound(key));
}

template <class Key, class Compare, class Allocator>
ft::pair<typename ft::set<Key, Compare, Allocator>::const_iterator, typename ft::set<Key, Compare, Allocator>::const_iterator>	ft::set<Key, Compare, Allocator>::equal_range(const key_type& key) const
{
	return ft::make_pair(lower_bound(key), upper_bound(key));
}

template <class Key, class Compare, class Allocator>
typename ft::set<Key, Compare, Allocator>::iterator	ft::set<Key, Compare, Allocator>::lower_bound(const key_type& key)
{
	return this->_tree.lower_bound(key);
}

template <class Key, class Compare, class Allocator>
typename ft::set<Key, Compare, Allocator>::const_iterator	ft::set<Key, Compare, Allocator>::lower_bound(const key_type& key) const
{
	return this->_tree.lower_bound(key);
}

template <class Key, class Compare, class Allocator>
typename ft::set<Key, Compare, Allocator>::iterator	ft::set<Key, Compare, Allocator>::upper_bound(const key_type& key)
{
	return this->_tree.upper_bound(key);
}

template <class Key, class Compare, class Allocator>
typename ft::set<Key, Compare, Allocator>::const_iterator	ft::set<Key, Compare, Allocator>::upper_bound(const key_type& key) const
{
	return this->_tree.upper_bound(key);
}
