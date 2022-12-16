#ifndef UTILS
# define UTILS

# include <iterator>

namespace ft
{
	template <class InputIt>
	size_t	distance(InputIt first, InputIt last);

	template <bool B, class T = void>
	struct	enable_if;
	
	template <class T>
	struct	is_integral;
}

# include "utils.tpp"

#endif
