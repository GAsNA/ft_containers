/**********************************************************/
/*						CONSTRUCTORS					  */
/**********************************************************/
template <class Iterator>
ft::reverse_iterator<Iterator>::reverse_iterator() : _iterator(NULL)
{}

template <class Iterator>
ft::reverse_iterator<Iterator>::reverse_iterator(iterator x) : _iterator(x)
{}

template <class Iterator>
template <class U>
ft::reverse_iterator<Iterator>::reverse_iterator(const reverse_iterator<U>& other) : _iterator(other.base())
{}

/**********************************************************/
/*						OPERATORS						  */
/**********************************************************/
template <class Iterator>
template <class U>
ft::reverse_iterator<Iterator>	&ft::reverse_iterator<Iterator>::operator=(const reverse_iterator<U>& other)
{
	this->_iterator = other.base();
	return *this;
}

template <class Iterator>
typename ft::reverse_iterator<Iterator>::reference	ft::reverse_iterator<Iterator>::operator*() const
{
	iterator tmp = this->_iterator;
	return *--tmp;
}

template <class Iterator>
typename ft::reverse_iterator<Iterator>::pointer	ft::reverse_iterator<Iterator>::operator->() const
{
	return &(this->operator*());
}

template <class Iterator>
typename ft::reverse_iterator<Iterator>::reference	ft::reverse_iterator<Iterator>::operator[](difference_type n) const
{
	return this->base()[ -n -1];
}

template <class Iterator>
ft::reverse_iterator<Iterator>	&ft::reverse_iterator<Iterator>::operator++()
{
	this->_iterator--;
	return *this;
}

template <class Iterator>
ft::reverse_iterator<Iterator>	&ft::reverse_iterator<Iterator>::operator--()
{
	this->_iterator++;
	return *this;
}

template <class Iterator>
ft::reverse_iterator<Iterator>	ft::reverse_iterator<Iterator>::operator++(int)
{
	reverse_iterator	riv(*this);
	operator++();
	return riv;
}

template <class Iterator>
ft::reverse_iterator<Iterator>	ft::reverse_iterator<Iterator>::operator--(int)
{
	reverse_iterator	riv(*this);
	operator--();
	return riv;
}

template <class Iterator>
ft::reverse_iterator<Iterator>	ft::reverse_iterator<Iterator>::operator+(difference_type n) const
{
	reverse_iterator	riv(*this);
	riv += n;
	return riv;
}

template <class Iterator>
ft::reverse_iterator<Iterator>	ft::reverse_iterator<Iterator>::operator-(difference_type n) const
{
	reverse_iterator	riv(*this);
	riv -= n;
	return riv;
}

template <class Iterator>
ft::reverse_iterator<Iterator>	&ft::reverse_iterator<Iterator>::operator+=(difference_type n)
{
	this->_iterator -= n;
	return *this;
}

template <class Iterator>
ft::reverse_iterator<Iterator>	&ft::reverse_iterator<Iterator>::operator-=(difference_type n)
{
	this->_iterator += n;
	return *this;
}

// EXTERN
template <class Iterator1, class Iterator2>
bool operator==(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs)
{
	return lhs.base() == rhs.base();
}

template <class Iterator>
bool operator==(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs)
{
	return lhs.base() == rhs.base();
}

template <class Iterator1, class Iterator2>
bool operator!=(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs)
{
	return lhs.base() != rhs.base();
}

template <class Iterator>
bool operator!=(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs)
{
	return lhs.base() != rhs.base();
}

template <class Iterator1, class Iterator2>
bool operator<(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs)
{
	return lhs.base() > rhs.base();
}

template <class Iterator>
bool operator<(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs)
{
	return lhs.base() > rhs.base();
}

template <class Iterator1, class Iterator2>
bool operator<=(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs)
{
	return lhs.base() >= rhs.base();
}

template <class Iterator>
bool operator<=(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs)
{
	return lhs.base() >= rhs.base();
}

template <class Iterator1, class Iterator2>
bool operator>(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs)
{
	return lhs.base() < rhs.base();
}

template <class Iterator>
bool operator>(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs)
{
	return lhs.base() < rhs.base();
}

template <class Iterator1, class Iterator2>
bool operator>=(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs)
{
	return lhs.base() <= rhs.base();
}

template <class Iterator>
bool operator>=(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs)
{
	return lhs.base() <= rhs.base();
}

template <class Iter>
ft::reverse_iterator<Iter> operator+(typename ft::reverse_iterator<Iter>::difference_type n, const ft::reverse_iterator<Iter>& it)
{
	return ft::reverse_iterator<Iter>(it.base() - n);
}

template <class Iterator1, class Iterator2>
typename ft::reverse_iterator<Iterator1>::difference_type operator-(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs)
{
	return rhs.base() - lhs.base();
}

/**********************************************************/
/*							ACCESS						  */
/**********************************************************/
template <class Iterator>
typename ft::reverse_iterator<Iterator>::iterator	ft::reverse_iterator<Iterator>::base() const
{
	return iterator(this->_iterator);
}
