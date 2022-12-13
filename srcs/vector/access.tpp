template <class T, class Alloc>
typename ft::vector<T, Alloc>::allocator_type	ft::vector<T, Alloc>::get_allocator() const
{
	return this->_alloc;
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::reference	ft::vector<T, Alloc>::at(size_type pos)
{
	if (pos >= this->_size || pos < 0) {throw std::out_of_range("Index out of range");}

	return this->_datas[pos];
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::const_reference	ft::vector<T, Alloc>::at(size_type pos) const
{
	if (pos >= this->_size || pos < 0) {throw std::out_of_range("Index out of range");}

	return this->_datas[pos];
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::reference	ft::vector<T, Alloc>::front()
{
	return this->_datas[0];
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::const_reference	ft::vector<T, Alloc>::front() const
{
	return this->_datas[0];
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::reference	ft::vector<T, Alloc>::back()
{
	return this->_datas[this->_size - 1];
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::const_reference	ft::vector<T, Alloc>::back() const
{
	return this->_datas[this->_size - 1];
}

template <class T, class Alloc>
T*	ft::vector<T, Alloc>::data()
{
	return this->_datas;
}

template <class T, class Alloc>
const T*	ft::vector<T, Alloc>::data() const
{
	return this->_datas;
}
