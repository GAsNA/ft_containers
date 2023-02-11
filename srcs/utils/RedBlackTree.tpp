/**********************************************************/
/*						CONSTRUCTORS					  */
/**********************************************************/
template <class T, class Comp, class Alloc>
ft::RBT<T, Comp, Alloc>::RBT(const allocator_type& alloc, const value_compare& comp) : _alloc(alloc), _comp(comp), _root(NULL), _nil(createNode(0)), _size(0) {}

template <class T, class Comp, class Alloc>
ft::RBT<T, Comp, Alloc>::RBT(const RBT &cpy) : _root(cpy._root) {}

template <class T, class Comp, class Alloc>
ft::RBT<T, Comp, Alloc>::~RBT()
{
	//node = this->_alloc.allocate(sizeof(Node<T>));
	//this->_alloc.construct(node, Node<T>(val));
	//Node<T>	*node = this->_root;
	//Node<T>	*tmp = this->_root;
	// HOW ?
}
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

template <class T, class Comp, class Alloc>
typename ft::RBT<T, Comp, Alloc>::size_type	ft::RBT<T, Comp, Alloc>::size() const { return this->_size; }

/**********************************************************/
/*						MODIFIERS						  */
/**********************************************************/
template <class T, class Comp, class Alloc>
void	ft::RBT<T, Comp, Alloc>::setRoot(Node<T> *root) { this->_root = root; }

template <class T, class Comp, class Alloc>
void	ft::RBT<T, Comp, Alloc>::insert(value_type val)
{
	Node<T>	*newNode = createNode(val);
	Node<T>	*parent = NULL;
	Node<T>	*node = this->_root;
	int		dir = 1;

	if (!this->_root) { this->_root = newNode; this->_size++; return; }
	while (node != this->_nil)
	{
		parent = node;
		if (*newNode >= *node) { dir = 2; node = node->right; }
		else if (*newNode < *node) { dir = 1; node = node->left; } // what if equal
	}
	if (dir == 1) { parent->left = newNode; }
	else { parent->right = newNode; }
	newNode->parent = parent;
	this->_size++;
}

template <class T, class Comp, class Alloc>
void	ft::RBT<T, Comp, Alloc>::deleteNode(value_type val)
{
	Node<T>	*nodeToDestroy = searchNode(val);
	Node<T>	*parent = NULL;
	Node<T>	*node = this->_root;
	Node<T>	*tmp;
	int		dir = 1;

	if (!nodeToDestroy) { return; }
	if (nodeToDestroy == this->_root) { tmp = this->_root->left; /*tmp*/  }
	while (node != this->_nil)
	{
		parent = node;
		if (*nodeToDestroy >= *node) { dir = 2; node = node->right; }
		else if (*nodeToDestroy < *node) { dir = 1; node = node->left; }
		
		/*if (*node == *nodeToDestroy)
		{
			parent
		}*/
		if (dir == 1) {}
	}
}

template <class T, class Comp, class Alloc>
void	ft::RBT<T, Comp, Alloc>::leftRotate(Node<T> *node)
{
	(void)node;
}

/**********************************************************/
/*						OTHERS							  */
/**********************************************************/
template <class T, class Comp, class Alloc>
void	ft::RBT<T, Comp, Alloc>::printHelper(Node<T> *root, std::string indent, bool last) const
{
	if (root != this->_nil)
	{
		std::cout << indent;
		if (last)
		{
			std::cout << "R----";
			indent += "   ";
		}
		else
		{
			std::cout << "L----";
			indent += "|  ";
		}

		std::string sColor = root->color == RED ? "RED" : "BLACK";
		std::cout << root->value << "(" << sColor << ")" << std::endl;
		printHelper(root->left, indent, false);
		printHelper(root->right, indent, true);
	}
}

template <class T, class Comp, class Alloc>
void	ft::RBT<T, Comp, Alloc>::printTree() const
{
	if (this->_root) { printHelper(this->_root, "", true); }
}

/**********************************************************/
/*						PRIVATES						  */
/**********************************************************/
template <class T, class Comp, class Alloc>
Node<T>	*ft::RBT<T, Comp, Alloc>::createNode(value_type val)
{
	Node<T>	*node;

	node = this->_alloc.allocate(sizeof(Node<T>));
	this->_alloc.construct(node, Node<T>(val));
	node->parent = this->_nil;
	node->left = this->_nil;
	node->right = this->_nil;
	return node;
}
