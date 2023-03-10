template <class Key, class T, class Compare, class Allocator>
void	ft::map<Key, T, Compare, Allocator>::clear()
{
	this->_tree.clear(this->_tree.getRoot());
}

template <class Key, class T, class Compare, class Allocator>
ft::pair<typename ft::map<Key, T, Compare, Allocator>::iterator, bool>	ft::map<Key, T, Compare, Allocator>::insert(const value_type& x)
{
	return this->_tree.insert(x);
}

template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::iterator	ft::map<Key, T, Compare, Allocator>::insert(iterator pos, const value_type& x)
{
	static_cast<void>(pos); //verif
	return this->_tree.insert(x).first;
}

template <class Key, class T, class Compare, class Allocator>
template <class InputIterator>
void	ft::map<Key, T, Compare, Allocator>::insert(InputIterator first, InputIterator last)
{
	for (; first != last; first++)
		this->_tree.insert(*first);
}

template <class Key, class T, class Compare, class Allocator>
void	ft::map<Key, T, Compare, Allocator>::erase(iterator position)
{
	erase(position->first);
}

template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::size_type	ft::map<Key, T, Compare, Allocator>::erase(const key_type& x)
{
	return this->_tree.erase(ft::make_pair(x, mapped_type()));
}

template <class Key, class T, class Compare, class Allocator>
void	ft::map<Key, T, Compare, Allocator>::erase(iterator first, iterator last)
{
	//this->_tree.multi_erase(first, last);
	(void)first;
	(void)last;
}

template <class Key, class T, class Compare, class Allocator>
void	ft::map<Key, T, Compare, Allocator>::swap(map& map)
{
	this->_tree.swap(map._tree);
}
