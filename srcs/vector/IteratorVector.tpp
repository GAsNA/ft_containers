/* CONSTRUCTORS */
template <class T, class Category, class Distance, class Pointer, class Reference>
ft::IteratorVector<T, Category, Distance, Pointer, Reference>::IteratorVector() : _pointer(NULL) {}

template <class T, class Category, class Distance, class Pointer, class Reference>
ft::IteratorVector<T, Category, Distance, Pointer, Reference>::IteratorVector(pointer ptr) : _pointer(ptr) {}

template <class T, class Category, class Distance, class Pointer, class Reference>
ft::IteratorVector<T, Category, Distance, Pointer, Reference>::IteratorVector(const IteratorVector &x) : _pointer(x.get_pointer()) {}

template <class T, class Category, class Distance, class Pointer, class Reference>
ft::IteratorVector<T, Category, Distance, Pointer, Reference>::~IteratorVector() {};

/* OPERATORS */
template <class T, class Category, class Distance, class Pointer, class Reference>
ft::IteratorVector<T, Category, Distance, Pointer, Reference>	&ft::IteratorVector<T, Category, Distance, Pointer, Reference>::operator=(const IteratorVector &rhs)
{
	if (this == &rhs) {return *this;}

	this->_pointer = rhs.get_pointer();
	return *this;
}

template <class T, class Category, class Distance, class Pointer, class Reference>
ft::IteratorVector<T, Category, Distance, Pointer, Reference>	&ft::IteratorVector<T, Category, Distance, Pointer, Reference>::operator++()
{
	this->_pointer++;
	return *this;
}

template <class T, class Category, class Distance, class Pointer, class Reference>
ft::IteratorVector<T, Category, Distance, Pointer, Reference>	ft::IteratorVector<T, Category, Distance, Pointer, Reference>::operator++(int)
{
	IteratorVector iv(*this);
	operator++();
	return iv;
}

template <class T, class Category, class Distance, class Pointer, class Reference>
ft::IteratorVector<T, Category, Distance, Pointer, Reference>	&ft::IteratorVector<T, Category, Distance, Pointer, Reference>::operator--()
{
	this->_pointer--;
	return *this;
}

template <class T, class Category, class Distance, class Pointer, class Reference>
ft::IteratorVector<T, Category, Distance, Pointer, Reference>	ft::IteratorVector<T, Category, Distance, Pointer, Reference>::operator--(int)
{
	IteratorVector iv(*this);
	operator--();
	return iv;
}

template <class T, class Category, class Distance, class Pointer, class Reference>
bool	ft::IteratorVector<T, Category, Distance, Pointer, Reference>::operator>(IteratorVector const &iv) const
{
	if (this->_pointer > iv.get_pointer())
		return 1;
	return 0;
	//return this->_pointer > iv.pointer()
}

template <class T, class Category, class Distance, class Pointer, class Reference>
bool	ft::IteratorVector<T, Category, Distance, Pointer, Reference>::operator<(IteratorVector const &iv) const
{
	if (this->_pointer < iv.get_pointer())
		return 1;
	return 0;
}

template <class T, class Category, class Distance, class Pointer, class Reference>
bool	ft::IteratorVector<T, Category, Distance, Pointer, Reference>::operator>=(IteratorVector const &iv) const
{
	if (this->_pointer >= iv.get_pointer())
		return 1;
	return 0;
}

template <class T, class Category, class Distance, class Pointer, class Reference>
bool	ft::IteratorVector<T, Category, Distance, Pointer, Reference>::operator<=(IteratorVector const &iv) const
{
	if (this->_pointer <= iv.get_pointer())
		return 1;
	return 0;
}

template <class T, class Category, class Distance, class Pointer, class Reference>
bool	ft::IteratorVector<T, Category, Distance, Pointer, Reference>::operator==(IteratorVector const &iv) const
{
	if (this->_pointer == iv.get_pointer())
		return 1;
	return 0;
}

template <class T, class Category, class Distance, class Pointer, class Reference>
bool	ft::IteratorVector<T, Category, Distance, Pointer, Reference>::operator!=(IteratorVector const &iv) const
{
	if (this->_pointer != iv.get_pointer())
		return 1;
	return 0;
}

template <class T, class Category, class Distance, class Pointer, class Reference>
T	&ft::IteratorVector<T, Category, Distance, Pointer, Reference>::operator*()
{
	return *this->_pointer;
}

/* ACCESS  */
template <class T, class Category, class Distance, class Pointer, class Reference>
typename ft::IteratorVector<T, Category, Distance, Pointer, Reference>::pointer	ft::IteratorVector<T, Category, Distance, Pointer, Reference>::get_pointer() const
{
	return this->_pointer;
}
