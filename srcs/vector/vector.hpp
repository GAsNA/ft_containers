/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <rleseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:42:02 by rleseur           #+#    #+#             */
/*   Updated: 2022/12/09 17:45:37 by rleseur          ###   ########.fr       */
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

			explicit vector (const allocator_type& alloc = allocator_type());
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type* = NULL);
			vector (const vector &x);

			~vector();

		private:
			pointer			_datas;
			size_t			_size;
			size_t			_capacity;
			allocator_type	_alloc;

	};

}

# include "vector.tpp"

#endif
