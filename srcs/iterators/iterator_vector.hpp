#ifndef ITERATOR_VECTOR
# define ITERATOR_VECTOR

# include <iterator>

namespace ft
{
	template <class T, class Category = std::random_access_iterator_tag, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
	class iterator_vector
	{
		public:
			typedef Category	iterator_category;
			typedef T			value_type;
			typedef Distance	difference_type;
			typedef Pointer		pointer;
			typedef Reference	reference;

			/* CONSTRUCTORS */
			iterator_vector();
			iterator_vector(pointer ptr);
			iterator_vector(const iterator_vector &x);
			~iterator_vector();

			/* OPERATORS */
			operator		iterator_vector<const T>() const;
			iterator_vector	&operator=(const iterator_vector<const T> &rhs);
			iterator_vector	&operator++();
			iterator_vector	operator++(int);
			iterator_vector	&operator--();
			iterator_vector	operator--(int);
			bool			operator>(iterator_vector<const T> const &) const;
			bool			operator<(iterator_vector<const T> const &) const;
			bool			operator>=(iterator_vector<const T> const &) const;
			bool			operator<=(iterator_vector<const T> const &) const;
			bool			operator==(iterator_vector<const T> const &) const;
			bool			operator!=(iterator_vector<const T> const &) const;
			value_type		&operator*();
			value_type		*operator->();
			iterator_vector	operator+(int n) const;
			iterator_vector	&operator+=(int n);
			iterator_vector	operator-(int n) const;
			iterator_vector	&operator-=(int n);
			int				operator-(iterator_vector<const T> const &) const;
			reference		operator[](int i);

			/* ACCESS */
			pointer	get_pointer() const;

		private:
			pointer	_pointer;
	};

	/*template <class T, class Category, class Distance, class Pointer, class Reference>
	iterator_vector	operator+(int n, iterator_vector<const T> const &) const;*/
}

# include "iterator_vector.tpp"

#endif
