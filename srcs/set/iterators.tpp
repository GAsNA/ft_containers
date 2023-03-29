template <class Key, class Compare, class Allocator>
typename ft::set<Key, Compare, Allocator>::iterator	ft::set<Key, Compare, Allocator>::begin()
{
	return this->_tree.begin();
}

template <class Key, class Compare, class Allocator>
typename ft::set<Key, Compare, Allocator>::const_iterator	ft::set<Key, Compare, Allocator>::begin() const
{
	return this->_tree.begin();
}

template <class Key, class Compare, class Allocator>
typename ft::set<Key, Compare, Allocator>::iterator	ft::set<Key, Compare, Allocator>::end()
{
	return this->_tree.end();
}

template <class Key, class Compare, class Allocator>
typename ft::set<Key, Compare, Allocator>::const_iterator	ft::set<Key, Compare, Allocator>::end() const
{
	return this->_tree.end();
}

template <class Key, class Compare, class Allocator>
typename ft::set<Key, Compare, Allocator>::reverse_iterator	ft::set<Key, Compare, Allocator>::rbegin()
{
	return reverse_iterator(this->_tree.end()); //return this->_tree.rbegin();
}

template <class Key, class Compare, class Allocator>
typename ft::set<Key, Compare, Allocator>::const_reverse_iterator	ft::set<Key, Compare, Allocator>::rbegin() const
{
	return const_reverse_iterator(this->_tree.end()); //return this->_tree.rbegin();
}

template <class Key, class Compare, class Allocator>
typename ft::set<Key, Compare, Allocator>::reverse_iterator	ft::set<Key, Compare, Allocator>::rend()
{
	return reverse_iterator(this->_tree.begin()); //return this->_tree.rend();
}

template <class Key, class Compare, class Allocator>
typename ft::set<Key, Compare, Allocator>::const_reverse_iterator	ft::set<Key, Compare, Allocator>::rend() const
{
	return const_reverse_iterator(this->_tree.begin()); //return this->_tree.rend();
}
