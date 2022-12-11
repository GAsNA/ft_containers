template <class T, class Alloc>
void	ft::vector<T, Alloc>::clear()
{
	for (int i = 0; i < this->_size; i++)
		this->_alloc.destroy(&this->_datas[i]);

	this->_size = 0;
}

template <class T, class Alloc>
void	ft::vector<T, Alloc>::push_back(const T& value)
{
	if (this->_size + 1 > this->_capacity) {this->reserve(this->_capacity * 2);}
	
	this->_alloc.construct(&this->_datas[this->_size], value);
	this->_size += 1;
}
