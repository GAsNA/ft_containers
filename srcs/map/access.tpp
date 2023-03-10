template <class Key, class T, class Compare, class Allocator>
T&	ft::map<Key, T, Compare, Allocator>::at(const Key &key)
{
	(void)key;
}

template <class Key, class T, class Compare, class Allocator>
const T&	ft::map<Key, T, Compare, Allocator>::at(const Key &key) const
{
	(void)key;
}

template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::allocator_type	ft::map<Key, T, Compare, Allocator>::get_allocator() const
{
	return allocator_type(this->_tree.get_allocator());
}
