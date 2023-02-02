#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP

# include <functional>
# include <memory>

# include "utils.hpp"

namespace ft
{
	enum Color { RED, BLACK };

	template <class Key>
	struct Node
	{
		Color		color;
		Key		key;
		Node<Key>	*left;
		Node<Key>	*right;
		Node<Key>	*parent;
	};

	template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
	class RBT
	{
		public:
		private:
	};

	# include "RedBlackTree.tpp"
}

#endif
