#ifndef ITERATOR_RBT
# define ITERATOR_RBT

# include <iterator>

namespace ft
{
	template <class T, class N>
	class iterator_rbt
	{
		public:
			typedef std::bidirectional_iterator_tag						iterator_category;
			typedef typename ft::iterator_traits<T*>::value_type		value_type;
			typedef typename ft::iterator_traits<T*>::difference_type	difference_type;
			typedef typename ft::iterator_traits<T*>::pointer			pointer;
			typedef typename ft::iterator_traits<T*>::reference			reference;
			typedef N*													node_pointer;

			/* CONSTRUCTORS */
			iterator_rbt();
			iterator_rbt(node_pointer ptr);
			iterator_rbt(const iterator_rbt &x);
			~iterator_rbt();

			/* OPERATORS */
			operator	iterator_rbt<const T, N>() const
			{
				return iterator_rbt<const T, N>(_pointer);
			}
			iterator_rbt	&operator=(const iterator_rbt<const T, N> &rhs);
			iterator_rbt	&operator++();
			iterator_rbt	operator++(int);
			iterator_rbt	&operator--();
			iterator_rbt	operator--(int);
			/*bool			operator>(iterator_rbt<const T, N> const &) const;
			bool			operator<(iterator_rbt<const T, N> const &) const;
			bool			operator>=(iterator_rbt<const T, N> const &) const;
			bool			operator<=(iterator_rbt<const T, N> const &) const;*/
			bool			operator==(iterator_rbt<const T, N> const &) const;
			bool			operator!=(iterator_rbt<const T, N> const &) const;
			T				&operator*() const;
			T				*operator->() const;
			//reference		operator[](int i);

			/* ACCESS */
			node_pointer	get_pointer() const;

		private:
			node_pointer	_pointer;
	};
}

# include "iterator_rbt.tpp"

#endif
