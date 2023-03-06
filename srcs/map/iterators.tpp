template <class Key, class T, class Compare, class Allocator>
ft::map<Key, T, Compare, Allocator>::iterator	ft::map<Key, T, Compare, Allocator>::begin()
{
	return this->_tree.begin();
}

template <class Key, class T, class Compare, class Allocator>
ft::map<Key, T, Compare, Allocator>::const_iterator	ft::map<Key, T, Compare, Allocator>::begin() const
{
	return this->_tree.begin();
}

template <class Key, class T, class Compare, class Allocator>
ft::map<Key, T, Compare, Allocator>::iterator	ft::map<Key, T, Compare, Allocator>::end()
{
	return this->_tree.end();
}

template <class Key, class T, class Compare, class Allocator>
ft::map<Key, T, Compare, Allocator>::const_iterator	ft::map<Key, T, Compare, Allocator>::end() const
{
	return this->_tree.end();
}

template <class Key, class T, class Compare, class Allocator>
ft::map<Key, T, Compare, Allocator>::reverse_iterator	ft::map<Key, T, Compare, Allocator>::rbegin()
{
	return this->_tree.rbegin();
}

template <class Key, class T, class Compare, class Allocator>
ft::map<Key, T, Compare, Allocator>::const_reverse_iterator	ft::map<Key, T, Compare, Allocator>::rbegin() const
{
	return this->_tree.rbegin();
}

template <class Key, class T, class Compare, class Allocator>
ft::map<Key, T, Compare, Allocator>::reverse_iterator	ft::map<Key, T, Compare, Allocator>::rend()
{
	return this->_tree.rend();
}

template <class Key, class T, class Compare, class Allocator>
ft::map<Key, T, Compare, Allocator>::const_reverse_iterator	ft::map<Key, T, Compare, Allocator>::rend() const
{
	return this->_tree.rend();
}
