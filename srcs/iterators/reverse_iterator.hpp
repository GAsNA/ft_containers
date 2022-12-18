#ifndef REVERSE_ITERATOR
# define REVERSE_ITERATOR

# include <iterator>

# include "../utils/utils.hpp"

namespace ft
{
	template <class Iterator>
	class reverse_iterator
	{
		public:
			typedef Iterator													iterator;
			typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
			typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
			typedef typename ft::iterator_traits<Iterator>::reference			reference;
			typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;

			/* CONSTRUCTORS */
			reverse_iterator();
			explicit reverse_iterator(iterator x);
			template <class U>
			reverse_iterator(const reverse_iterator<U>& other);

			/* OPERATORS */
			template <class U>
			reverse_iterator	&operator=(const reverse_iterator<U>& other);
			reference				operator*() const;
			pointer					operator->() const;
			reference				operator[](difference_type n) const;
			reverse_iterator	&operator++();
			reverse_iterator	&operator--();
			reverse_iterator	operator++(int);
			reverse_iterator	operator--(int);
			reverse_iterator	operator+(difference_type n) const;
			reverse_iterator	operator-(difference_type n) const;
			reverse_iterator	&operator+=(difference_type n);
			reverse_iterator	&operator-=(difference_type n);
			
			/* ACCESS */
			iterator	base() const;

		protected:
			iterator	_iterator;
	};
}

# include "reverse_iterator.tpp"

#endif
