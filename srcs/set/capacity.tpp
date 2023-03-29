template <class Key, class Compare, class Allocator>
bool		ft::set<Key, Compare, Allocator>::empty() const
{
	return this->_tree.empty();
}

template <class Key, class Compare, class Allocator>
typename ft::set<Key, Compare, Allocator>::size_type	ft::set<Key, Compare, Allocator>::size() const
{
	return this->_tree.size();
}

template <class Key, class Compare, class Allocator>
typename ft::set<Key, Compare, Allocator>::size_type	ft::set<Key, Compare, Allocator>::max_size() const
{
	return this->_tree.max_size();
}
