template <class Key, class Compare, class Allocator>
typename ft::set<Key, Compare, Allocator>::key_compare	ft::set<Key, Compare, Allocator>::key_comp() const
{
	return key_compare();
}

template <class Key, class Compare, class Allocator>
typename ft::set<Key, Compare, Allocator>::value_compare	ft::set<Key, Compare, Allocator>::value_comp() const
{
	return value_compare(this->_tree.compare());
}
