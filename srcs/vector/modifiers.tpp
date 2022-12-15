template <class T, class Alloc>
void	ft::vector<T, Alloc>::assign(size_type count, const T& value)
{
	this->clear();
	for (int i = 0; i < count; i++)
		this->push_back(value);
}

template <class T, class Alloc>
template <class InputIt>
void	ft::vector<T, Alloc>::assign(InputIt first, InputIt last, typename std::enable_if<!std::is_integral<InputIt>::value, InputIt>::type*)
{
	this->clear();
	for (; first < last; first++)
		this->push_back(*first);
}

template <class T, class Alloc>
void	ft::vector<T, Alloc>::clear()
{
	for (int i = 0; i < this->_size; i++)
		this->_alloc.destroy(&this->_datas[i]);

	this->_size = 0;
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::iterator	ft::vector<T, Alloc>::insert(iterator position, const value_type& val)
{
	size_type pos = 0;
	iterator it = this->begin();
	while (position > it)
	{
		it++;
		pos++;
	}

	if (this->_capacity < this->_size + 1)
		this->reserve(this->_capacity * 2);

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
		position = this->insert(position, val);
}

template <class T, class Alloc>
template <class InputIt>
void	ft::vector<T, Alloc>::insert(iterator position, InputIt first, InputIt last)
{
	size_type n = std::distance(first, last);

	for (size_type i = 0; i < n; i++, first++)
		position = this->insert(position, *first);
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::iterator	ft::vector<T, Alloc>::erase(iterator pos)
{
	int			diff = 0;
	iterator	it_begin = this->begin();
	while (pos != it_begin)
	{
		it_begin++;
		diff++;
	}
	iterator	it_end = this->end();

	for (; pos < it_end; pos++, diff++)
	{
		this->_alloc.destroy(&this->_datas[diff]);
		if (diff + 1 < this->_size)
			this->_alloc.construct(&this->_datas[diff], this->_datas[diff + 1]);
	}
	this->_size--;
	return iterator(this->begin() + diff);
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::iterator	ft::vector<T, Alloc>::erase(iterator first, iterator last)
{
}

template <class T, class Alloc>
void	ft::vector<T, Alloc>::push_back(const T& value)
{
	if (this->_size + 1 > this->_capacity) {this->reserve(this->_capacity * 2);}

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
		for (int i = count; i < this->_size; i++)
			this->_alloc.destroy(&this->_datas[i]);
	else if (this->_size < count)
		for (int i = this->_size; i < count; i++)
			this->_alloc.construct(&this->_datas[i], value);
	
	this->_size = count;
}

template <class T, class Alloc>
void	ft::vector<T, Alloc>::swap(vector &other)
{
	T	*data_this = new T[this->_size];
	for (int i = 0; i < this->_size; i++)
		data_this[i] = this->_datas[i];
	size_type size_this = this->_size;

	T	*data_other = new T[other.size()];
	for (int i = 0; i < other.size(); i++)
		data_other[i] = other[i];
	size_type size_other = other.size();
	
	this->clear();
	other.clear();

	for (int i = 0; i < size_other; i++)
		this->push_back(data_other[i]);

	for (int i = 0; i < size_this; i++)
		other.push_back(data_this[i]);

	delete[] data_this;
	delete[] data_other;
}

template <class T, class Alloc>
void	ft::swap(ft::vector<T, Alloc> &lhs, ft::vector<T, Alloc> &rhs)
{
	lhs.swap(rhs);
}
