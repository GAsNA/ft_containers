#ifndef REVERSE_ITERATOR_VECTOR
# define REVERSE_ITERATOR_VECTOR

# include <iterator>

# include "../utils/utils.hpp"

namespace ft
{
	template <class Iterator>
	class ReverseIteratorVector
	{
		public:
			typedef Iterator													iterator;
			typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
			typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
			typedef typename ft::iterator_traits<Iterator>::reference			reference;
			typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;

			/* CONSTRUCTORS */
			ReverseIteratorVector();
			explicit ReverseIteratorVector(iterator x);
			template <class U>
			ReverseIteratorVector(const ReverseIteratorVector<U>& other);

			/* OPERATORS */
			template <class U>
			ReverseIteratorVector	&operator=(const ReverseIteratorVector<U>& other);
			reference				operator*() const;
			pointer					operator->() const;
			reference				operator[](difference_type n) const;
			ReverseIteratorVector	&operator++();
			ReverseIteratorVector	&operator--();
			ReverseIteratorVector	operator++(int);
			ReverseIteratorVector	operator--(int);
			ReverseIteratorVector	operator+(difference_type n) const;
			ReverseIteratorVector	operator-(difference_type n) const;
			ReverseIteratorVector	&operator+=(difference_type n);
			ReverseIteratorVector	&operator-=(difference_type n);
			
			/* ACCESS */
			iterator	base() const;

		protected:
			iterator	_iterator;
	};
}

# include "ReverseIteratorVector.tpp"

#endif
