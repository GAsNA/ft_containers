template <class T, class Alloc>
void	ft::vector<T, Alloc>::assign(size_type count, const T& value)
{
	this->clear();
	for (size_type i = 0; i < count; i++)
		this->push_back(value);
}

template <class T, class Alloc>
template <class InputIt>
void	ft::vector<T, Alloc>::assign(InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type*)
{
	this->clear();
	for (; first != last; ++first)
		this->push_back(*first);
}

template <class T, class Alloc>
void	ft::vector<T, Alloc>::clear()
{
	for (int i = 0; i < (int)this->_size; i++)
		this->_alloc.destroy(&this->_datas[i]);

	this->_size = 0;
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::iterator	ft::vector<T, Alloc>::insert(iterator position, const value_type& val)
{
	size_type pos = ft::distance(this->begin(), position);

	if (this->_capacity < this->_size + 1)
		this->reserve(this->_capacity * 2 + 1);

	for (size_type i = this->_size; i > pos; i--)
	{
		this->_alloc.construct(&this->_datas[i], this->_datas[i - 1]);
		this->_alloc.destroy(&this->_datas[i - 1]);
	}
	this->_alloc.construct(&this->_datas[pos], val);
	
	this->_size++;

	return iterator(&this->_datas[pos]);
}

template <class T, class Alloc>
void	ft::vector<T, Alloc>::insert(iterator position, size_type n, const value_type& val)
{
	for (size_type i = 0; i < n; i++)
		position = this->insert(position, val) + 1;
}

template <class T, class Alloc>
template <class InputIt>
void	ft::vector<T, Alloc>::insert(iterator position, InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type*)
{
	size_type n = ft::distance(first, last);

	for (size_type i = 0; i < n; i++, first++)
		position = this->insert(position, *first) + 1;
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::iterator	ft::vector<T, Alloc>::erase(iterator pos)
{
	size_type	diff = ft::distance(this->begin(), pos);
	size_type	ret = diff;
	iterator	it_end = this->end();

	for (; pos < it_end; pos++, diff++)
	{
		this->_alloc.destroy(&this->_datas[diff]);
		if (diff + 1 < this->_size)
			this->_alloc.construct(&this->_datas[diff], this->_datas[diff + 1]);
	}
	this->_size--;
	return iterator(this->begin() + ret);
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::iterator	ft::vector<T, Alloc>::erase(iterator first, iterator last)
{
	size_type	dis = ft::distance(first, last);
	size_type	ret = ft::distance(this->begin(), first);
	for (; dis > 0; dis--)
		this->erase(first);
	return iterator(this->begin() + ret);
}

template <class T, class Alloc>
void	ft::vector<T, Alloc>::push_back(const T& value)
{
	if (this->_size + 1 > this->_capacity) {this->reserve(this->_capacity * 2 + 1);}

	this->_alloc.construct(&this->_datas[this->_size], value);
	this->_size += 1;
}

template <class T, class Alloc>
void	ft::vector<T, Alloc>::pop_back()
{
	this->_alloc.destroy(&this->_datas[this->_size - 1]);
	this->_size -= 1;
}

template <class T, class Alloc>
void	ft::vector<T, Alloc>::resize(size_type count, T value)
{
	if (this->_size > count)
		for (int i = count; i < (int)this->_size; i++)
			this->_alloc.destroy(&this->_datas[i]);
	else if (this->_size < count)
		for (size_type i = this->_size; i < count; i++)
			this->push_back(value);
	
	this->_size = count;
}

template <class T, class Alloc>
void	ft::vector<T, Alloc>::swap(vector &other)
{
	pointer	tmp_datas = this->_datas;
	size_type tmp_size = this->_size;
	size_type tmp_capacity = this->_capacity;
	allocator_type tmp_alloc = this->_alloc;

	this->_datas = other._datas;
	this->_size = other._size;
	this->_capacity = other._capacity;
	this->_alloc = other._alloc;

	other._datas = tmp_datas;
	other._size = tmp_size;
	other._capacity = tmp_capacity;
	other._alloc = tmp_alloc;
}

template <class T, class Alloc>
void	swap(ft::vector<T, Alloc> &lhs, ft::vector<T, Alloc> &rhs)
{
	lhs.swap(rhs);
}
