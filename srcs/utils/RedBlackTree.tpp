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
		if (node->value >= val) { node = node->left; }
		else { node = node->right; }
	}
	return NULL;
}

template <class T, class Comp, class Alloc>
Node<T>		*ft::RBT<T, Comp, Alloc>::minimum(Node<T> *node) const
{
	while (node->left != this->_nil) { node = node->left; }
	return node;
}

template <class T, class Comp, class Alloc>
Node<T>		*ft::RBT<T, Comp, Alloc>::maximum(Node<T> *node) const
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
void	ft::RBT<T, Comp, Alloc>::insert(value_type val)
{
	Node<T>	*newNode = createNode(val);
	Node<T>	*node = this->_root;
	Node<T>	*tmp = this->_nil;

	if (!this->_root) { this->_root = newNode; this->_size++; return; }

	while (node != this->_nil)
	{
		tmp = node;
		if (newNode->value < node->value) { node = node->left; }
		else { node = node->right; }
	}

	newNode->parent = tmp;

	if (tmp == this->_nil) { this->_root = newNode; }
	else if (newNode->value < tmp->value) { tmp->left = newNode; }
	else { tmp->right = newNode; }

	newNode->color = RED;
	this->_size++;

	this->insert_fixup(newNode);
}

template <class T, class Comp, class Alloc>
void	ft::RBT<T, Comp, Alloc>::deleteNode(value_type val)
{
	Node<T>	*z = search(val);

	if (z == NULL) { return; }

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

	this->destroyNode(z);
	this->_size--;

	if (y_original_color == BLACK) { this->delete_fixup(x); }
}

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
void	ft::RBT<T, Comp, Alloc>::rightRotate(Node<T> *node)
{
	Node<T>	*x = node;
	Node<T>	*y;

	y = x->left;
	x->left = y->right;

	if (y->right != this->_nil) { y->right->parent = x; }
	
	y->parent = x->parent;

	if (x->parent == this->_nil) { this->_root = y; }
	else if (x == x->parent->right) { x->parent->right = y; }
	else { x->parent->left = y; }

	y->right = x;
	x->parent = y;
}

template <class T, class Comp, class Alloc>
void	ft::RBT<T, Comp, Alloc>::insert_fixup(Node<T> *node)
{
	Node<T>	*tmp;

	while (node->parent->color == RED)
	{
		if (node->parent == node->parent->parent->left)
		{
			tmp = node->parent->parent->right;
			if (tmp->color == RED)
			{
				node->parent->color = BLACK;
				tmp->color = BLACK;
				node->parent->parent->color = RED;
				node = node->parent->parent;
			}
			else
			{
				if (node == node->parent->right) { node = node->parent; this->leftRotate(node); }
				node->parent->color = BLACK;
				node->parent->parent->color = RED;
				this->rightRotate(node->parent->parent);
			}
		}
		else
		{
			tmp = node->parent->parent->left;
			if (tmp->color == RED)
			{
				node->parent->color = BLACK;
				tmp->color = BLACK;
				node->parent->parent->color = RED;
				node = node->parent->parent;
			}
			else
			{
				if (node == node->parent->left) { node = node->parent; this->rightRotate(node); }
				node->parent->color = BLACK;
				node->parent->parent->color = RED;
				this->leftRotate(node->parent->parent);
			}
		}
	}

	this->_root->color = BLACK;
}

template <class T, class Comp, class Alloc>
void	ft::RBT<T, Comp, Alloc>::transplant(Node<T> *n1, Node<T> *n2)
{
	if (n1->parent == this->_nil) { this->_root = n2; }
	else if (n1 == n1->parent->left) { n1->parent->left = n2; }
	else { n1->parent->right = n2; }

	n2->parent = n1->parent;
}

template <class T, class Comp, class Alloc>
void	ft::RBT<T, Comp, Alloc>::delete_fixup(Node<T> *node)
{
	Node<T>	*tmp;

	while (node != this->_root && node->color == BLACK)
	{
		if (node == node->parent->left)
		{
			tmp = node->parent->right;
			if (tmp->color == RED)
			{
				tmp->color = BLACK;
				node->parent->color = RED;
				this->leftRotate(node->parent);
				tmp = node->parent->right;
			}
			if (tmp->left->color == BLACK && tmp->right->color == BLACK) { tmp->color = RED; node = node->parent; }
			else
			{
				if (tmp->right->color == BLACK)
				{
					tmp->left->color = BLACK;
					tmp->color = RED;
					this->rightRotate(tmp);
					tmp = node->parent->right;
				}
				tmp->color = node->parent->color;
				node->parent->color = BLACK;
				tmp->right->color = BLACK;
				this->leftRotate(node->parent);
				node = this->_root;
			}
		}
		else
		{
			tmp = node->parent->left;
			if (tmp->color == RED)
			{
				tmp->color = BLACK;
				node->parent->color = RED;
				this->rightRotate(node->parent);
				tmp = node->parent->left;
			}
			if (tmp->right->color == BLACK && tmp->left->color == BLACK) { tmp->color = RED; node = node->parent; }
			else
			{
				if (tmp->left->color == BLACK)
				{
					tmp->right->color = BLACK;
					tmp->color = RED;
					this->leftRotate(tmp);
					tmp = node->parent->left;
				}
				tmp->color = node->parent->color;
				node->parent->color = BLACK;
				tmp->left->color = BLACK;
				this->rightRotate(node->parent);
				node = this->_root;
			}
		}
	}
	node->color = BLACK;
}
