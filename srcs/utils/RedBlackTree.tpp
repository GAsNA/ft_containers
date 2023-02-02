/**********************************************************/
/*						CONSTRUCTORS					  */
/**********************************************************/
template <class T, class Comp, class Alloc>
ft::RBT<T, Comp, Alloc>::RBT(const allocator_type& alloc, const value_compare& comp) : _alloc(alloc), _comp(comp), _root(NULL), _size(0) {}

template <class T, class Comp, class Alloc>
ft::RBT<T, Comp, Alloc>::RBT(const RBT &cpy) : _root(cpy._root) {}

template <class T, class Comp, class Alloc>
ft::RBT<T, Comp, Alloc>::~RBT() {}		// delete root

/**********************************************************/
/*						OPERATORS						  */
/**********************************************************/
template <class T, class Comp, class Alloc>
ft::RBT<T, Comp, Alloc>	&ft::RBT<T, Comp, Alloc>::operator=(RBT const &rhs)
{
	if (this == &rhs) { return *this; }
	this->_root = rhs._root;
	return *this;
}

/**********************************************************/
/*						ACCESS							  */
/**********************************************************/
template <class T, class Comp, class Alloc>
ft::Node<T>	*ft::RBT<T, Comp, Alloc>::getRoot() const { return this->_root; }

/**********************************************************/
/*						MODIFIERS						  */
/**********************************************************/
template <class T, class Comp, class Alloc>
void	ft::RBT<T, Comp, Alloc>::setRoot(Node<T> *root) { this->_root = root; }
