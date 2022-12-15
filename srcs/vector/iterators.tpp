template <class T, class Alloc>
typename ft::vector<T, Alloc>::iterator	ft::vector<T, Alloc>::begin()
{
	return iterator(this->_datas);
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::const_iterator	ft::vector<T, Alloc>::begin() const
{
	return const_iterator(this->_datas);
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::iterator	ft::vector<T, Alloc>::end()
{
	return iterator(&this->_datas[this->_size]);
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::const_iterator	ft::vector<T, Alloc>::end() const
{
	return const_iterator(&this->_datas[this->_size]);
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::reverse_iterator	ft::vector<T, Alloc>::rbegin()
{
	return reverse_iterator(&this->_datas[this->_size - 1]);
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::const_reverse_iterator	ft::vector<T, Alloc>::rbegin() const
{
	return const_reverse_iterator(&this->_datas[this->_size - 1]);
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::reverse_iterator	ft::vector<T, Alloc>::rend()
{
	return reverse_iterator(this->_datas - 1);
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::const_reverse_iterator	ft::vector<T, Alloc>::rend() const
{
	return const_reverse_iterator(this->_datas - 1);
}
