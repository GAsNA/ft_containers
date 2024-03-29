template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::key_compare	ft::map<Key, T, Compare, Allocator>::key_comp() const
{
	return key_compare();
}

template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::value_compare	ft::map<Key, T, Compare, Allocator>::value_comp() const
{
	return value_compare(this->_tree.compare());
}
