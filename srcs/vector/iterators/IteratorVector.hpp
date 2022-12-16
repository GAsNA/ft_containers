#ifndef ITERATOR_VECTOR
# define ITERATOR_VECTOR

# include <iterator>

namespace ft
{
	template <class T, class Category = std::random_access_iterator_tag, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
	class IteratorVector
	{
		public:
			typedef Category	iterator_category;
			typedef T			value_type;
			typedef Distance	difference_type;
			typedef Pointer		pointer;
			typedef Reference	reference;

			/* CONSTRUCTORS */
			IteratorVector();
			IteratorVector(pointer ptr);
			IteratorVector(const IteratorVector &x);
			~IteratorVector();

			/* OPERATORS */
			operator		IteratorVector<const T>() const;
			IteratorVector	&operator=(const IteratorVector<const T> &rhs);
			IteratorVector	&operator++();
			IteratorVector	operator++(int);
			IteratorVector	&operator--();
			IteratorVector	operator--(int);
			bool			operator>(IteratorVector<const T> const &) const;
			bool			operator<(IteratorVector<const T> const &) const;
			bool			operator>=(IteratorVector<const T> const &) const;
			bool			operator<=(IteratorVector<const T> const &) const;
			bool			operator==(IteratorVector<const T> const &) const;
			bool			operator!=(IteratorVector<const T> const &) const;
			value_type		&operator*();
			value_type		*operator->(); // TODO
			IteratorVector	operator+(int n) const;
			IteratorVector	&operator+=(int n);
			IteratorVector	operator-(int n) const;
			IteratorVector	&operator-=(int n);
			int				operator-(IteratorVector<const T> const &) const;

			/* ACCESS */
			pointer	get_pointer() const;

		private:
			pointer	_pointer;
	};
}

# include "IteratorVector.tpp"

#endif
