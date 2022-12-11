template <class T, class Alloc>
void	ft::vector<T, Alloc>::modify_capacity(size_type new_cap)
{
	T	*data = new T[this->_size];
	for (int i = 0; i < this->_size; i++)
		data[i] = this->_datas[i];

	for (int i = 0; i < this->_size; i++)
		this->_alloc.destroy(&this->_datas[i]);
	this->_alloc.deallocate(this->_datas, this->_size);
	
	this->_capacity = new_cap;

	this->_datas = this->_alloc.allocate(this->_capacity);
	for (int i = 0; i < this->_size; i++)
		this->_alloc.construct(&this->_datas[i], data[i]);
	
	delete[] data;
}
