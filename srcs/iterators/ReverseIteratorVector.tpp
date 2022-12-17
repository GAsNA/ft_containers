/**********************************************************/
/*						CONSTRUCTORS					  */
/**********************************************************/
template <class Iterator>
ft::ReverseIteratorVector<Iterator>::ReverseIteratorVector() : _iterator(NULL)
{}

template <class Iterator>
ft::ReverseIteratorVector<Iterator>::ReverseIteratorVector(iterator x) : _iterator(x)
{}

template <class Iterator>
template <class U>
ft::ReverseIteratorVector<Iterator>::ReverseIteratorVector(const ReverseIteratorVector<U>& other) : _iterator(other.base())
{}

/**********************************************************/
/*						OPERATORS						  */
/**********************************************************/
template <class Iterator>
template <class U>
ft::ReverseIteratorVector<Iterator>	&ft::ReverseIteratorVector<Iterator>::operator=(const ReverseIteratorVector<U>& other)
{
	if (this == &other) {return;}

	this->_iterator = other.base();
	return *this;
}

template <class Iterator>
typename ft::ReverseIteratorVector<Iterator>::reference	ft::ReverseIteratorVector<Iterator>::operator*() const
{
	iterator tmp = this->_iterator;
	return *(--tmp);
}

template <class Iterator>
typename ft::ReverseIteratorVector<Iterator>::pointer	ft::ReverseIteratorVector<Iterator>::operator->() const
{
	return &(this->operator*()); //??????
}

template <class Iterator>
typename ft::ReverseIteratorVector<Iterator>::reference	ft::ReverseIteratorVector<Iterator>::operator[](difference_type n) const
{
	return &(this->base()[-n-1]);
}

template <class Iterator>
ft::ReverseIteratorVector<Iterator>	&ft::ReverseIteratorVector<Iterator>::operator++()
{
	this->_iterator--;
	return *this;
}

template <class Iterator>
ft::ReverseIteratorVector<Iterator>	&ft::ReverseIteratorVector<Iterator>::operator--()
{
	this->_iterator++;
	return *this;
}

template <class Iterator>
ft::ReverseIteratorVector<Iterator>	ft::ReverseIteratorVector<Iterator>::operator++(int)
{
	ReverseIteratorVector	riv(*this);
	operator++();
	return riv;
}

template <class Iterator>
ft::ReverseIteratorVector<Iterator>	ft::ReverseIteratorVector<Iterator>::operator--(int)
{
	ReverseIteratorVector	riv(*this);
	operator--();
	return riv;
}

template <class Iterator>
ft::ReverseIteratorVector<Iterator>	ft::ReverseIteratorVector<Iterator>::operator+(difference_type n) const
{
	ReverseIteratorVector	riv(*this);
	riv -= n;
	return riv;
}

template <class Iterator>
ft::ReverseIteratorVector<Iterator>	ft::ReverseIteratorVector<Iterator>::operator-(difference_type n) const
{
	ReverseIteratorVector	riv(*this);
	riv += n;
	return riv;
}

template <class Iterator>
ft::ReverseIteratorVector<Iterator>	&ft::ReverseIteratorVector<Iterator>::operator+=(difference_type n)
{
	this->_iterator -= n;
	return *this;
}

template <class Iterator>
ft::ReverseIteratorVector<Iterator>	&ft::ReverseIteratorVector<Iterator>::operator-=(difference_type n)
{
	this->_iterator += n;
	return *this;
}

// EXTERN
template <class Iterator1, class Iterator2>
bool operator==(const ft::ReverseIteratorVector<Iterator1>& lhs, const ft::ReverseIteratorVector<Iterator2>& rhs)
{
	return lhs.base() == rhs.base();
}

template <class Iterator1, class Iterator2>
bool operator!=(const ft::ReverseIteratorVector<Iterator1>& lhs, const ft::ReverseIteratorVector<Iterator2>& rhs)
{
	return lhs.base() != rhs.base();
}

template <class Iterator1, class Iterator2>
bool operator<(const ft::ReverseIteratorVector<Iterator1>& lhs, const ft::ReverseIteratorVector<Iterator2>& rhs)
{
	return lhs.base < rhs.base();
}

template <class Iterator1, class Iterator2>
bool operator<=(const ft::ReverseIteratorVector<Iterator1>& lhs, const ft::ReverseIteratorVector<Iterator2>& rhs)
{
	return lhs.base() <= rhs.base();
}

template <class Iterator1, class Iterator2>
bool operator>(const ft::ReverseIteratorVector<Iterator1>& lhs, const ft::ReverseIteratorVector<Iterator2>& rhs)
{
	return lhs.base() > rhs.base();
}

template <class Iterator1, class Iterator2>
bool operator>=(const ft::ReverseIteratorVector<Iterator1>& lhs, const ft::ReverseIteratorVector<Iterator2>& rhs)
{
	return lhs.base >= rhs.base();
}

template <class Iter>
ft::ReverseIteratorVector<Iter> operator+(typename ft::ReverseIteratorVector<Iter>::difference_type n, const ft::ReverseIteratorVector<Iter>& it)
{
	return ft::ReverseIteratorVector<Iter>(it.base() - n);
}

template <class Iterator1, class Iterator2>
typename ft::ReverseIteratorVector<Iterator1>::difference_type operator-(const ft::ReverseIteratorVector<Iterator1>& lhs, const ft::ReverseIteratorVector<Iterator2>& rhs)
{
	return rhs.base - lhs.base();
}

/**********************************************************/
/*							ACCESS						  */
/**********************************************************/
template <class Iterator>
typename ft::ReverseIteratorVector<Iterator>::iterator	ft::ReverseIteratorVector<Iterator>::base() const
{
	return iterator(this->_iterator);
}
