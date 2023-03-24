#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP

# include <functional>
# include <memory>
# include <iostream>

# include "utils.hpp"
# include "../iterators/reverse_iterator.hpp"
# include "../iterators/iterator_rbt.hpp"

enum Color { RED, BLACK };

namespace ft
{
	template <class T, class K, class Compare = std::less<K>, class Allocator = std::allocator<T> >
	class RBT
	{
		public:
			typedef	T																value_type;

		private:
			struct Node
			{
				Color	color;
				T		value;
				Node	*left;
				Node	*right;
				Node	*parent;
				bool	is_nil;
				
				Node(const value_type& val, bool is_nil) : color(BLACK), value(val), left(NULL), right(NULL), parent(NULL), is_nil(is_nil) {}
			};

		public:
			typedef	const T															const_value_type;
			typedef	K																key_type;
			typedef Allocator														allocator_type;
			typedef Compare															value_compare;
			typedef value_type&														reference;
			typedef const value_type&												const_reference;
			typedef value_type*														pointer;
			typedef const value_type*												const_pointer;
			typedef Node*															node_pointer;
			typedef const Node*														const_node_pointer;

			typedef std::ptrdiff_t													difference_type;
			typedef std::size_t														size_type;

			typedef typename allocator_type::template rebind<Node>::other			node_allocator;
			typedef typename ft::iterator_rbt<value_type, Node>						iterator;
			typedef typename ft::iterator_rbt<const_value_type, Node>				const_iterator;

			/* CONSTRUCTORS */
			explicit RBT(const allocator_type& alloc = allocator_type(), const value_compare& comp = value_compare());
			RBT(const RBT &cpy);
			~RBT();

			/* OPERATORS */
			RBT	&operator=(const RBT &rhs);

			/* ACCESS */
			node_pointer	getRoot() const;
			node_allocator	get_allocator() const;
			node_pointer	search(value_type val) const;
			node_pointer	minimum(node_pointer node) const;
			node_pointer	maximum(node_pointer node) const;
			value_compare	compare() const;

			/* ITERATORS */
			iterator				begin();
			const_iterator			begin() const;
			iterator				end();
			const_iterator			end() const;

			/* MODIFIERS */
			void						setRoot(node_pointer root);
			ft::pair<iterator, bool>	insert(value_type val);
			size_type					erase(value_type val);
			void						multi_erase(iterator it, iterator ite);
			void						swap(RBT& rhs);
			void						clear(node_pointer node);

			/* LOOKUP */
			iterator		find(const value_type& v);
			const_iterator	find(const value_type& v) const;
			size_type		count(const value_type& v) const;
			iterator		lower_bound(const value_type& x);
			const_iterator	lower_bound(const value_type& x) const;
			iterator		upper_bound(const value_type& x);
			const_iterator	upper_bound(const value_type& x) const;

			/* CAPACITY */
			bool			empty() const;
			size_type		size() const;
			size_type		max_size() const;

			/* OTHERS */
			void	printHelper(node_pointer root, std::string indent, bool last) const;
			void	printTree() const;

		private:
			node_allocator	_alloc;
			value_compare	_comp;
			node_pointer	_root;
			node_pointer	_end;
			node_pointer	_nil;
			size_type		_size;

			node_pointer	createNode(bool is_nil, const value_type &val = value_type());
			void			destroyNode(node_pointer node);
			void			updateEnd();
			void			leftRotate(node_pointer node);
			void			rightRotate(node_pointer node);
			void			insert_fixup(node_pointer node);
			void			transplant(node_pointer n1, node_pointer n2);
			void			delete_fixup(node_pointer node);
	};

	# include "RedBlackTree.tpp"
}

#endif
