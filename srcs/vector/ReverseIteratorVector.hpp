#ifndef REVERSE_ITERATOR_VECTOR
# define REVERSE_ITERATOR_VECTOR

# include <iterator>

namespace ft
{
	template <class T, class Category = std::random_access_iterator_tag, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
	class ReverseIteratorVector
	{
		public:
			typedef Category	iterator_category;
			typedef T			value_type;
			typedef Distance	difference_type;
			typedef Pointer		pointer;
			typedef Reference	reference;

			/* CONSTRUCTORS */
			ReverseIteratorVector();
			ReverseIteratorVector(pointer ptr);
			ReverseIteratorVector(const ReverseIteratorVector &x);
			~ReverseIteratorVector();

			/* OPERATORS */
			ReverseIteratorVector	&operator=(const ReverseIteratorVector &rhs);
			ReverseIteratorVector	&operator++();
			ReverseIteratorVector	operator++(int);
			ReverseIteratorVector	&operator--();
			ReverseIteratorVector	operator--(int);
			bool			operator>(ReverseIteratorVector const &) const;
			bool			operator<(ReverseIteratorVector const &) const;
			bool			operator>=(ReverseIteratorVector const &) const;
			bool			operator<=(ReverseIteratorVector const &) const;
			bool			operator==(ReverseIteratorVector const &) const;
			bool			operator!=(ReverseIteratorVector const &) const;
			T				&operator*();

			/* ACCESS */
			pointer	get_pointer() const;

		private:
			pointer	_pointer;
	};
}

# include "ReverseIteratorVector.tpp"

#endif
