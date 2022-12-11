/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <rleseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:42:02 by rleseur           #+#    #+#             */
/*   Updated: 2022/12/11 19:31:49 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <string>
# include <memory>
# include <stdexcept>

namespace ft
{
	template <class T, class Allocator = std::allocator<T>>
	class vector
	{
		public:
			typedef Allocator									allocator_type;
			typedef typename allocator_type::value_type			value_type;
			typedef typename allocator_type::size_type			size_type;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			
			class InvalidIndexException : public std::exception
			{
				public:
					virtual const char* what() const throw() {return "Invalid index!";}
			};

			/* CONSTRUCTORS */
			explicit vector (const allocator_type& alloc = allocator_type());
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type* = NULL);
			vector (const vector &x);
			~vector();

			/* OPERATORS */
			vector	&operator=(const vector &rhs);
			T		&operator[](const int i) const;

			/* ACCESS */
			reference		at(size_type pos);
			const_reference	at(size_type pos) const;
			reference		front();
			const_reference	front() const;
			reference		back();
			const_reference	back() const;
			T*				data();
			const T*		data() const;

			/* CAPACITY */
			bool		empty() const;
			size_type	size() const;
			size_type	max_size() const;
			void		reserve(size_type new_cap);
			size_type	capacity() const;

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
