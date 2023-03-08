template <class Key, class T, class Compare, class Allocator>
void	ft::map<Key, T, Compare, Allocator>::clear()
{
	this->_tree.clear(this->_tree.getRoot());
}

template <class Key, class T, class Compare, class Allocator>
ft::pair<iterator, bool>	ft::map<Key, T, Compare, Allocator>::insert(const value_type& x)
{
}

template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::iterator	ft::map<Key, T, Compare, Allocator>::insert(iterator pos, const value_type& x)
{
}

template <class Key, class T, class Compare, class Allocator>
template <class InputIterator>
void	ft::map<Key, T, Compare, Allocator>::insert(InputIterator first, InputIterator last)
{
}

template <class Key, class T, class Compare, class Allocator>
void	ft::map<Key, T, Compare, Allocator>::erase(iterator position)
{
}

template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::size_type	ft::map<Key, T, Compare, Allocator>::erase(const key_type& x)
{
}

template <class Key, class T, class Compare, class Allocator>
void	ft::map<Key, T, Compare, Allocator>::erase(iterator first, iterator last)
{
}

template <class Key, class T, class Compare, class Allocator>
void	ft::map<Key, T, Compare, Allocator>::swap(map& map)
{
}
