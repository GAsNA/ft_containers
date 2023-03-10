/**********************************************************/
/*						DISTANCE						  */
/**********************************************************/

template <class InputIt>
size_t	ft::distance(InputIt first, InputIt last)
{
	size_t i = 0;
	for (; first != last; ++first, i++);
	return i;
}

/**********************************************************/
/*					ITERATOR_TRAITS						  */
/**********************************************************/

template <class Ite>
class ft::iterator_traits
{
	public:
		typedef typename Ite::difference_type	difference_type;
		typedef typename Ite::value_type		value_type;
		typedef typename Ite::pointer			pointer;
		typedef typename Ite::reference			reference;
		typedef typename Ite::iterator_category	iterator_category;
};

template <class T>
class ft::iterator_traits<T*>
{
	public:
		typedef std::ptrdiff_t					difference_type;
		typedef T								value_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef std::random_access_iterator_tag	iterator_category;
};

template <class T>
class ft::iterator_traits<const T*>
{
	public:
		typedef std::ptrdiff_t					difference_type;
		typedef T								value_type;
		typedef const T*						pointer;
		typedef const T&						reference;
		typedef std::random_access_iterator_tag	iterator_category;
};

/**********************************************************/
/*						ENABLE_IF						  */
/**********************************************************/

template <bool B, class T>
struct	ft::enable_if
{};

template <class T>
struct ft::enable_if<true, T>
{
	typedef T	type;
};

/**********************************************************/
/*						IS_INTEGRAL						  */
/**********************************************************/

template <class T>
struct	ft::is_integral
{
	static const bool	value = false;
};

template <>
struct	ft::is_integral<bool>
{
	static const bool	value = true;
};

template <>
struct	ft::is_integral<char>
{
	static const bool	value = true;
};

template <>
struct	ft::is_integral<wchar_t>
{
	static const bool	value = true;
};

template <>
struct	ft::is_integral<signed char>
{
	static const bool	value = true;
};

template <>
struct	ft::is_integral<short int>
{
	static const bool	value = true;
};

template <>
struct	ft::is_integral<int>
{
	static const bool	value = true;
};

template <>
struct	ft::is_integral<long int>
{
	static const bool	value = true;
};

template <>
struct	ft::is_integral<long long int>
{
	static const bool	value = true;
};

template <>
struct	ft::is_integral<unsigned char>
{
	static const bool	value = true;
};

template <>
struct	ft::is_integral<unsigned short int>
{
	static const bool	value = true;
};

template <>
struct	ft::is_integral<unsigned int>
{
	static const bool	value = true;
};

template <>
struct	ft::is_integral<unsigned long int>
{
	static const bool	value = true;
};

template <>
struct	ft::is_integral<unsigned long long int>
{
	static const bool	value = true;
};

template <>
struct	ft::is_integral<const bool>
{
	static const bool	value = true;
};

template <>
struct	ft::is_integral<const char>
{
	static const bool	value = true;
};

template <>
struct	ft::is_integral<const wchar_t>
{
	static const bool	value = true;
};

template <>
struct	ft::is_integral<const signed char>
{
	static const bool	value = true;
};

template <>
struct	ft::is_integral<const short int>
{
	static const bool	value = true;
};

template <>
struct	ft::is_integral<const int>
{
	static const bool	value = true;
};

template <>
struct	ft::is_integral<const long int>
{
	static const bool	value = true;
};

template <>
struct	ft::is_integral<const long long int>
{
	static const bool	value = true;
};

template <>
struct	ft::is_integral<const unsigned char>
{
	static const bool	value = true;
};

template <>
struct	ft::is_integral<const unsigned short int>
{
	static const bool	value = true;
};

template <>
struct	ft::is_integral<const unsigned int>
{
	static const bool	value = true;
};

template <>
struct	ft::is_integral<const unsigned long int>
{
	static const bool	value = true;
};

template <>
struct	ft::is_integral<const unsigned long long int>
{
	static const bool	value = true;
};

/**********************************************************/
/*					LEXICOGRAPHICAL_COMPARE				  */
/**********************************************************/

template<class InputIt1, class InputIt2>
bool	ft::lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
{
	for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
	{
		if (*first1 < *first2)
			return true;
		if (*first2 < *first1)
			return false;
	}
	return (first1 == last1) && (first2 != last2);
}

template <class InputIt1, class InputIt2, class Compare>
bool	lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp)
{
	for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
	{
		if (comp(*first1, *first2))
			return true;
		if (comp(*first2, *first1))
			return false;
	}
	return (first1 == last1) && (first2 != last2);	
}


/**********************************************************/
/*							PAIR						  */
/**********************************************************/

template <class T1, class T2>
struct	ft::pair
{
	typedef T1	first_type;
	typedef T2	second_type;

	T1	first;
	T2	second;

	pair() : first(T1()), second(T2()) {}
	pair(const T1& x, const T2& y) : first(x), second(y) {}
	template <class U1, class U2>
	pair(const pair<U1, U2>& p) : first(p.first), second(p.second) {}
	
	pair &operator=(const pair &other)
	{
		if (this == &other) {return ;}

		first = other.first;
		second = other.second;
		return *this;
	}
};

template <class T1, class T2>
bool	operator==(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs)
{
	return lhs.first == rhs.first && lhs.second == rhs.second;
}

template <class T1, class T2>
bool	operator!=(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs)
{
	return !(lhs == rhs);
}

template <class T1, class T2>
bool	operator<(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs)
{
	return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
}

template <class T1, class T2>
bool	operator<=(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs)
{
	return !(rhs < lhs);
}

template <class T1, class T2>
bool	operator>(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs)
{
	return rhs < lhs;
}

template <class T1, class T2>
bool	operator>=(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs)
{
	return !(lhs < rhs);
}

/**********************************************************/
/*						MAKE_PAIR						  */
/**********************************************************/

template <class T1, class T2>
ft::pair<T1, T2> ft::make_pair(T1 t, T2 u)
{
	return pair<T1, T2>(t, u);
}

/**********************************************************/
/*							SWAP						  */
/**********************************************************/

template <class T>
void	ft::swap(T& a, T& b)
{
	T	tmp = a;
	a = b;
	b = tmp;
}
