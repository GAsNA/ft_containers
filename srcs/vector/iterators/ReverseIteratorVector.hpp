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
			operator				ReverseIteratorVector<const T>() const;
			ReverseIteratorVector	&operator=(const ReverseIteratorVector<const T> &rhs);
			ReverseIteratorVector	&operator++();
			ReverseIteratorVector	operator++(int);
			ReverseIteratorVector	&operator--();
			ReverseIteratorVector	operator--(int);
			bool					operator>(ReverseIteratorVector<const T> const &) const;
			bool					operator<(ReverseIteratorVector<const T> const &) const;
			bool					operator>=(ReverseIteratorVector<const T> const &) const;
			bool					operator<=(ReverseIteratorVector<const T> const &) const;
			bool					operator==(ReverseIteratorVector<const T> const &) const;
			bool					operator!=(ReverseIteratorVector<const T> const &) const;
			value_type				&operator*();
			value_type				*operator->();
			ReverseIteratorVector	operator+(int n) const;
			ReverseIteratorVector	&operator+=(int n);
			ReverseIteratorVector	operator-(int n) const;
			ReverseIteratorVector	&operator-=(int n);
			int						operator-(ReverseIteratorVector<const T> const &) const;
			reference				operator[](int i);

			/* ACCESS */
			pointer	get_pointer() const;

		private:
			pointer	_pointer;
	};
}

# include "ReverseIteratorVector.tpp"

#endif
