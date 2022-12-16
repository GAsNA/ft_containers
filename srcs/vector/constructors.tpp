template <class T, class Alloc>
ft::vector<T, Alloc>::vector (const allocator_type& alloc) : _datas(NULL), _size(0), _capacity(0), _alloc(alloc)
{
}

template <class T, class Alloc>
ft::vector<T, Alloc>::vector (size_type n, const value_type& val, const allocator_type& alloc) : _size(n), _capacity(n * 2), _alloc(alloc)
{
	this->_datas = this->_alloc.allocate(this->_capacity);
	for (int i = 0; i < (int)this->_size; i++)
		this->_alloc.construct(&this->_datas[i], val);
}

template <class T, class Alloc>
template <class InputIterator>
ft::vector<T, Alloc>::vector (InputIterator first, InputIterator last, const allocator_type& alloc, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type*) : _alloc(alloc)
{
	this->_size = std::distance(first, last);
	this->_capacity = this->_size * 2;
	this->_datas = this->_alloc.allocate(this->_capacity);
	for (int i = 0; i < (int)this->_size; i++, first++)
		this->_alloc.construct(&this->_datas[i], *first);
}

template <class T, class Alloc>
ft::vector<T, Alloc>::vector(const vector &x) : _size(x._size), _capacity(x._capacity), _alloc(x._alloc)
{
	this->_datas = this->_alloc.allocate(this->_capacity);
	for (int i = 0; i < (int)this->_size; i++)
		this->_alloc.construct(&this->_datas[i], x._datas[i]);
}

template <class T, class Alloc>
ft::vector<T, Alloc>::~vector ()
{
	for (size_t i = 0; i < this->_size; i++)
		this->_alloc.destroy(&this->_datas[i]);
	
	this->_alloc.deallocate(this->_datas, this->_size);
}
