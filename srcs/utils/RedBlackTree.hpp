#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP

# include <functional>
# include <memory>
# include <iostream>

# include "utils.hpp"

namespace ft
{
	enum Color { RED, BLACK };

	template <class T>
	struct Node
	{
		Color		color;
		T			value;
		Node<T>		*left;
		Node<T>		*right;
		Node<T>		*parent;

		Node(T val) : color(BLACK), value(val), left(NULL), right(NULL), parent(NULL) {}
	};

	template <class T>
	bool	operator==(const Node<T>& lhs, const Node<T>& rhs)
	{
		return lhs.value == rhs.value && lhs.parent == rhs.parent;
	}

	template <class T>
	bool	operator!=(const Node<T>& lhs, const Node<T>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class T>
	bool	operator<(const Node<T>& lhs, const Node<T>& rhs)
	{
		return lhs.value < rhs.value;
	}

	template <class T>
	bool	operator>(const Node<T>& lhs, const Node<T>& rhs)
	{
		return lhs.value > rhs.value;
	}
	
	template <class T>
	bool	operator<=(const Node<T>& lhs, const Node<T>& rhs)
	{
		return lhs.value <= rhs.value;
	}

	template <class T>
	bool	operator>=(const Node<T>& lhs, const Node<T>& rhs)
	{
		return lhs.value >= rhs.value;
	}

	template <class T, class Compare = std::less<T>, class Allocator = std::allocator<Node<T> > >
	class RBT
	{
		public:
			typedef	T											value_type;
			typedef Allocator									allocator_type;
			typedef Compare										value_compare;

			typedef std::ptrdiff_t								difference_type;
			typedef std::size_t									size_type;
			// SEE ITERATORS

			//template rebind ?? node alloc
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;

			/* CONSTRUCTORS */
			explicit RBT(const allocator_type& alloc = allocator_type(), const value_compare& comp = value_compare());
			RBT(const RBT &cpy);
			~RBT();

			/* OPERATORS */
			RBT	&operator=(const RBT &rhs);

			/* ACCESS */
			Node<T>		*getRoot() const;
			size_type	size() const;
			Node<T>		*search(value_type val) const;
			Node<T>		*minimum(Node<T> *node) const;
			Node<T>		*maximum(Node<T> *node) const;

			/* MODIFIERS */
			void	setRoot(Node<T> *root);
			void	insert(value_type val);
			void	deleteNode(value_type val);
			void	clear(Node<T> *node);

			/* OTHERS */
			void	printHelper(Node<T> *root, std::string indent, bool last) const;
			void	printTree() const;

		private:
			allocator_type	_alloc;
			//node alloc ?? see for typedef
			value_compare	_comp;
			Node<T>			*_root;
			Node<T>			*_nil;
			size_type		_size;

			Node<T>			*createNode(value_type val);
			void			destroyNode(Node<T> *node);
			void			leftRotate(Node<T> *node);
			void			rightRotate(Node<T> *node);
			void			insert_fixup(Node<T> *node);
			void			transplant(Node<T> *n1, Node<T> *n2);
			void			delete_fixup(Node<T> *node);
	};

	# include "RedBlackTree.tpp"
}

#endif
