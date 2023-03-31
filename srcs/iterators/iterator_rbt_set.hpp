#ifndef ITERATOR_RBT_SET
# define ITERATOR_RBT_SET

# include <iterator>

namespace ft
{
	template <class T, class N>
	class iterator_rbt_set
	{
		public:
			typedef std::bidirectional_iterator_tag						iterator_category;
			typedef typename ft::iterator_traits<T*>::value_type		value_type;
			typedef typename ft::iterator_traits<T*>::difference_type	difference_type;
			typedef typename ft::iterator_traits<T*>::pointer			pointer;
			typedef typename ft::iterator_traits<T*>::reference			reference;
			typedef N*													node_pointer;

			/* CONSTRUCTORS */
			iterator_rbt_set();
			iterator_rbt_set(node_pointer ptr);
			iterator_rbt_set(const iterator_rbt_set &x);
			~iterator_rbt_set();

			/* OPERATORS */
			operator	iterator_rbt_set<const T, N>() const
			{
				return iterator_rbt_set<const T, N>(_pointer);
			}
			iterator_rbt_set	&operator=(const iterator_rbt_set<const T, N> &rhs);
			iterator_rbt_set	&operator++();
			iterator_rbt_set	operator++(int);
			iterator_rbt_set	&operator--();
			iterator_rbt_set	operator--(int);
			/*bool			operator>(iterator_rbt_set<const T, N> const &) const;
			bool			operator<(iterator_rbt_set<const T, N> const &) const;
			bool			operator>=(iterator_rbt_set<const T, N> const &) const;
			bool			operator<=(iterator_rbt_set<const T, N> const &) const;*/
			bool			operator==(iterator_rbt_set<const T, N> const &) const;
			bool			operator!=(iterator_rbt_set<const T, N> const &) const;
			T				&operator*() const;
			T				*operator->() const;
			//reference		operator[](int i);

			/* ACCESS */
			node_pointer	get_pointer() const;

		private:
			node_pointer	_pointer;
	};
}

# include "iterator_rbt_set.tpp"

#endif
