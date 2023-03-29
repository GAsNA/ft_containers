template <class Key, class Compare, class Allocator>
typename ft::set<Key, Compare, Allocator>::allocator_type	ft::set<Key, Compare, Allocator>::get_allocator() const
{
	return allocator_type(this->_tree.get_allocator());
}
