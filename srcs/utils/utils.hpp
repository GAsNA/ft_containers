#ifndef UTILS
# define UTILS

# include <iterator>
# include <cstddef>

namespace ft
{
	/* DISTANCE */
	template <class InputIt>
	size_t	distance(InputIt first, InputIt last);

	/* ITERATOR_TRAITS */
	template <class Ite>
	class iterator_traits;

	template <class T>
	class iterator_traits<T*>;

	template <class T>
	class iterator_traits<const T*>;

	/* ENABLE_IF */
	template <bool B, class T = void>
	struct	enable_if;
	
	/* IS_INTEGRAL */
	template <class T>
	struct	is_integral;

	/* LEXICOGRAPHICAL_COMPARE */
	template <class InputIt1, class InputIt2>
	bool	lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2);

	template <class InputIt1, class InputIt2, class Compare>
	bool	lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp);

	/* PAIR */
	template <class T1, class T2>
	struct pair;

	/* MAKE_PAIR */
	template <class T1, class T2>
	ft::pair<T1, T2> make_pair(T1 t, T2 u);
}

# include "utils.tpp"

#endif
