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
	this->clear(this->_root);
	this->destroyNode(this->_nil);
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

template <class T, class Comp, class Alloc>
ft::Node<T>	*ft::RBT<T, Comp, Alloc>::search(value_type val) const
{
	Node<T>	*node = this->_root;

	while(node != this->_nil)
	{
		if (node->value == val) { return node; }
		if (node->value > val) { node = node->left; }
		else { node = node->right; }
	}
	return NULL;
}

template <class T, class Comp, class Alloc>
Node<T>		*minimum(Node<T> *node) const
{
	while (node->left != this->_nil) { node = node->left; }
	return node;
}

template <class T, class Comp, class Alloc>
Node<T>		*maximum(Node<T> *node) const
{
	while (node->right != this->_nil) { node = node->right; }
	return node;
}

/**********************************************************/
/*						MODIFIERS						  */
/**********************************************************/
template <class T, class Comp, class Alloc>
void	ft::RBT<T, Comp, Alloc>::setRoot(Node<T> *root) { this->_root = root; }

template <class T, class Comp, class Alloc>
void	ft::RBT<T, Comp, Alloc>::insert(value_type val) // TODO A FIXE
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
		else if (*newNode < *node) { dir = 1; node = node->left; }
	}
	if (dir == 1) { parent->left = newNode; }
	else { parent->right = newNode; }
	newNode->parent = parent;
	this->_size++;
}

template <class T, class Comp, class Alloc>
void	ft::RBT<T, Comp, Alloc>::deleteNode(value_type val)			// TODO delete_fixup (RB-DELETE)
{
	Node<T>	*z = searchNode(val);
	Node<T>	*y = z;
	Node<T>	*x;
	Color	y_original_color = y->color;

	if (z->left == this->_nil) { x = z->right; this->transplant(z, z->right); }
	else if (z->right == this->_nil) { x = z->left; this->transplant(z, z->left); }
	else
	{
		y = minimum(z->right);
		y_original_color = y->color;
		x = y->right;
		
		if (y->parent == z) { x->parent = y; }
		else { this->transplant(y, y->right); y->right = z->right; y->right->parent = y; }

		this->transplant(z, y);
		y->left = z->left;
		y->left->parent = y;
		y->color = z->color;
	}

	if (y_original_color == BLACK) { this->delete_fixup(x); }
}

template <class T, class Comp, class Alloc>
void	ft::RBT<T, Comp, Alloc>::leftRotate(Node<T> *node)
{
	Node<T>	*x = node;
	Node<T>	*y;

	y = x->right;
	x->right = y->left;

	if (y->left != this->_nil) { y->left->parent = x; }
	
	y->parent = x->parent;

	if (x->parent == this->_nil) { this->_root = y; }
	else if (x == x->parent->left) { x->parent->left = y; }
	else { x->parent->right = y; }

	y->left = x;
	x->parent = y;
}

template <class T, class Comp, class Alloc>
void	ft::RBT<T, Comp, Alloc>::rightRotate(Node<T> *node) // TODO
{}

template <class T, class Comp, class Alloc>
void	ft::RBT<T, Comp, Alloc>::clear(Node<T> *node)
{
	if (node == NULL || node == this->_nil) { return; }
	clear(node->left);
	clear(node->right);
	destroyNode(node);
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

template <class T, class Comp, class Alloc>
void	ft::RBT<T, Comp, Alloc>::destroyNode(Node<T> *node)
{
	this->_alloc.destroy(node);
	this->_alloc.deallocate(node, sizeof(Node<T>));
}

template <class T, class Comp, class Alloc>
void	ft::RBT<T, Comp, Alloc>::transplant(Node<T> *n1, Node<T> *n2)
{
	if (n1->parent == this->_nil) { this->_root = n2; }
	else if (n1 == n1->parent->left) { n1->parent->left = n2; }
	else { n1->parent->right = n2; }

	n2->parent = n1->parent;
}
