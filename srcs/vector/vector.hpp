/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <rleseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:42:02 by rleseur           #+#    #+#             */
/*   Updated: 2022/12/11 00:49:49 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <string>
# include <memory>

namespace ft
{
	template <class T, class Allocator = std::allocator<T>>
	class vector
	{
		public:
			typedef Allocator								allocator_type;
			typedef typename allocator_type::value_type		value_type;
			typedef typename allocator_type::size_type		size_type;
			typedef typename allocator_type::pointer		pointer;
			
			class InvalidIndexException : public std::exception
			{
				public:
					virtual const char* what() const throw() {return "Invalid index!";}
			};

			explicit vector (const allocator_type& alloc = allocator_type());
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type* = NULL);
			vector (const vector &x);

			~vector();

			vector	&operator=(const vector &rhs);
			T		&operator[](const int i) const;

			size_type	size(void) const {return this->_size;}

		private:
			pointer			_datas;
			size_type		_size;
			size_type		_capacity;
			allocator_type	_alloc;

	};
	
/*	template <class T, class Alloc>
	bool	operator==(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs);
	template <class T, class Alloc>
	bool	operator!=(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs);
	template <class T, class Alloc>
	bool	operator<(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs);
	template <class T, class Alloc>
	bool	operator<=(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs);
	template <class T, class Alloc>
	bool	operator>(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs);
	template <class T, class Alloc>
	bool	operator>=(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs);
*/
}

# include "vector.tpp"

#endif
