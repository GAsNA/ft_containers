#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP

# include <functional>
# include <memory>

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
	};

	template <class T, class Compare = std::less<T>, class Allocator = std::allocator<T> >
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
			RBT();
			RBT(const RBT &cpy);
			~RBT();

			/* OPERATORS */
			RBT	&operator=(const RBT &rhs);

			/* ACCESS */
			Node<T>	*getRoot() const;

			/* MODIFIERS */
			void		setRoot(Node<T> *root);

		private:
			allocator_type	_alloc;
			//node alloc ?? see for typedef
			value_compare	_comp;
			Node<T>			*_root;
			// nill and header ?
			size_type		_size;
	};

	# include "RedBlackTree.tpp"
}

#endif
