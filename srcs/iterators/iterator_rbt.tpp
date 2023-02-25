/**********************************************************/
/*						CONSTRUCTORS					  */
/**********************************************************/
template <class T>
ft::iterator_rbt<T>::iterator_rbt() : _pointer(NULL) {}

template <class T>
ft::iterator_rbt<T>::iterator_rbt(pointer ptr) : _pointer(ptr) {}

template <class T>
ft::iterator_rbt<T>::iterator_rbt(const iterator_rbt &x) : _pointer(x.get_pointer()) {}

template <class T>
ft::iterator_rbt<T>::~iterator_rbt() {};

/**********************************************************/
/*						OPERATORS						  */
/**********************************************************/
template <class T>
ft::iterator_rbt<T>::operator iterator_rbt<const T>() const
{
	return iterator_rbt<const T>(this->_pointer);
}

template <class T>
ft::iterator_rbt<T>	&ft::iterator_rbt<T>::operator=(const iterator_rbt<const T> &rhs)
{
	if (this == &rhs) {return *this;}

	this->_pointer = rhs.get_pointer();
	return *this;
}

template <class T>
ft::iterator_rbt<T>	&ft::iterator_rbt<T>::operator++()
{
	ft::Node<T>	node = this->_pointer;
	ft::Node<T>	tmp = this->_pointer->parent;

	if (!this->_pointer->is_nil && !this->_pointer->right->is_nil)
	{
		this->_pointer = this->pointer->right;
		while (!this->_pointer->is_nil && !this->_pointer->left->is_nil) { this->_pointer = this->_pointer->left; }
	}
	else if (!this->_pointer->is_nil && !this->_pointer->parent->is_nil)
	{
		node = this->_pointer;
		tmp = this->_pointer->parent;
		while (!tmp->is_nil && this->_pointer == tmp->right)
		{
			if (tmp->parent->is_nil) { this->_pointer = node->parent; return *this; }
			this->_pointer = tmp;
			tmp = tmp->parent;
		}
		this->_pointer = tmp;
	}

	return *this;
}

template <class T>
ft::iterator_rbt<T>	ft::iterator_rbt<T>::operator++(int)
{
	iterator_rbt iv(*this);
	operator++();
	return iv;
}

template <class T>
ft::iterator_rbt<T>	&ft::iterator_rbt<T>::operator--()
{
	ft::Node<T>	node = this->_pointer;
	ft::Node<T>	tmp = this->_pointer->parent;

	if (!this->_pointer->is_nil && !this->_pointer->left->is_nil)
	{
		this->_pointer = this->pointer->left;
		while (!this->_pointer->is_nil && !this->_pointer->right->is_nil) { this->_pointer = this->_pointer->right; }
	}
	else if (!this->_pointer->is_nil && !this->_pointer->parent->is_nil)
	{
		node = this->_pointer;
		tmp = this->_pointer->parent;
		while (!tmp->is_nil && this->_pointer == tmp->left)
		{
			if (tmp->parent->is_nil) { this->_pointer = node->parent; return *this; }
			this->_pointer = tmp;
			tmp = tmp->parent;
		}
		this->_pointer = tmp;
	}

	return *this;
}

template <class T>
ft::iterator_rbt<T>	ft::iterator_rbt<T>::operator--(int)
{
	iterator_rbt iv(*this);
	operator--();
	return iv;
}

template <class T>
bool	ft::iterator_rbt<T>::operator>(iterator_rbt<const T> const &iv) const
{
	return this->_pointer->value > iv.pointer()->value && this->_pointer->is_nil == iv.getPointer()->is_nil;
}

template <class T>
bool	ft::iterator_rbt<T>::operator<(iterator_rbt<const T> const &iv) const
{
	return this->_pointer->value < iv.pointer()->value && this->_pointer->is_nil == iv.getPointer()->is_nil;
}

template <class T>
bool	ft::iterator_rbt<T>::operator>=(iterator_rbt<const T> const &iv) const
{
	return !(this->_pointer > iv.get_pointer());
}

template <class T>
bool	ft::iterator_rbt<T>::operator<=(iterator_rbt<const T> const &iv) const
{
	return !(this->_pointer < iv.get_pointer());
}

template <class T>
bool	ft::iterator_rbt<T>::operator==(iterator_rbt<const T> const &iv) const
{
	return this->_pointer->value == iv.get_pointer()->value && this->_pointer->is_nil == iv.getPointer()->is_nil;
}

template <class T>
bool	ft::iterator_rbt<T>::operator!=(iterator_rbt<const T> const &iv) const
{
	return !(this == iv);
}

template <class T>
T	&ft::iterator_rbt<T>::operator*()
{
	return *(this->_pointer->value);
}

template <class T>
typename ft::iterator_rbt<T>::value_type	*ft::iterator_rbt<T>::operator->()
{
	return this->_pointer->value;
}

/*template <class T>
typename ft::iterator_rbt<T>::reference		ft::iterator_rbt<T>::operator[](int i)
{
	return this->_pointer[i];	//TODO
}*/

/**********************************************************/
/*							ACCESS						  */
/**********************************************************/
template <class T>
typename ft::iterator_rbt<T>::pointer	ft::iterator_rbt<T>::get_pointer() const
{
	return this->_pointer;
}
