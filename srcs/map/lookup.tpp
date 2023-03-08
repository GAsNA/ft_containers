template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::size_type	ft::map<Key, T, Compare, Allocator>::count(const Key &key) const
{
	return this->_tree.count(ft::make_pair(key, mapped_type()));
}

template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::iterator	ft::map<Key, T, Compare, Allocator>::find(const Key &key)
{
	return this->_tree.find(ft::make_pair(key, mapped_type()));
}

template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::const_iterator	ft::map<Key, T, Compare, Allocator>::find(const Key &key) const
{
	return this->_tree.find(ft::make_pair(key, mapped_type()));
}

template <class Key, class T, class Compare, class Allocator>
ft::pair<iterator, iterator>	ft::map<Key, T, Compare, Allocator>::equal_range(const Key& key)
{
	return ft::make_pair(lower_bound(k), upper_bound(k));
}

template <class Key, class T, class Compare, class Allocator>
ft::pair<const_iterator, const_iterator>	ft::map<Key, T, Compare, Allocator>::equal_range(const Key& key) const
{
	return ft::make_pair(lower_bound(k), upper_bound(k));
}

template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::iterator	ft::map<Key, T, Compare, Allocator>::lower_bound(const Key& key)
{
	return this->_tree.lower_bound(ft::make_pair(key, mapped_type()));
}

template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::const_iterator	ft::map<Key, T, Compare, Allocator>::lower_bound(const Key& key) const
{
	return this->_tree.lower_bound(ft::make_pair(key, mapped_type()));
}

template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::iterator	ft::map<Key, T, Compare, Allocator>::upper_bound(const Key& key)
{
	return this->_tree.upper_bound(ft::make_pair(key, mapped_type()));
}

template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::const_iterator	ft::map<Key, T, Compare, Allocator>::upper_bound(const Key& key) const
{
	return this->_tree.upper_bound(ft::make_pair(key, mapped_type()));
}
