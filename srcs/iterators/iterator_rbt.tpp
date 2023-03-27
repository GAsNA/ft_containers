/**********************************************************/
/*						CONSTRUCTORS					  */
/**********************************************************/
template <class T, class N>
ft::iterator_rbt<T, N>::iterator_rbt() : _pointer(NULL) {}

template <class T, class N>
ft::iterator_rbt<T, N>::iterator_rbt(node_pointer ptr) : _pointer(ptr) {}

template <class T, class N>
ft::iterator_rbt<T, N>::iterator_rbt(const iterator_rbt &x) : _pointer(x.get_pointer()) {}

template <class T, class N>
ft::iterator_rbt<T, N>::~iterator_rbt() {};

/**********************************************************/
/*						OPERATORS						  */
/**********************************************************/
/*template <class T, class N>
ft::iterator_rbt<T, N>::operator iterator_rbt<const T, N>() const
{
	return iterator_rbt<const T, N>(this->_pointer);
}*/

template <class T, class N>
ft::iterator_rbt<T, N>	&ft::iterator_rbt<T, N>::operator=(const iterator_rbt<const T, N> &rhs)
{
	if (this == &rhs) {return *this;}

	this->_pointer = rhs.get_pointer();
	return *this;
}

template <class T, class N>
ft::iterator_rbt<T, N>	&ft::iterator_rbt<T, N>::operator++()
{
	node_pointer node = this->_pointer;
	node_pointer tmp = this->_pointer->parent;

	if (!this->_pointer->is_nil && !this->_pointer->right->is_nil)
	{
		this->_pointer = this->_pointer->right;
		while (!this->_pointer->is_nil && !this->_pointer->left->is_nil) { this->_pointer = this->_pointer->left; }
	}
	else if (!this->_pointer->is_nil && !this->_pointer->parent->is_nil)
	{
		node = this->_pointer;
		tmp = this->_pointer->parent;
		while (!tmp->is_nil && this->_pointer == tmp->right)
		{
			if (tmp->parent->is_nil) { this->_pointer = node->right; return *this; } //node->parent
			this->_pointer = tmp;
			tmp = tmp->parent;
		}
		this->_pointer = tmp;
	}
	else if (!this->_pointer->is_nil) { this->_pointer = this->_pointer->right; }

	return *this;
}

template <class T, class N>
ft::iterator_rbt<T, N>	ft::iterator_rbt<T, N>::operator++(int)
{
	iterator_rbt iv(*this);
	operator++();
	return iv;
}

template <class T, class N>
ft::iterator_rbt<T, N>	&ft::iterator_rbt<T, N>::operator--()
{
	node_pointer	node = this->_pointer;
	node_pointer	tmp = this->_pointer->parent;

	if (this->_pointer->is_nil) { this->_pointer = this->_pointer->parent; }
	else if (!this->_pointer->is_nil && !this->_pointer->left->is_nil)
	{
		this->_pointer = this->_pointer->left;
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

template <class T, class N>
ft::iterator_rbt<T, N>	ft::iterator_rbt<T, N>::operator--(int)
{
	iterator_rbt iv(*this);
	operator--();
	return iv;
}

/*template <class T, class N>
bool	ft::iterator_rbt<T, N>::operator>(iterator_rbt<const T, N> const &iv) const
{
	if (this->_pointer->is_nil == iv.get_pointer()->is_nil) { return false; }
	return this->_pointer->value > iv.get_pointer()->value;
}

template <class T, class N>
bool	ft::iterator_rbt<T, N>::operator<(iterator_rbt<const T, N> const &iv) const
{
	if (this->_pointer->is_nil == iv.get_pointer()->is_nil) { return false; }
	return this->_pointer->value < iv.get_pointer()->value;
}

template <class T, class N>
bool	ft::iterator_rbt<T, N>::operator>=(iterator_rbt<const T, N> const &iv) const
{
	return !(this->_pointer > iv.get_pointer());
}

template <class T, class N>
bool	ft::iterator_rbt<T, N>::operator<=(iterator_rbt<const T, N> const &iv) const
{
	return !(this->_pointer < iv.get_pointer());
}*/

template <class T, class N>
bool	ft::iterator_rbt<T, N>::operator==(iterator_rbt<const T, N> const &iv) const
{
	return this->_pointer->value.first == iv.get_pointer()->value.first && this->_pointer->is_nil == iv.get_pointer()->is_nil;
	//return this->_pointer == iv.get_pointer();
}

template <class T, class N>
bool	ft::iterator_rbt<T, N>::operator!=(iterator_rbt<const T, N> const &iv) const
{
	return !(*this == iv);
	//return this->_pointer != iv.get_pointer();
}

template <class T, class N>
T	&ft::iterator_rbt<T, N>::operator*() const
{
	return this->_pointer->value;
}

template <class T, class N>
T	*ft::iterator_rbt<T, N>::operator->() const
{
	return &(this->_pointer->value);
}

/**********************************************************/
/*							ACCESS						  */
/**********************************************************/
template <class T, class N>
typename ft::iterator_rbt<T, N>::node_pointer	ft::iterator_rbt<T, N>::get_pointer() const
{
	return this->_pointer;
}
