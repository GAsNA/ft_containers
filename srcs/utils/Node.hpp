#ifndef NODE_HPP
# define NODE_HPP

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
		bool		is_nil;

		Node(T val, bool is_nil) : color(BLACK), value(val), left(NULL), right(NULL), parent(NULL), is_nil(is_nil) {}
	};
	# include "Node.tpp"
}

#endif
