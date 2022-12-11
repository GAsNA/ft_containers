template <class T, class Alloc>
ft::vector<T, Alloc>	&ft::vector<T, Alloc>::operator=(vector const &rhs)
{
	if (this == &rhs) {return *this;}
	if (this->_datas)
	{
		for (int i = 0; i < this->_size; i++)
			this->_alloc.destroy(&this->_datas[i]);
		this->_alloc.deallocate(this->_datas, this->_size);
	}
	this->_alloc = rhs._alloc; this->_size = rhs._size; this->_capacity = rhs._capacity;
	this->_datas = this->_alloc.allocate(this->_capacity);
	for (int i = 0; i < (int)this->_size; i++)
		this->_alloc.construct(&this->_datas[i], rhs._datas[i]);
	return *this;
}

template <class T, class Alloc>
T		&ft::vector<T, Alloc>::operator[](const int i) const
{
	if (i >= this->_size || i < 0) {throw InvalidIndexException();}
	return this->_datas[i];
}

template <class T, class Alloc>
bool	operator==(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
{
	if (lhs.size() != rhs.size()) {return false;}
	
	for (int i = 0; i < (int)lhs.size(); i++)
		if (lhs[i] != rhs[i])
			return false;
	
	return true;
}

template <class T, class Alloc>
bool	operator!=(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
{
	return !(lhs == rhs);
}

/*template <class T, class Alloc>
bool	operator<(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs);

template <class T, class Alloc>
bool	operator<=(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs);

template <class T, class Alloc>
bool	operator>(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs);

template <class T, class Alloc>
bool	operator>=(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs);
*/
