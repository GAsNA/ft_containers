/**********************************************************/
/*						CONSTRUCTORS					  */
/**********************************************************/
template <class T, class Category, class Distance, class Pointer, class Reference>
ft::iterator_vector<T, Category, Distance, Pointer, Reference>::iterator_vector() : _pointer(NULL) {}

template <class T, class Category, class Distance, class Pointer, class Reference>
ft::iterator_vector<T, Category, Distance, Pointer, Reference>::iterator_vector(pointer ptr) : _pointer(ptr) {}

template <class T, class Category, class Distance, class Pointer, class Reference>
ft::iterator_vector<T, Category, Distance, Pointer, Reference>::iterator_vector(const iterator_vector &x) : _pointer(x.get_pointer()) {}

template <class T, class Category, class Distance, class Pointer, class Reference>
ft::iterator_vector<T, Category, Distance, Pointer, Reference>::~iterator_vector() {};

/**********************************************************/
/*						OPERATORS						  */
/**********************************************************/
template <class T, class Category, class Distance, class Pointer, class Reference>
ft::iterator_vector<T, Category, Distance, Pointer, Reference>::operator iterator_vector<const T>() const
{
	return iterator_vector<const T>(this->_pointer);
}

template <class T, class Category, class Distance, class Pointer, class Reference>
ft::iterator_vector<T, Category, Distance, Pointer, Reference>	&ft::iterator_vector<T, Category, Distance, Pointer, Reference>::operator=(const iterator_vector<const T> &rhs)
{
	if (this == &rhs) {return *this;}

	this->_pointer = rhs.get_pointer();
	return *this;
}

template <class T, class Category, class Distance, class Pointer, class Reference>
ft::iterator_vector<T, Category, Distance, Pointer, Reference>	&ft::iterator_vector<T, Category, Distance, Pointer, Reference>::operator++()
{
	this->_pointer++;
	return *this;
}

template <class T, class Category, class Distance, class Pointer, class Reference>
ft::iterator_vector<T, Category, Distance, Pointer, Reference>	ft::iterator_vector<T, Category, Distance, Pointer, Reference>::operator++(int)
{
	iterator_vector iv(*this);
	operator++();
	return iv;
}

template <class T, class Category, class Distance, class Pointer, class Reference>
ft::iterator_vector<T, Category, Distance, Pointer, Reference>	&ft::iterator_vector<T, Category, Distance, Pointer, Reference>::operator--()
{
	this->_pointer--;
	return *this;
}

template <class T, class Category, class Distance, class Pointer, class Reference>
ft::iterator_vector<T, Category, Distance, Pointer, Reference>	ft::iterator_vector<T, Category, Distance, Pointer, Reference>::operator--(int)
{
	iterator_vector iv(*this);
	operator--();
	return iv;
}

template <class T, class Category, class Distance, class Pointer, class Reference>
bool	ft::iterator_vector<T, Category, Distance, Pointer, Reference>::operator>(iterator_vector<const T> const &iv) const
{
	if (this->_pointer > iv.get_pointer())
		return 1;
	return 0;
	//return this->_pointer > iv.pointer()
}

template <class T, class Category, class Distance, class Pointer, class Reference>
bool	ft::iterator_vector<T, Category, Distance, Pointer, Reference>::operator<(iterator_vector<const T> const &iv) const
{
	if (this->_pointer < iv.get_pointer())
		return 1;
	return 0;
}

template <class T, class Category, class Distance, class Pointer, class Reference>
bool	ft::iterator_vector<T, Category, Distance, Pointer, Reference>::operator>=(iterator_vector<const T> const &iv) const
{
	if (this->_pointer >= iv.get_pointer())
		return 1;
	return 0;
}

template <class T, class Category, class Distance, class Pointer, class Reference>
bool	ft::iterator_vector<T, Category, Distance, Pointer, Reference>::operator<=(iterator_vector<const T> const &iv) const
{
	if (this->_pointer <= iv.get_pointer())
		return 1;
	return 0;
}

template <class T, class Category, class Distance, class Pointer, class Reference>
bool	ft::iterator_vector<T, Category, Distance, Pointer, Reference>::operator==(iterator_vector<const T> const &iv) const
{
	if (this->_pointer == iv.get_pointer())
		return 1;
	return 0;
}

template <class T, class Category, class Distance, class Pointer, class Reference>
bool	ft::iterator_vector<T, Category, Distance, Pointer, Reference>::operator!=(iterator_vector<const T> const &iv) const
{
	if (this->_pointer != iv.get_pointer())
		return 1;
	return 0;
}

template <class T, class Category, class Distance, class Pointer, class Reference>
T	&ft::iterator_vector<T, Category, Distance, Pointer, Reference>::operator*()
{
	return *this->_pointer;
}

template <class T, class Category, class Distance, class Pointer, class Reference>
typename ft::iterator_vector<T, Category, Distance, Pointer, Reference>::value_type	*ft::iterator_vector<T, Category, Distance, Pointer, Reference>::operator->()
{
	return this->_pointer;
}

template <class T, class Category, class Distance, class Pointer, class Reference>
ft::iterator_vector<T, Category, Distance, Pointer, Reference>	ft::iterator_vector<T, Category, Distance, Pointer, Reference>::operator+(int n) const
{
	iterator_vector iv(*this);
	iv += n;
	return iv;
}

template <class T, class Category, class Distance, class Pointer, class Reference>
ft::iterator_vector<T, Category, Distance, Pointer, Reference>	&ft::iterator_vector<T, Category, Distance, Pointer, Reference>::operator+=(int n)
{
	this->_pointer += n;
	return *this;
}

template <class T, class Category, class Distance, class Pointer, class Reference>
ft::iterator_vector<T, Category, Distance, Pointer, Reference>	ft::iterator_vector<T, Category, Distance, Pointer, Reference>::operator-(int n) const
{
	iterator_vector iv(*this);
	iv -= n;
	return iv;
}

template <class T, class Category, class Distance, class Pointer, class Reference>
ft::iterator_vector<T, Category, Distance, Pointer, Reference>	&ft::iterator_vector<T, Category, Distance, Pointer, Reference>::operator-=(int n)
{
	this->_pointer -= n;
	return *this;
}

template <class T, class Category, class Distance, class Pointer, class Reference>
int	ft::iterator_vector<T, Category, Distance, Pointer, Reference>::operator-(iterator_vector<const T> const &iv) const
{
	return this->_pointer - iv.get_pointer();
}

template <class T, class Category, class Distance, class Pointer, class Reference>
typename ft::iterator_vector<T, Category, Distance, Pointer, Reference>::reference		ft::iterator_vector<T, Category, Distance, Pointer, Reference>::operator[](int i)
{
	return this->_pointer[i];
}

template <class T, class Category, class Distance, class Pointer, class Reference>
ft::iterator_vector<T, Category, Distance, Pointer, Reference>	operator+(int n, ft::iterator_vector<T, Category, Distance, Pointer, Reference> const &iv)
{
	return iv + n;
}

/**********************************************************/
/*							ACCESS						  */
/**********************************************************/
template <class T, class Category, class Distance, class Pointer, class Reference>
typename ft::iterator_vector<T, Category, Distance, Pointer, Reference>::pointer	ft::iterator_vector<T, Category, Distance, Pointer, Reference>::get_pointer() const
{
	return this->_pointer;
}
