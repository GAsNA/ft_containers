template <class Key, class Compare, class Allocator>
void	ft::set<Key, Compare, Allocator>::clear()
{
	if (!this->_tree.empty())
		this->_tree.clear(this->_tree.getRoot());
}

template <class Key, class Compare, class Allocator>
pair<typename ft::set<Key, Compare, Allocator>::iterator, bool>	ft::set<Key, Compare, Allocator>::insert(const value_type& x)
{
	return this->_tree.insert(x);
}

template <class Key, class Compare, class Allocator>
typename ft::set<Key, Compare, Allocator>::iterator	ft::set<Key, Compare, Allocator>::insert(iterator pos, const value_type& x)
{
	static_cast<void>(pos);
	return this->_tree.insert(x).first;
}

template <class Key, class Compare, class Allocator>
template <class InputIterator>
void	ft::set<Key, Compare, Allocator>::insert(InputIterator first, InputIterator last)
{
	for (; first != last; first++)
		this->_tree.insert(*first);
}

template <class Key, class Compare, class Allocator>
void	ft::set<Key, Compare, Allocator>::erase(iterator position)
{
	erase(position->first);
}

template <class Key, class Compare, class Allocator>
typename ft::set<Key, Compare, Allocator>::size_type	ft::set<Key, Compare, Allocator>::erase(const key_type& x)
{
	return this->_tree.erase(ft::make_pair(x, value_type()));
}

template <class Key, class Compare, class Allocator>
void	ft::set<Key, Compare, Allocator>::erase(iterator first, iterator last)
{
	this->_tree.multi_erase(first, last);
}

template <class Key, class Compare, class Allocator>
void	ft::set<Key, Compare, Allocator>::swap(set<Key, Compare, Allocator>& set)
{
	this->_tree.swap(set._tree);
}
