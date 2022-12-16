#ifndef UTILS
# define UTILS

# include <iterator>

namespace ft
{
	template <class InputIt>
	size_t	distance(InputIt first, InputIt last);

	//iterator_traits

	template <bool B, class T = void>
	struct	enable_if;
	
	template <class T>
	struct	is_integral;

	//lexicographical_compare
	template <class InputIt1, class InputIt2>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2);

	//pair

	//make_pair
}

# include "utils.tpp"

#endif
