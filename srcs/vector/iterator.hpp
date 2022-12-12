#ifndef ITERATOR_VECTOR
# define ITERATOR_VECTOR

namespace ft
{
	template <class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
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
			~IteratorVertor();

			/* OPERATORS */
			IteratorVector	&operator=(const IteratorVector &rhs);
			IteratorVector	&operator++();
			IteratorVector	operator++(int);
			IteratorVector	&operator--();
			IteratorVector	operator--(int);

			/* ACCESS */
			pointer	pointer();

		private:
			pointer	_pointer;
	};
}

# include "iterator.tpp"

#endif
