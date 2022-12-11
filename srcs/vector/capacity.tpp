template <class T, class Alloc>
bool	ft::vector<T, Alloc>::empty() const
{
	return this->_size == 0 ? true : false;
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::size_type	ft::vector<T, Alloc>::size() const
{
	return this->_size;
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::size_type	ft::vector<T, Alloc>::max_size() const
{
	return this->_alloc.max_size();
}

template <class T, class Alloc>
void	ft::vector<T, Alloc>::reserve(size_type new_cap)
{
	if (new_cap > this->max_size()) {throw std::length_error("New capacty too high.");}
	if (new_cap <= this->_capacity) {return;}

	modify_capacity(new_cap);
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::size_type	ft::vector<T, Alloc>::capacity() const
{
	return this->_capacity;
}
