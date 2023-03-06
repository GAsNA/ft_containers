template <class Key, class T, class Compare, class Allocator>
bool		ft::map<Key, T, Compare, Allocator>::empty() const
{
	return this->_tree.empty();
}

template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::size_type	ft::map<Key, T, Compare, Allocator>::size() const
{
	return this->_tree.size();
}

template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::size_type	ft::map<Key, T, Compare, Allocator>::max_size() const
{
	return this->_tree.max_size();
}
