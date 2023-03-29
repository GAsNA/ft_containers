#include <unistd.h>

/**********************************************************/
/*						CONSTRUCTORS					  */
/**********************************************************/
template <class T, class K, class Comp, class Alloc>
ft::RBT<T, K, Comp, Alloc>::RBT(const allocator_type& alloc, const value_compare& comp) : _alloc(alloc), _comp(comp), _end(createNode(true)), _nil(createNode(true)), _size(0) { this->_root = this->_nil; }

template <class T, class K, class Comp, class Alloc>
ft::RBT<T, K, Comp, Alloc>::RBT(const RBT &cpy)
{
	this->clear(this->_root);
	this->destroyNode(this->_end);
	this->destroyNode(this->_nil);

	this->_alloc = cpy._alloc;
	this->_node_alloc = cpy._node_alloc;
	this->_comp = cpy._comp;
	this->_end = createNode(true);
	this->_nil = createNode(true);
	this->_size = 0;

	iterator	it = cpy.begin();
	iterator	ite = cpy.end();
	for (; it != ite; it++) { this->insert(*it); }
}

template <class T, class K, class Comp, class Alloc>
ft::RBT<T, K, Comp, Alloc>::~RBT()
{
	//this->clear(this->_root);
	this->destroyNode(this->_end);
	this->destroyNode(this->_nil);
}
/**********************************************************/
/*						OPERATORS						  */
/**********************************************************/
template <class T, class K, class Comp, class Alloc>
ft::RBT<T, K, Comp, Alloc>	&ft::RBT<T, K, Comp, Alloc>::operator=(RBT const &rhs)
{
	if (this == &rhs) { return *this; }
	this->clear(this->_root);
	this->destroyNode(this->_end);
	this->destroyNode(this->_nil);

	this->_alloc = rhs._alloc;
	this->_node_alloc = rhs._node_alloc;
	this->_comp = rhs._comp;
	this->_end = createNode(true);
	this->_nil = createNode(true);
	this->_size = 0;

	iterator	it = rhs.begin();
	iterator	ite = rhs.end();
	for (; it != ite; it++) { this->insert(*it); }
	return *this;
}

/**********************************************************/
/*						ACCESS							  */
/**********************************************************/
template <class T, class K, class Comp, class Alloc>
typename ft::RBT<T, K, Comp, Alloc>::node_pointer	ft::RBT<T, K, Comp, Alloc>::getRoot() const { return this->_root; }

template <class T, class K, class Comp, class Alloc>
typename ft::RBT<T, K, Comp, Alloc>::node_allocator	ft::RBT<T, K, Comp, Alloc>::get_allocator() const { return this->_node_alloc; }

template <class T, class K, class Comp, class Alloc>
typename ft::RBT<T, K, Comp, Alloc>::node_pointer	ft::RBT<T, K, Comp, Alloc>::search(value_type val) const
{
	node_pointer	node = this->_root;
	
	while(node != this->_nil && node != this->_end)
	{
		if (this->_comp(node->value.first, val.first)) { node = node->right; }
		else if (this->_comp(val.first, node->value.first)) { node = node->left; }
		else { return node; }
	}
	return NULL;
}

template <class T, class K, class Comp, class Alloc>
typename ft::RBT<T, K, Comp, Alloc>::node_pointer	ft::RBT<T, K, Comp, Alloc>::minimum(node_pointer node) const
{	
	while (node != this->_nil && node != this->_end && node->left != this->_nil && node->left != this->_end) { node = node->left; }
	return node;
}

template <class T, class K, class Comp, class Alloc>
typename ft::RBT<T, K, Comp, Alloc>::node_pointer	ft::RBT<T, K, Comp, Alloc>::maximum(node_pointer node) const
{
	while (node != this->_nil && node != this->_end && node->right != this->_nil && node->right != this->_end) { node = node->right; }
	return node;
}

template <class T, class K, class Comp, class Alloc>
typename ft::RBT<T, K, Comp, Alloc>::value_compare	ft::RBT<T, K, Comp, Alloc>::compare() const { return this->_comp; }

/**********************************************************/
/*						ITERATORS						  */
/**********************************************************/
template <class T, class K, class Comp, class Alloc>
typename ft::RBT<T, K, Comp, Alloc>::iterator	ft::RBT<T, K, Comp, Alloc>::begin() { return iterator(minimum(this->_root)); }

template <class T, class K, class Comp, class Alloc>
typename ft::RBT<T, K, Comp, Alloc>::const_iterator	ft::RBT<T, K, Comp, Alloc>::begin() const { return const_iterator(minimum(this->_root)); }

template <class T, class K, class Comp, class Alloc>
typename ft::RBT<T, K, Comp, Alloc>::iterator	ft::RBT<T, K, Comp, Alloc>::end() { return iterator(this->_end); }

template <class T, class K, class Comp, class Alloc>
typename ft::RBT<T, K, Comp, Alloc>::const_iterator	ft::RBT<T, K, Comp, Alloc>::end() const { return const_iterator(this->_end); }

/**********************************************************/
/*						MODIFIERS						  */
/**********************************************************/
template <class T, class K, class Comp, class Alloc>
void	ft::RBT<T, K, Comp, Alloc>::setRoot(node_pointer root) { this->_root = root; }

template <class T, class K, class Comp, class Alloc>
ft::pair<typename ft::RBT<T, K, Comp, Alloc>::iterator, bool>	ft::RBT<T, K, Comp, Alloc>::insert(value_type val)
{
	if (search(val)) { return ft::make_pair(iterator(search(val)), false); }

	node_pointer	newNode = createNode(false, val);
	node_pointer	node = this->_root;
	node_pointer	tmp = this->_nil;
	
	if (this->_root == this->_nil || this->_root == this->_end) { this->_root = newNode; this->updateEnd(); this->_size++; return ft::make_pair(iterator(this->_root), true); }

	while (node != this->_nil && node != this->_end)
	{
		tmp = node;
		if (this->_comp(newNode->value.first, node->value.first)) { node = node->left; }
		else { node = node->right; }
	}

	newNode->parent = tmp;

	if (tmp == this->_nil || tmp == this->_end) { this->_root = newNode; }
	else if (this->_comp(newNode->value.first, tmp->value.first)) { tmp->left = newNode; }
	else { tmp->right = newNode; }

	newNode->color = RED;
	this->_size++;

	this->insert_fixup(newNode);
	this->updateEnd();
	return ft::make_pair(iterator(newNode), true);
}

template <class T, class K, class Comp, class Alloc>
typename ft::RBT<T, K, Comp, Alloc>::size_type	ft::RBT<T, K, Comp, Alloc>::erase(value_type val)
{
	node_pointer	z = search(val);

	if (!z) { return 0; }

	node_pointer	y = z;
	node_pointer	x;
	Color			y_original_color = y->color;
	
	if (z->left == this->_nil || z->left == this->_end) { x = z->right; this->transplant(z, z->right); }
	else if (z->right == this->_nil || z->right == this->_end) { x = z->left; this->transplant(z, z->left); }
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
	this->updateEnd();

	return 1;
}

template <class T, class K, class Comp, class Alloc>
void	ft::RBT<T, K, Comp, Alloc>::multi_erase(iterator it, iterator ite)
{
	iterator		tmp = it;
	size_type		n = 0;

	for (; it != ite; it++, n++);

	node_pointer	nodes[n];
	n = 0;
	for (; tmp != ite; tmp++, n++) { nodes[n] = tmp.get_pointer(); }

	for (size_type i = 0; i < n; i++) { erase(nodes[i]->value); }
}

template <class T, class K, class Comp, class Alloc>
void	ft::RBT<T, K, Comp, Alloc>::swap(RBT& rhs)
{
	ft::swap(this->_root, rhs._root);
	ft::swap(this->_end, rhs._end);
	ft::swap(this->_nil, rhs._nil);
	ft::swap(this->_size, rhs._size);
	ft::swap(this->_alloc, rhs._alloc);
	ft::swap(this->_comp, rhs._comp);
}

template <class T, class K, class Comp, class Alloc>
void	ft::RBT<T, K, Comp, Alloc>::clear(node_pointer node)
{
	if (node == NULL || node == this->_nil || node == this->_end) { this->_size = 0; this->_root = this->_nil; return; }
	clear(node->left);
	clear(node->right);
	destroyNode(node);
}

/**********************************************************/
/*						LOOKUP							  */
/**********************************************************/
template <class T, class K, class Comp, class Alloc>
typename ft::RBT<T, K, Comp, Alloc>::iterator	ft::RBT<T, K, Comp, Alloc>::find(const value_type& v)
{
	node_pointer	find = search(v);

	if (!find) { return iterator(_end); }
	return iterator(find);
}

template <class T, class K, class Comp, class Alloc>
typename ft::RBT<T, K, Comp, Alloc>::const_iterator	ft::RBT<T, K, Comp, Alloc>::find(const value_type& v) const
{
	node_pointer	find = search(v);

	if (!find) { return const_iterator(_end); }
	return const_iterator(find);
}

template <class T, class K, class Comp, class Alloc>
typename ft::RBT<T, K, Comp, Alloc>::size_type	ft::RBT<T, K, Comp, Alloc>::count(const value_type& v) const
{
	if (!search(v)) { return 0; }
	return 1;
}

template <class T, class K, class Comp, class Alloc>
typename ft::RBT<T, K, Comp, Alloc>::iterator	ft::RBT<T, K, Comp, Alloc>::lower_bound(const value_type& x)
{
	iterator	it = begin();
	iterator	it_end = end();

	for (; it != it_end; it++)
		if (!this->_comp(it->first, x.first)) { return it; }

	return it_end;
}

template <class T, class K, class Comp, class Alloc>
typename ft::RBT<T, K, Comp, Alloc>::const_iterator	ft::RBT<T, K, Comp, Alloc>::lower_bound(const value_type& x) const
{
	const_iterator	it = begin();
	const_iterator	it_end = end();

	for (; it != it_end; it++)
		if (!this->_comp(it->first, x.first)) { return it; }

	return it_end;
}

template <class T, class K, class Comp, class Alloc>
typename ft::RBT<T, K, Comp, Alloc>::iterator	ft::RBT<T, K, Comp, Alloc>::upper_bound(const value_type& x)
{
	iterator	it = begin();
	iterator	it_end = end();

	for (; it != it_end; it++)
		if (this->_comp(x.first, it->first)) { return it; }

	return it_end;
}

template <class T, class K, class Comp, class Alloc>
typename ft::RBT<T, K, Comp, Alloc>::const_iterator	ft::RBT<T, K, Comp, Alloc>::upper_bound(const value_type& x) const
{
	const_iterator	it = begin();
	const_iterator	it_end = end();

	for (; it != it_end; it++)
		if (this->_comp(x.first, it->first)) { return it; }

	return it_end;
}

/**********************************************************/
/*						CAPACITY						  */
/**********************************************************/
template <class T, class K, class Comp, class Alloc>
bool	ft::RBT<T, K, Comp, Alloc>::empty() const { return (this->_size == 0); }

template <class T, class K, class Comp, class Alloc>
typename ft::RBT<T, K, Comp, Alloc>::size_type	ft::RBT<T, K, Comp, Alloc>::size() const { return this->_size; }

template <class T, class K, class Comp, class Alloc>
typename ft::RBT<T, K, Comp, Alloc>::size_type	ft::RBT<T, K, Comp, Alloc>::max_size() const { return this->_alloc.max_size(); }

/**********************************************************/
/*						OTHERS							  */
/**********************************************************/
template <class T, class K, class Comp, class Alloc>
void	ft::RBT<T, K, Comp, Alloc>::printHelper(node_pointer root, std::string indent, bool last) const
{
	if (root == this->_nil || root == this->_end) { return; }
		
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
	std::cout << root->value.first << "(" << sColor << ")" << std::endl;
	printHelper(root->left, indent, false);
	printHelper(root->right, indent, true);
}

template <class T, class K, class Comp, class Alloc>
void	ft::RBT<T, K, Comp, Alloc>::printTree() const
{
	if (this->_root) { printHelper(this->_root, "", true); }
}

/**********************************************************/
/*						PRIVATES						  */
/**********************************************************/
template <class T, class K, class Comp, class Alloc>
typename ft::RBT<T, K, Comp, Alloc>::node_pointer	ft::RBT<T, K, Comp, Alloc>::createNode(bool is_nil, const value_type &val)
{
	node_pointer	node;

	node = this->_alloc.allocate(1);
	this->_alloc.construct(node, Node(val, is_nil));
	node->parent = this->_nil;
	node->left = this->_nil;
	node->right = this->_nil;
	return node;
}

template <class T, class K, class Comp, class Alloc>
void	ft::RBT<T, K, Comp, Alloc>::destroyNode(node_pointer node)
{
	this->_alloc.destroy(node);
	this->_alloc.deallocate(node, 1);
}

template <class T, class K, class Comp, class Alloc>
void	ft::RBT<T, K, Comp, Alloc>::updateEnd()
{
	node_pointer	node = maximum(this->_root);

	node->right = this->_end;
	this->_end->parent = node;
	this->_end->left = this->_nil;
	this->_end->right = this->_nil;
}

template <class T, class K, class Comp, class Alloc>
void	ft::RBT<T, K, Comp, Alloc>::leftRotate(node_pointer node)
{
	node_pointer	x = node;
	node_pointer	y;

	y = x->right;
	x->right = y->left;

	if (y->left != this->_nil && y->left != this->_end) { y->left->parent = x; }
	
	y->parent = x->parent;

	if (x->parent == this->_nil || x->parent == this->_end) { this->_root = y; }
	else if (x == x->parent->left) { x->parent->left = y; }
	else { x->parent->right = y; }

	y->left = x;
	x->parent = y;
}

template <class T, class K, class Comp, class Alloc>
void	ft::RBT<T, K, Comp, Alloc>::rightRotate(node_pointer node)
{
	node_pointer	x = node;
	node_pointer	y;

	y = x->left;
	x->left = y->right;

	if (y->right != this->_nil && y->right != this->_end) { y->right->parent = x; }
	
	y->parent = x->parent;

	if (x->parent == this->_nil || x->parent == this->_end) { this->_root = y; }
	else if (x == x->parent->right) { x->parent->right = y; }
	else { x->parent->left = y; }

	y->right = x;
	x->parent = y;
}

template <class T, class K, class Comp, class Alloc>
void	ft::RBT<T, K, Comp, Alloc>::insert_fixup(node_pointer node)
{
	node_pointer	tmp;

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

template <class T, class K, class Comp, class Alloc>
void	ft::RBT<T, K, Comp, Alloc>::transplant(node_pointer n1, node_pointer n2)
{
	if (n1->parent == this->_nil || n1->parent == this->_end) { this->_root = n2; }
	else if (n1 == n1->parent->left) { n1->parent->left = n2; }
	else { n1->parent->right = n2; }

	n2->parent = n1->parent;
}

template <class T, class K, class Comp, class Alloc>
void	ft::RBT<T, K, Comp, Alloc>::delete_fixup(node_pointer node)
{
	node_pointer	tmp;

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
