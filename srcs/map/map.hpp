/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <rleseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:42:02 by rleseur           #+#    #+#             */
/*   Updated: 2022/12/20 18:53:40 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <string>
# include <memory>
# include <stdexcept>
# include <iterator>

# include "../utils/utils.hpp"
# include "../iterators/reverse_iterator.hpp"

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		public:
			typedef Key									key_type;
			typedef T									mapped_type;
			typedef ft::pair<const Key, T>				value_type;
			typedef std::size_t							size_type;
			typedef std::ptrdiff_t						difference_type;
			typedef Compare								key_compare;
			typedef Allocator							allocator_type;
			typedef value_type&							reference;
			typedef const value_type&					const_reference;
			typedef typename Allocator::pointer			pointer;
			typedef typename Allocator::const_pointer	const_pointer;
			// iterators

			/* CONSTRUCTORS */

			/* OPERATORS */

			/* ACCESS */

			/* ITERATORS */

			/* CAPACITY */

			/* MODIFIERS */

		private:
			Compare			_comp;
			allocator_type	_alloc;
	};

	//# include "constructors.tpp"
}

#endif
