#ifndef ITERATOR_RBT
# define ITERATOR_RBT

# include <iterator>

namespace ft
{
	template <class T>
	class iterator_rbt
	{
		public:
			typedef std::bidirectionel_iterator_tag						iterator_category;
			typedef typename ft::iterator_traits<T*>::value_type		value_type;
			typedef typename ft::iterator_traits<T*>::difference_type	difference_type;
			typedef typename ft::iterator_traits<T*>::pointer			pointer;
			typedef typename ft::iterator_traits<T*>::reference			reference;
			typedef ft::Node<T>*										node_pointer;

			/* CONSTRUCTORS */
			iterator_rbt();
			iterator_rbt(node_pointer ptr);
			iterator_rbt(const iterator_rbt &x);
			~iterator_rbt();

			/* OPERATORS */
			operator		iterator_rbt<const T>() const;
			iterator_rbt	&operator=(const iterator_rbt<const T> &rhs);
			iterator_rbt	&operator++();
			iterator_rbt	operator++(int);
			iterator_rbt	&operator--();
			iterator_rbt	operator--(int);
			bool			operator>(iterator_rbt<const T> const &) const;
			bool			operator<(iterator_rbt<const T> const &) const;
			bool			operator>=(iterator_rbt<const T> const &) const;
			bool			operator<=(iterator_rbt<const T> const &) const;
			bool			operator==(iterator_rbt<const T> const &) const;
			bool			operator!=(iterator_rbt<const T> const &) const;
			value_type		&operator*();
			value_type		*operator->();
			//reference		operator[](int i);

			/* ACCESS */
			node_pointer	get_pointer() const;

		private:
			node_pointer	_pointer;
	};
}

# include "iterator_rbt.tpp"

#endif
