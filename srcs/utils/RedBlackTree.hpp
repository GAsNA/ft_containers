#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP

# include <functional>
# include <memory>
# include <iostream>

# include "utils.hpp"
# include "Node.hpp"
# include "../iterators/iterator_rbt.hpp"

namespace ft
{
	template <class T, class Compare = std::less<T>, class Allocator = std::allocator<T> >
	class RBT
	{
		public:
			typedef	T																value_type;
			typedef	const T															const_value_type;
			typedef Allocator														allocator_type;
			typedef Compare															value_compare;

			typedef std::ptrdiff_t													difference_type;
			typedef std::size_t														size_type;
			typedef typename ft::iterator_rbt<value_type>							iterator;
			typedef typename ft::iterator_rbt<const_value_type>						const_iterator;

			typedef typename allocator_type::template rebind<ft::Node<T> >::other	node_allocator;
			typedef typename allocator_type::reference								reference;
			typedef typename allocator_type::const_reference						const_reference;
			typedef typename allocator_type::pointer								pointer;
			typedef typename allocator_type::const_pointer							const_pointer;

			/* CONSTRUCTORS */
			explicit RBT(const allocator_type& alloc = allocator_type(), const value_compare& comp = value_compare());
			RBT(const RBT &cpy);
			~RBT();

			/* OPERATORS */
			RBT	&operator=(const RBT &rhs);

			/* ACCESS */
			ft::Node<T>		*getRoot() const;
			size_type		size() const;
			ft::Node<T>		*search(value_type val) const;
			ft::Node<T>		*minimum(ft::Node<T> *node) const;
			ft::Node<T>		*maximum(ft::Node<T> *node) const;

			/* MODIFIERS */
			void	setRoot(ft::Node<T> *root);
			void	insert(value_type val);
			void	deleteNode(value_type val);
			void	clear(ft::Node<T> *node);

			/* OTHERS */
			void	printHelper(ft::Node<T> *root, std::string indent, bool last) const;
			void	printTree() const;

		private:
			allocator_type	_alloc;
			node_allocator	_node_alloc;
			value_compare	_comp;
			ft::Node<T>		*_root;
			ft::Node<T>		*_nil;
			size_type		_size;

			ft::Node<T>		*createNode(value_type val, bool is_nil);
			void			destroyNode(ft::Node<T> *node);
			void			leftRotate(ft::Node<T> *node);
			void			rightRotate(ft::Node<T> *node);
			void			insert_fixup(ft::Node<T> *node);
			void			transplant(ft::Node<T> *n1, ft::Node<T> *n2);
			void			delete_fixup(ft::Node<T> *node);
	};

	# include "RedBlackTree.tpp"
}

#endif
