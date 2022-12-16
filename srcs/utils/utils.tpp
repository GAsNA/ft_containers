/**********************************************************/
/*						DISTANCE						  */
/**********************************************************/

template <class InputIt>
size_t	ft::distance(InputIt first, InputIt last)
{
	/*size_t i = 0;
	for (; first < last; first++, i++);
	return i;*/
	return last - first;
}

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
